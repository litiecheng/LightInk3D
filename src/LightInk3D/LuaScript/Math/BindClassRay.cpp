

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
#include "Math/Plane.h"
#include "Math/Ray.h"
#include "Math/Sphere.h"
#include "LuaScript/LuaUtils.h"
#include "LuaEngine/LuaEngine.h"

namespace Urho3D
{
	using namespace LightInk;
	struct RayVVF
	{
		Vector3 outNormal_;
		Vector3 outBary_;
		float distance_;
	};
	
	static RayVVF RayHitDistanceVVF(const Ray* self, const Vector3& v0, const Vector3& v1, const Vector3& v2)
	{
		RayVVF rv;
		rv.distance_ = self->HitDistance(v0, v1, v2, rv.outNormal_, rv.outBary_);
		return rv;
	}
	void bind_class_Ray(LuaModule & lm)
	{
		lm
		[
			LuaRegister<Ray, void ()>(lm.state(), "Ray")
				.def(&Ray::operator==, "__eq")
				.def(&Ray::Define, "Define")
				.def(&Ray::Project, "Project")
				.def(&Ray::Distance, "Distance")
				.def(&Ray::ClosestPoint, "ClosestPoint")
				.def(static_cast<float(Ray::*)(const Plane&) const>(&Ray::HitDistance), "HitDistanceP")
				.def(static_cast<float(Ray::*)(const BoundingBox&) const>(&Ray::HitDistance), "HitDistanceB")
				.def(static_cast<float(Ray::*)(const Frustum&, bool) const>(&Ray::HitDistance), "HitDistanceFB")
				.def(static_cast<float(Ray::*)(const Sphere&) const>(&Ray::HitDistance), "HitDistanceS")
				.def(RayHitDistanceVVF, "HitDistance3V")
				.def(&Ray::Transformed, "Transformed")
				.def(&Ray::origin_, "origin")
				.def(&Ray::direction_, "direction")
			<=
			LuaRegister<RayVVF, void ()>(lm.state(), "RayVVF")
				.def(&RayVVF::outNormal_, "outNormal")
				.def(&RayVVF::outBary_, "outBary")
				.def(&RayVVF::distance_, "distance")
		];
	}
}

