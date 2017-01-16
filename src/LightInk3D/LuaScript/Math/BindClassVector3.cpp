

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
#include "Math/Vector3.h"
#include "LuaScript/LuaUtils.h"
#include "LuaEngine/LuaEngine.h"

namespace Urho3D
{
	using namespace LightInk;
	void bind_class_Vector3(LuaModule & lm)
	{
		lm
		[
			LuaRegister<Vector3, void (float, float, float)>(lm.state(), "Vector3")
				.def(&Vector3::operator==, "__eq")
				.def(&Vector3::operator+, "__add")
				.def(static_cast<Vector3(Vector3::*)(const Vector3&) const>(&Vector3::operator-), "__sub")
				.def(static_cast<Vector3(Vector3::*)() const>(&Vector3::operator-), "sub")
				.def(static_cast<Vector3(Vector3::*)(const Vector3&) const>(&Vector3::operator*), "__mul")
				.def(static_cast<Vector3(Vector3::*)(float) const>(&Vector3::operator*), "mulF")
				.def(static_cast<Vector3(Vector3::*)(const Vector3&) const>(&Vector3::operator/), "__div")
				.def(static_cast<Vector3(Vector3::*)(float) const>(&Vector3::operator/), "divF")
				.def(&Vector3::Normalize, "Normalize")
				.def(&Vector3::Length, "Length")
				.def(&Vector3::LengthSquared, "LengthSquared")
				.def(&Vector3::DotProduct, "DotProduct")
				.def(&Vector3::AbsDotProduct, "AbsDotProduct")
				.def(&Vector3::CrossProduct, "CrossProduct")
				.def(&Vector3::Abs, "Abs")
				.def(&Vector3::Lerp, "Lerp")
				.def(&Vector3::Equals, "Equals")
				.def(&Vector3::Angle, "Angle")
				.def(&Vector3::IsNaN, "IsNaN")
				.def(&Vector3::Normalized, "Normalized")
				.def(&Vector3::ToString, "ToString")
				.def(&Vector3::x_, "x")
				.def(&Vector3::y_, "y")
				.def(&Vector3::z_, "z")
				.def(&Vector3::ZERO, "ZERO")
				.def(&Vector3::LEFT, "LEFT")
				.def(&Vector3::RIGHT, "RIGHT")
				.def(&Vector3::UP, "UP")
				.def(&Vector3::DOWN, "DOWN")
				.def(&Vector3::FORWARD, "FORWARD")
				.def(&Vector3::BACK, "BACK")
				.def(&Vector3::ONE, "ONE")
				
		];
	}
}

