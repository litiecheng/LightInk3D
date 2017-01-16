

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
#include "Math/BoundingBox.h"
#include "Math/Frustum.h"
#include "Math/Polyhedron.h"
#include "LuaScript/LuaUtils.h"
#include "LuaEngine/LuaEngine.h"

namespace Urho3D
{
	using namespace LightInk;
	void bind_class_Polyhedron(LuaModule & lm)
	{
		lm
		[
			LuaRegister<Polyhedron, void ()>(lm.state(), "Polyhedron")
				.def(static_cast<void(Polyhedron::*)(const BoundingBox&)>(&Polyhedron::Define), "DefineB")
				.def(static_cast<void(Polyhedron::*)(const Frustum&)>(&Polyhedron::Define), "DefineF")
				.def(static_cast<void(Polyhedron::*)(const Vector3&, const Vector3&, const Vector3&)>(&Polyhedron::AddFace), "AddFace3V")
				.def(static_cast<void(Polyhedron::*)(const Vector3&, const Vector3&, const Vector3&, const Vector3&)>(&Polyhedron::AddFace), "AddFace4V")
				.def(static_cast<void(Polyhedron::*)(const Plane&)>(&Polyhedron::Clip), "ClipP")
				.def(static_cast<void(Polyhedron::*)(const BoundingBox&)>(&Polyhedron::Clip), "ClipB")
				.def(static_cast<void(Polyhedron::*)(const Frustum&)>(&Polyhedron::Clip), "ClipF")
				.def(&Polyhedron::Clear, "Clear")
				.def(static_cast<void(Polyhedron::*)(const Matrix3&)>(&Polyhedron::Transform), "TransformM3")
				.def(static_cast<void(Polyhedron::*)(const Matrix3x4&)>(&Polyhedron::Transform), "TransformM3x4")
				.def(static_cast<Polyhedron(Polyhedron::*)(const Matrix3&) const>(&Polyhedron::Transformed), "TransformedM3")
				.def(static_cast<Polyhedron(Polyhedron::*)(const Matrix3x4&) const>(&Polyhedron::Transformed), "TransformedM3x4")
				.def(&Polyhedron::Empty, "Empty")
		];
	}
}

