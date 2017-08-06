
#ifndef __RND_OS__GUI_DESKTOP_H
#define __RND_OS__GUI_DESKTOP_H

#include <gui/widget.h>
#include <drivers/mouse.h>

namespace rnd_os
{
    namespace gui
    {
        class Desktop : public CompositeWidget, public rnd_os::drivers::MouseEventHandler
        {
        protected:
            common::uint32_t MouseX;
            common::uint32_t MouseY;
            
            
        public:
            Desktop(common::int32_t w, common::int32_t h,
                common::uint8_t r, common::uint8_t g, common::uint8_t b);
            ~Desktop();
            
            void Draw(common::GraphicsContext* gc);
            
            void OnMouseDown(rnd_os::common::uint8_t button);
            void OnMouseUp(rnd_os::common::uint8_t button);
            void OnMouseMove(int x, int y);
        };
    }
}

#endif
