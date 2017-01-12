

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
#include "../../Math/Vector4.h"
#include "../../LuaScript/LuaUtils.h"
#include "LuaEngine/LuaEngine.h"

namespace Urho3D
{
	using namespace LightInk;
	void bind_class_Vector4(LuaModele & lm)
	{
		lm
		[
			LuaRegister<Vector4, void (float, float, float, float)>(lm.state(), "Vector4")
				.def(&Vector4::operator==, "__eq")
				.def(&Vector4::operator+, "__add")
				.def(static_cast<Vector4(Vector4::*)(const Vector4&) const>(&Vector4::operator-), "__sub")
				.def(static_cast<Vector4(Vector4::*)() const>(&Vector4::operator-), "sub")
				.def(static_cast<Vector4(Vector4::*)(const Vector4&) const>(&Vector4::operator*), "__mul")
				.def(static_cast<Vector4(Vector4::*)(float) const>(&Vector4::operator*), "mulF")
				.def(static_cast<Vector4(Vector4::*)(const Vector4&) const>(&Vector4::operator/), "__div")
				.def(static_cast<Vector4(Vector4::*)(float) const>(&Vector4::operator/), "divF")
				.def(&Vector4::DotProduct, "DotProduct")
				.def(&Vector4::AbsDotProduct, "AbsDotProduct")
				.def(&Vector4::Abs, "Abs")
				.def(&Vector4::Lerp, "Lerp")
				.def(&Vector4::Equals, "Equals")
				.def(&Vector4::IsNaN, "IsNaN")
				.def(&Vector4::ToString, "ToString")
				.def(&Vector4::x_, "x")
				.def(&Vector4::y_, "y")
				.def(&Vector4::z_, "z")
				.def(&Vector4::w_, "w")
				.def(&Vector4::ZERO, "ZERO")
				.def(&Vector4::ONE, "ONE")
				
		];
	}
}

