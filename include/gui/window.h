
#ifndef __RND_OS__GUI_WINDOW_H
#define __RND_OS__GUI_WINDOW_H

#include <gui/widget.h>
#include <drivers/mouse.h>

namespace rnd_os
{
    namespace gui
    {
        class Window : public CompositeWidget
        {
        protected:
            bool Dragging;
        public:
            Window(Widget* parent,
                   common::int32_t x, common::int32_t y, common::int32_t w, common::int32_t h,
                   common::uint8_t r, common::uint8_t g, common::uint8_t b);
           ~Window();
           
            void OnMouseDown(common::int32_t x, common::int32_t y, common::uint8_t button);
            void OnMouseUp(common::int32_t x, common::int32_t y, common::uint8_t button);
            void OnMouseMove(common::int32_t oldx, common::int32_t oldy, common::int32_t newx, common::int32_t newy);

        };
    }
}

#endif
