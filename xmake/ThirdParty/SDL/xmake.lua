

local name = "SDL"
local sdl_sub_h = {
		atomic = {"/*.h"},
		libm = {"/*.h"},
		stdlib = {"/*.h"},
		thread = {"/*.h"},
		timer = {"/*.h"},
		
		audio = {"/*.h"},
		cpuinfo = {"/*.h"},
		events = {"/*.h"},
		file = {"/*.h"},
		haptic = {"/*.h"},
		joystick = {"/*.h"},
		power = {"/*.h"},
		render = {"/*.h"},
		video = {"/*.h"},
	}
	local sdl_sub = {
		atomic = {"/*.c"},
		libm = {"/*.c"},
		stdlib = {"/*.c"},
		thread = {"/*.c"},
		timer = {"/*.c"},
		
		audio = {"/*.c"},
		cpuinfo = {"/*.c"},
		events = {"/*.c"},
		file = {"/*.c"},
		haptic = {"/*.c"},
		joystick = {"/*.c"},
		power = {"/*.c"},
		render = {"/*.c"},
		video = {"/*.c"},
	}

	local sdl_option_sub_h = {
		audio = {
			LightInk3DDUMMYAUDIO = {"/dummy/*.h"},
			LightInk3DDISKAUDIO = {"/disk/*.h"},
		},
		video = {
			LightInk3DVIDEO_DUMMY = {"/dummy/*.h"},
		},
	}

	local sdl_option_sub = {
		audio = {
			LightInk3DDUMMYAUDIO = {"/dummy/*.c"},
			LightInk3DDISKAUDIO = {"/disk/*.c"},
		},
		video = {
			LightInk3DVIDEO_DUMMY = {"/dummy/*.c"},
		},
	}

	local sdl_plat_sub_h = {
		timer = {
			android = {"/unix/*.h"},
			emscripten = {"/dummy/*.h"},
			iphoneos = {"/unix/*.h"},
			macosx = {"/unix/*.h"},
			linux = {"/unix/*.h"},
			windows = {"/windows/*.h"},
			wiz = {"/dummy/*.h"},
			psp = {"/psp/*.h"},
		},
		loadso = {
			android = {"/dlopen/*.h", },
			emscripten = {"/dummy/*.h"},
			iphoneos = {"/dummy/*.h"},
			macosx = {"/dlopen/*.h"},
			linux = {"/dummy/*.h"},
			windows = {"/windows/*.h"},
			wiz = {"/dlopen/*.h"},
			psp = {"/psp/*.h"},
		},
		
		thread = {
			android = {"/pthread/*.h", },
			emscripten = {"/generic/*.h"},
			iphoneos = {"/pthread/*.h", },
			macosx = {"/pthread/*.h"},
			linux = {"/pthread/*.h"},
			windows = {"/windows/*.h"},
			wiz = {"/pthread/*.h"},
			psp = {"/psp/*.h"},
		}, 
		
		audio = {
			android = {"/android/*.h"},
			emscripten = {"/emscripten/*.h"},
			iphoneos = {"/coreaudio/*.h", },
			macosx = {"/coreaudio/*.h"},
			windows = {"/winmm/*.h", "/directsound/*.h", "/xaudio2/*.h"},
			psp = {"/psp/*.h"},
		},
		
		core = {
			android = {"/android/*.h", },
			linux = {"/linux/*.h"},
			windows = {"/windows/*.h"},
		},
		
		file = {
			iphoneos = {"/cocoa/*.h", },
			macosx = {"/cocoa/*.h"},
		},
		
		filesystem = {
			android = {"/android/*.h", },
			emscripten = {"/emscripten/*.h"},
			iphoneos = {"/cocoa/*.h", },
			macosx = {"/cocoa/*.h"},
			linux = {"/unix/*.h"},
			windows = {"/windows/*.h"},
			wiz = {"/dummy/*.h"},
			psp = {"/dummy/*.h"},
		},
		joystick = {
			android = {"/android/*.h", },
			emscripten = {"/emscripten/*.h"},
			iphoneos = {"/iphoneos/*.h", },
			macosx = {"/darwin/*.h"},
			linux = {"/linux/*.h"},
			windows = {"/windows/*.h"},
			wiz = {"/dummy/*.h"},
			psp = {"/psp/*.h"},
		},
		power = {
			android = {"/android/*.h", },
			emscripten = {"/emscripten/*.h"},
			iphoneos = {"/uikit/*.h"},
			macosx = {"/macosx/*.h"},
			linux = {"/linux/*.h"},
			windows = {"/windows/*.h"},
		},
		video = {
			android = {"/android/*.h", },
			emscripten = {"/emscripten/*.h"},
			iphoneos = {"/uikit/*.h"},
			macosx = {"/cocoa/*.h"},
			windows = {"/windows/*.h"},
		},
		haptic = {
			android = {"/dummy/*.h"},
			emscripten = {"/dummy/*.h"},
			iphoneos = {"/dummy/*.h"},
			macosx = {"/darwin/*.h"},
			linux = {"/linux/*.h"},
			windows = {"/windows/*.h"},
			wiz = {"/dummy/*.h"},
			psp = {"/psp/*.h"},
		},
	}

	local sdl_plat_sub = {
		timer = {
			android = {"/unix/*.c"},
			emscripten = {"/dummy/*.c"},
			iphoneos = {"/unix/*.c"},
			macosx = {"/unix/*.c"},
			linux = {"/unix/*.c"},
			windows = {"/windows/*.c"},
			wiz = {"/dummy/*.c"},
			psp = {"/psp/*.c"},
		},
		loadso = {
			android = {"/dlopen/*.c"},
			emscripten = {"/dummy/*.c"},
			iphoneos = {"/dummy/*.c"},
			macosx = {"/dlopen/*.c"},
			linux = {"/dummy/*.c"},
			windows = {"/windows/*.c"},
			wiz = {"/dlopen/*.c"},
			psp = {"/psp/*.c"},
		},
		
		thread = {
			android = {"/pthread/*.c"},
			emscripten = {"/generic/*.c"},
			iphoneos = {"/pthread/*.c"},
			macosx = {"/pthread/*.c"},
			linux = {"/pthread/*.c"},
			windows = {"/windows/*.c", "/generic/SDL_syscond.c"},
			wiz = {"/pthread/*.c"},
			psp = {"/psp/*.c"},
		}, 
		
		audio = {
			android = {"/android/*.c"},
			emscripten = {"/emscripten/*.c"},
			iphoneos = {"/coreaudio/*.c"},
			macosx = {"/coreaudio/*.c"},
			windows = {"/winmm/*.c", "/directsound/*.c", "/xaudio2/*.c"},
			psp = {"/psp/*.c"},
		},
		
		core = {
			android = {"/android/*.c"},
			linux = {"/linux/*.c"},
			windows = {"/windows/*.c"},
		},
		
		file = {
			iphoneos = {"/cocoa/*.m"},
			macosx = {"/cocoa/*.m"},
		},
		
		filesystem = {
			android = {"/android/*.c"},
			emscripten = {"/emscripten/*.c"},
			iphoneos = {"/cocoa/*.m"},
			macosx = {"/cocoa/*.m"},
			linux = {"/unix/*.c"},
			windows = {"/windows/*.c"},
			wiz = {"/dummy/*.c"},
			psp = {"/dummy/*.c"},
		},
		joystick = {
			android = {"/android/*.c"},
			emscripten = {"/emscripten/*.c"},
			iphoneos = {"/iphoneos/*.m"},
			macosx = {"/darwin/*.c"},
			linux = {"/linux/*.c"},
			windows = {"/windows/*.c"},
			wiz = {"/dummy/*.c"},
			psp = {"/psp/*.c"},
		},
		power = {
			android = {"/android/*.c"},
			emscripten = {"/emscripten/*.c"},
			iphoneos = {"/uikit/*.m"},
			macosx = {"/macosx/*.c"},
			linux = {"/linux/*.c"},
			windows = {"/windows/*.c"},
		},
		video = {
			android = {"/android/*.c"},
			emscripten = {"/emscripten/*.c"},
			iphoneos = {"/uikit/*.m"},
			macosx = {"/cocoa/*.c"},
			windows = {"/windows/*.c"},
		},
		haptic = {
			android = {"/dummy/*.c"},
			emscripten = {"/dummy/*.c"},
			iphoneos = {"/dummy/*.c"},
			macosx = {"/darwin/*.c"},
			linux = {"/linux/*.c"},
			windows = {"/windows/*.c"},
			wiz = {"/dummy/*.c"},
			psp = {"/psp/*.c"},
		},
	}
	
	
if ThirdPartyCall then
ThirdPartyCall[name] = function(prefixInclude, prefixSrc)

	prefixInclude = prefixInclude .. name
	prefixSrc = prefixSrc .. name

	add_includedirs(prefixInclude)

	--add_defines("SDL_EXPORTS", "BUILD_SDL")

	if is_plat("windows") then
		add_links("winmm")
		add_links("imm32")
		add_links("ole32")
		add_links("oleaut32")
		add_links("user32")
		add_links("shell32")
		add_links("gdi32")
		add_links("version")
	end


	-- add headers
	add_headers(prefixInclude .. "/*.h|SDL_config_*.h")
	add_headers(prefixSrc .. "/*.h")
	for k, v in pairs(sdl_sub_h) do
		for ki, vi in ipairs(v) do
			add_headers(prefixSrc .. "/" .. k .. vi)
		end
	end

	for k, v in pairs(sdl_option_sub_h) do
		for ko, vo in pairs(v) do
			if is_option(ko) then
				for ki, vi in ipairs(vo) do
					add_headers(prefixSrc .. "/" .. k .. vi)
				end
			end
		end
	end

	for k, v in pairs(sdl_plat_sub_h) do
		for ko, vo in pairs(v) do
			if is_plat(ko) then
				for ki, vi in ipairs(vo) do
					add_headers(prefixSrc .. "/" .. k .. vi)
				end
			end
		end
	end


	-- add files
	add_files(prefixSrc .. "/*.c")
	for k, v in pairs(sdl_sub) do
		for ki, vi in ipairs(v) do
			add_files(prefixSrc .. "/" .. k .. vi)
		end
	end

	for k, v in pairs(sdl_option_sub) do
		for ko, vo in pairs(v) do
			if is_option(ko) then
				for ki, vi in ipairs(vo) do
					add_files(prefixSrc .. "/" .. k .. vi)
				end
			end
		end
	end

	for k, v in pairs(sdl_plat_sub) do
		for ko, vo in pairs(v) do
			if is_plat(ko) then
				for ki, vi in ipairs(vo) do
					add_files(prefixSrc .. "/" .. k .. vi)
				end
			end
		end
	end

	add_defines("SDL_RENDER_DISABLED=1")

end
end

	

if LightInk3DCall then
LightInk3DCall[name] = function(prefixInclude, prefixSrc)

	prefixInclude = prefixInclude .. name
	prefixSrc = prefixSrc .. name

	--add_defines("SDL_EXPORTS")
	
	add_includedirs(prefixInclude)


	if is_plat("windows") then
		add_links("winmm")
		add_links("imm32")
		add_links("ole32")
		add_links("oleaut32")
		add_links("user32")
		add_links("shell32")
		add_links("gdi32")
		add_links("version")
	end

	add_defines("SDL_RENDER_DISABLED=1")

end
end