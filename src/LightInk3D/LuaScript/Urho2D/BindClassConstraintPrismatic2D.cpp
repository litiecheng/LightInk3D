

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
#include "Urho2D/ConstraintPrismatic2D.h"
#include "LuaScript/LuaUtils.h"
#include "LuaEngine/LuaEngine.h"

namespace Urho3D
{
	using namespace LightInk;
	void bind_class_ConstraintPrismatic2D(LuaModele & lm)
	{
		lm
		[
			LuaRegister<ConstraintPrismatic2D, void ()>(lm.state(), "ConstraintPrismatic2D", BaseClassStrategy<Constraint2D>())
				.disable_new()
				.def(CreateObject<ConstraintPrismatic2D>, "new")
				.def(&ConstraintPrismatic2D::SetAnchor, "SetAnchor")
				.def(&ConstraintPrismatic2D::SetAxis, "SetAxis")
				.def(&ConstraintPrismatic2D::SetEnableLimit, "SetEnableLimit")
				.def(&ConstraintPrismatic2D::SetLowerTranslation, "SetLowerTranslation")
				.def(&ConstraintPrismatic2D::SetUpperTranslation, "SetUpperTranslation")
				.def(&ConstraintPrismatic2D::SetEnableMotor, "SetEnableMotor")
				.def(&ConstraintPrismatic2D::SetMaxMotorForce, "SetMaxMotorForce")
				.def(&ConstraintPrismatic2D::SetMotorSpeed, "SetMotorSpeed")
				.def(&ConstraintPrismatic2D::GetAnchor, "GetAnchor")
				.def(&ConstraintPrismatic2D::GetAxis, "GetAxis")
				.def(&ConstraintPrismatic2D::GetEnableLimit, "GetEnableLimit")
				.def(&ConstraintPrismatic2D::GetLowerTranslation, "GetLowerTranslation")
				.def(&ConstraintPrismatic2D::GetUpperTranslation, "GetUpperTranslation")
				.def(&ConstraintPrismatic2D::GetEnableMotor, "GetEnableMotor")
				.def(&ConstraintPrismatic2D::GetMaxMotorForce, "GetMaxMotorForce")
				.def(&ConstraintPrismatic2D::GetMotorSpeed, "GetMotorSpeed")
				
				
		];
	}
}
