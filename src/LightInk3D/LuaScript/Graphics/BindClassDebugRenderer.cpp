

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
#include "Graphics/DebugRenderer.h"
#include "Graphics/Camera.h"
#include "Graphics/Skeleton.h"
#include "Math/Polyhedron.h"
#include "Scene/Node.h"
#include "LuaScript/LuaUtils.h"
#include "LuaEngine/LuaEngine.h"

namespace Urho3D
{
	using namespace LightInk;
	void bind_class_DebugRenderer(LuaModule & lm)
	{
		lm
		[
			LuaRegister<DebugRenderer, void ()>(lm.state(), "DebugRenderer", BaseClassStrategy<Component>())
				.disable_new()
				.def(CreateObject<DebugRenderer>, "new")
				.def(&DebugRenderer::SetView, "SetView")
				.def(static_cast<void(DebugRenderer::*)(const Vector3&, const Vector3&, const Color&, bool)>(&DebugRenderer::AddLine), "AddLineVVCB")
				.def(static_cast<void(DebugRenderer::*)(const Vector3&, const Vector3&, unsigned int, bool)>(&DebugRenderer::AddLine), "AddLineVVUB")
				.def(static_cast<void(DebugRenderer::*)(const Vector3&, const Vector3&, const Vector3&, const Color&, bool)>(&DebugRenderer::AddTriangle), "AddTriangleVVVCB")
				.def(static_cast<void(DebugRenderer::*)(const Vector3&, const Vector3&, const Vector3&, unsigned int, bool)>(&DebugRenderer::AddTriangle), "AddTriangleVVVUB")
				.def(&DebugRenderer::AddNode, "AddNode")
				.def(static_cast<void(DebugRenderer::*)(const BoundingBox&, const Color&, bool)>(&DebugRenderer::AddBoundingBox), "AddBoundingBoxBCB")
				.def(static_cast<void(DebugRenderer::*)(const BoundingBox&, const Matrix3x4&, const Color&, bool)>(&DebugRenderer::AddBoundingBox), "AddBoundingBoxBMCB")
				.def(&DebugRenderer::AddFrustum, "AddFrustum")
				.def(&DebugRenderer::AddPolyhedron, "AddPolyhedron")
				.def(&DebugRenderer::AddSphere, "AddSphere")
				.def(&DebugRenderer::AddCylinder, "AddCylinder")
				.def(&DebugRenderer::AddSkeleton, "AddSkeleton")
				.def(&DebugRenderer::AddTriangleMesh, "AddTriangleMesh")
				.def(&DebugRenderer::AddCircle, "AddCircle")
				.def(&DebugRenderer::AddCross, "AddCross")
				.def(&DebugRenderer::AddQuad, "AddQuad")
				.def(&DebugRenderer::Render, "Render")
				.def(&DebugRenderer::GetView, "GetView")
				.def(&DebugRenderer::GetProjection, "GetProjection")
				.def(&DebugRenderer::GetFrustum, "GetFrustum")
				.def(&DebugRenderer::IsInside, "IsInside")

		];
	}
}

