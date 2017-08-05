
#ifndef __RND_OS__DRIVERS__MOUSE_H
#define __RND_OS__DRIVERS__MOUSE_H

#include <common/types.h>
#include <hardwarecommunication/port.h>
#include <drivers/driver.h>
#include <hardwarecommunication/interrupts.h>

namespace rnd_os
{
    namespace drivers
    {
    
        class MouseEventHandler
        {
        public:
            MouseEventHandler();

            virtual void OnActivate();
            virtual void OnMouseDown(rnd_os::common::uint8_t button);
            virtual void OnMouseUp(rnd_os::common::uint8_t button);
            virtual void OnMouseMove(int x, int y);
        };
        
        
        class MouseDriver : public rnd_os::hardwarecommunication::InterruptHandler, public Driver
        {
            rnd_os::hardwarecommunication::Port8Bit dataport;
            rnd_os::hardwarecommunication::Port8Bit commandport;
            rnd_os::common::uint8_t buffer[3];
            rnd_os::common::uint8_t offset;
            rnd_os::common::uint8_t buttons;

            MouseEventHandler* handler;
        public:
            MouseDriver(rnd_os::hardwarecommunication::InterruptManager* manager, MouseEventHandler* handler);
            ~MouseDriver();
            virtual rnd_os::common::uint32_t HandleInterrupt(rnd_os::common::uint32_t esp);
            virtual void Activate();
        };

    }
}
    
#endif
