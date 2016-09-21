/*
  pci-device-c.c - Generic PCI device in C


  THIS FILE IS OBSOLETE. DO NOT USE FOR NEW DEVELOPMENT!


  Copyright (C) 2000-2003 Virtutech AB, All Rights Reserved

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

#define PCI_DEVICE_IN_C
#include "pci-device.c"

void
pci_device_init(log_object_t *log,
                pci_device_t *pci_dev,
                uint32 header_type,
                conf_read_func_t conf_read_func,
                conf_write_func_t conf_write_func,
                pci_irq_ack_t pci_irq_ack,
                pci_operation_t pci_operation)
{
        if (pci_irq_ack) {
                pr("Can't register interrupt ack callback in the old PCI device interface.");
                ASSERT(0);
        }

        PCI_device_init(log, 0, pci_dev,
                        get_pci_device_ptr,
                        NULL,
                        conf_read_func,
                        // ignore the return value for conf_write_func
                        (void (*)(conf_object_t *, uint32, uint32, uint32))conf_write_func,
                        pci_operation);
}


void
handle_pci_mapping(pci_device_t *pci_ptr, int reg, addr_space_t space, uint32 size, int function)
{
        PCI_handle_mapping32(pci_ptr, reg, space, size, function, 0, 0, NULL, 0, 0);
}


void
handle_pci_mapping64(pci_device_t *pci_ptr, int reg, uint64 size, int function)
{
        PCI_handle_mapping64(pci_ptr, reg, size, function, 0, 0, NULL, 0, 0);
}


int
valid_config_register(pci_device_t *pci, uint32 offset)
{
        return PCI_config_register_size(pci, offset) ? 1 : 0;
}

const char *
config_register_name(pci_device_t *pci, uint32 offset)
{
        return PCI_config_register_name(pci, offset);
}

uint32
config_register_size(pci_device_t *pci, uint32 offset)
{
        return PCI_config_register_size(pci, offset);
}

uint32
read_sized_config_register(pci_device_t *pci, uint32 offset, uint32 size)
{
        return PCI_read_sized_config_register(pci, offset, size);
}

uint32
read_config_register(pci_device_t *pci, uint32 offset)
{
        return PCI_read_config_register(pci, offset);
}

void
write_sized_config_register(pci_device_t *pci, uint32 offset, uint32 value, uint32 size)
{
        PCI_write_sized_config_register(pci, offset, value, size);
}


void
write_config_register(pci_device_t *pci, uint32 offset, uint32 value)
{
        PCI_write_config_register(pci, offset, value);
}

uint32
default_configuration_read_access(conf_object_t *obj, uint32 offset, uint32 size)
{
        return PCI_default_configuration_read_access(obj, offset, size);
}


exception_type_t
default_configuration_write_access(conf_object_t *obj, uint32 offset, uint32 size, uint32 value)
{
        PCI_default_configuration_write_access(obj, offset, size, value);
	return Sim_PE_No_Exception;
}

exception_type_t
#if defined(PCI_EXPRESS)
configuration_access(pci_device_t *pci, generic_transaction_t *trans)
{
        return PCI_configuration_access(pci, trans);
}
#else   /* !PCI_EXPRESS */
configuration_access(pci_device_t *pci, generic_transaction_t *trans)
{
        return PCI_configuration_access(pci, trans);
}
#endif  /* !PCI_EXPRESS */

void
raise_pci_interrupt(pci_device_t *pci, int pin)
{
	PCI_raise_interrupt_pin(pci, pin);
}


void
lower_pci_interrupt(pci_device_t *pci, int pin)
{
	PCI_lower_interrupt_pin(pci, pin);
}


exception_type_t
read_from_memory(pci_device_t *pci, void *buffer, uint64 address, uint64 size)
{
        return PCI_data_from_memory(pci, Sim_Addr_Space_Memory,
                                    buffer, address, size);
}


exception_type_t
write_to_memory(pci_device_t *pci, void *buffer, uint64 address, uint64 size)
{
        return PCI_data_to_memory(pci, Sim_Addr_Space_Memory,
                                  buffer, address, size);
}


void
register_pci_device_attributes(conf_class_t *pci_class)
{
        PCI_register_device_attributes(pci_class, NULL, NULL, NULL, NULL, NULL);
}
