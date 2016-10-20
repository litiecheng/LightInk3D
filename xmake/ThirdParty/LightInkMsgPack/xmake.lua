

local name = "LightInkMsgPack"

if ThirdPartyCall then
ThirdPartyCall[name] = function(prefixInclude, prefixSrc)
	if is_option("LightInk3DNETWORK") then

		prefixInclude = prefixInclude .. name
		prefixSrc = prefixSrc .. name

		add_includedirs(prefixInclude)
		
		--add_defines("LIGHTINK_AS_DLL", "LIGHTINK_EXPORTS")

		-- add headers
		add_headers(prefixInclude .. "/Msgpack/**.h", 
					prefixInclude .. "/Msgpack/*.cpp")

			
		-- add files
		add_files(prefixSrc .. "/Msgpack/**.cpp")


	end

end
end


if LightInk3DCall then
LightInk3DCall[name] = function(prefixInclude, prefixSrc)
	if is_option("LightInk3DNETWORK") then

		prefixInclude = prefixInclude .. name
		prefixSrc = prefixSrc .. name

		add_includedirs(prefixInclude)
		
		--add_defines("LIGHTINK_AS_DLL")

	end

end
end
