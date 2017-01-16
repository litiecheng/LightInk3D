

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
#include "UI/Font.h"
#include "UI/Text.h"
#include "LuaScript/LuaUtils.h"
#include "LuaEngine/LuaEngine.h"

namespace Urho3D
{
	using namespace LightInk;
	void bind_class_Text(LuaModule & lm)
	{
		lm
		[
			LuaRegister<Text, void ()>(lm.state(), "Text", BaseClassStrategy<UIElement>())
				.disable_new()
				.def(CreateObject<Text>, "new")
				.def(static_cast<bool(Text::*)(const String&, int)>(&Text::SetFont), "SetFontSI")
				.def(static_cast<bool(Text::*)(Font*, int)>(&Text::SetFont), "SetFontFI")
				.def(&Text::SetFontSize, "SetFontSize")
				.def(&Text::SetText, "SetText")
				.def(&Text::SetTextAlignment, "SetTextAlignment")
				.def(&Text::SetRowSpacing, "SetRowSpacing")
				.def(&Text::SetWordwrap, "SetWordwrap")
				.def(&Text::SetAutoLocalizable, "SetAutoLocalizable")
				.def(&Text::SetSelection, "SetSelection")
				.def(&Text::ClearSelection, "ClearSelection")
				.def(&Text::SetSelectionColor, "SetSelectionColor")
				.def(&Text::SetHoverColor, "SetHoverColor")
				.def(&Text::SetTextEffect, "SetTextEffect")
				.def(&Text::SetEffectShadowOffset, "SetEffectShadowOffset")
				.def(&Text::SetEffectStrokeThickness, "SetEffectStrokeThickness")
				.def(&Text::SetEffectRoundStroke, "SetEffectRoundStroke")
				.def(&Text::SetEffectColor, "SetEffectColor")
				.def(&Text::GetFont, "GetFont")
				.def(&Text::GetFontSize, "GetFontSize")
				.def(&Text::GetText, "GetText")
				.def(&Text::GetTextAlignment, "GetTextAlignment")
				.def(&Text::GetRowSpacing, "GetRowSpacing")
				.def(&Text::GetWordwrap, "GetWordwrap")
				.def(&Text::GetAutoLocalizable, "GetAutoLocalizable")
				.def(&Text::GetSelectionStart, "GetSelectionStart")
				.def(&Text::GetSelectionLength, "GetSelectionLength")
				.def(&Text::GetSelectionColor, "GetSelectionColor")
				.def(&Text::GetHoverColor, "GetHoverColor")
				.def(&Text::GetTextEffect, "GetTextEffect")
				.def(&Text::GetEffectShadowOffset, "GetEffectShadowOffset")
				.def(&Text::GetEffectStrokeThickness, "GetEffectStrokeThickness")
				.def(&Text::GetEffectRoundStroke, "GetEffectRoundStroke")
				.def(&Text::GetEffectColor, "GetEffectColor")
				.def(&Text::GetRowHeight, "GetRowHeight")
				.def(&Text::GetNumRows, "GetNumRows")
				.def(&Text::GetNumChars, "GetNumChars")
				.def(&Text::GetRowWidth, "GetRowWidth")
				.def(&Text::GetCharPosition, "GetCharPosition")
				.def(&Text::GetCharSize, "GetCharSize")
				.def(&Text::SetEffectDepthBias, "SetEffectDepthBias")
				.def(&Text::GetEffectDepthBias, "GetEffectDepthBias")
				
		];
	}
}
