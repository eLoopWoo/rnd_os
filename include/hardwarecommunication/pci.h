
#ifndef __RND_OS__HARDWARECOMMUNICATION__PCI_H
#define __RND_OS__HARDWARECOMMUNICATION__PCI_H

#include <hardwarecommunication/port.h>
#include <common/types.h>
#include <drivers/driver.h>
#include <hardwarecommunication/interrupts.h>

namespace rnd_os
{
    namespace hardwarecommunication
    {
        enum BaseAddressRegisterType
        {
            MemoryMapping = 0,
            InputOutput = 1
        };
        
        class BaseAddressRegister
        {
        public:
            bool prefetchable;
            rnd_os::common::uint8_t* address;
            rnd_os::common::uint32_t size;
            BaseAddressRegisterType type;
        };
        
        
        class PeripheralComponentInterconnectDeviceDescriptor
        {
        public:
            rnd_os::common::uint32_t portBase;
            rnd_os::common::uint32_t interrupt;
            
            rnd_os::common::uint16_t bus;
            rnd_os::common::uint16_t device;
            rnd_os::common::uint16_t function;
            
            rnd_os::common::uint16_t vendor_id;
            rnd_os::common::uint16_t device_id;
            
            rnd_os::common::uint8_t class_id;
            rnd_os::common::uint8_t subclass_id;
            rnd_os::common::uint8_t interface_id;
            
            rnd_os::common::uint8_t revision;
            
            PeripheralComponentInterconnectDeviceDescriptor();
            ~PeripheralComponentInterconnectDeviceDescriptor();
        };

        class PeripheralComponentInterconnectController
        {
            Port32Bit dataPort;
            Port32Bit commandPort;
            
        public:
            PeripheralComponentInterconnectController();
            ~PeripheralComponentInterconnectController();
            
            rnd_os::common::uint32_t Read(rnd_os::common::uint16_t bus, rnd_os::common::uint16_t device, rnd_os::common::uint16_t function, rnd_os::common::uint32_t registeroffset);
            void Write(rnd_os::common::uint16_t bus, rnd_os::common::uint16_t device, rnd_os::common::uint16_t function, rnd_os::common::uint32_t registeroffset, rnd_os::common::uint32_t value);
            bool DeviceHasFunctions(rnd_os::common::uint16_t bus, rnd_os::common::uint16_t device);
            
            void SelectDrivers(rnd_os::drivers::DriverManager* driverManager, rnd_os::hardwarecommunication::InterruptManager* interrupts);
            rnd_os::drivers::Driver* GetDriver(PeripheralComponentInterconnectDeviceDescriptor dev, rnd_os::hardwarecommunication::InterruptManager* interrupts);
            PeripheralComponentInterconnectDeviceDescriptor GetDeviceDescriptor(rnd_os::common::uint16_t bus, rnd_os::common::uint16_t device, rnd_os::common::uint16_t function);
            BaseAddressRegister GetBaseAddressRegister(rnd_os::common::uint16_t bus, rnd_os::common::uint16_t device, rnd_os::common::uint16_t function, rnd_os::common::uint16_t bar);
        };
    }
}
#endif
