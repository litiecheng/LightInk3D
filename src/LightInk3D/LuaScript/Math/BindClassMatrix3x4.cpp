

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
#include "Math/Matrix3x4.h"
#include "LuaScript/LuaUtils.h"
#include "LuaEngine/LuaEngine.h"

namespace Urho3D
{
	using namespace LightInk;
	struct M3x4VQV
	{
		Vector3 translation_;
		Quaternion rotation_;
		Vector3 scale_;
	};
	
	static M3x4VQV Matrix3x4Decompose(const Matrix3x4* self)
	{
		M3x4VQV mvqv;
		self->Decompose(mvqv.translation_, mvqv.rotation_, mvqv.scale_);
		return mvqv;
	}
	void bind_class_Matrix3x4(LuaModele & lm)
	{
		lm
		[
			LuaRegister<Matrix3x4, void ()>(lm.state(), "Matrix3x4")
				.def(&Matrix3x4::operator==, "__eq")
				.def(static_cast<Matrix3x4(Matrix3x4::*)(const Matrix3x4&) const>(&Matrix3x4::operator*), "__mul")
				.def(static_cast<Vector3(Matrix3x4::*)(const Vector3&) const>(&Matrix3x4::operator*), "mulV3")
				.def(static_cast<Vector3(Matrix3x4::*)(const Vector4&) const>(&Matrix3x4::operator*), "mulV4")
				.def(static_cast<Matrix3x4(Matrix3x4::*)(float) const>(&Matrix3x4::operator*), "mulF")
				.def(static_cast<Matrix4(Matrix3x4::*)(const Matrix4&) const>(&Matrix3x4::operator*), "mulM4")
				.def(&Matrix3x4::operator+, "__add")
				.def(&Matrix3x4::operator-, "__sub")
				.def(&Matrix3x4::SetTranslation, "SetTranslation")
				.def(&Matrix3x4::SetRotation, "SetRotation")
				.def(static_cast<void(Matrix3x4::*)(const Vector3&)>(&Matrix3x4::SetScale), "SetScaleV")
				.def(static_cast<void(Matrix3x4::*)(float)>(&Matrix3x4::SetScale), "SetScaleF")
				.def(&Matrix3x4::ToMatrix3, "ToMatrix3")
				.def(&Matrix3x4::ToMatrix4, "ToMatrix4")
				.def(&Matrix3x4::RotationMatrix, "RotationMatrix")
				.def(&Matrix3x4::Translation, "Translation")
				.def(&Matrix3x4::Rotation, "Rotation")
				.def(&Matrix3x4::Scale, "Scale")
				.def(&Matrix3x4::Equals, "Equals")
				.def(Matrix3x4Decompose, "Decompose")
				.def(&Matrix3x4::Inverse, "Inverse")
				.def(&Matrix3x4::ToString, "ToString")
				.def(&Matrix3x4::m00_, "m00")
				.def(&Matrix3x4::m01_, "m01")
				.def(&Matrix3x4::m02_, "m02")
				.def(&Matrix3x4::m03_, "m03")
				.def(&Matrix3x4::m10_, "m10")
				.def(&Matrix3x4::m11_, "m11")
				.def(&Matrix3x4::m12_, "m12")
				.def(&Matrix3x4::m13_, "m13")
				.def(&Matrix3x4::m20_, "m20")
				.def(&Matrix3x4::m21_, "m21")
				.def(&Matrix3x4::m22_, "m22")
				.def(&Matrix3x4::m23_, "m23")
				.def(&Matrix3x4::ZERO, "ZERO")
				.def(&Matrix3x4::IDENTITY, "IDENTITY")
			<=
			LuaRegister<M3x4VQV, void ()>(lm.state(), "M3x4VQV")
				.def(&M3x4VQV::translation_, "translation")
				.def(&M3x4VQV::rotation_, "rotation")
				.def(&M3x4VQV::scale_, "scale")
		];
	}
}

