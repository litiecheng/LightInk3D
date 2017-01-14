

local name = "LightInkLua"

if ThirdPartyCall then
ThirdPartyCall[name] = function(prefixInclude, prefixSrc)
	if is_option("LightInk3DLua") then
	
		add_includedirs(prefixInclude .. "LightInkLog")

		prefixInclude = prefixInclude .. name
		prefixSrc = prefixSrc .. name

		add_includedirs(prefixInclude)
		
		--add_defines("LIGHTINK_AS_DLL", "LIGHTINK_EXPORTS")
		add_defines("LIGHTINK_EXPORTS")

		-- add headers
		add_headers(prefixInclude .. "/LuaEngine/**.h", 
					prefixInclude .. "/LuaEngine/**.hpp", 
					prefixInclude .. "/LuaEngine/**.cpp")

			
		-- add files
		add_files(prefixSrc .. "/LuaEngine/**.cpp", prefixSrc .. "/LuaEngine/**.c")


	end
		
end
end


if LightInk3DCall then
LightInk3DCall[name] = function(prefixInclude, prefixSrc)
	if is_option("LightInk3DLua") then

		add_includedirs(prefixInclude .. "LightInkLog")
	
		prefixInclude = prefixInclude .. name
		prefixSrc = prefixSrc .. name
		
		--add_defines("LIGHTINK_AS_DLL")

		add_includedirs(prefixInclude)

	end
		
end
end