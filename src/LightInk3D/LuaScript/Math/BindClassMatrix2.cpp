

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
#include "Math/Matrix2.h"
#include "LuaScript/LuaUtils.h"
#include "LuaEngine/LuaEngine.h"

namespace Urho3D
{
	using namespace LightInk;
	void bind_class_Matrix2(LuaModele & lm)
	{
		lm
		[
			LuaRegister<Matrix2, void ()>(lm.state(), "Matrix2")
				.def(&Matrix2::operator==, "__eq")
				.def(static_cast<Matrix2(Matrix2::*)(const Matrix2&) const>(&Matrix2::operator*), "__mul")
				.def(static_cast<Vector2(Matrix2::*)(const Vector2&) const>(&Matrix2::operator*), "mulV")
				.def(static_cast<Matrix2(Matrix2::*)(float) const>(&Matrix2::operator*), "mulF")
				.def(&Matrix2::operator+, "__add")
				.def(&Matrix2::operator-, "__sub")
				.def(static_cast<void(Matrix2::*)(const Vector2&)>(&Matrix2::SetScale), "SetScaleV")
				.def(static_cast<void(Matrix2::*)(float)>(&Matrix2::SetScale), "SetScaleF")
				.def(&Matrix2::Scale, "Scale")
				.def(&Matrix2::Transpose, "Transpose")
				.def(&Matrix2::Scaled, "Scaled")
				.def(&Matrix2::Equals, "Equals")
				.def(&Matrix2::Inverse, "Inverse")
				.def(&Matrix2::ToString, "ToString")
				.def(&Matrix2::m00_, "m00")
				.def(&Matrix2::m01_, "m01")
				.def(&Matrix2::m10_, "m10")
				.def(&Matrix2::m11_, "m11")
				.def(&Matrix2::ZERO, "ZERO")
				.def(&Matrix2::IDENTITY, "IDENTITY")
		];
	}
}

