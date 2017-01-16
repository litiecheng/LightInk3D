

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
#include "Math/Rect.h"
#include "LuaScript/LuaUtils.h"
#include "LuaEngine/LuaEngine.h"

namespace Urho3D
{
	using namespace LightInk;
	void bind_class_Rect(LuaModule & lm)
	{
		lm
		[
			LuaRegister<IntRect, void ()>(lm.state(), "IntRect")
				.def(&IntRect::operator==, "__eq")
				.def(&IntRect::Size, "Size")
				.def(&IntRect::Width, "Width")
				.def(&IntRect::Height, "Height")
				.def(&IntRect::IsInside, "IsInside")
				.def(&IntRect::ToString, "ToString")
				.def(&IntRect::left_, "left")
				.def(&IntRect::top_, "top")
				.def(&IntRect::right_, "right")
				.def(&IntRect::bottom_, "bottom")
				.def(&IntRect::ZERO, "ZERO")
			<=
			LuaRegister<Rect, void ()>(lm.state(), "Rect")
				.def(&Rect::operator==, "__eq")
				.def(static_cast<void(Rect::*)(const Rect&)>(&Rect::Define), "DefineR")
				.def(static_cast<void(Rect::*)(const Vector2&, const Vector2&)>(&Rect::Define), "DefineVV")
				.def(static_cast<void(Rect::*)(const Vector2&)>(&Rect::Define), "DefineV")
				.def(static_cast<void(Rect::*)(const Vector2&)>(&Rect::Merge), "MergeV")
				.def(static_cast<void(Rect::*)(const Rect&)>(&Rect::Merge), "MergeR")
				.def(&Rect::Clear, "Clear")
				.def(&Rect::Clip, "Clip")
				.def(&Rect::Defined, "Defined")
				.def(&Rect::Center, "Center")
				.def(&Rect::Size, "Size")
				.def(&Rect::HalfSize, "HalfSize")
				.def(&Rect::Equals, "Equals")
				.def(&Rect::IsInside, "IsInside")
				.def(&Rect::ToVector4, "ToVector4")
				.def(&Rect::ToString, "ToString")
				.def(&Rect::min_, "min")
				.def(&Rect::max_, "max")
				.def(&Rect::FULL, "FULL")
				.def(&Rect::POSITIVE, "POSITIVE")
				.def(&Rect::ZERO, "ZERO")
				
		];
	}
}

