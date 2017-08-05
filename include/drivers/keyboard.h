
#ifndef __RND_OS__DRIVERS__KEYBOARD_H
#define __RND_OS__DRIVERS__KEYBOARD_H

#include <common/types.h>
#include <hardwarecommunication/interrupts.h>
#include <drivers/driver.h>
#include <hardwarecommunication/port.h>

namespace rnd_os
{
    namespace drivers
    {
        class KeyboardEventHandler
        {
        public:
            KeyboardEventHandler();
            
            virtual void OnKeyDown(char);
            virtual void OnKeyUp(char);
        };

        class KeyboardDriver : public rnd_os::hardwarecommunication::InterruptHandler, public Driver
        {
            rnd_os::hardwarecommunication::Port8Bit dataport;
            rnd_os::hardwarecommunication::Port8Bit commandport;
            
            KeyboardEventHandler* handler;
        public:
            KeyboardDriver(rnd_os::hardwarecommunication::InterruptManager* manager, KeyboardEventHandler *handler);
            ~KeyboardDriver();
            virtual rnd_os::common::uint32_t HandleInterrupt(rnd_os::common::uint32_t esp);
            virtual void Activate();
        };
    }
}

#endif
