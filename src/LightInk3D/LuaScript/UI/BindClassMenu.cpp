

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
#include "UI/Menu.h"
#include "LuaScript/LuaUtils.h"
#include "LuaEngine/LuaEngine.h"

namespace Urho3D
{
	using namespace LightInk;
	static SharedPtr<UIElement> MenuGetPopup(const Menu* self)
	{
		return SharedPtr<UIElement>(self->GetPopup());
	}
	void bind_class_Menu(LuaModule & lm)
	{
		lm
		[
			LuaRegister<Menu, void ()>(lm.state(), "Menu", BaseClassStrategy<Button>())
				.disable_new()
				.def(CreateObject<Menu>, "new")
				.def(&Menu::SetPopup, "SetPopup")
				.def(static_cast<void(Menu::*)(const IntVector2&)>(&Menu::SetPopupOffset), "SetPopupOffsetIV")
				.def(static_cast<void(Menu::*)(int, int)>(&Menu::SetPopupOffset), "SetPopupOffsetII")
				.def(&Menu::ShowPopup, "ShowPopup")
				.def(&Menu::SetAccelerator, "SetAccelerator")
				.def(MenuGetPopup, "GetPopup")
				.def(&Menu::GetPopupOffset, "GetPopupOffset")
				.def(&Menu::GetShowPopup, "GetShowPopup")
				.def(&Menu::GetAcceleratorKey, "GetAcceleratorKey")
				.def(&Menu::GetAcceleratorQualifiers, "GetAcceleratorQualifiers")
				
		];
	}
}
