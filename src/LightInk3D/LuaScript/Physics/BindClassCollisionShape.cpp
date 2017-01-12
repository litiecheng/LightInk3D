

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

#include "../../Precompiled.h"
#include "../../Graphics/CustomGeometry.h"
#include "../../Graphics/Model.h"
#include "../../Physics/CollisionShape.h"
#include "../../Physics/PhysicsWorld.h"
#include "../../LuaScript/LuaUtils.h"
#include "LuaEngine/LuaEngine.h"

namespace Urho3D
{
	using namespace LightInk;
	void bind_class_CollisionShape(LuaModele & lm)
	{
		lm
		[
			LuaRegister<CollisionShape, void ()>(lm.state(), "CollisionShape", BaseClassStrategy<Component>())
				.disable_new()
				.def(CreateObject<CollisionShape>, "new")
				.def(&CollisionShape::SetBox, "SetBox")
				.def(&CollisionShape::SetSphere, "SetSphere")
				.def(&CollisionShape::SetStaticPlane, "SetStaticPlane")
				.def(&CollisionShape::SetCylinder, "SetCylinder")
				.def(&CollisionShape::SetCapsule, "SetCapsule")
				.def(&CollisionShape::SetCone, "SetCone")
				.def(&CollisionShape::SetTriangleMesh, "SetTriangleMesh")
				.def(&CollisionShape::SetCustomTriangleMesh, "SetCustomTriangleMesh")
				.def(&CollisionShape::SetConvexHull, "SetConvexHull")
				.def(&CollisionShape::SetCustomConvexHull, "SetCustomConvexHull")
				.def(&CollisionShape::SetTerrain, "SetTerrain")
				.def(&CollisionShape::SetShapeType, "SetShapeType")
				.def(&CollisionShape::SetSize, "SetSize")
				.def(&CollisionShape::SetPosition, "SetPosition")
				.def(&CollisionShape::SetRotation, "SetRotation")
				.def(&CollisionShape::SetTransform, "SetTransform")
				.def(&CollisionShape::SetMargin, "SetMargin")
				.def(&CollisionShape::SetModel, "SetModel")
				.def(&CollisionShape::SetLodLevel, "SetLodLevel")
				.def(&CollisionShape::GetPhysicsWorld, "GetPhysicsWorld")
				.def(&CollisionShape::GetShapeType, "GetShapeType")
				.def(&CollisionShape::GetSize, "GetSize")
				.def(&CollisionShape::GetPosition, "GetPosition")
				.def(&CollisionShape::GetRotation, "GetRotation")
				.def(&CollisionShape::GetMargin, "GetMargin")
				.def(&CollisionShape::GetModel, "GetModel")
				.def(&CollisionShape::GetLodLevel, "GetLodLevel")
		];
	}
}

#endif