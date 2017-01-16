

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

 

#include "../Precompiled.h"
#include "LuaEngine/LuaEngine.h"


namespace Urho3D
{
	using namespace LightInk;

	extern void bind_class_AnimatedModel(LuaModule & lm);
	extern void bind_class_Animation(LuaModule & lm);
	extern void bind_class_AnimationController(LuaModule & lm);
	extern void bind_class_AnimationState(LuaModule & lm);
	extern void bind_class_BillboardSet(LuaModule & lm);
	extern void bind_class_Camera(LuaModule & lm);
	extern void bind_class_CustomGeometry(LuaModule & lm);
	extern void bind_class_DebugRenderer(LuaModule & lm);
	extern void bind_class_DecalSet(LuaModule & lm);
	extern void bind_class_Drawable(LuaModule & lm);
	extern void bind_class_Geometry(LuaModule & lm);
	extern void bind_class_Graphics(LuaModule & lm);
	extern void bind_class_GraphicsDefs(LuaModule & lm);
	extern void bind_class_IndexBuffer(LuaModule & lm);
	extern void bind_class_Light(LuaModule & lm);
	extern void bind_class_Material(LuaModule & lm);
	extern void bind_class_Model(LuaModule & lm);
	extern void bind_class_Octree(LuaModule & lm);
	extern void bind_class_OctreeQuery(LuaModule & lm);
	extern void bind_class_ParticleEffect(LuaModule & lm);
	extern void bind_class_ParticleEmitter(LuaModule & lm);
	extern void bind_class_Renderer(LuaModule & lm);
	extern void bind_class_RenderPath(LuaModule & lm);
	extern void bind_class_RenderSurface(LuaModule & lm);
	extern void bind_class_RibbonTrail(LuaModule & lm);
	extern void bind_class_Skeleton(LuaModule & lm);
	extern void bind_class_Skybox(LuaModule & lm);
	extern void bind_class_StaticModel(LuaModule & lm);
	extern void bind_class_StaticModelGroup(LuaModule & lm);
	extern void bind_class_Technique(LuaModule & lm);
	extern void bind_class_Terrain(LuaModule & lm);
	extern void bind_class_TerrainPatch(LuaModule & lm);
	extern void bind_class_Texture(LuaModule & lm);
	extern void bind_class_Texture2D(LuaModule & lm);
	extern void bind_class_Texture2DArray(LuaModule & lm);
	extern void bind_class_Texture3D(LuaModule & lm);
	extern void bind_class_TextureCube(LuaModule & lm);
	extern void bind_class_VertexBuffer(LuaModule & lm);
	extern void bind_class_Viewport(LuaModule & lm);
	extern void bind_class_Zone(LuaModule & lm);

	void bind_graphics_module(lua_State * lua, Context * context)
	{
		lua_pushvalue(lua, LUA_GLOBALSINDEX);
		LuaRef lrf(lua, true);
		
		LuaModule lm(lua, "LightInk3D__", lrf);
		
		bind_class_Camera(lm);
		bind_class_Geometry(lm);
		bind_class_Material(lm);
		bind_class_DebugRenderer(lm);
		bind_class_Graphics(lm);
		bind_class_GraphicsDefs(lm);
		bind_class_IndexBuffer(lm);
		bind_class_Renderer(lm);
		bind_class_RenderPath(lm);
		bind_class_RenderSurface(lm);
		bind_class_Technique(lm);
		bind_class_Texture(lm);
		bind_class_Texture2D(lm);
		bind_class_Texture2DArray(lm);
		bind_class_Texture3D(lm);
		bind_class_TextureCube(lm);
		bind_class_VertexBuffer(lm);
		bind_class_Viewport(lm); 
		
		bind_class_Animation(lm);
		bind_class_AnimationController(lm);
		bind_class_AnimationState(lm);
		bind_class_Model(lm);
		bind_class_Octree(lm);
		bind_class_OctreeQuery(lm);
		bind_class_ParticleEffect(lm);
		bind_class_Skeleton(lm);
		bind_class_Terrain(lm);

		bind_class_Drawable(lm);
		bind_class_StaticModel(lm);

		bind_class_AnimatedModel(lm);
		bind_class_BillboardSet(lm);
		bind_class_CustomGeometry(lm);
		bind_class_DecalSet(lm);
		bind_class_Light(lm);
		bind_class_ParticleEmitter(lm);
		bind_class_RibbonTrail(lm);
		bind_class_Skybox(lm);
		bind_class_StaticModelGroup(lm);
		bind_class_TerrainPatch(lm);
		bind_class_Zone(lm);

		
		// [Constant] unsigned char CHANNEL_POSITION
		lrf["CHANNEL_POSITION"] = CHANNEL_POSITION;
		// [Constant] unsigned char CHANNEL_ROTATION
		lrf["CHANNEL_ROTATION"] = CHANNEL_ROTATION;
		// [Constant] unsigned char CHANNEL_SCALE
		lrf["CHANNEL_SCALE"] = CHANNEL_SCALE;
		
		// [Enum] AnimationBlendMode
		lrf["ABM_LERP"] = ABM_LERP;
		lrf["ABM_ADDITIVE"] = ABM_ADDITIVE;
		
		// [Constant] unsigned DRAWABLE_GEOMETRY
		lrf["DRAWABLE_GEOMETRY"] = DRAWABLE_GEOMETRY;
		// [Constant] unsigned DRAWABLE_LIGHT
		lrf["DRAWABLE_LIGHT"] = DRAWABLE_LIGHT;
		// [Constant] unsigned DRAWABLE_ZONE
		lrf["DRAWABLE_ZONE"] = DRAWABLE_ZONE;
		// [Constant] unsigned DRAWABLE_GEOMETRY2D
		lrf["DRAWABLE_GEOMETRY2D"] = DRAWABLE_GEOMETRY2D;
		// [Constant] unsigned DRAWABLE_ANY
		lrf["DRAWABLE_ANY"] = DRAWABLE_ANY;
		// [Constant] unsigned DEFAULT_VIEWMASK
		lrf["DEFAULT_VIEWMASK"] = DEFAULT_VIEWMASK;
		// [Constant] unsigned DEFAULT_LIGHTMASK
		lrf["DEFAULT_LIGHTMASK"] = DEFAULT_LIGHTMASK;
		// [Constant] unsigned DEFAULT_SHADOWMASK
		lrf["DEFAULT_SHADOWMASK"] = DEFAULT_SHADOWMASK;
		// [Constant] unsigned DEFAULT_ZONEMASK
		lrf["DEFAULT_ZONEMASK"] = DEFAULT_ZONEMASK;
		// [Constant] int MAX_VERTEX_LIGHTS
		lrf["MAX_VERTEX_LIGHTS"] = MAX_VERTEX_LIGHTS;
		// [Constant] float ANIMATION_LOD_BASESCALE
		lrf["ANIMATION_LOD_BASESCALE"] = ANIMATION_LOD_BASESCALE;
		
		
		// [Enum] LightType
		lrf["LIGHT_DIRECTIONAL"] = LIGHT_DIRECTIONAL;
		lrf["LIGHT_SPOT"] = LIGHT_SPOT;
		lrf["LIGHT_POINT"] = LIGHT_POINT;

		// [Constant] float SHADOW_MIN_QUANTIZE
		lrf["SHADOW_MIN_QUANTIZE"] = SHADOW_MIN_QUANTIZE;
		// [Constant] float SHADOW_MIN_VIEW
		lrf["SHADOW_MIN_VIEW"] = SHADOW_MIN_VIEW;
		// [Constant] int MAX_LIGHT_SPLITS
		lrf["MAX_LIGHT_SPLITS"] = MAX_LIGHT_SPLITS;
		// [Constant] unsigned MAX_CASCADE_SPLITS
		lrf["MAX_CASCADE_SPLITS"] = MAX_CASCADE_SPLITS;
		
		// [Constant] unsigned char DEFAULT_RENDER_ORDER
		lrf["DEFAULT_RENDER_ORDER"] = DEFAULT_RENDER_ORDER;
		
		
		// [Enum] RayQueryLevel
		lrf["RAY_AABB"] = RAY_AABB;
		lrf["RAY_OBB"] = RAY_OBB;
		lrf["RAY_TRIANGLE"] = RAY_TRIANGLE;
		lrf["RAY_TRIANGLE_UV"] = RAY_TRIANGLE_UV;
		
		// [Enum] EmitterType
		lrf["EMITTER_SPHERE"] = EMITTER_SPHERE;
		lrf["EMITTER_BOX"] = EMITTER_BOX;
		
		
		// [Enum] RenderCommandType
		lrf["CMD_NONE"] = CMD_NONE;
		lrf["CMD_CLEAR"] = CMD_CLEAR;
		lrf["CMD_SCENEPASS"] = CMD_SCENEPASS;
		lrf["CMD_QUAD"] = CMD_QUAD;
		lrf["CMD_FORWARDLIGHTS"] = CMD_FORWARDLIGHTS;
		lrf["CMD_LIGHTVOLUMES"] = CMD_LIGHTVOLUMES;
		lrf["CMD_RENDERUI"] = CMD_RENDERUI;
		lrf["CMD_SENDEVENT"] = CMD_SENDEVENT;

		// [Enum] RenderCommandSortMode
		lrf["SORT_FRONTTOBACK"] = SORT_FRONTTOBACK;
		lrf["SORT_BACKTOFRONT"] = SORT_BACKTOFRONT;

		// [Enum] RenderTargetSizeMode
		lrf["SIZE_ABSOLUTE"] = SIZE_ABSOLUTE;
		lrf["SIZE_VIEWPORTDIVISOR"] = SIZE_VIEWPORTDIVISOR;
		lrf["SIZE_VIEWPORTMULTIPLIER"] = SIZE_VIEWPORTMULTIPLIER;
		
		// [Enum] TrailType
		lrf["TT_FACE_CAMERA"] = TT_FACE_CAMERA;
		lrf["TT_BONE"] = TT_BONE;
		
		// [Constant] unsigned BONECOLLISION_NONE
		lrf["BONECOLLISION_NONE"] = BONECOLLISION_NONE;
		// [Constant] unsigned BONECOLLISION_SPHERE
		lrf["BONECOLLISION_SPHERE"] = BONECOLLISION_SPHERE;
		// [Constant] unsigned BONECOLLISION_BOX
		lrf["BONECOLLISION_BOX"] = BONECOLLISION_BOX;
		
		
		// [Enum] PassLightingMode
		lrf["LIGHTING_UNLIT"] = LIGHTING_UNLIT;
		lrf["LIGHTING_PERVERTEX"] = LIGHTING_PERVERTEX;
		lrf["LIGHTING_PERPIXEL"] = LIGHTING_PERPIXEL;
			

		lrf["graphics"] = GetSubsystem<Graphics>(context);
		LuaDefAutoTool::def(lua, GetSubsystem<Graphics>, "GetGraphics");
		
		lrf["renderer"] = GetSubsystem<Renderer>(context);
		LuaDefAutoTool::def(lua, GetSubsystem<Renderer>, "GetRenderer");


}

