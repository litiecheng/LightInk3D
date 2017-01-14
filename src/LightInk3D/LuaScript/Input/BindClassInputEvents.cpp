

/* Copyright ChenDong(Wilbur), email <baisaichen@live.com>. All rights reserved.
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to
 * deal in the Software without restriction, including without limitation the
 * rights to use, copy, modify, merge, publish, distribute, sublicense, and/or
 * sell copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS
 * IN THE SOFTWARE.
 */


#include "Precompiled.h"
#include "Input/InputEvents.h"
#include "LuaScript/LuaUtils.h"
#include "LuaEngine/LuaEngine.h"

namespace Urho3D
{
	using namespace LightInk;
	void bind_class_InputEvents(LuaModele & lm)
	{
		lua_State * lua = lm.state();
		lua_pushvalue(lua, LUA_GLOBALSINDEX);
		LuaRef lrf(lua, true);
		
		// [Constant] int MOUSEB_LEFT
		lrf["MOUSEB_LEFT"] = MOUSEB_LEFT;
		// [Constant] int MOUSEB_MIDDLE
		lrf["MOUSEB_MIDDLE"] = MOUSEB_MIDDLE;
		// [Constant] int MOUSEB_RIGHT
		lrf["MOUSEB_RIGHT"] = MOUSEB_RIGHT;
		// [Constant] int MOUSEB_X1
		lrf["MOUSEB_X1"] = MOUSEB_X1;
		// [Constant] int MOUSEB_X2
		lrf["MOUSEB_X2"] = MOUSEB_X2;

		// [Constant] int QUAL_SHIFT
		lrf["QUAL_SHIFT"] = QUAL_SHIFT;
		// [Constant] int QUAL_CTRL
		lrf["QUAL_CTRL"] = QUAL_CTRL;
		// [Constant] int QUAL_ALT
		lrf["QUAL_ALT"] = QUAL_ALT;
		// [Constant] int QUAL_ANY
		lrf["QUAL_ANY"] = QUAL_ANY;

		// [Constant] int KEY_A
		lrf["KEY_A"] = KEY_A;
		// [Constant] int KEY_B
		lrf["KEY_B"] = KEY_B;
		// [Constant] int KEY_C
		lrf["KEY_C"] = KEY_C;
		// [Constant] int KEY_D
		lrf["KEY_D"] = KEY_D;
		// [Constant] int KEY_E
		lrf["KEY_E"] = KEY_E;
		// [Constant] int KEY_F
		lrf["KEY_F"] = KEY_F;
		// [Constant] int KEY_G
		lrf["KEY_G"] = KEY_G;
		// [Constant] int KEY_H
		lrf["KEY_H"] = KEY_H;
		// [Constant] int KEY_I
		lrf["KEY_I"] = KEY_I;
		// [Constant] int KEY_J
		lrf["KEY_J"] = KEY_J;
		// [Constant] int KEY_K
		lrf["KEY_K"] = KEY_K;
		// [Constant] int KEY_L
		lrf["KEY_L"] = KEY_L;
		// [Constant] int KEY_M
		lrf["KEY_M"] = KEY_M;
		// [Constant] int KEY_N
		lrf["KEY_N"] = KEY_N;
		// [Constant] int KEY_O
		lrf["KEY_O"] = KEY_O;
		// [Constant] int KEY_P
		lrf["KEY_P"] = KEY_P;
		// [Constant] int KEY_Q
		lrf["KEY_Q"] = KEY_Q;
		// [Constant] int KEY_R
		lrf["KEY_R"] = KEY_R;
		// [Constant] int KEY_S
		lrf["KEY_S"] = KEY_S;
		// [Constant] int KEY_T
		lrf["KEY_T"] = KEY_T;
		// [Constant] int KEY_U
		lrf["KEY_U"] = KEY_U;
		// [Constant] int KEY_V
		lrf["KEY_V"] = KEY_V;
		// [Constant] int KEY_W
		lrf["KEY_W"] = KEY_W;
		// [Constant] int KEY_X
		lrf["KEY_X"] = KEY_X;
		// [Constant] int KEY_Y
		lrf["KEY_Y"] = KEY_Y;
		// [Constant] int KEY_Z
		lrf["KEY_Z"] = KEY_Z;
		// [Constant] int KEY_0
		lrf["KEY_0"] = KEY_0;
		// [Constant] int KEY_1
		lrf["KEY_1"] = KEY_1;
		// [Constant] int KEY_2
		lrf["KEY_2"] = KEY_2;
		// [Constant] int KEY_3
		lrf["KEY_3"] = KEY_3;
		// [Constant] int KEY_4
		lrf["KEY_4"] = KEY_4;
		// [Constant] int KEY_5
		lrf["KEY_5"] = KEY_5;
		// [Constant] int KEY_6
		lrf["KEY_6"] = KEY_6;
		// [Constant] int KEY_7
		lrf["KEY_7"] = KEY_7;
		// [Constant] int KEY_8
		lrf["KEY_8"] = KEY_8;
		// [Constant] int KEY_9
		lrf["KEY_9"] = KEY_9;
		// [Constant] int KEY_BACKSPACE
		lrf["KEY_BACKSPACE"] = KEY_BACKSPACE;
		// [Constant] int KEY_TAB
		lrf["KEY_TAB"] = KEY_TAB;
		// [Constant] int KEY_RETURN
		lrf["KEY_RETURN"] = KEY_RETURN;
		// [Constant] int KEY_RETURN2
		lrf["KEY_RETURN2"] = KEY_RETURN2;
		// [Constant] int KEY_KP_ENTER
		lrf["KEY_KP_ENTER"] = KEY_KP_ENTER;
		// [Constant] int KEY_SHIFT
		lrf["KEY_SHIFT"] = KEY_SHIFT;
		// [Constant] int KEY_CTRL
		lrf["KEY_CTRL"] = KEY_CTRL;
		// [Constant] int KEY_ALT
		lrf["KEY_ALT"] = KEY_ALT;
		// [Constant] int KEY_GUI
		lrf["KEY_GUI"] = KEY_GUI;
		// [Constant] int KEY_PAUSE
		lrf["KEY_PAUSE"] = KEY_PAUSE;
		// [Constant] int KEY_CAPSLOCK
		lrf["KEY_CAPSLOCK"] = KEY_CAPSLOCK;
		// [Constant] int KEY_ESCAPE
		lrf["KEY_ESCAPE"] = KEY_ESCAPE;
		// [Constant] int KEY_SPACE
		lrf["KEY_SPACE"] = KEY_SPACE;
		// [Constant] int KEY_PAGEUP
		lrf["KEY_PAGEUP"] = KEY_PAGEUP;
		// [Constant] int KEY_PAGEDOWN
		lrf["KEY_PAGEDOWN"] = KEY_PAGEDOWN;
		// [Constant] int KEY_END
		lrf["KEY_END"] = KEY_END;
		// [Constant] int KEY_HOME
		lrf["KEY_HOME"] = KEY_HOME;
		// [Constant] int KEY_LEFT
		lrf["KEY_LEFT"] = KEY_LEFT;
		// [Constant] int KEY_UP
		lrf["KEY_UP"] = KEY_UP;
		// [Constant] int KEY_RIGHT
		lrf["KEY_RIGHT"] = KEY_RIGHT;
		// [Constant] int KEY_DOWN
		lrf["KEY_DOWN"] = KEY_DOWN;
		// [Constant] int KEY_SELECT
		lrf["KEY_SELECT"] = KEY_SELECT;
		// [Constant] int KEY_PRINTSCREEN
		lrf["KEY_PRINTSCREEN"] = KEY_PRINTSCREEN;
		// [Constant] int KEY_INSERT
		lrf["KEY_INSERT"] = KEY_INSERT;
		// [Constant] int KEY_DELETE
		lrf["KEY_DELETE"] = KEY_DELETE;
		// [Constant] int KEY_LGUI
		lrf["KEY_LGUI"] = KEY_LGUI;
		// [Constant] int KEY_RGUI
		lrf["KEY_RGUI"] = KEY_RGUI;
		// [Constant] int KEY_APPLICATION
		lrf["KEY_APPLICATION"] = KEY_APPLICATION;
		// [Constant] int KEY_KP_0
		lrf["KEY_KP_0"] = KEY_KP_0;
		// [Constant] int KEY_KP_1
		lrf["KEY_KP_1"] = KEY_KP_1;
		// [Constant] int KEY_KP_2
		lrf["KEY_KP_2"] = KEY_KP_2;
		// [Constant] int KEY_KP_3
		lrf["KEY_KP_3"] = KEY_KP_3;
		// [Constant] int KEY_KP_4
		lrf["KEY_KP_4"] = KEY_KP_4;
		// [Constant] int KEY_KP_5
		lrf["KEY_KP_5"] = KEY_KP_5;
		// [Constant] int KEY_KP_6
		lrf["KEY_KP_6"] = KEY_KP_6;
		// [Constant] int KEY_KP_7
		lrf["KEY_KP_7"] = KEY_KP_7;
		// [Constant] int KEY_KP_8
		lrf["KEY_KP_8"] = KEY_KP_8;
		// [Constant] int KEY_KP_9
		lrf["KEY_KP_9"] = KEY_KP_9;
		// [Constant] int KEY_KP_MULTIPLY
		lrf["KEY_KP_MULTIPLY"] = KEY_KP_MULTIPLY;
		// [Constant] int KEY_KP_PLUS
		lrf["KEY_KP_PLUS"] = KEY_KP_PLUS;
		// [Constant] int KEY_KP_MINUS
		lrf["KEY_KP_MINUS"] = KEY_KP_MINUS;
		// [Constant] int KEY_KP_PERIOD
		lrf["KEY_KP_PERIOD"] = KEY_KP_PERIOD;
		// [Constant] int KEY_KP_DIVIDE
		lrf["KEY_KP_DIVIDE"] = KEY_KP_DIVIDE;
		// [Constant] int KEY_F1
		lrf["KEY_F1"] = KEY_F1;
		// [Constant] int KEY_F2
		lrf["KEY_F2"] = KEY_F2;
		// [Constant] int KEY_F3
		lrf["KEY_F3"] = KEY_F3;
		// [Constant] int KEY_F4
		lrf["KEY_F4"] = KEY_F4;
		// [Constant] int KEY_F5
		lrf["KEY_F5"] = KEY_F5;
		// [Constant] int KEY_F6
		lrf["KEY_F6"] = KEY_F6;
		// [Constant] int KEY_F7
		lrf["KEY_F7"] = KEY_F7;
		// [Constant] int KEY_F8
		lrf["KEY_F8"] = KEY_F8;
		// [Constant] int KEY_F9
		lrf["KEY_F9"] = KEY_F9;
		// [Constant] int KEY_F10
		lrf["KEY_F10"] = KEY_F10;
		// [Constant] int KEY_F11
		lrf["KEY_F11"] = KEY_F11;
		// [Constant] int KEY_F12
		lrf["KEY_F12"] = KEY_F12;
		// [Constant] int KEY_F13
		lrf["KEY_F13"] = KEY_F13;
		// [Constant] int KEY_F14
		lrf["KEY_F14"] = KEY_F14;
		// [Constant] int KEY_F15
		lrf["KEY_F15"] = KEY_F15;
		// [Constant] int KEY_F16
		lrf["KEY_F16"] = KEY_F16;
		// [Constant] int KEY_F17
		lrf["KEY_F17"] = KEY_F17;
		// [Constant] int KEY_F18
		lrf["KEY_F18"] = KEY_F18;
		// [Constant] int KEY_F19
		lrf["KEY_F19"] = KEY_F19;
		// [Constant] int KEY_F20
		lrf["KEY_F20"] = KEY_F20;
		// [Constant] int KEY_F21
		lrf["KEY_F21"] = KEY_F21;
		// [Constant] int KEY_F22
		lrf["KEY_F22"] = KEY_F22;
		// [Constant] int KEY_F23
		lrf["KEY_F23"] = KEY_F23;
		// [Constant] int KEY_F24
		lrf["KEY_F24"] = KEY_F24;
		// [Constant] int KEY_NUMLOCKCLEAR
		lrf["KEY_NUMLOCKCLEAR"] = KEY_NUMLOCKCLEAR;
		// [Constant] int KEY_SCROLLLOCK
		lrf["KEY_SCROLLLOCK"] = KEY_SCROLLLOCK;
		// [Constant] int KEY_LSHIFT
		lrf["KEY_LSHIFT"] = KEY_LSHIFT;
		// [Constant] int KEY_RSHIFT
		lrf["KEY_RSHIFT"] = KEY_RSHIFT;
		// [Constant] int KEY_LCTRL
		lrf["KEY_LCTRL"] = KEY_LCTRL;
		// [Constant] int KEY_RCTRL
		lrf["KEY_RCTRL"] = KEY_RCTRL;
		// [Constant] int KEY_LALT
		lrf["KEY_LALT"] = KEY_LALT;
		// [Constant] int KEY_RALT
		lrf["KEY_RALT"] = KEY_RALT;

		// [Constant] int SCANCODE_UNKNOWN
		lrf["SCANCODE_UNKNOWN"] = SCANCODE_UNKNOWN;
		// [Constant] int SCANCODE_CTRL
		lrf["SCANCODE_CTRL"] = SCANCODE_CTRL;
		// [Constant] int SCANCODE_SHIFT
		lrf["SCANCODE_SHIFT"] = SCANCODE_SHIFT;
		// [Constant] int SCANCODE_ALT
		lrf["SCANCODE_ALT"] = SCANCODE_ALT;
		// [Constant] int SCANCODE_GUI
		lrf["SCANCODE_GUI"] = SCANCODE_GUI;
		// [Constant] int SCANCODE_A
		lrf["SCANCODE_A"] = SCANCODE_A;
		// [Constant] int SCANCODE_B
		lrf["SCANCODE_B"] = SCANCODE_B;
		// [Constant] int SCANCODE_C
		lrf["SCANCODE_C"] = SCANCODE_C;
		// [Constant] int SCANCODE_D
		lrf["SCANCODE_D"] = SCANCODE_D;
		// [Constant] int SCANCODE_E
		lrf["SCANCODE_E"] = SCANCODE_E;
		// [Constant] int SCANCODE_F
		lrf["SCANCODE_F"] = SCANCODE_F;
		// [Constant] int SCANCODE_G
		lrf["SCANCODE_G"] = SCANCODE_G;
		// [Constant] int SCANCODE_H
		lrf["SCANCODE_H"] = SCANCODE_H;
		// [Constant] int SCANCODE_I
		lrf["SCANCODE_I"] = SCANCODE_I;
		// [Constant] int SCANCODE_J
		lrf["SCANCODE_J"] = SCANCODE_J;
		// [Constant] int SCANCODE_K
		lrf["SCANCODE_K"] = SCANCODE_K;
		// [Constant] int SCANCODE_L
		lrf["SCANCODE_L"] = SCANCODE_L;
		// [Constant] int SCANCODE_M
		lrf["SCANCODE_M"] = SCANCODE_M;
		// [Constant] int SCANCODE_N
		lrf["SCANCODE_N"] = SCANCODE_N;
		// [Constant] int SCANCODE_O
		lrf["SCANCODE_O"] = SCANCODE_O;
		// [Constant] int SCANCODE_P
		lrf["SCANCODE_P"] = SCANCODE_P;
		// [Constant] int SCANCODE_Q
		lrf["SCANCODE_Q"] = SCANCODE_Q;
		// [Constant] int SCANCODE_R
		lrf["SCANCODE_R"] = SCANCODE_R;
		// [Constant] int SCANCODE_S
		lrf["SCANCODE_S"] = SCANCODE_S;
		// [Constant] int SCANCODE_T
		lrf["SCANCODE_T"] = SCANCODE_T;
		// [Constant] int SCANCODE_U
		lrf["SCANCODE_U"] = SCANCODE_U;
		// [Constant] int SCANCODE_V
		lrf["SCANCODE_V"] = SCANCODE_V;
		// [Constant] int SCANCODE_W
		lrf["SCANCODE_W"] = SCANCODE_W;
		// [Constant] int SCANCODE_X
		lrf["SCANCODE_X"] = SCANCODE_X;
		// [Constant] int SCANCODE_Y
		lrf["SCANCODE_Y"] = SCANCODE_Y;
		// [Constant] int SCANCODE_Z
		lrf["SCANCODE_Z"] = SCANCODE_Z;
		// [Constant] int SCANCODE_1
		lrf["SCANCODE_1"] = SCANCODE_1;
		// [Constant] int SCANCODE_2
		lrf["SCANCODE_2"] = SCANCODE_2;
		// [Constant] int SCANCODE_3
		lrf["SCANCODE_3"] = SCANCODE_3;
		// [Constant] int SCANCODE_4
		lrf["SCANCODE_4"] = SCANCODE_4;
		// [Constant] int SCANCODE_5
		lrf["SCANCODE_5"] = SCANCODE_5;
		// [Constant] int SCANCODE_6
		lrf["SCANCODE_6"] = SCANCODE_6;
		// [Constant] int SCANCODE_7
		lrf["SCANCODE_7"] = SCANCODE_7;
		// [Constant] int SCANCODE_8
		lrf["SCANCODE_8"] = SCANCODE_8;
		// [Constant] int SCANCODE_9
		lrf["SCANCODE_9"] = SCANCODE_9;
		// [Constant] int SCANCODE_0
		lrf["SCANCODE_0"] = SCANCODE_0;
		// [Constant] int SCANCODE_RETURN
		lrf["SCANCODE_RETURN"] = SCANCODE_RETURN;
		// [Constant] int SCANCODE_ESCAPE
		lrf["SCANCODE_ESCAPE"] = SCANCODE_ESCAPE;
		// [Constant] int SCANCODE_BACKSPACE
		lrf["SCANCODE_BACKSPACE"] = SCANCODE_BACKSPACE;
		// [Constant] int SCANCODE_TAB
		lrf["SCANCODE_TAB"] = SCANCODE_TAB;
		// [Constant] int SCANCODE_SPACE
		lrf["SCANCODE_SPACE"] = SCANCODE_SPACE;
		// [Constant] int SCANCODE_MINUS
		lrf["SCANCODE_MINUS"] = SCANCODE_MINUS;
		// [Constant] int SCANCODE_EQUALS
		lrf["SCANCODE_EQUALS"] = SCANCODE_EQUALS;
		// [Constant] int SCANCODE_LEFTBRACKET
		lrf["SCANCODE_LEFTBRACKET"] = SCANCODE_LEFTBRACKET;
		// [Constant] int SCANCODE_RIGHTBRACKET
		lrf["SCANCODE_RIGHTBRACKET"] = SCANCODE_RIGHTBRACKET;
		// [Constant] int SCANCODE_BACKSLASH
		lrf["SCANCODE_BACKSLASH"] = SCANCODE_BACKSLASH;
		// [Constant] int SCANCODE_NONUSHASH
		lrf["SCANCODE_NONUSHASH"] = SCANCODE_NONUSHASH;
		// [Constant] int SCANCODE_SEMICOLON
		lrf["SCANCODE_SEMICOLON"] = SCANCODE_SEMICOLON;
		// [Constant] int SCANCODE_APOSTROPHE
		lrf["SCANCODE_APOSTROPHE"] = SCANCODE_APOSTROPHE;
		// [Constant] int SCANCODE_GRAVE
		lrf["SCANCODE_GRAVE"] = SCANCODE_GRAVE;
		// [Constant] int SCANCODE_COMMA
		lrf["SCANCODE_COMMA"] = SCANCODE_COMMA;
		// [Constant] int SCANCODE_PERIOD
		lrf["SCANCODE_PERIOD"] = SCANCODE_PERIOD;
		// [Constant] int SCANCODE_SLASH
		lrf["SCANCODE_SLASH"] = SCANCODE_SLASH;
		// [Constant] int SCANCODE_CAPSLOCK
		lrf["SCANCODE_CAPSLOCK"] = SCANCODE_CAPSLOCK;
		// [Constant] int SCANCODE_F1
		lrf["SCANCODE_F1"] = SCANCODE_F1;
		// [Constant] int SCANCODE_F2
		lrf["SCANCODE_F2"] = SCANCODE_F2;
		// [Constant] int SCANCODE_F3
		lrf["SCANCODE_F3"] = SCANCODE_F3;
		// [Constant] int SCANCODE_F4
		lrf["SCANCODE_F4"] = SCANCODE_F4;
		// [Constant] int SCANCODE_F5
		lrf["SCANCODE_F5"] = SCANCODE_F5;
		// [Constant] int SCANCODE_F6
		lrf["SCANCODE_F6"] = SCANCODE_F6;
		// [Constant] int SCANCODE_F7
		lrf["SCANCODE_F7"] = SCANCODE_F7;
		// [Constant] int SCANCODE_F8
		lrf["SCANCODE_F8"] = SCANCODE_F8;
		// [Constant] int SCANCODE_F9
		lrf["SCANCODE_F9"] = SCANCODE_F9;
		// [Constant] int SCANCODE_F10
		lrf["SCANCODE_F10"] = SCANCODE_F10;
		// [Constant] int SCANCODE_F11
		lrf["SCANCODE_F11"] = SCANCODE_F11;
		// [Constant] int SCANCODE_F12
		lrf["SCANCODE_F12"] = SCANCODE_F12;
		// [Constant] int SCANCODE_PRINTSCREEN
		lrf["SCANCODE_PRINTSCREEN"] = SCANCODE_PRINTSCREEN;
		// [Constant] int SCANCODE_SCROLLLOCK
		lrf["SCANCODE_SCROLLLOCK"] = SCANCODE_SCROLLLOCK;
		// [Constant] int SCANCODE_PAUSE
		lrf["SCANCODE_PAUSE"] = SCANCODE_PAUSE;
		// [Constant] int SCANCODE_INSERT
		lrf["SCANCODE_INSERT"] = SCANCODE_INSERT;
		// [Constant] int SCANCODE_HOME
		lrf["SCANCODE_HOME"] = SCANCODE_HOME;
		// [Constant] int SCANCODE_PAGEUP
		lrf["SCANCODE_PAGEUP"] = SCANCODE_PAGEUP;
		// [Constant] int SCANCODE_DELETE
		lrf["SCANCODE_DELETE"] = SCANCODE_DELETE;
		// [Constant] int SCANCODE_END
		lrf["SCANCODE_END"] = SCANCODE_END;
		// [Constant] int SCANCODE_PAGEDOWN
		lrf["SCANCODE_PAGEDOWN"] = SCANCODE_PAGEDOWN;
		// [Constant] int SCANCODE_RIGHT
		lrf["SCANCODE_RIGHT"] = SCANCODE_RIGHT;
		// [Constant] int SCANCODE_LEFT
		lrf["SCANCODE_LEFT"] = SCANCODE_LEFT;
		// [Constant] int SCANCODE_DOWN
		lrf["SCANCODE_DOWN"] = SCANCODE_DOWN;
		// [Constant] int SCANCODE_UP
		lrf["SCANCODE_UP"] = SCANCODE_UP;
		// [Constant] int SCANCODE_NUMLOCKCLEAR
		lrf["SCANCODE_NUMLOCKCLEAR"] = SCANCODE_NUMLOCKCLEAR;
		// [Constant] int SCANCODE_KP_DIVIDE
		lrf["SCANCODE_KP_DIVIDE"] = SCANCODE_KP_DIVIDE;
		// [Constant] int SCANCODE_KP_MULTIPLY
		lrf["SCANCODE_KP_MULTIPLY"] = SCANCODE_KP_MULTIPLY;
		// [Constant] int SCANCODE_KP_MINUS
		lrf["SCANCODE_KP_MINUS"] = SCANCODE_KP_MINUS;
		// [Constant] int SCANCODE_KP_PLUS
		lrf["SCANCODE_KP_PLUS"] = SCANCODE_KP_PLUS;
		// [Constant] int SCANCODE_KP_ENTER
		lrf["SCANCODE_KP_ENTER"] = SCANCODE_KP_ENTER;
		// [Constant] int SCANCODE_KP_1
		lrf["SCANCODE_KP_1"] = SCANCODE_KP_1;
		// [Constant] int SCANCODE_KP_2
		lrf["SCANCODE_KP_2"] = SCANCODE_KP_2;
		// [Constant] int SCANCODE_KP_3
		lrf["SCANCODE_KP_3"] = SCANCODE_KP_3;
		// [Constant] int SCANCODE_KP_4
		lrf["SCANCODE_KP_4"] = SCANCODE_KP_4;
		// [Constant] int SCANCODE_KP_5
		lrf["SCANCODE_KP_5"] = SCANCODE_KP_5;
		// [Constant] int SCANCODE_KP_6
		lrf["SCANCODE_KP_6"] = SCANCODE_KP_6;
		// [Constant] int SCANCODE_KP_7
		lrf["SCANCODE_KP_7"] = SCANCODE_KP_7;
		// [Constant] int SCANCODE_KP_8
		lrf["SCANCODE_KP_8"] = SCANCODE_KP_8;
		// [Constant] int SCANCODE_KP_9
		lrf["SCANCODE_KP_9"] = SCANCODE_KP_9;
		// [Constant] int SCANCODE_KP_0
		lrf["SCANCODE_KP_0"] = SCANCODE_KP_0;
		// [Constant] int SCANCODE_KP_PERIOD
		lrf["SCANCODE_KP_PERIOD"] = SCANCODE_KP_PERIOD;
		// [Constant] int SCANCODE_NONUSBACKSLASH
		lrf["SCANCODE_NONUSBACKSLASH"] = SCANCODE_NONUSBACKSLASH;
		// [Constant] int SCANCODE_APPLICATION
		lrf["SCANCODE_APPLICATION"] = SCANCODE_APPLICATION;
		// [Constant] int SCANCODE_POWER
		lrf["SCANCODE_POWER"] = SCANCODE_POWER;
		// [Constant] int SCANCODE_KP_EQUALS
		lrf["SCANCODE_KP_EQUALS"] = SCANCODE_KP_EQUALS;
		// [Constant] int SCANCODE_F13
		lrf["SCANCODE_F13"] = SCANCODE_F13;
		// [Constant] int SCANCODE_F14
		lrf["SCANCODE_F14"] = SCANCODE_F14;
		// [Constant] int SCANCODE_F15
		lrf["SCANCODE_F15"] = SCANCODE_F15;
		// [Constant] int SCANCODE_F16
		lrf["SCANCODE_F16"] = SCANCODE_F16;
		// [Constant] int SCANCODE_F17
		lrf["SCANCODE_F17"] = SCANCODE_F17;
		// [Constant] int SCANCODE_F18
		lrf["SCANCODE_F18"] = SCANCODE_F18;
		// [Constant] int SCANCODE_F19
		lrf["SCANCODE_F19"] = SCANCODE_F19;
		// [Constant] int SCANCODE_F20
		lrf["SCANCODE_F20"] = SCANCODE_F20;
		// [Constant] int SCANCODE_F21
		lrf["SCANCODE_F21"] = SCANCODE_F21;
		// [Constant] int SCANCODE_F22
		lrf["SCANCODE_F22"] = SCANCODE_F22;
		// [Constant] int SCANCODE_F23
		lrf["SCANCODE_F23"] = SCANCODE_F23;
		// [Constant] int SCANCODE_F24
		lrf["SCANCODE_F24"] = SCANCODE_F24;
		// [Constant] int SCANCODE_EXECUTE
		lrf["SCANCODE_EXECUTE"] = SCANCODE_EXECUTE;
		// [Constant] int SCANCODE_HELP
		lrf["SCANCODE_HELP"] = SCANCODE_HELP;
		// [Constant] int SCANCODE_MENU
		lrf["SCANCODE_MENU"] = SCANCODE_MENU;
		// [Constant] int SCANCODE_SELECT
		lrf["SCANCODE_SELECT"] = SCANCODE_SELECT;
		// [Constant] int SCANCODE_STOP
		lrf["SCANCODE_STOP"] = SCANCODE_STOP;
		// [Constant] int SCANCODE_AGAIN
		lrf["SCANCODE_AGAIN"] = SCANCODE_AGAIN;
		// [Constant] int SCANCODE_UNDO
		lrf["SCANCODE_UNDO"] = SCANCODE_UNDO;
		// [Constant] int SCANCODE_CUT
		lrf["SCANCODE_CUT"] = SCANCODE_CUT;
		// [Constant] int SCANCODE_COPY
		lrf["SCANCODE_COPY"] = SCANCODE_COPY;
		// [Constant] int SCANCODE_PASTE
		lrf["SCANCODE_PASTE"] = SCANCODE_PASTE;
		// [Constant] int SCANCODE_FIND
		lrf["SCANCODE_FIND"] = SCANCODE_FIND;
		// [Constant] int SCANCODE_MUTE
		lrf["SCANCODE_MUTE"] = SCANCODE_MUTE;
		// [Constant] int SCANCODE_VOLUMEUP
		lrf["SCANCODE_VOLUMEUP"] = SCANCODE_VOLUMEUP;
		// [Constant] int SCANCODE_VOLUMEDOWN
		lrf["SCANCODE_VOLUMEDOWN"] = SCANCODE_VOLUMEDOWN;
		// [Constant] int SCANCODE_KP_COMMA
		lrf["SCANCODE_KP_COMMA"] = SCANCODE_KP_COMMA;
		// [Constant] int SCANCODE_KP_EQUALSAS400
		lrf["SCANCODE_KP_EQUALSAS400"] = SCANCODE_KP_EQUALSAS400;
		// [Constant] int SCANCODE_INTERNATIONAL1
		lrf["SCANCODE_INTERNATIONAL1"] = SCANCODE_INTERNATIONAL1;
		// [Constant] int SCANCODE_INTERNATIONAL2
		lrf["SCANCODE_INTERNATIONAL2"] = SCANCODE_INTERNATIONAL2;
		// [Constant] int SCANCODE_INTERNATIONAL3
		lrf["SCANCODE_INTERNATIONAL3"] = SCANCODE_INTERNATIONAL3;
		// [Constant] int SCANCODE_INTERNATIONAL4
		lrf["SCANCODE_INTERNATIONAL4"] = SCANCODE_INTERNATIONAL4;
		// [Constant] int SCANCODE_INTERNATIONAL5
		lrf["SCANCODE_INTERNATIONAL5"] = SCANCODE_INTERNATIONAL5;
		// [Constant] int SCANCODE_INTERNATIONAL6
		lrf["SCANCODE_INTERNATIONAL6"] = SCANCODE_INTERNATIONAL6;
		// [Constant] int SCANCODE_INTERNATIONAL7
		lrf["SCANCODE_INTERNATIONAL7"] = SCANCODE_INTERNATIONAL7;
		// [Constant] int SCANCODE_INTERNATIONAL8
		lrf["SCANCODE_INTERNATIONAL8"] = SCANCODE_INTERNATIONAL8;
		// [Constant] int SCANCODE_INTERNATIONAL9
		lrf["SCANCODE_INTERNATIONAL9"] = SCANCODE_INTERNATIONAL9;
		// [Constant] int SCANCODE_LANG1
		lrf["SCANCODE_LANG1"] = SCANCODE_LANG1;
		// [Constant] int SCANCODE_LANG2
		lrf["SCANCODE_LANG2"] = SCANCODE_LANG2;
		// [Constant] int SCANCODE_LANG3
		lrf["SCANCODE_LANG3"] = SCANCODE_LANG3;
		// [Constant] int SCANCODE_LANG4
		lrf["SCANCODE_LANG4"] = SCANCODE_LANG4;
		// [Constant] int SCANCODE_LANG5
		lrf["SCANCODE_LANG5"] = SCANCODE_LANG5;
		// [Constant] int SCANCODE_LANG6
		lrf["SCANCODE_LANG6"] = SCANCODE_LANG6;
		// [Constant] int SCANCODE_LANG7
		lrf["SCANCODE_LANG7"] = SCANCODE_LANG7;
		// [Constant] int SCANCODE_LANG8
		lrf["SCANCODE_LANG8"] = SCANCODE_LANG8;
		// [Constant] int SCANCODE_LANG9
		lrf["SCANCODE_LANG9"] = SCANCODE_LANG9;
		// [Constant] int SCANCODE_ALTERASE
		lrf["SCANCODE_ALTERASE"] = SCANCODE_ALTERASE;
		// [Constant] int SCANCODE_SYSREQ
		lrf["SCANCODE_SYSREQ"] = SCANCODE_SYSREQ;
		// [Constant] int SCANCODE_CANCEL
		lrf["SCANCODE_CANCEL"] = SCANCODE_CANCEL;
		// [Constant] int SCANCODE_CLEAR
		lrf["SCANCODE_CLEAR"] = SCANCODE_CLEAR;
		// [Constant] int SCANCODE_PRIOR
		lrf["SCANCODE_PRIOR"] = SCANCODE_PRIOR;
		// [Constant] int SCANCODE_RETURN2
		lrf["SCANCODE_RETURN2"] = SCANCODE_RETURN2;
		// [Constant] int SCANCODE_SEPARATOR
		lrf["SCANCODE_SEPARATOR"] = SCANCODE_SEPARATOR;
		// [Constant] int SCANCODE_OUT
		lrf["SCANCODE_OUT"] = SCANCODE_OUT;
		// [Constant] int SCANCODE_OPER
		lrf["SCANCODE_OPER"] = SCANCODE_OPER;
		// [Constant] int SCANCODE_CLEARAGAIN
		lrf["SCANCODE_CLEARAGAIN"] = SCANCODE_CLEARAGAIN;
		// [Constant] int SCANCODE_CRSEL
		lrf["SCANCODE_CRSEL"] = SCANCODE_CRSEL;
		// [Constant] int SCANCODE_EXSEL
		lrf["SCANCODE_EXSEL"] = SCANCODE_EXSEL;
		// [Constant] int SCANCODE_KP_00
		lrf["SCANCODE_KP_00"] = SCANCODE_KP_00;
		// [Constant] int SCANCODE_KP_000
		lrf["SCANCODE_KP_000"] = SCANCODE_KP_000;
		// [Constant] int SCANCODE_THOUSANDSSEPARATOR
		lrf["SCANCODE_THOUSANDSSEPARATOR"] = SCANCODE_THOUSANDSSEPARATOR;
		// [Constant] int SCANCODE_DECIMALSEPARATOR
		lrf["SCANCODE_DECIMALSEPARATOR"] = SCANCODE_DECIMALSEPARATOR;
		// [Constant] int SCANCODE_CURRENCYUNIT
		lrf["SCANCODE_CURRENCYUNIT"] = SCANCODE_CURRENCYUNIT;
		// [Constant] int SCANCODE_CURRENCYSUBUNIT
		lrf["SCANCODE_CURRENCYSUBUNIT"] = SCANCODE_CURRENCYSUBUNIT;
		// [Constant] int SCANCODE_KP_LEFTPAREN
		lrf["SCANCODE_KP_LEFTPAREN"] = SCANCODE_KP_LEFTPAREN;
		// [Constant] int SCANCODE_KP_RIGHTPAREN
		lrf["SCANCODE_KP_RIGHTPAREN"] = SCANCODE_KP_RIGHTPAREN;
		// [Constant] int SCANCODE_KP_LEFTBRACE
		lrf["SCANCODE_KP_LEFTBRACE"] = SCANCODE_KP_LEFTBRACE;
		// [Constant] int SCANCODE_KP_RIGHTBRACE
		lrf["SCANCODE_KP_RIGHTBRACE"] = SCANCODE_KP_RIGHTBRACE;
		// [Constant] int SCANCODE_KP_TAB
		lrf["SCANCODE_KP_TAB"] = SCANCODE_KP_TAB;
		// [Constant] int SCANCODE_KP_BACKSPACE
		lrf["SCANCODE_KP_BACKSPACE"] = SCANCODE_KP_BACKSPACE;
		// [Constant] int SCANCODE_KP_A
		lrf["SCANCODE_KP_A"] = SCANCODE_KP_A;
		// [Constant] int SCANCODE_KP_B
		lrf["SCANCODE_KP_B"] = SCANCODE_KP_B;
		// [Constant] int SCANCODE_KP_C
		lrf["SCANCODE_KP_C"] = SCANCODE_KP_C;
		// [Constant] int SCANCODE_KP_D
		lrf["SCANCODE_KP_D"] = SCANCODE_KP_D;
		// [Constant] int SCANCODE_KP_E
		lrf["SCANCODE_KP_E"] = SCANCODE_KP_E;
		// [Constant] int SCANCODE_KP_F
		lrf["SCANCODE_KP_F"] = SCANCODE_KP_F;
		// [Constant] int SCANCODE_KP_XOR
		lrf["SCANCODE_KP_XOR"] = SCANCODE_KP_XOR;
		// [Constant] int SCANCODE_KP_POWER
		lrf["SCANCODE_KP_POWER"] = SCANCODE_KP_POWER;
		// [Constant] int SCANCODE_KP_PERCENT
		lrf["SCANCODE_KP_PERCENT"] = SCANCODE_KP_PERCENT;
		// [Constant] int SCANCODE_KP_LESS
		lrf["SCANCODE_KP_LESS"] = SCANCODE_KP_LESS;
		// [Constant] int SCANCODE_KP_GREATER
		lrf["SCANCODE_KP_GREATER"] = SCANCODE_KP_GREATER;
		// [Constant] int SCANCODE_KP_AMPERSAND
		lrf["SCANCODE_KP_AMPERSAND"] = SCANCODE_KP_AMPERSAND;
		// [Constant] int SCANCODE_KP_DBLAMPERSAND
		lrf["SCANCODE_KP_DBLAMPERSAND"] = SCANCODE_KP_DBLAMPERSAND;
		// [Constant] int SCANCODE_KP_VERTICALBAR
		lrf["SCANCODE_KP_VERTICALBAR"] = SCANCODE_KP_VERTICALBAR;
		// [Constant] int SCANCODE_KP_DBLVERTICALBAR
		lrf["SCANCODE_KP_DBLVERTICALBAR"] = SCANCODE_KP_DBLVERTICALBAR;
		// [Constant] int SCANCODE_KP_COLON
		lrf["SCANCODE_KP_COLON"] = SCANCODE_KP_COLON;
		// [Constant] int SCANCODE_KP_HASH
		lrf["SCANCODE_KP_HASH"] = SCANCODE_KP_HASH;
		// [Constant] int SCANCODE_KP_SPACE
		lrf["SCANCODE_KP_SPACE"] = SCANCODE_KP_SPACE;
		// [Constant] int SCANCODE_KP_AT
		lrf["SCANCODE_KP_AT"] = SCANCODE_KP_AT;
		// [Constant] int SCANCODE_KP_EXCLAM
		lrf["SCANCODE_KP_EXCLAM"] = SCANCODE_KP_EXCLAM;
		// [Constant] int SCANCODE_KP_MEMSTORE
		lrf["SCANCODE_KP_MEMSTORE"] = SCANCODE_KP_MEMSTORE;
		// [Constant] int SCANCODE_KP_MEMRECALL
		lrf["SCANCODE_KP_MEMRECALL"] = SCANCODE_KP_MEMRECALL;
		// [Constant] int SCANCODE_KP_MEMCLEAR
		lrf["SCANCODE_KP_MEMCLEAR"] = SCANCODE_KP_MEMCLEAR;
		// [Constant] int SCANCODE_KP_MEMADD
		lrf["SCANCODE_KP_MEMADD"] = SCANCODE_KP_MEMADD;
		// [Constant] int SCANCODE_KP_MEMSUBTRACT
		lrf["SCANCODE_KP_MEMSUBTRACT"] = SCANCODE_KP_MEMSUBTRACT;
		// [Constant] int SCANCODE_KP_MEMMULTIPLY
		lrf["SCANCODE_KP_MEMMULTIPLY"] = SCANCODE_KP_MEMMULTIPLY;
		// [Constant] int SCANCODE_KP_MEMDIVIDE
		lrf["SCANCODE_KP_MEMDIVIDE"] = SCANCODE_KP_MEMDIVIDE;
		// [Constant] int SCANCODE_KP_PLUSMINUS
		lrf["SCANCODE_KP_PLUSMINUS"] = SCANCODE_KP_PLUSMINUS;
		// [Constant] int SCANCODE_KP_CLEAR
		lrf["SCANCODE_KP_CLEAR"] = SCANCODE_KP_CLEAR;
		// [Constant] int SCANCODE_KP_CLEARENTRY
		lrf["SCANCODE_KP_CLEARENTRY"] = SCANCODE_KP_CLEARENTRY;
		// [Constant] int SCANCODE_KP_BINARY
		lrf["SCANCODE_KP_BINARY"] = SCANCODE_KP_BINARY;
		// [Constant] int SCANCODE_KP_OCTAL
		lrf["SCANCODE_KP_OCTAL"] = SCANCODE_KP_OCTAL;
		// [Constant] int SCANCODE_KP_DECIMAL
		lrf["SCANCODE_KP_DECIMAL"] = SCANCODE_KP_DECIMAL;
		// [Constant] int SCANCODE_KP_HEXADECIMAL
		lrf["SCANCODE_KP_HEXADECIMAL"] = SCANCODE_KP_HEXADECIMAL;
		// [Constant] int SCANCODE_LCTRL
		lrf["SCANCODE_LCTRL"] = SCANCODE_LCTRL;
		// [Constant] int SCANCODE_LSHIFT
		lrf["SCANCODE_LSHIFT"] = SCANCODE_LSHIFT;
		// [Constant] int SCANCODE_LALT
		lrf["SCANCODE_LALT"] = SCANCODE_LALT;
		// [Constant] int SCANCODE_LGUI
		lrf["SCANCODE_LGUI"] = SCANCODE_LGUI;
		// [Constant] int SCANCODE_RCTRL
		lrf["SCANCODE_RCTRL"] = SCANCODE_RCTRL;
		// [Constant] int SCANCODE_RSHIFT
		lrf["SCANCODE_RSHIFT"] = SCANCODE_RSHIFT;
		// [Constant] int SCANCODE_RALT
		lrf["SCANCODE_RALT"] = SCANCODE_RALT;
		// [Constant] int SCANCODE_RGUI
		lrf["SCANCODE_RGUI"] = SCANCODE_RGUI;
		// [Constant] int SCANCODE_MODE
		lrf["SCANCODE_MODE"] = SCANCODE_MODE;
		// [Constant] int SCANCODE_AUDIONEXT
		lrf["SCANCODE_AUDIONEXT"] = SCANCODE_AUDIONEXT;
		// [Constant] int SCANCODE_AUDIOPREV
		lrf["SCANCODE_AUDIOPREV"] = SCANCODE_AUDIOPREV;
		// [Constant] int SCANCODE_AUDIOSTOP
		lrf["SCANCODE_AUDIOSTOP"] = SCANCODE_AUDIOSTOP;
		// [Constant] int SCANCODE_AUDIOPLAY
		lrf["SCANCODE_AUDIOPLAY"] = SCANCODE_AUDIOPLAY;
		// [Constant] int SCANCODE_AUDIOMUTE
		lrf["SCANCODE_AUDIOMUTE"] = SCANCODE_AUDIOMUTE;
		// [Constant] int SCANCODE_MEDIASELECT
		lrf["SCANCODE_MEDIASELECT"] = SCANCODE_MEDIASELECT;
		// [Constant] int SCANCODE_WWW
		lrf["SCANCODE_WWW"] = SCANCODE_WWW;
		// [Constant] int SCANCODE_MAIL
		lrf["SCANCODE_MAIL"] = SCANCODE_MAIL;
		// [Constant] int SCANCODE_CALCULATOR
		lrf["SCANCODE_CALCULATOR"] = SCANCODE_CALCULATOR;
		// [Constant] int SCANCODE_COMPUTER
		lrf["SCANCODE_COMPUTER"] = SCANCODE_COMPUTER;
		// [Constant] int SCANCODE_AC_SEARCH
		lrf["SCANCODE_AC_SEARCH"] = SCANCODE_AC_SEARCH;
		// [Constant] int SCANCODE_AC_HOME
		lrf["SCANCODE_AC_HOME"] = SCANCODE_AC_HOME;
		// [Constant] int SCANCODE_AC_BACK
		lrf["SCANCODE_AC_BACK"] = SCANCODE_AC_BACK;
		// [Constant] int SCANCODE_AC_FORWARD
		lrf["SCANCODE_AC_FORWARD"] = SCANCODE_AC_FORWARD;
		// [Constant] int SCANCODE_AC_STOP
		lrf["SCANCODE_AC_STOP"] = SCANCODE_AC_STOP;
		// [Constant] int SCANCODE_AC_REFRESH
		lrf["SCANCODE_AC_REFRESH"] = SCANCODE_AC_REFRESH;
		// [Constant] int SCANCODE_AC_BOOKMARKS
		lrf["SCANCODE_AC_BOOKMARKS"] = SCANCODE_AC_BOOKMARKS;
		// [Constant] int SCANCODE_BRIGHTNESSDOWN
		lrf["SCANCODE_BRIGHTNESSDOWN"] = SCANCODE_BRIGHTNESSDOWN;
		// [Constant] int SCANCODE_BRIGHTNESSUP
		lrf["SCANCODE_BRIGHTNESSUP"] = SCANCODE_BRIGHTNESSUP;
		// [Constant] int SCANCODE_DISPLAYSWITCH
		lrf["SCANCODE_DISPLAYSWITCH"] = SCANCODE_DISPLAYSWITCH;
		// [Constant] int SCANCODE_KBDILLUMTOGGLE
		lrf["SCANCODE_KBDILLUMTOGGLE"] = SCANCODE_KBDILLUMTOGGLE;
		// [Constant] int SCANCODE_KBDILLUMDOWN
		lrf["SCANCODE_KBDILLUMDOWN"] = SCANCODE_KBDILLUMDOWN;
		// [Constant] int SCANCODE_KBDILLUMUP
		lrf["SCANCODE_KBDILLUMUP"] = SCANCODE_KBDILLUMUP;
		// [Constant] int SCANCODE_EJECT
		lrf["SCANCODE_EJECT"] = SCANCODE_EJECT;
		// [Constant] int SCANCODE_SLEEP
		lrf["SCANCODE_SLEEP"] = SCANCODE_SLEEP;
		// [Constant] int SCANCODE_APP1
		lrf["SCANCODE_APP1"] = SCANCODE_APP1;
		// [Constant] int SCANCODE_APP2
		lrf["SCANCODE_APP2"] = SCANCODE_APP2;

		// [Constant] int HAT_CENTER
		lrf["HAT_CENTER"] = HAT_CENTER;
		// [Constant] int HAT_UP
		lrf["HAT_UP"] = HAT_UP;
		// [Constant] int HAT_RIGHT
		lrf["HAT_RIGHT"] = HAT_RIGHT;
		// [Constant] int HAT_DOWN
		lrf["HAT_DOWN"] = HAT_DOWN;
		// [Constant] int HAT_LEFT
		lrf["HAT_LEFT"] = HAT_LEFT;
		
		// [Constant] int CONTROLLER_BUTTON_A
		lrf["CONTROLLER_BUTTON_A"] = CONTROLLER_BUTTON_A;
		// [Constant] int CONTROLLER_BUTTON_B
		lrf["CONTROLLER_BUTTON_B"] = CONTROLLER_BUTTON_B;
		// [Constant] int CONTROLLER_BUTTON_X
		lrf["CONTROLLER_BUTTON_X"] = CONTROLLER_BUTTON_X;
		// [Constant] int CONTROLLER_BUTTON_Y
		lrf["CONTROLLER_BUTTON_Y"] = CONTROLLER_BUTTON_Y;
		// [Constant] int CONTROLLER_BUTTON_BACK
		lrf["CONTROLLER_BUTTON_BACK"] = CONTROLLER_BUTTON_BACK;
		// [Constant] int CONTROLLER_BUTTON_GUIDE
		lrf["CONTROLLER_BUTTON_GUIDE"] = CONTROLLER_BUTTON_GUIDE;
		// [Constant] int CONTROLLER_BUTTON_START
		lrf["CONTROLLER_BUTTON_START"] = CONTROLLER_BUTTON_START;
		// [Constant] int CONTROLLER_BUTTON_LEFTSTICK
		lrf["CONTROLLER_BUTTON_LEFTSTICK"] = CONTROLLER_BUTTON_LEFTSTICK;
		// [Constant] int CONTROLLER_BUTTON_RIGHTSTICK
		lrf["CONTROLLER_BUTTON_RIGHTSTICK"] = CONTROLLER_BUTTON_RIGHTSTICK;
		// [Constant] int CONTROLLER_BUTTON_LEFTSHOULDER
		lrf["CONTROLLER_BUTTON_LEFTSHOULDER"] = CONTROLLER_BUTTON_LEFTSHOULDER;
		// [Constant] int CONTROLLER_BUTTON_RIGHTSHOULDER
		lrf["CONTROLLER_BUTTON_RIGHTSHOULDER"] = CONTROLLER_BUTTON_RIGHTSHOULDER;
		// [Constant] int CONTROLLER_BUTTON_DPAD_UP
		lrf["CONTROLLER_BUTTON_DPAD_UP"] = CONTROLLER_BUTTON_DPAD_UP;
		// [Constant] int CONTROLLER_BUTTON_DPAD_DOWN
		lrf["CONTROLLER_BUTTON_DPAD_DOWN"] = CONTROLLER_BUTTON_DPAD_DOWN;
		// [Constant] int CONTROLLER_BUTTON_DPAD_LEFT
		lrf["CONTROLLER_BUTTON_DPAD_LEFT"] = CONTROLLER_BUTTON_DPAD_LEFT;
		// [Constant] int CONTROLLER_BUTTON_DPAD_RIGHT
		lrf["CONTROLLER_BUTTON_DPAD_RIGHT"] = CONTROLLER_BUTTON_DPAD_RIGHT;

		// [Constant] int CONTROLLER_AXIS_LEFTX
		lrf["CONTROLLER_AXIS_LEFTX"] = CONTROLLER_AXIS_LEFTX;
		// [Constant] int CONTROLLER_AXIS_LEFTY
		lrf["CONTROLLER_AXIS_LEFTY"] = CONTROLLER_AXIS_LEFTY;
		// [Constant] int CONTROLLER_AXIS_RIGHTX
		lrf["CONTROLLER_AXIS_RIGHTX"] = CONTROLLER_AXIS_RIGHTX;
		// [Constant] int CONTROLLER_AXIS_RIGHTY
		lrf["CONTROLLER_AXIS_RIGHTY"] = CONTROLLER_AXIS_RIGHTY;
		// [Constant] int CONTROLLER_AXIS_TRIGGERLEFT
		lrf["CONTROLLER_AXIS_TRIGGERLEFT"] = CONTROLLER_AXIS_TRIGGERLEFT;
		// [Constant] int CONTROLLER_AXIS_TRIGGERRIGHT
		lrf["CONTROLLER_AXIS_TRIGGERRIGHT"] = CONTROLLER_AXIS_TRIGGERRIGHT;
	}
}

