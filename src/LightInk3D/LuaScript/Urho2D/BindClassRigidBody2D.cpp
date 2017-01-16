

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
#include "Urho2D/RigidBody2D.h"
#include "LuaScript/LuaUtils.h"
#include "LuaEngine/LuaEngine.h"

namespace Urho3D
{
	using namespace LightInk;
	void bind_class_RigidBody2D(LuaModule & lm)
	{
		lm
		[
			LuaRegister<RigidBody2D, void ()>(lm.state(), "RigidBody2D", BaseClassStrategy<Component>())
				.disable_new()
				.def(CreateObject<RigidBody2D>, "new")
				.def(&RigidBody2D::SetBodyType, "SetBodyType")
				.def(&RigidBody2D::SetMass, "SetMass")
				.def(&RigidBody2D::SetInertia, "SetInertia")
				.def(&RigidBody2D::SetMassCenter, "SetMassCenter")
				.def(&RigidBody2D::SetUseFixtureMass, "SetUseFixtureMass")
				.def(&RigidBody2D::SetLinearDamping, "SetLinearDamping")
				.def(&RigidBody2D::SetAngularDamping, "SetAngularDamping")
				.def(&RigidBody2D::SetAllowSleep, "SetAllowSleep")
				.def(&RigidBody2D::SetFixedRotation, "SetFixedRotation")
				.def(&RigidBody2D::SetBullet, "SetBullet")
				.def(&RigidBody2D::SetGravityScale, "SetGravityScale")
				.def(&RigidBody2D::SetAwake, "SetAwake")
				.def(&RigidBody2D::SetLinearVelocity, "SetLinearVelocity")
				.def(&RigidBody2D::SetAngularVelocity, "SetAngularVelocity")
				.def(&RigidBody2D::ApplyForce, "ApplyForce")
				.def(&RigidBody2D::ApplyForceToCenter, "ApplyForceToCenter")
				.def(&RigidBody2D::ApplyTorque, "ApplyTorque")
				.def(&RigidBody2D::ApplyLinearImpulse, "ApplyLinearImpulse")
				.def(&RigidBody2D::ApplyAngularImpulse, "ApplyAngularImpulse")
				.def(&RigidBody2D::GetBodyType, "GetBodyType")
				.def(&RigidBody2D::GetMass, "GetMass")
				.def(&RigidBody2D::GetInertia, "GetInertia")
				.def(&RigidBody2D::GetMassCenter, "GetMassCenter")
				.def(&RigidBody2D::GetUseFixtureMass, "GetUseFixtureMass")
				.def(&RigidBody2D::GetLinearDamping, "GetLinearDamping")
				.def(&RigidBody2D::GetAngularDamping, "GetAngularDamping")
				.def(&RigidBody2D::IsAllowSleep, "IsAllowSleep")
				.def(&RigidBody2D::IsFixedRotation, "IsFixedRotation")
				.def(&RigidBody2D::IsBullet, "IsBullet")
				.def(&RigidBody2D::GetGravityScale, "GetGravityScale")
				.def(&RigidBody2D::IsAwake, "IsAwake")
				.def(&RigidBody2D::GetLinearVelocity, "GetLinearVelocity")
				.def(&RigidBody2D::GetAngularVelocity, "GetAngularVelocity")
				
		];
	}
}
