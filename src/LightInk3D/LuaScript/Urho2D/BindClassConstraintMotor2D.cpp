

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
#include "Urho2D/ConstraintMotor2D.h"
#include "LuaScript/LuaUtils.h"
#include "LuaEngine/LuaEngine.h"

namespace Urho3D
{
	using namespace LightInk;
	void bind_class_ConstraintMotor2D(LuaModele & lm)
	{
		lm
		[
			LuaRegister<ConstraintMotor2D, void ()>(lm.state(), "ConstraintMotor2D", BaseClassStrategy<Constraint2D>())
				.disable_new()
				.def(CreateObject<ConstraintMotor2D>, "new")
				.def(&ConstraintMotor2D::SetLinearOffset, "SetLinearOffset")
				.def(&ConstraintMotor2D::SetAngularOffset, "SetAngularOffset")
				.def(&ConstraintMotor2D::SetMaxForce, "SetMaxForce")
				.def(&ConstraintMotor2D::SetMaxTorque, "SetMaxTorque")
				.def(&ConstraintMotor2D::SetCorrectionFactor, "SetCorrectionFactor")
				.def(&ConstraintMotor2D::GetAngularOffset, "GetAngularOffset")
				.def(&ConstraintMotor2D::GetMaxForce, "GetMaxForce")
				.def(&ConstraintMotor2D::GetMaxTorque, "GetMaxTorque")
				.def(&ConstraintMotor2D::GetCorrectionFactor, "GetCorrectionFactor")
				
		];
	}
}
