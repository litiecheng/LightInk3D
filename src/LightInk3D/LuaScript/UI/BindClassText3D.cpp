

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
#include "Graphics/Material.h"
#include "Resource/Image.h"
#include "UI/Font.h"
#include "UI/Text3D.h"
#include "LuaScript/LuaUtils.h"
#include "LuaEngine/LuaEngine.h"

namespace Urho3D
{
	using namespace LightInk;
	void bind_class_Text3D(LuaModule & lm)
	{
		lm
		[
			LuaRegister<Text3D, void ()>(lm.state(), "Text3D", BaseClassStrategy<Drawable>())
				.disable_new()
				.def(CreateObject<Text3D>, "new")
				.def(static_cast<bool(Text3D::*)(const String&, int)>(&Text3D::SetFont), "SetFontSI")
				.def(static_cast<bool(Text3D::*)(Font*, int)>(&Text3D::SetFont), "SetFontFI")
				.def(&Text3D::SetFontSize, "SetFontSize")
				.def(&Text3D::SetMaterial, "SetMaterial")
				.def(&Text3D::SetText, "SetText")
				.def(&Text3D::SetAlignment, "SetAlignment")
				.def(&Text3D::SetHorizontalAlignment, "SetHorizontalAlignment")
				.def(&Text3D::SetVerticalAlignment, "SetVerticalAlignment")
				.def(&Text3D::SetTextAlignment, "SetTextAlignment")
				.def(&Text3D::SetRowSpacing, "SetRowSpacing")
				.def(&Text3D::SetWordwrap, "SetWordwrap")
				.def(&Text3D::SetTextEffect, "SetTextEffect")
				.def(&Text3D::SetEffectShadowOffset, "SetEffectShadowOffset")
				.def(&Text3D::SetEffectStrokeThickness, "SetEffectStrokeThickness")
				.def(&Text3D::SetEffectRoundStroke, "SetEffectRoundStroke")
				.def(&Text3D::SetEffectColor, "SetEffectColor")
				.def(&Text3D::SetEffectDepthBias, "SetEffectDepthBias")
				.def(&Text3D::SetWidth, "SetWidth")
				.def(static_cast<void(Text3D::*)(const Color&)>(&Text3D::SetColor), "SetColorC")
				.def(static_cast<void(Text3D::*)(Corner, const Color&)>(&Text3D::SetColor), "SetColorCC")
				.def(&Text3D::SetOpacity, "SetOpacity")
				.def(&Text3D::SetFixedScreenSize, "SetFixedScreenSize")
				.def(&Text3D::SetFaceCameraMode, "SetFaceCameraMode")
				.def(&Text3D::GetFont, "GetFont")
				.def(&Text3D::GetFontSize, "GetFontSize")
				.def(&Text3D::GetMaterial, "GetMaterial")
				.def(&Text3D::GetText, "GetText")
				.def(&Text3D::GetTextAlignment, "GetTextAlignment")
				.def(&Text3D::GetHorizontalAlignment, "GetHorizontalAlignment")
				.def(&Text3D::GetVerticalAlignment, "GetVerticalAlignment")
				.def(&Text3D::GetRowSpacing, "GetRowSpacing")
				.def(&Text3D::GetWordwrap, "GetWordwrap")
				.def(&Text3D::GetTextEffect, "GetTextEffect")
				.def(&Text3D::GetEffectShadowOffset, "GetEffectShadowOffset")
				.def(&Text3D::GetEffectStrokeThickness, "GetEffectStrokeThickness")
				.def(&Text3D::GetEffectRoundStroke, "GetEffectRoundStroke")
				.def(&Text3D::GetEffectColor, "GetEffectColor")
				.def(&Text3D::GetEffectDepthBias, "GetEffectDepthBias")
				.def(&Text3D::GetWidth, "GetWidth")
				.def(&Text3D::GetRowHeight, "GetRowHeight")
				.def(&Text3D::GetNumRows, "GetNumRows")
				.def(&Text3D::GetNumChars, "GetNumChars")
				.def(&Text3D::GetRowWidth, "GetRowWidth")
				.def(&Text3D::GetCharPosition, "GetCharPosition")
				.def(&Text3D::GetCharSize, "GetCharSize")
				.def(&Text3D::GetColor, "GetColor")
				.def(&Text3D::GetOpacity, "GetOpacity")
				.def(&Text3D::IsFixedScreenSize, "IsFixedScreenSize")
				.def(&Text3D::GetFaceCameraMode, "GetFaceCameraMode")
		];
	}
}
