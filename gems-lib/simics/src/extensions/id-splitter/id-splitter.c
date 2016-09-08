/*
  id-splitter.c - Instruction-Data transaction splitter.

  Copyright (C) 2002-2003 Virtutech AB, All Rights Reserved

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

/*
  <add id="simics sparc module short">
  <name index="true">id splitter</name>
  The id splitter module splits up memory operations into separate
  data and instruction streams. Data operations are forwarded to
  the timing interface of the object specified by the dbranch attribute and,
  in the same manner, instruction operations are forwarded to the ibranch.
  </add>
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <simics/api.h>
#include <simics/alloc.h>
#include <simics/utils.h>

static conf_class_t *id_splitter_class;
static class_data_t id_splitter_data;
static timing_model_interface_t timing_interface;

typedef struct {
        conf_object_t obj;

        conf_object_t *ibranch;
        conf_object_t *dbranch;

        timing_model_interface_t dbranch_if, ibranch_if;
} id_splitter_t;


static cycles_t
id_splitter_operate(conf_object_t *mem_hier, conf_object_t *space,
                    map_list_t *map, generic_transaction_t *mem_trans)
{
        id_splitter_t *ids = (id_splitter_t *)mem_hier;

        if (SIM_mem_op_is_data(mem_trans)) {
                if (ids->dbranch)
                        return ids->dbranch_if.operate(ids->dbranch, space, map, mem_trans);
        } else {
                if (ids->ibranch)
                        return ids->ibranch_if.operate(ids->ibranch, space, map, mem_trans);
        }
        return 0;
}


static set_error_t
set_dbranch(void *dont_care, conf_object_t *obj, attr_value_t *val, attr_value_t *idx)
{
        id_splitter_t *ids = (id_splitter_t *)obj;
        timing_model_interface_t *timing_interface;
        
        if (val->kind != Sim_Val_Object)
                return Sim_Set_Need_Object;
        
        ids->dbranch = val->u.object;
        
        timing_interface = SIM_get_interface(ids->dbranch, "timing-model");
        if (!timing_interface) {
                pr("object `%s' has no timing interface\n",
		   ids->dbranch->name);
                return Sim_Set_Interface_Not_Found;
        }
        ids->dbranch_if = *timing_interface;
        
        if (ids->dbranch_if.operate == NULL) {
                pr("object `%s' doesn't export the operate function!\n",
		   ids->dbranch->name);
                return Sim_Set_Interface_Not_Found;
        }
        return Sim_Set_Ok;
}

static attr_value_t                                                     
get_dbranch(void *dont_care, conf_object_t *obj, attr_value_t *idx)      
{                                                                       
        id_splitter_t *ids = (id_splitter_t *)obj;                    
        attr_value_t ret;                                               
        ret.kind = Sim_Val_Object;                                      
        ret.u.object = ids->dbranch;                                     
        return ret;                                     
}


static set_error_t
set_ibranch(void *dont_care, conf_object_t *obj, attr_value_t *val, attr_value_t *idx)
{
        id_splitter_t *ids = (id_splitter_t *)obj;
        timing_model_interface_t *timing_interface;
        
        if (val->kind != Sim_Val_Object)
                return Sim_Set_Need_Object;
        
        ids->ibranch = val->u.object;
        
        timing_interface = SIM_get_interface(ids->ibranch, "timing-model");
        if (!timing_interface) {
                pr("object `%s' has no timing interface\n",
		   ids->ibranch->name);
                return Sim_Set_Interface_Not_Found;
        }
        ids->ibranch_if = *timing_interface;
        
        if (ids->ibranch_if.operate == NULL) {
                pr("object `%s' doesn't export the operate function!\n",
		   ids->ibranch->name);
                return Sim_Set_Interface_Not_Found;
        }
        return Sim_Set_Ok;
}

static attr_value_t                                                     
get_ibranch(void *dont_care, conf_object_t *obj, attr_value_t *idx)      
{                                                                       
        id_splitter_t *ids = (id_splitter_t *)obj;                    
        attr_value_t ret;                                               
        ret.kind = Sim_Val_Object;                                      
        ret.u.object = ids->ibranch;                                     
        return ret;                                     
}


static conf_object_t *
id_splitter_new_instance(parse_object_t *pa)
{
        id_splitter_t *ids = MM_ZALLOC(1, id_splitter_t);

        SIM_object_constructor(&ids->obj, pa);
        return &ids->obj;
}

DLL_EXPORT void
init_local(void)
{                
        id_splitter_data.new_instance = id_splitter_new_instance;
        id_splitter_data.description = "The id splitter module splits up memory operations into separate "
                "data and instruction streams. Data operations are forwarded to "
                "the timing interface of the object specified by the dbranch attribute and, "
                "in the same manner, instruction operations are forwarded to the ibranch.";
        
        if (!(id_splitter_class = SIM_register_class("id-splitter", &id_splitter_data))) {
                pr("Could not create id-splitter class\n");
        }
        
        /* set up custom interfaces */
        timing_interface.operate = id_splitter_operate;
        SIM_register_interface(id_splitter_class, "timing-model", &timing_interface);

        SIM_register_attribute(id_splitter_class, "ibranch",
                               get_ibranch, 0, set_ibranch, 0, Sim_Attr_Optional,
                               "Object to receive instruction transactions.");
        SIM_register_attribute(id_splitter_class, "dbranch",
                               get_dbranch, 0, set_dbranch, 0, Sim_Attr_Optional,
                               "Object to receive data transactions.");

}
