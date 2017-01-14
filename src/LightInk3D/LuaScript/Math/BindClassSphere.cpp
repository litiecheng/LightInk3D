

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
#include "Math/Frustum.h"
#include "Math/Polyhedron.h"
#include "Math/Sphere.h"
#include "LuaScript/LuaUtils.h"
#include "LuaEngine/LuaEngine.h"

namespace Urho3D
{
	using namespace LightInk;
	void bind_class_Sphere(LuaModele & lm)
	{
		lm
		[
			LuaRegister<Sphere, void ()>(lm.state(), "Sphere")
				.def(&Sphere::operator==, "__eq")
				.def(static_cast<void(Sphere::*)(const Sphere&)>(&Sphere::Define), "DefineS")
				.def(static_cast<void(Sphere::*)(const Vector3&, float)>(&Sphere::Define), "DefineVF")
				.def(static_cast<void(Sphere::*)(const BoundingBox&)>(&Sphere::Define), "DefineB")
				.def(static_cast<void(Sphere::*)(const Frustum&)>(&Sphere::Define), "DefineF")
				.def(static_cast<void(Sphere::*)(const Polyhedron&)>(&Sphere::Define), "DefineP")
				.def(static_cast<void(Sphere::*)(const Vector3&)>(&Sphere::Merge), "MergeV")
				.def(static_cast<void(Sphere::*)(const BoundingBox&)>(&Sphere::Merge), "MergeB")
				.def(static_cast<void(Sphere::*)(const Frustum&)>(&Sphere::Merge), "MergeF")
				.def(static_cast<void(Sphere::*)(const Polyhedron&)>(&Sphere::Merge), "MergeP")
				.def(static_cast<void(Sphere::*)(const Sphere&)>(&Sphere::Merge), "MergeS")
				.def(&Sphere::Clear, "Clear")
				.def(&Sphere::Defined, "Defined")
				.def(static_cast<Intersection(Sphere::*)(const Vector3&) const>(&Sphere::IsInside), "IsInsideV")
				.def(static_cast<Intersection(Sphere::*)(const Sphere&) const>(&Sphere::IsInside), "IsInsideS")
				.def(static_cast<Intersection(Sphere::*)(const BoundingBox&) const>(&Sphere::IsInside), "IsInsideB")
				.def(static_cast<Intersection(Sphere::*)(const Sphere&) const>(&Sphere::IsInsideFast), "IsInsideFastS")
				.def(static_cast<Intersection(Sphere::*)(const BoundingBox&) const>(&Sphere::IsInsideFast), "IsInsideFastB")
				.def(&Sphere::center_, "center")
				.def(&Sphere::radius_, "radius")

		];
	}
}

