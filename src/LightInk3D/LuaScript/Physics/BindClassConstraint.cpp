

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
 
#ifdef URHO3D_PHYSICS

#include "Precompiled.h"
#include "Physics/Constraint.h"
#include "Physics/PhysicsWorld.h"
#include "Physics/RigidBody.h"
#include "LuaScript/LuaUtils.h"
#include "LuaEngine/LuaEngine.h"

namespace Urho3D
{
	using namespace LightInk;
	void bind_class_Constraint(LuaModule & lm)
	{
		lm
		[
			LuaRegister<Constraint, void ()>(lm.state(), "Constraint", BaseClassStrategy<Component>())
				.disable_new()
				.def(CreateObject<Constraint>, "new")
				.def(&Constraint::SetConstraintType, "SetConstraintType")
				.def(&Constraint::SetOtherBody, "SetOtherBody")
				.def(&Constraint::SetPosition, "SetPosition")
				.def(&Constraint::SetRotation, "SetRotation")
				.def(&Constraint::SetAxis, "SetAxis")
				.def(&Constraint::SetOtherPosition, "SetOtherPosition")
				.def(&Constraint::SetOtherRotation, "SetOtherRotation")
				.def(&Constraint::SetOtherAxis, "SetOtherAxis")
				.def(&Constraint::SetWorldPosition, "SetWorldPosition")
				.def(&Constraint::SetHighLimit, "SetHighLimit")
				.def(&Constraint::SetLowLimit, "SetLowLimit")
				.def(&Constraint::SetERP, "SetERP")
				.def(&Constraint::SetCFM, "SetCFM")
				.def(&Constraint::SetDisableCollision, "SetDisableCollision")
				.def(&Constraint::GetPhysicsWorld, "GetPhysicsWorld")
				.def(&Constraint::GetConstraintType, "GetConstraintType")
				.def(&Constraint::GetOwnBody, "GetOwnBody")
				.def(&Constraint::GetOtherBody, "GetOtherBody")
				.def(&Constraint::GetPosition, "GetPosition")
				.def(&Constraint::GetRotation, "GetRotation")
				.def(&Constraint::GetOtherPosition, "GetOtherPosition")
				.def(&Constraint::GetOtherRotation, "GetOtherRotation")
				.def(&Constraint::GetWorldPosition, "GetWorldPosition")
				.def(&Constraint::GetHighLimit, "GetHighLimit")
				.def(&Constraint::GetLowLimit, "GetLowLimit")
				.def(&Constraint::GetERP, "GetERP")
				.def(&Constraint::GetCFM, "GetCFM")
				.def(&Constraint::GetDisableCollision, "GetDisableCollision")
				
		];
	}
}

#endif