

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
#include "../../Urho2D/ConstraintRevolute2D.h"
#include "../../LuaScript/LuaUtils.h"
#include "LuaEngine/LuaEngine.h"

namespace Urho3D
{
	using namespace LightInk;
	void bind_class_ConstraintRevolute2D(LuaModele & lm)
	{
		lm
		[
			LuaRegister<ConstraintRevolute2D, void ()>(lm.state(), "ConstraintRevolute2D", BaseClassStrategy<Constraint2D>())
				.disable_new()
				.def(CreateObject<ConstraintRevolute2D>, "new")
				.def(&ConstraintRevolute2D::SetAnchor, "SetAnchor")
				.def(&ConstraintRevolute2D::SetEnableLimit, "SetEnableLimit")
				.def(&ConstraintRevolute2D::SetLowerAngle, "SetLowerAngle")
				.def(&ConstraintRevolute2D::SetUpperAngle, "SetUpperAngle")
				.def(&ConstraintRevolute2D::SetEnableMotor, "SetEnableMotor")
				.def(&ConstraintRevolute2D::SetMotorSpeed, "SetMotorSpeed")
				.def(&ConstraintRevolute2D::SetMaxMotorTorque, "SetMaxMotorTorque")
				.def(&ConstraintRevolute2D::GetAnchor, "GetAnchor")
				.def(&ConstraintRevolute2D::GetEnableLimit, "GetEnableLimit")
				.def(&ConstraintRevolute2D::GetLowerAngle, "GetLowerAngle")
				.def(&ConstraintRevolute2D::GetUpperAngle, "GetUpperAngle")
				.def(&ConstraintRevolute2D::GetEnableMotor, "GetEnableMotor")
				.def(&ConstraintRevolute2D::GetMotorSpeed, "GetMotorSpeed")
				.def(&ConstraintRevolute2D::GetMaxMotorTorque, "GetMaxMotorTorque")
				
		];
	}
}
