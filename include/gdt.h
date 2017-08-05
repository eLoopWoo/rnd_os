#ifndef __RND_OS__GDT_H
#define __RND_OS__GDT_H

#include <common/types.h>

namespace rnd_os
{
    class GlobalDescriptorTable
    {
        public:

            class SegmentDescriptor
            {
                private:
                    rnd_os::common::uint16_t limit_lo;
                    rnd_os::common::uint16_t base_lo;
                    rnd_os::common::uint8_t base_hi;
                    rnd_os::common::uint8_t type;
                    rnd_os::common::uint8_t limit_hi;
                    rnd_os::common::uint8_t base_vhi;

                public:
                    SegmentDescriptor(rnd_os::common::uint32_t base, rnd_os::common::uint32_t limit, rnd_os::common::uint8_t type);
                    rnd_os::common::uint32_t Base();
                    rnd_os::common::uint32_t Limit();
            } __attribute__((packed));

        private:
            SegmentDescriptor nullSegmentSelector;
            SegmentDescriptor unusedSegmentSelector;
            SegmentDescriptor codeSegmentSelector;
            SegmentDescriptor dataSegmentSelector;

        public:

            GlobalDescriptorTable();
            ~GlobalDescriptorTable();

            rnd_os::common::uint16_t CodeSegmentSelector();
            rnd_os::common::uint16_t DataSegmentSelector();
    };
}

#endif
