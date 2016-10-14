
if is_option("LightInk3DLua") then

	local name = "LightInkLua"

	local prefixInclude = "../../../include/ThirdParty/" .. name
	local prefixSrc = "../../../src/ThirdParty/" .. name

	add_includedirs(prefixInclude)
	
	add_defines("LIGHTINK_AS_DLL", "LIGHTINK_EXPORTS")

	-- add headers
	add_headers(prefixInclude .. "/LuaEngine/**.h", 
				prefixInclude .. "/LuaEngine/**.hpp", 
				prefixInclude .. "/LuaEngine/**.cpp")

		
	-- add files
	add_files(prefixSrc .. "/LuaEngine/**.cpp", prefixSrc .. "/LuaEngine/**.c")


end
	

