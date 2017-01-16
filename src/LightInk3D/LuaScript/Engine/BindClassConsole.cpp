

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
#include "Engine/Console.h"
#include "Resource/XMLFile.h"
#include "UI/BorderImage.h"
#include "UI/Button.h"
#include "UI/LineEdit.h"
#include "LuaScript/LuaUtils.h"
#include "LuaEngine/LuaEngine.h"

namespace Urho3D
{
	using namespace LightInk;
	void bind_class_Console(LuaModule & lm)
	{
		lm
		[
			LuaRegister<Console, void ()>(lm.state(), "Console", BaseClassStrategy<Object>())
				.def(&Console::SetDefaultStyle, "SetDefaultStyle")
				.def(&Console::SetVisible, "SetVisible")
				.def(&Console::Toggle, "Toggle")
				.def(&Console::SetAutoVisibleOnError, "SetAutoVisibleOnError")
				.def(&Console::SetCommandInterpreter, "SetCommandInterpreter")
				.def(&Console::SetNumBufferedRows, "SetNumBufferedRows")
				.def(&Console::SetNumRows, "SetNumRows")
				.def(&Console::SetNumHistoryRows, "SetNumHistoryRows")
				.def(&Console::SetFocusOnShow, "SetFocusOnShow")
				.def(&Console::UpdateElements, "UpdateElements")
				.def(&Console::GetDefaultStyle, "GetDefaultStyle")
				.def(&Console::GetBackground, "GetBackground")
				.def(&Console::GetLineEdit, "GetLineEdit")
				.def(&Console::GetCloseButton, "GetCloseButton")
				.def(&Console::IsVisible, "IsVisible")
				.def(&Console::IsAutoVisibleOnError, "IsAutoVisibleOnError")
				.def(&Console::GetCommandInterpreter, "GetCommandInterpreter")
				.def(&Console::GetNumBufferedRows, "GetNumBufferedRows")
				.def(&Console::GetNumRows, "GetNumRows")
				.def(&Console::CopySelectedRows, "CopySelectedRows")
				.def(&Console::GetNumHistoryRows, "GetNumHistoryRows")
				.def(&Console::GetHistoryPosition, "GetHistoryPosition")
				.def(&Console::GetHistoryRow, "GetHistoryRow")
				.def(&Console::GetFocusOnShow, "GetFocusOnShow")
		];
	}
}

