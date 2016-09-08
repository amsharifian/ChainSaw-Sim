/*
  local-space-mapper.c - map to memory-space based in initiator

  Copyright (C) 1998-2005 Virtutech AB, All Rights Reserved

  This program is a component ("Component") of Virtutech Simics and is
  being distributed under Section 1(a)(iv) of the Virtutech Simics
  Software License Agreement (the "Agreement").  You should have
  received a copy of the Agreement with this Component; if not, please
  write to Virtutech AB, Norrtullsgatan 15, 1tr, SE-113 27 STOCKHOLM,
  Sweden for a copy of the Agreement prior to using this Component.

  By using this Component, you agree to be bound by all of the terms of
  the Agreement.  If you do not agree to the terms of the Agreement, you
  may not use, copy or otherwise access the Component or any derivatives
  thereof.  You may create and use derivative works of this Component
  pursuant to the terms the Agreement provided that any such derivative
  works may only be used in conjunction with and as a part of Virtutech
  Simics for use by an authorized licensee of Virtutech.

  THIS COMPONENT AND ANY DERIVATIVES THEREOF ARE PROVIDED ON AN "AS IS"
  BASIS.  VIRTUTECH MAKES NO WARRANTIES WITH RESPECT TO THE COMPONENT OR
  ANY DERIVATIVES THEREOF AND DISCLAIMS ALL IMPLIED WARRANTIES,
  INCLUDING, WITHOUT LIMITATION, WARRANTIES OF MERCHANTABILITY AND
  FITNESS FOR A PARTICULAR PURPOSE AND NON-INFRINGEMENT.

*/

#include <string.h>

#include <simics/api.h>
#include <simics/alloc.h>
#include <simics/utils.h>

#define DEVICE_NAME "local-space-mapper"

typedef struct {
        log_object_t log;
        ht_table_t spaces;
} map_device_t;

static conf_object_t *
new_instance(parse_object_t *parse_obj)
{
        map_device_t *map = MM_ZALLOC(1, map_device_t);

        SIM_log_constructor(&map->log, parse_obj);
	ht_init_table(&map->spaces, 1);
	return &map->log.obj;
}

static conf_object_t *
translate(conf_object_t *obj, generic_transaction_t *mop, map_info_t mapinfo)
{
        map_device_t *map = (map_device_t *)obj;
        conf_object_t *space = NULL;

        if (mop->ini_ptr)
                space = ht_lookup_int(&map->spaces, (uintptr_t)mop->ini_ptr);

        mop->physical_address -= mapinfo.base;
        mop->physical_address += mapinfo.start;

	/* if space is NULL, the default memory-space from the configuration
           will be used */
        return space;
}

static set_error_t
set_memory_spaces(void *arg, conf_object_t *obj, attr_value_t *val,
                  attr_value_t *idx)
{
        map_device_t *map = (map_device_t *)obj;
	
	/* check that all objects are memory-spaces */
	for (int i = 0; i < val->u.list.size; i++) {
		if (!SIM_get_interface(
                            val->u.list.vector[i].u.list.vector[1].u.object,
                            MEMORY_SPACE_INTERFACE))
			return Sim_Set_Interface_Not_Found;
	}

	ht_clear_table(&map->spaces, 0, 0);
	
	for (int i = 0; i < val->u.list.size; i++) {
		ht_insert_int(&map->spaces,
                              (uintptr_t)
                              val->u.list.vector[i].u.list.vector[0].u.object,
                              val->u.list.vector[i].u.list.vector[1].u.object);
	}
        return Sim_Set_Ok;
}

static attr_value_t
get_memory_spaces(void *arg, conf_object_t *obj, attr_value_t *idx)
{
        map_device_t *map = (map_device_t *)obj;
        ht_iter_t iter;
        ht_entry_t *entry;
        int count = 0;

        ht_new_iter(&map->spaces, &iter);
        while ((entry = ht_iter_next(&iter)))
                count++;

	attr_value_t ret = SIM_alloc_attr_list(count);
        count = 0;
        ht_new_iter(&map->spaces, &iter);
        while ((entry = ht_iter_next(&iter))) {
                ret.u.list.vector[count++] = SIM_make_attr_list(
                        2,
                        SIM_make_attr_object(
                                 (void *)(uintptr_t)ht_int_key(entry)),
                        SIM_make_attr_object(ht_value(entry)));
        }
	return ret;
}

void
init_local(void)
{
        class_data_t funcs;
        conf_class_t *class;
        translate_interface_t *translate_interface;

        memset(&funcs, 0, sizeof(class_data_t));
        funcs.new_instance = new_instance;
	funcs.description =
		"The local-space-mapper device is used to map accesses "
		"between memory spaces, based on the initiating object. A "
		"typical example is processor-local memory, that is mapped "
		"in the global physical memory space, but where the access "
		"will be directed to different local spaces depending on "
		"which processor initiated the transaction. The same setup "
		"can be achieved by using separate processor spaces where "
		"local memory and devices are directly mapped, and where the "
		"global physical space is set as default target. In this "
		"case all accesses that do not hit a local memory or device "
		"will be directed to the global space.";

        class = SIM_register_class(DEVICE_NAME, &funcs);

        translate_interface = MM_ZALLOC(1, translate_interface_t);
        translate_interface->translate = translate;
        SIM_register_interface(class, TRANSLATE_INTERFACE,
                               translate_interface);

        SIM_register_typed_attribute(
                class, "memory-spaces",
                get_memory_spaces, NULL,
                set_memory_spaces, NULL,
                Sim_Attr_Required,
                "[[oo]*]", NULL,
                "List of initiators and their corresponding memory spaces. "
                "The format is a list of two entry lists, where the first "
                "entry is the initiator and the second is the memory-space.");
}
