

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
#include "UI/MessageBox.h"
#include "UI/UIElement.h"
#include "LuaScript/LuaUtils.h"
#include "LuaEngine/LuaEngine.h"

namespace Urho3D
{
	using namespace LightInk;
	static SharedPtr<MessageBox> CreateMessageBox(Context * context, const String& messageString, const String& titleString = "", XMLFile* layoutFile = 0, XMLFile* styleFile = 0)
	{
		return SharedPtr<MessageBox>(new MessageBox(context, messageString, titleString, layoutFile, styleFile));
	}
	static SharedPtr<UIElement> MessageBoxGetWindow(const MessageBox* self)
	{
		return SharedPtr<UIElement>(self->GetWindow());
	}
	void bind_class_MessageBox(LuaModele & lm)
	{
		lm
		[
			LuaRegister<MessageBox, void ()>(lm.state(), "MessageBox", BaseClassStrategy<Object>())
				.disable_new()
				.def(CreateMessageBox, "new")
				.def(&MessageBox::SetTitle, "SetTitle")
				.def(&MessageBox::SetMessage, "SetMessage")
				.def(&MessageBox::GetTitle, "GetTitle")
				.def(&MessageBox::GetMessage, "GetMessage")
				.def(MessageBoxGetWindow, "GetWindow")
				
		];
	}
}
