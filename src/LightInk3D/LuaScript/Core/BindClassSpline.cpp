

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

#include "../../Core/Spline.h"
#include "../../LuaScript/LuaUtils.h"
#include "LuaEngine/LuaEngine.h"

namespace Urho3D
{
	using namespace LightInk;
	void bind_class_Spline(LuaModele & lm)
	{
		lm
		[
			LuaRegister<Spline, void ()>(lm.state(), "Spline")
				.def(&Spline::operator==, "__eq")
				.def(&Spline::SetInterpolationMode, "SetInterpolationMode")
				.def(&Spline::SetKnot, "SetKnot")
				.def(static_cast<void(Spline::*)(const Variant&)>(&Spline::AddKnot), "AddKnot")
				.def(static_cast<void(Spline::*)(const Variant&, unsigned)>(&Spline::AddKnot), "AddKnot2")
				.def(static_cast<void(Spline::*)()>(&Spline::RemoveKnot), "RemoveKnot")
				.def(static_cast<void(Spline::*)(unsigned)>(&Spline::RemoveKnot), "RemoveKnot2")
				.def(&Spline::Clear, "Clear")
				.def(&Spline::GetInterpolationMode, "GetInterpolationMode")
				.def(&Spline::GetKnot, "GetKnot")
				.def(&Spline::GetPoint, "GetPoint")
		];

	}
}

