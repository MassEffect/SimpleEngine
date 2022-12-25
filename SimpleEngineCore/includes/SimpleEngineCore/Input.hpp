#pragma once
#include "Keys.hpp"
#include <cstdlib>

namespace SimpleEngine
{
    class Input
    {
    public:
        static bool IsKeyPressed(const KeyCode key_code);
        static bool PressKey(const KeyCode key_code);
        static bool ReleaseKey(const KeyCode key_code);

    private:
        static bool m_keys_pressed[static_cast<size_t>(KeyCode::KEY_LAST)];
    };
}
