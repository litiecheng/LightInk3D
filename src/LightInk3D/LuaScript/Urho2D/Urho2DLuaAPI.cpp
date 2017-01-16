

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

	extern void bind_class_Drawable2D(LuaModule & lm); 
	extern void bind_class_StaticSprite2D(LuaModule & lm);
	extern void bind_class_CollisionShape2D(LuaModule & lm);
	extern void bind_class_Constraint2D(LuaModule & lm);
	extern void bind_class_AnimatedSprite2D(LuaModule & lm);
	extern void bind_class_AnimationSet2D(LuaModule & lm);
	extern void bind_class_CollisionBox2D(LuaModule & lm);
	extern void bind_class_CollisionChain2D(LuaModule & lm);
	extern void bind_class_CollisionCircle2D(LuaModule & lm);
	extern void bind_class_CollisionEdge2D(LuaModule & lm);
	extern void bind_class_CollisionPolygon2D(LuaModule & lm);
	extern void bind_class_ConstraintDistance2D(LuaModule & lm);
	extern void bind_class_ConstraintFriction2D(LuaModule & lm);
	extern void bind_class_ConstraintGear2D(LuaModule & lm);
	extern void bind_class_ConstraintMotor2D(LuaModule & lm);
	extern void bind_class_ConstraintMouse2D(LuaModule & lm);
	extern void bind_class_ConstraintPrismatic2D(LuaModule & lm);
	extern void bind_class_ConstraintPulley2D(LuaModule & lm);
	extern void bind_class_ConstraintRevolute2D(LuaModule & lm);
	extern void bind_class_ConstraintRope2D(LuaModule & lm);
	extern void bind_class_ConstraintWeld2D(LuaModule & lm);
	extern void bind_class_ConstraintWheel2D(LuaModule & lm);
	extern void bind_class_ParticleEffect2D(LuaModule & lm);
	extern void bind_class_ParticleEmitter2D(LuaModule & lm);
	extern void bind_class_PhysicsWorld2D(LuaModule & lm);
	extern void bind_class_RigidBody2D(LuaModule & lm);
	extern void bind_class_Sprite2D(LuaModule & lm);
	extern void bind_class_SpriteSheet2D(LuaModule & lm);
	extern void bind_class_TileMap2D(LuaModule & lm);
	extern void bind_class_TileMapDefs2D(LuaModule & lm);
	extern void bind_class_TileMapLayer2D(LuaModule & lm);
	extern void bind_class_TmxFile2D(LuaModule & lm);
	

	void bind_urho2d_module(lua_State * lua, Context * context)
	{
		lua_pushvalue(lua, LUA_GLOBALSINDEX);
		LuaRef lrf(lua, true);
		
		LuaModule lm(lua, "LightInk3D__", lrf);
		
		bind_class_Drawable2D(lm); 
		bind_class_StaticSprite2D(lm);
		bind_class_CollisionShape2D(lm);
		bind_class_Constraint2D(lm);

		bind_class_AnimatedSprite2D(lm);
		bind_class_AnimationSet2D(lm);
		bind_class_CollisionBox2D(lm);
		bind_class_CollisionChain2D(lm);
		bind_class_CollisionCircle2D(lm);
		bind_class_CollisionEdge2D(lm);
		bind_class_CollisionPolygon2D(lm);
		bind_class_ConstraintDistance2D(lm);
		bind_class_ConstraintFriction2D(lm);
		bind_class_ConstraintGear2D(lm);
		bind_class_ConstraintMotor2D(lm);
		bind_class_ConstraintMouse2D(lm);
		bind_class_ConstraintPrismatic2D(lm);
		bind_class_ConstraintPulley2D(lm);
		bind_class_ConstraintRevolute2D(lm);
		bind_class_ConstraintRope2D(lm);
		bind_class_ConstraintWeld2D(lm);
		bind_class_ConstraintWheel2D(lm);
		bind_class_ParticleEffect2D(lm);
		bind_class_ParticleEmitter2D(lm);
		bind_class_PhysicsWorld2D(lm);
		bind_class_RigidBody2D(lm);
		bind_class_Sprite2D(lm);
		bind_class_SpriteSheet2D(lm);
		bind_class_TileMap2D(lm);
		bind_class_TileMapDefs2D(lm);
		bind_class_TileMapLayer2D(lm);
		bind_class_TmxFile2D(lm);
		
		// [Enum] LoopMode2D
		lrf["LM_DEFAULT"] = LM_DEFAULT;
		lrf["LM_FORCE_LOOPED"] = LM_FORCE_LOOPED;
		lrf["LM_FORCE_CLAMPED"] = LM_FORCE_CLAMPED;
		
		// [Constant] float PIXEL_SIZE
		lrf["PIXEL_SIZE"] = PIXEL_SIZE;
		
		// [Enum] EmitterType2D
		lrf["EMITTER_TYPE_GRAVITY"] = EMITTER_TYPE_GRAVITY;
		lrf["EMITTER_TYPE_RADIAL"] = EMITTER_TYPE_RADIAL;
		
		// [Enum] TileMapLayerType2D
		lrf["LT_TILE_LAYER"] = LT_TILE_LAYER;
		lrf["LT_OBJECT_GROUP"] = LT_OBJECT_GROUP;
		lrf["LT_IMAGE_LAYER"] = LT_IMAGE_LAYER;
		lrf["LT_INVALID"] = LT_INVALID;

		// [Enum] TileMapObjectType2D
		lrf["OT_RECTANGLE"] = OT_RECTANGLE;
		lrf["OT_ELLIPSE"] = OT_ELLIPSE;
		lrf["OT_POLYGON"] = OT_POLYGON;
		lrf["OT_POLYLINE"] = OT_POLYLINE;
		lrf["OT_TILE"] = OT_TILE;
		lrf["OT_INVALID"] = OT_INVALID;
		
		// [Enum] Orientation2D
		lrf["O_ORTHOGONAL"] = O_ORTHOGONAL;
		lrf["O_ISOMETRIC"] = O_ISOMETRIC;
		lrf["O_STAGGERED"] = O_STAGGERED;
		lrf["O_HEXAGONAL"] = O_HEXAGONAL;
		

}

