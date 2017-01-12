

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

#include "../../Precompiled.h"
#include "../../UI/LineEdit.h"
#include "../../UI/Text.h"
#include "../../LuaScript/LuaUtils.h"
#include "LuaEngine/LuaEngine.h"

namespace Urho3D
{
	using namespace LightInk;
	void bind_class_LineEdit(LuaModele & lm)
	{
		lm
		[
			LuaRegister<LineEdit, void ()>(lm.state(), "LineEdit", BaseClassStrategy<BorderImage>())
				.disable_new()
				.def(CreateObject<LineEdit>, "new")
				.def(&LineEdit::SetText, "SetText")
				.def(&LineEdit::SetCursorPosition, "SetCursorPosition")
				.def(&LineEdit::SetCursorBlinkRate, "SetCursorBlinkRate")
				.def(&LineEdit::SetMaxLength, "SetMaxLength")
				.def(&LineEdit::SetEchoCharacter, "SetEchoCharacter")
				.def(&LineEdit::SetCursorMovable, "SetCursorMovable")
				.def(&LineEdit::SetTextSelectable, "SetTextSelectable")
				.def(&LineEdit::SetTextCopyable, "SetTextCopyable")
				.def(&LineEdit::GetText, "GetText")
				.def(&LineEdit::GetCursorPosition, "GetCursorPosition")
				.def(&LineEdit::GetCursorBlinkRate, "GetCursorBlinkRate")
				.def(&LineEdit::GetMaxLength, "GetMaxLength")
				.def(&LineEdit::GetEchoCharacter, "GetEchoCharacter")
				.def(&LineEdit::IsCursorMovable, "IsCursorMovable")
				.def(&LineEdit::IsTextSelectable, "IsTextSelectable")
				.def(&LineEdit::IsTextCopyable, "IsTextCopyable")
				.def(&LineEdit::GetTextElement, "GetTextElement")
				.def(&LineEdit::GetCursor, "GetCursor")
				
		];
	}
}
