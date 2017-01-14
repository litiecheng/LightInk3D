

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
#include "Math/Vector2.h"
#include "LuaScript/LuaUtils.h"
#include "LuaEngine/LuaEngine.h"

namespace Urho3D
{
	using namespace LightInk;
	void bind_class_Vector2(LuaModele & lm)
	{
		lm
		[
			LuaRegister<IntVector2, void ()>(lm.state(), "IntVector2")
				.def(&IntVector2::operator==, "__eq")
				.def(&IntVector2::operator+, "__add")
				.def(static_cast<IntVector2(IntVector2::*)(const IntVector2&) const>(&IntVector2::operator-), "__sub")
				.def(static_cast<IntVector2(IntVector2::*)() const>(&IntVector2::operator-), "sub")
				.def(&IntVector2::operator*, "__mul")
				.def(&IntVector2::operator/, "__div")
				.def(&IntVector2::ToString, "ToString")
				.def(&IntVector2::x_, "x")
				.def(&IntVector2::y_, "y")
				.def(&IntVector2::ZERO, "ZERO")
			<=
			LuaRegister<Vector2, void ()>(lm.state(), "Vector2")
				.def(&Vector2::operator==, "__eq")
				.def(&Vector2::operator+, "__add")
				.def(static_cast<Vector2(Vector2::*)(const Vector2&) const>(&Vector2::operator-), "__sub")
				.def(static_cast<Vector2(Vector2::*)() const>(&Vector2::operator-), "sub")
				.def(static_cast<Vector2(Vector2::*)(const Vector2&) const>(&Vector2::operator*), "__mul")
				.def(static_cast<Vector2(Vector2::*)(float) const>(&Vector2::operator*), "mulF")
				.def(static_cast<Vector2(Vector2::*)(const Vector2&) const>(&Vector2::operator/), "__div")
				.def(static_cast<Vector2(Vector2::*)(float) const>(&Vector2::operator/), "divF")
				.def(&Vector2::Normalize, "Normalize")
				.def(&Vector2::Length, "Length")
				.def(&Vector2::LengthSquared, "LengthSquared")
				.def(&Vector2::DotProduct, "DotProduct")
				.def(&Vector2::AbsDotProduct, "AbsDotProduct")
				.def(&Vector2::Angle, "Angle")
				.def(&Vector2::Abs, "Abs")
				.def(&Vector2::Lerp, "Lerp")
				.def(&Vector2::Equals, "Equals")
				.def(&Vector2::IsNaN, "IsNaN")
				.def(&Vector2::Normalized, "Normalized")
				.def(&Vector2::ToString, "ToString")
				.def(&Vector2::x_, "x")
				.def(&Vector2::y_, "y")
				.def(&Vector2::ZERO, "ZERO")
				.def(&Vector2::LEFT, "LEFT")
				.def(&Vector2::RIGHT, "RIGHT")
				.def(&Vector2::UP, "UP")
				.def(&Vector2::DOWN, "DOWN")
				.def(&Vector2::ONE, "ONE")
		];
	}
}

