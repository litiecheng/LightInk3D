

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
#include "../../Math/Quaternion.h"
#include "../../LuaScript/LuaUtils.h"
#include "LuaEngine/LuaEngine.h"

namespace Urho3D
{
	using namespace LightInk;
	void bind_class_Quaternion(LuaModele & lm)
	{
		lm
		[
			LuaRegister<Quaternion, void ()>(lm.state(), "Quaternion")
				.def(&Quaternion::operator==, "__eq")
				.def(static_cast<Quaternion(Quaternion::*)(const Quaternion&) const>(&Quaternion::operator*), "__mul")
				.def(static_cast<Quaternion(Quaternion::*)(float) const>(&Quaternion::operator*), "mulF")
				.def(static_cast<Vector3(Quaternion::*)(const Vector3&) const>(&Quaternion::operator*), "mulV")
				.def(static_cast<Quaternion(Quaternion::*)(const Quaternion&) const>(&Quaternion::operator-), "__sub")
				.def(static_cast<Quaternion(Quaternion::*)() const>(&Quaternion::operator-), "sub")
				.def(&Quaternion::operator+, "__add")
				.def(&Quaternion::FromAngleAxis, "FromAngleAxis")
				.def(&Quaternion::FromEulerAngles, "FromEulerAngles")
				.def(&Quaternion::FromRotationTo, "FromRotationTo")
				.def(&Quaternion::FromAxes, "FromAxes")
				.def(&Quaternion::FromRotationMatrix, "FromRotationMatrix")
				.def(&Quaternion::FromLookRotation, "FromLookRotation")
				.def(&Quaternion::Normalize, "Normalize")
				.def(&Quaternion::Normalized, "Normalized")
				.def(&Quaternion::Inverse, "Inverse")
				.def(&Quaternion::LengthSquared, "LengthSquared")
				.def(&Quaternion::DotProduct, "DotProduct")
				.def(&Quaternion::Equals, "Equals")
				.def(&Quaternion::IsNaN, "IsNaN")
				.def(&Quaternion::Conjugate, "Conjugate")
				.def(&Quaternion::EulerAngles, "EulerAngles")
				.def(&Quaternion::YawAngle, "YawAngle")
				.def(&Quaternion::PitchAngle, "PitchAngle")
				.def(&Quaternion::RollAngle, "RollAngle")
				.def(&Quaternion::RotationMatrix, "RotationMatrix")
				.def(&Quaternion::Slerp, "Slerp")
				.def(&Quaternion::Nlerp, "Nlerp")
				.def(&Quaternion::ToString, "ToString")
				.def(&Quaternion::w_, "w")
				.def(&Quaternion::x_, "x")
				.def(&Quaternion::y_, "y")
				.def(&Quaternion::z_, "z")
				.def(&Quaternion::IDENTITY, "IDENTITY")
				
		];
	}
}

