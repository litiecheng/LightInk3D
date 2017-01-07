

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
#include "../../Math/Color.h"
#include "../../LuaScript/LuaUtils.h"
#include "LuaEngine/LuaEngine.h"

namespace Urho3D
{
	using namespace LightInk;
	void bind_class_Color(LuaModele & lm)
	{
		lm
		[
			LuaRegister<Color, void ()>(lm.state(), "Color")
				.def(&Color::operator==, "__eq")
				.def(&Color::operator*, "__mul")
				.def(&Color::operator+, "__add")
				.def(&Color::ToUInt, "ToUInt")
				.def(&Color::ToHSL, "ToHSL")
				.def(&Color::ToHSV, "ToHSV")
				.def(&Color::FromHSL, "FromHSL")
				.def(&Color::FromHSV, "FromHSV")
				.def(&Color::ToVector3, "ToVector3")
				.def(&Color::ToVector4, "ToVector4")
				.def(&Color::SumRGB, "SumRGB")
				.def(&Color::Average, "Average")
				.def(&Color::Luma, "Luma")
				.def(&Color::Chroma, "Chroma")
				.def(static_cast<float(Color::*)() const>(&Color::Hue), "Hue")
				.def(static_cast<float(Color::*)() const>(&Color::SaturationHSL), "SaturationHSL")
				.def(static_cast<float(Color::*)() const>(&Color::SaturationHSV), "SaturationHSV")
				.def(&Color::Value, "Value")
				.def(&Color::Lightness, "Lightness")
				.def(&Color::MaxRGB, "MaxRGB")
				.def(&Color::MinRGB, "MinRGB")
				.def(&Color::Range, "Range")
				.def(&Color::Clip, "Clip")
				.def(&Color::Invert, "Invert")
				.def(&Color::Lerp, "Lerp")
				.def(&Color::Abs, "Abs")
				.def(&Color::Equals, "Equals")
				.def(&Color::ToString, "ToString")
				.def(&Color::r_, "r")
				.def(&Color::g_, "g")
				.def(&Color::b_, "b")
				.def(&Color::a_, "a")
				.def(&Color::WHITE, "WHITE")
				.def(&Color::GRAY, "GRAY")
				.def(&Color::BLACK, "BLACK")
				.def(&Color::RED, "RED")
				.def(&Color::GREEN, "GREEN")
				.def(&Color::BLUE, "BLUE")
				.def(&Color::CYAN, "CYAN")
				.def(&Color::MAGENTA, "MAGENTA")
				.def(&Color::YELLOW, "YELLOW")
				.def(&Color::TRANSPARENT, "TRANSPARENT")
		];
	}
}

