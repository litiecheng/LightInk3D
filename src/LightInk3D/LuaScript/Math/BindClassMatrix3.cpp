

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
#include "Math/Matrix3.h"
#include "LuaScript/LuaUtils.h"
#include "LuaEngine/LuaEngine.h"

namespace Urho3D
{
	using namespace LightInk;
	void bind_class_Matrix3(LuaModele & lm)
	{
		lm
		[
			LuaRegister<Matrix3, void ()>(lm.state(), "Matrix3")
				.def(&Matrix3::operator==, "__eq")
				.def(static_cast<Matrix3(Matrix3::*)(const Matrix3&) const>(&Matrix3::operator*), "__mul")
				.def(static_cast<Vector3(Matrix3::*)(const Vector3&) const>(&Matrix3::operator*), "mulV")
				.def(static_cast<Matrix3(Matrix3::*)(float) const>(&Matrix3::operator*), "mulF")
				.def(&Matrix3::operator+, "__add")
				.def(&Matrix3::operator-, "__sub")
				.def(static_cast<void(Matrix3::*)(const Vector3&)>(&Matrix3::SetScale), "SetScaleV")
				.def(static_cast<void(Matrix3::*)(float)>(&Matrix3::SetScale), "SetScaleF")
				.def(&Matrix3::Scale, "Scale")
				.def(&Matrix3::Transpose, "Transpose")
				.def(&Matrix3::Scaled, "Scaled")
				.def(&Matrix3::Equals, "Equals")
				.def(&Matrix3::Inverse, "Inverse")
				.def(&Matrix3::ToString, "ToString")
				.def(&Matrix3::m00_, "m00")
				.def(&Matrix3::m01_, "m01")
				.def(&Matrix3::m02_, "m02")
				.def(&Matrix3::m10_, "m10")
				.def(&Matrix3::m11_, "m11")
				.def(&Matrix3::m12_, "m12")
				.def(&Matrix3::m20_, "m20")
				.def(&Matrix3::m21_, "m21")
				.def(&Matrix3::m22_, "m22")
				.def(&Matrix3::ZERO, "ZERO")
				.def(&Matrix3::IDENTITY, "IDENTITY")
				
		];
	}
}

