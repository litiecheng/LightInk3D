

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
#include "Graphics/Model.h"
#include "Math/Ray.h"
#include "Physics/CollisionShape.h"
#include "Physics/PhysicsWorld.h"
#include "Physics/RigidBody.h"
#include "LuaScript/LuaUtils.h"
#include "LuaEngine/LuaEngine.h"

namespace Urho3D
{
	using namespace LightInk;
	static PODVector<PhysicsRaycastResult> PhysicsWorldRaycast(PhysicsWorld* self, const Ray& ray, float maxDistance, unsigned int collisionMask = M_MAX_UNSIGNED)
	{
		PODVector<PhysicsRaycastResult> result;
		self->Raycast(result, ray, maxDistance, collisionMask);
		return result;
	}
	static PhysicsRaycastResult PhysicsWorldRaycastSingle(PhysicsWorld* self, const Ray& ray, float maxDistance, unsigned int collisionMask = M_MAX_UNSIGNED)
	{
		PhysicsRaycastResult result;
		self->RaycastSingle(result, ray, maxDistance, collisionMask);
		return result;
	}
	static PhysicsRaycastResult PhysicsWorldRaycastSingleSegmented(PhysicsWorld* self, const Ray& ray, float maxDistance, float segmentDistance, unsigned int collisionMask = M_MAX_UNSIGNED)
	{
		PhysicsRaycastResult result;
		self->RaycastSingleSegmented(result, ray, maxDistance, segmentDistance, collisionMask);
		return result;
	}
	static PhysicsRaycastResult PhysicsWorldSphereCast(PhysicsWorld* self, const Ray& ray, float radius, float maxDistance, unsigned int collisionMask = M_MAX_UNSIGNED)
	{
		PhysicsRaycastResult result;
		self->SphereCast(result, ray, radius, maxDistance, collisionMask);
		return result;
	}
	static PhysicsRaycastResult PhysicsWorldConvexCast(PhysicsWorld* self, CollisionShape* shape, const Vector3& startPos, const Quaternion& startRot, const Vector3& endPos, const Quaternion& endRot, unsigned int collisionMask = M_MAX_UNSIGNED)
	{
		PhysicsRaycastResult result;
		self->ConvexCast(result, shape, startPos, startRot, endPos, endRot, collisionMask);
		return result;
	}
	static PODVector<RigidBody*> PhysicsWorldGetRigidBodiesSU(PhysicsWorld* self, const Sphere& sphere, unsigned int collisionMask = M_MAX_UNSIGNED)
	{
		PODVector<RigidBody*> result;
		self->GetRigidBodies(result, sphere, collisionMask);
		return result;
	}
	static PODVector<RigidBody*> PhysicsWorldGetRigidBodiesBU(PhysicsWorld* self, const BoundingBox& box, unsigned int collisionMask = M_MAX_UNSIGNED)
	{
		PODVector<RigidBody*> result;
		self->GetRigidBodies(result, box, collisionMask);
		return result;
	}
	static PODVector<RigidBody*> PhysicsWorldGetCollidingBodies(PhysicsWorld* self, const RigidBody* body)
	{
		PODVector<RigidBody*> result;
		self->GetCollidingBodies(result, body);
		return result;
	}
	
	void bind_class_PhysicsWorld(LuaModule & lm)
	{
		lm
		[
			LuaRegister<PhysicsWorld, void ()>(lm.state(), "PhysicsWorld", BaseClassStrategy<Component>())
				.disable_new()
				.def(CreateObject<PhysicsWorld>, "new")
				.def(static_cast<void(PhysicsWorld::*)(bool)>(&PhysicsWorld::DrawDebugGeometry), "DrawDebugGeometry")
				.def(&PhysicsWorld::SetFps, "SetFps")
				.def(&PhysicsWorld::SetGravity, "SetGravity")
				.def(&PhysicsWorld::SetMaxSubSteps, "SetMaxSubSteps")
				.def(&PhysicsWorld::SetNumIterations, "SetNumIterations")
				.def(&PhysicsWorld::SetUpdateEnabled, "SetUpdateEnabled")
				.def(&PhysicsWorld::SetInterpolation, "SetInterpolation")
				.def(&PhysicsWorld::SetInternalEdge, "SetInternalEdge")
				.def(&PhysicsWorld::SetSplitImpulse, "SetSplitImpulse")
				.def(&PhysicsWorld::SetMaxNetworkAngularVelocity, "SetMaxNetworkAngularVelocity")
				.def(PhysicsWorldRaycast, "Raycast")
				.def(PhysicsWorldRaycastSingle, "RaycastSingle")
				.def(PhysicsWorldRaycastSingleSegmented, "RaycastSingleSegmented")
				.def(PhysicsWorldSphereCast, "SphereCast")
				.def(PhysicsWorldConvexCast, "ConvexCast")
				.def(&PhysicsWorld::RemoveCachedGeometry, "RemoveCachedGeometry")
				.def(PhysicsWorldGetRigidBodiesSU, "GetRigidBodiesSU")
				.def(PhysicsWorldGetRigidBodiesBU, "GetRigidBodiesBU")
				.def(PhysicsWorldGetCollidingBodies, "GetCollidingBodies")
				.def(&PhysicsWorld::GetGravity, "GetGravity")
				.def(&PhysicsWorld::GetMaxSubSteps, "GetMaxSubSteps")
				.def(&PhysicsWorld::GetNumIterations, "GetNumIterations")
				.def(&PhysicsWorld::IsUpdateEnabled, "IsUpdateEnabled")
				.def(&PhysicsWorld::GetInterpolation, "GetInterpolation")
				.def(&PhysicsWorld::GetInternalEdge, "GetInternalEdge")
				.def(&PhysicsWorld::GetSplitImpulse, "GetSplitImpulse")
				.def(&PhysicsWorld::GetFps, "GetFps")
				.def(&PhysicsWorld::GetMaxNetworkAngularVelocity, "GetMaxNetworkAngularVelocity")
			<=
			LuaRegister<PhysicsRaycastResult, void ()>(lm.state(), "PhysicsRaycastResult")
				.def(&PhysicsRaycastResult::position_, "position")
				.def(&PhysicsRaycastResult::normal_, "normal")
				.def(&PhysicsRaycastResult::distance_, "distance")
				.def(&PhysicsRaycastResult::hitFraction_, "hitFraction")
				.def(&PhysicsRaycastResult::body_, "body")
		];
	}
}

#endif