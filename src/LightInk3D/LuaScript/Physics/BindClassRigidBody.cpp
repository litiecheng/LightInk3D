

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
#include "Physics/PhysicsWorld.h"
#include "Physics/RigidBody.h"
#include "LuaScript/LuaScriptUtils.h"
#include <Bullet/BulletDynamics/Dynamics/btRigidBody.h>
#include <Bullet/BulletCollision/CollisionShapes/btCompoundShape.h>
#include "LuaScript/LuaUtils.h"
#include "LuaEngine/LuaEngine.h"

namespace Urho3D
{
	using namespace LightInk;
	static PODVector<RigidBody*> RigidBodyGetCollidingBodies(RigidBody* self)
	{
		PODVector<RigidBody*> result;
		self->GetCollidingBodies(result);
		return result;
	}
	
	void bind_class_RigidBody(LuaModele & lm)
	{
		lm
		[
			LuaRegister<RigidBody, void ()>(lm.state(), "RigidBody", BaseClassStrategy<Component>())
				.disable_new()
				.def(CreateObject<RigidBody>, "new")
				.def(&RigidBody::SetMass, "SetMass")
				.def(&RigidBody::SetPosition, "SetPosition")
				.def(&RigidBody::SetRotation, "SetRotation")
				.def(&RigidBody::SetTransform, "SetTransform")
				.def(&RigidBody::SetLinearVelocity, "SetLinearVelocity")
				.def(&RigidBody::SetLinearFactor, "SetLinearFactor")
				.def(&RigidBody::SetLinearRestThreshold, "SetLinearRestThreshold")
				.def(&RigidBody::SetLinearDamping, "SetLinearDamping")
				.def(&RigidBody::SetAngularVelocity, "SetAngularVelocity")
				.def(&RigidBody::SetAngularFactor, "SetAngularFactor")
				.def(&RigidBody::SetAngularRestThreshold, "SetAngularRestThreshold")
				.def(&RigidBody::SetAngularDamping, "SetAngularDamping")
				.def(&RigidBody::SetFriction, "SetFriction")
				.def(&RigidBody::SetAnisotropicFriction, "SetAnisotropicFriction")
				.def(&RigidBody::SetRollingFriction, "SetRollingFriction")
				.def(&RigidBody::SetRestitution, "SetRestitution")
				.def(&RigidBody::SetContactProcessingThreshold, "SetContactProcessingThreshold")
				.def(&RigidBody::SetCcdRadius, "SetCcdRadius")
				.def(&RigidBody::SetCcdMotionThreshold, "SetCcdMotionThreshold")
				.def(&RigidBody::SetUseGravity, "SetUseGravity")
				.def(&RigidBody::SetGravityOverride, "SetGravityOverride")
				.def(&RigidBody::SetKinematic, "SetKinematic")
				.def(&RigidBody::SetTrigger, "SetTrigger")
				.def(&RigidBody::SetCollisionLayer, "SetCollisionLayer")
				.def(&RigidBody::SetCollisionMask, "SetCollisionMask")
				.def(&RigidBody::SetCollisionLayerAndMask, "SetCollisionLayerAndMask")
				.def(&RigidBody::SetCollisionEventMode, "SetCollisionEventMode")
				.def(static_cast<void(RigidBody::*)(const Vector3&)>(&RigidBody::ApplyForce), "ApplyForceV")
				.def(static_cast<void(RigidBody::*)(const Vector3&, const Vector3&)>(&RigidBody::ApplyForce), "ApplyForceVV")
				.def(&RigidBody::ApplyTorque, "ApplyTorque")
				.def(static_cast<void(RigidBody::*)(const Vector3&)>(&RigidBody::ApplyImpulse), "ApplyImpulseV")
				.def(static_cast<void(RigidBody::*)(const Vector3&, const Vector3&)>(&RigidBody::ApplyImpulse), "ApplyImpulseVV")
				.def(&RigidBody::ApplyTorqueImpulse, "ApplyTorqueImpulse")
				.def(&RigidBody::ResetForces, "ResetForces")
				.def(&RigidBody::Activate, "Activate")
				.def(&RigidBody::ReAddBodyToWorld, "ReAddBodyToWorld")
				.def(&RigidBody::DisableMassUpdate, "DisableMassUpdate")
				.def(&RigidBody::EnableMassUpdate, "EnableMassUpdate")
				.def(&RigidBody::GetPhysicsWorld, "GetPhysicsWorld")
				.def(&RigidBody::GetBody, "GetBody")
				.def(&RigidBody::GetCompoundShape, "GetCompoundShape")
				.def(&RigidBody::GetMass, "GetMass")
				.def(&RigidBody::GetPosition, "GetPosition")
				.def(&RigidBody::GetRotation, "GetRotation")
				.def(&RigidBody::GetLinearVelocity, "GetLinearVelocity")
				.def(&RigidBody::GetLinearFactor, "GetLinearFactor")
				.def(&RigidBody::GetVelocityAtPoint, "GetVelocityAtPoint")
				.def(&RigidBody::GetLinearRestThreshold, "GetLinearRestThreshold")
				.def(&RigidBody::GetLinearDamping, "GetLinearDamping")
				.def(&RigidBody::GetAngularVelocity, "GetAngularVelocity")
				.def(&RigidBody::GetAngularFactor, "GetAngularFactor")
				.def(&RigidBody::GetAngularRestThreshold, "GetAngularRestThreshold")
				.def(&RigidBody::GetAngularDamping, "GetAngularDamping")
				.def(&RigidBody::GetFriction, "GetFriction")
				.def(&RigidBody::GetAnisotropicFriction, "GetAnisotropicFriction")
				.def(&RigidBody::GetRollingFriction, "GetRollingFriction")
				.def(&RigidBody::GetRestitution, "GetRestitution")
				.def(&RigidBody::GetContactProcessingThreshold, "GetContactProcessingThreshold")
				.def(&RigidBody::GetCcdRadius, "GetCcdRadius")
				.def(&RigidBody::GetCcdMotionThreshold, "GetCcdMotionThreshold")
				.def(&RigidBody::GetUseGravity, "GetUseGravity")
				.def(&RigidBody::GetGravityOverride, "GetGravityOverride")
				.def(&RigidBody::GetCenterOfMass, "GetCenterOfMass")
				.def(&RigidBody::IsKinematic, "IsKinematic")
				.def(&RigidBody::IsTrigger, "IsTrigger")
				.def(&RigidBody::IsActive, "IsActive")
				.def(&RigidBody::GetCollisionLayer, "GetCollisionLayer")
				.def(&RigidBody::GetCollisionMask, "GetCollisionMask")
				.def(&RigidBody::GetCollisionEventMode, "GetCollisionEventMode")
		];
	}
}

#endif