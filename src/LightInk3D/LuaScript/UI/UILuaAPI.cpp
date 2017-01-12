

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

	extern void bind_class_BorderImage(LuaModele & lm);
	extern void bind_class_Button(LuaModele & lm);
	extern void bind_class_CheckBox(LuaModele & lm);
	extern void bind_class_Cursor(LuaModele & lm);
	extern void bind_class_DropDownList(LuaModele & lm);
	extern void bind_class_FileSelector(LuaModele & lm);
	extern void bind_class_Font(LuaModele & lm);
	extern void bind_class_LineEdit(LuaModele & lm);
	extern void bind_class_ListView(LuaModele & lm);
	extern void bind_class_Menu(LuaModele & lm);
	extern void bind_class_MessageBox(LuaModele & lm);
	extern void bind_class_ScrollBar(LuaModele & lm);
	extern void bind_class_ScrollView(LuaModele & lm);
	extern void bind_class_Slider(LuaModele & lm);
	extern void bind_class_Sprite(LuaModele & lm);
	extern void bind_class_Text(LuaModele & lm);
	extern void bind_class_Text3D(LuaModele & lm);
	extern void bind_class_ToolTip(LuaModele & lm);
	extern void bind_class_UI(LuaModele & lm);
	extern void bind_class_View3D(LuaModele & lm);
	extern void bind_class_Window(LuaModele & lm);
	extern void bind_class_UIElement(LuaModele & lm);
	

	void bind_ui_module(lua_State * lua, Context * context)
	{
		lua_pushvalue(lua, LUA_GLOBALSINDEX);
		LuaRef lrf(lua, true);
		
		LuaModele lm(lua, "LightInk3D__", lrf);
		
		bind_class_UIElement(lm);

		bind_class_BorderImage(lm);
		bind_class_Button(lm);
		bind_class_CheckBox(lm);
		bind_class_Cursor(lm);

		bind_class_Menu(lm);
		bind_class_DropDownList(lm);
		bind_class_FileSelector(lm);

		bind_class_Font(lm);
		bind_class_LineEdit(lm);

		bind_class_ScrollView(lm);
		bind_class_ListView(lm);

		bind_class_MessageBox(lm);
		bind_class_ScrollBar(lm);

		bind_class_Slider(lm);
		bind_class_Sprite(lm);
		bind_class_Text(lm);
		bind_class_Text3D(lm);
		bind_class_ToolTip(lm);
		bind_class_UI(lm);

		bind_class_Window(lm);
		bind_class_View3D(lm);
		

		// [Enum] CursorShape
		lrf["CS_NORMAL"] = CS_NORMAL;
		lrf["CS_IBEAM"] = CS_IBEAM;
		lrf["CS_CROSS"] = CS_CROSS;
		lrf["CS_RESIZEVERTICAL"] = CS_RESIZEVERTICAL;
		lrf["CS_RESIZEDIAGONAL_TOPRIGHT"] = CS_RESIZEDIAGONAL_TOPRIGHT;
		lrf["CS_RESIZEHORIZONTAL"] = CS_RESIZEHORIZONTAL;
		lrf["CS_RESIZEDIAGONAL_TOPLEFT"] = CS_RESIZEDIAGONAL_TOPLEFT;
		lrf["CS_RESIZE_ALL"] = CS_RESIZE_ALL;
		lrf["CS_ACCEPTDROP"] = CS_ACCEPTDROP;
		lrf["CS_REJECTDROP"] = CS_REJECTDROP;
		lrf["CS_BUSY"] = CS_BUSY;
		lrf["CS_BUSY_ARROW"] = CS_BUSY_ARROW;
		lrf["CS_MAX_SHAPES"] = CS_MAX_SHAPES;
		
		
		// [Enum] HighlightMode
		lrf["HM_NEVER"] = HM_NEVER;
		lrf["HM_FOCUS"] = HM_FOCUS;
		lrf["HM_ALWAYS"] = HM_ALWAYS;
		
		// [Constant] const int DEFAULT_FONT_SIZE
		lrf["DEFAULT_FONT_SIZE"] = DEFAULT_FONT_SIZE;

		// [Enum] TextEffect
		lrf["TE_NONE"] = TE_NONE;
		lrf["TE_SHADOW"] = TE_SHADOW;
		lrf["TE_STROKE"] = TE_STROKE;
		
		
		// [Enum] HorizontalAlignment
		lrf["HA_LEFT"] = HA_LEFT;
		lrf["HA_CENTER"] = HA_CENTER;
		lrf["HA_RIGHT"] = HA_RIGHT;

		// [Enum] VerticalAlignment
		lrf["VA_TOP"] = VA_TOP;
		lrf["VA_CENTER"] = VA_CENTER;
		lrf["VA_BOTTOM"] = VA_BOTTOM;

		// [Enum] Corner
		lrf["C_TOPLEFT"] = C_TOPLEFT;
		lrf["C_TOPRIGHT"] = C_TOPRIGHT;
		lrf["C_BOTTOMLEFT"] = C_BOTTOMLEFT;
		lrf["C_BOTTOMRIGHT"] = C_BOTTOMRIGHT;
		lrf["MAX_UIELEMENT_CORNERS"] = MAX_UIELEMENT_CORNERS;

		// [Enum] Orientation
		lrf["O_HORIZONTAL"] = O_HORIZONTAL;
		lrf["O_VERTICAL"] = O_VERTICAL;

		// [Enum] FocusMode
		lrf["FM_NOTFOCUSABLE"] = FM_NOTFOCUSABLE;
		lrf["FM_RESETFOCUS"] = FM_RESETFOCUS;
		lrf["FM_FOCUSABLE"] = FM_FOCUSABLE;
		lrf["FM_FOCUSABLE_DEFOCUSABLE"] = FM_FOCUSABLE_DEFOCUSABLE;

		// [Enum] LayoutMode
		lrf["LM_FREE"] = LM_FREE;
		lrf["LM_HORIZONTAL"] = LM_HORIZONTAL;
		lrf["LM_VERTICAL"] = LM_VERTICAL;

		// [Enum] TraversalMode
		lrf["TM_BREADTH_FIRST"] = TM_BREADTH_FIRST;
		lrf["TM_DEPTH_FIRST"] = TM_DEPTH_FIRST;

		// [Constant] unsigned DD_DISABLED
		lrf["DD_DISABLED"] = DD_DISABLED;
		// [Constant] unsigned DD_SOURCE
		lrf["DD_SOURCE"] = DD_SOURCE;
		// [Constant] unsigned DD_TARGET
		lrf["DD_TARGET"] = DD_TARGET;
		// [Constant] unsigned DD_SOURCE_AND_TARGET
		lrf["DD_SOURCE_AND_TARGET"] = DD_SOURCE_AND_TARGET;
		
		
		// [Enum] WindowDragMode
		lrf["DRAG_NONE"] = DRAG_NONE;
		lrf["DRAG_MOVE"] = DRAG_MOVE;
		lrf["DRAG_RESIZE_TOPLEFT"] = DRAG_RESIZE_TOPLEFT;
		lrf["DRAG_RESIZE_TOP"] = DRAG_RESIZE_TOP;
		lrf["DRAG_RESIZE_TOPRIGHT"] = DRAG_RESIZE_TOPRIGHT;
		lrf["DRAG_RESIZE_RIGHT"] = DRAG_RESIZE_RIGHT;
		lrf["DRAG_RESIZE_BOTTOMRIGHT"] = DRAG_RESIZE_BOTTOMRIGHT;
		lrf["DRAG_RESIZE_BOTTOM"] = DRAG_RESIZE_BOTTOM;
		lrf["DRAG_RESIZE_BOTTOMLEFT"] = DRAG_RESIZE_BOTTOMLEFT;
		lrf["DRAG_RESIZE_LEFT"] = DRAG_RESIZE_LEFT;
		

		lrf["ui"] = GetSubsystem<UI>(context);
		LuaDefAutoTool::def(lua, GetSubsystem<UI>, "GetUI");
}

