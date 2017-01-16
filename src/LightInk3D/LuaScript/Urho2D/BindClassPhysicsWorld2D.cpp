

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
#include "Urho2D/PhysicsWorld2D.h"
#include "Urho2D/RigidBody2D.h"
#include "LuaScript/LuaUtils.h"
#include "LuaEngine/LuaEngine.h"

namespace Urho3D
{
	using namespace LightInk;
	static PODVector<PhysicsRaycastResult2D> PhysicsWorld2DRaycast(PhysicsWorld2D* self, const Vector2& startPoint, const Vector2& endPoint, unsigned int collisionMask = M_MAX_UNSIGNED)
	{
		PODVector<PhysicsRaycastResult2D> results;
		self->Raycast(results, startPoint, endPoint, collisionMask);
		return results;
	}

	static PhysicsRaycastResult2D PhysicsWorld2DRaycastSingle(PhysicsWorld2D* self, const Vector2& startPoint, const Vector2& endPoint, unsigned int collisionMask = M_MAX_UNSIGNED)
	{
		PhysicsRaycastResult2D result;
		self->RaycastSingle(result, startPoint, endPoint, collisionMask);
		return result;
	}

	static PODVector<RigidBody2D*> PhysicsWorld2DGetRigidBodies(PhysicsWorld2D* self, const Rect& aabb, unsigned int collisionMask = M_MAX_UNSIGNED)
	{
		PODVector<RigidBody2D*> result;
		self->GetRigidBodies(result, aabb, collisionMask);
		return result;
	}
	
	void bind_class_PhysicsWorld2D(LuaModule & lm)
	{
		lm
		[
			LuaRegister<PhysicsWorld2D, void ()>(lm.state(), "PhysicsWorld2D", BaseClassStrategy<Component>())
				.disable_new()
				.def(CreateObject<PhysicsWorld2D>, "new")
				.def(static_cast<void(PhysicsWorld2D::*)()>(&PhysicsWorld2D::DrawDebugGeometry), "DrawDebugGeometry")
				.def(&PhysicsWorld2D::SetUpdateEnabled, "SetUpdateEnabled")
				.def(&PhysicsWorld2D::SetDrawShape, "SetDrawShape")
				.def(&PhysicsWorld2D::SetDrawJoint, "SetDrawJoint")
				.def(&PhysicsWorld2D::SetDrawAabb, "SetDrawAabb")
				.def(&PhysicsWorld2D::SetDrawPair, "SetDrawPair")
				.def(&PhysicsWorld2D::SetDrawCenterOfMass, "SetDrawCenterOfMass")
				.def(&PhysicsWorld2D::SetAllowSleeping, "SetAllowSleeping")
				.def(&PhysicsWorld2D::SetWarmStarting, "SetWarmStarting")
				.def(&PhysicsWorld2D::SetContinuousPhysics, "SetContinuousPhysics")
				.def(&PhysicsWorld2D::SetSubStepping, "SetSubStepping")
				.def(&PhysicsWorld2D::SetGravity, "SetGravity")
				.def(&PhysicsWorld2D::SetAutoClearForces, "SetAutoClearForces")
				.def(&PhysicsWorld2D::SetVelocityIterations, "SetVelocityIterations")
				.def(&PhysicsWorld2D::SetPositionIterations, "SetPositionIterations")
				.def(PhysicsWorld2DRaycast, "Raycast")
				.def(PhysicsWorld2DRaycastSingle, "RaycastSingle")
				.def(static_cast<RigidBody2D*(PhysicsWorld2D::*)(const Vector2&, unsigned int)>(&PhysicsWorld2D::GetRigidBody), "GetRigidBodyVU")
				.def(static_cast<RigidBody2D*(PhysicsWorld2D::*)(int, int, unsigned int)>(&PhysicsWorld2D::GetRigidBody), "GetRigidBodyIIU")
				.def(PhysicsWorld2DGetRigidBodies, "GetRigidBodies")
				.def(&PhysicsWorld2D::IsUpdateEnabled, "IsUpdateEnabled")
				.def(&PhysicsWorld2D::GetDrawShape, "GetDrawShape")
				.def(&PhysicsWorld2D::GetDrawJoint, "GetDrawJoint")
				.def(&PhysicsWorld2D::GetDrawAabb, "GetDrawAabb")
				.def(&PhysicsWorld2D::GetDrawPair, "GetDrawPair")
				.def(&PhysicsWorld2D::GetDrawCenterOfMass, "GetDrawCenterOfMass")
				.def(&PhysicsWorld2D::GetAllowSleeping, "GetAllowSleeping")
				.def(&PhysicsWorld2D::GetWarmStarting, "GetWarmStarting")
				.def(&PhysicsWorld2D::GetContinuousPhysics, "GetContinuousPhysics")
				.def(&PhysicsWorld2D::GetSubStepping, "GetSubStepping")
				.def(&PhysicsWorld2D::GetAutoClearForces, "GetAutoClearForces")
				.def(&PhysicsWorld2D::GetGravity, "GetGravity")
				.def(&PhysicsWorld2D::GetVelocityIterations, "GetVelocityIterations")
				.def(&PhysicsWorld2D::GetPositionIterations, "GetPositionIterations")
			<=
			LuaRegister<PhysicsRaycastResult2D, void ()>(lm.state(), "PhysicsRaycastResult2D")
				.def(&PhysicsRaycastResult2D::position_, "position")
				.def(&PhysicsRaycastResult2D::normal_, "normal")
				.def(&PhysicsRaycastResult2D::distance_, "distance")
				.def(&PhysicsRaycastResult2D::body_, "body")

		];
	}
}
