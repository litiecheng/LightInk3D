

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


#include "../../Precompiled.h"
#include "../../Input/Input.h"
#include "../../IO/File.h"
#include "../../UI/UIElement.h"
#include "../../LuaScript/LuaUtils.h"
#include "LuaEngine/LuaEngine.h"

namespace Urho3D
{
	using namespace LightInk;
	static bool InputSaveGestures(Input* self, Context * context, const String& fileName)
	{
		SharedPtr<File> file(new File(context, fileName, FILE_WRITE));
		if (!file->IsOpen())
			return false;
		return self->SaveGestures(*file);
	}

	static bool InputSaveGesture(Input* self, Context * context, const String& fileName, unsigned gestureID)
	{
		SharedPtr<File> file(new File(context, fileName, FILE_WRITE));
		if (!file->IsOpen())
			return false;
		return self->SaveGesture(*file, gestureID);
	}

	static unsigned InputLoadGestures(Input* self, Context * context, const String& fileName)
	{
		SharedPtr<File> file(new File(context, fileName));
		if (!file->IsOpen())
			return false;
		return self->LoadGestures(*file);
	}
	static SharedPtr<UIElement> TouchStateGetTouchedElement(TouchState* self)
	{
		return SharedPtr<UIElement>(self->GetTouchedElement());
	}
	void bind_class_Input(LuaModele & lm)
	{
		lm
		[
			LuaRegister<Input, void ()>(lm.state(), "Input", BaseClassStrategy<Object>())
				.def(&Input::SetToggleFullscreen, "SetToggleFullscreen")
				.def(&Input::SetMouseVisible, "SetMouseVisible")
				.def(&Input::SetMouseGrabbed, "SetMouseGrabbed")
				.def(&Input::SetMouseMode, "SetMouseMode")
				.def(&Input::IsMouseLocked, "IsMouseLocked")
				.def(&Input::AddScreenJoystick, "AddScreenJoystick")
				.def(&Input::RemoveScreenJoystick, "RemoveScreenJoystick")
				.def(&Input::SetScreenJoystickVisible, "SetScreenJoystickVisible")
				.def(&Input::SetScreenKeyboardVisible, "SetScreenKeyboardVisible")
				.def(&Input::SetTouchEmulation, "SetTouchEmulation")
				.def(&Input::RecordGesture, "RecordGesture")
				.def(InputSaveGestures, "SaveGestures")
				.def(InputSaveGesture, "SaveGesture")
				.def(InputLoadGestures, "LoadGestures")
				.def(&Input::RemoveGesture, "RemoveGesture")
				.def(&Input::RemoveAllGestures, "RemoveAllGestures")
				.def(&Input::GetKeyFromName, "GetKeyFromName")
				.def(&Input::GetKeyFromScancode, "GetKeyFromScancode")
				.def(&Input::GetKeyName, "GetKeyName")
				.def(&Input::GetScancodeFromKey, "GetScancodeFromKey")
				.def(&Input::GetScancodeFromName, "GetScancodeFromName")
				.def(&Input::GetScancodeName, "GetScancodeName")
				.def(&Input::GetKeyDown, "GetKeyDown")
				.def(&Input::GetKeyPress, "GetKeyPress")
				.def(&Input::GetScancodeDown, "GetScancodeDown")
				.def(&Input::GetScancodePress, "GetScancodePress")
				.def(&Input::GetMouseButtonDown, "GetMouseButtonDown")
				.def(&Input::GetMouseButtonPress, "GetMouseButtonPress")
				.def(&Input::GetQualifierDown, "GetQualifierDown")
				.def(&Input::GetQualifierPress, "GetQualifierPress")
				.def(&Input::GetQualifiers, "GetQualifiers")
				.def(&Input::GetMousePosition, "GetMousePosition")
				.def(&Input::GetMouseMove, "GetMouseMove")
				.def(&Input::GetMouseMoveX, "GetMouseMoveX")
				.def(&Input::GetMouseMoveY, "GetMouseMoveY")
				.def(&Input::GetMouseMoveWheel, "GetMouseMoveWheel")
				.def(&Input::GetNumTouches, "GetNumTouches")
				.def(&Input::GetTouch, "GetTouch")
				.def(&Input::GetNumJoysticks, "GetNumJoysticks")
				.def(&Input::GetJoystick, "GetJoystick")
				.def(&Input::GetJoystickByIndex, "GetJoystickByIndex")
				.def(&Input::GetJoystickByName, "GetJoystickByName")
				.def(&Input::GetToggleFullscreen, "GetToggleFullscreen")
				.def(&Input::GetScreenKeyboardSupport, "GetScreenKeyboardSupport")
				.def(&Input::IsScreenJoystickVisible, "IsScreenJoystickVisible")
				.def(&Input::IsScreenKeyboardVisible, "IsScreenKeyboardVisible")
				.def(&Input::GetTouchEmulation, "GetTouchEmulation")
				.def(&Input::IsMouseVisible, "IsMouseVisible")
				.def(&Input::IsMouseGrabbed, "IsMouseGrabbed")
				.def(&Input::GetMouseMode, "GetMouseMode")
				.def(&Input::HasFocus, "HasFocus")
				.def(&Input::IsMinimized, "IsMinimized")
			<=
			LuaRegister<JoystickState, void ()>(lm.state(), "JoystickState")
				.def(&JoystickState::IsController, "IsController")
				.def(&JoystickState::GetNumButtons, "GetNumButtons")
				.def(&JoystickState::GetNumAxes, "GetNumAxes")
				.def(&JoystickState::GetNumHats, "GetNumHats")
				.def(&JoystickState::GetButtonDown, "GetButtonDown")
				.def(&JoystickState::GetButtonPress, "GetButtonPress")
				.def(&JoystickState::GetAxisPosition, "GetAxisPosition")
				.def(&JoystickState::GetHatPosition, "GetHatPosition")
				.def(&JoystickState::name_, "name")
				.def(&JoystickState::joystickID_, "joystickID")
			<=
			LuaRegister<TouchState, void ()>(lm.state(), "TouchState")
				.def(TouchStateGetTouchedElement, "GetTouchedElement")
				.def(&TouchState::touchID_, "touchID")
				.def(&TouchState::position_, "position")
				.def(&TouchState::lastPosition_, "lastPosition")
				.def(&TouchState::delta_, "delta")
				.def(&TouchState::pressure_, "pressure")
		];
	}
}

