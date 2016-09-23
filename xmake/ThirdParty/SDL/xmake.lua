

local name = "SDL"

local prefixInclude = "../../../include/ThirdParty/" .. name
local prefixSrc = "../../../src/ThirdParty/" .. name



-- add headers
add_headers(prefixInclude .. "/*.h")

local sdl_sub = {
	atomic = "",
	libm = "",
	stdlib = "",
	thread = "",
	timer = "",
	
	audio = "",
	cpuinfo = "",
	events = "",
	file = "",
	haptic = "",
	joystick = "",
	power = "",
	render = "",
	video = "",
}
-- add files
add_files(prefixSrc .. "/*.h", prefixSrc .. "/*.c", 
			prefixSrc .. "/atomic/*.c", 
			prefixSrc .. "/libm/*.c", 
			prefixSrc .. "/stdlib/*.c", 
			prefixSrc .. "/thread/*.c", 
			prefixSrc .. "/timer/*.c", 
			)



	

