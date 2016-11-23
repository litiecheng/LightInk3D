

local name = "LightInkLog"

if ThirdPartyCall then
ThirdPartyCall[name] = function(prefixInclude, prefixSrc)

	prefixInclude = prefixInclude .. name
	prefixSrc = prefixSrc .. name

	add_includedirs(prefixInclude)
	
	--add_defines("LIGHTINK_AS_DLL", "LIGHTINK_EXPORTS")
	add_defines("LIGHTINK_EXPORTS")

	-- add headers
	add_headers(prefixInclude .. "/fmt/**.h", 
				prefixInclude .. "/fmt/**.hpp", 
				prefixInclude .. "/Log/**.h")

		
	-- add files
	add_files(prefixSrc .. "/Log/**.cpp")
		
end
end


if LightInk3DCall then
LightInk3DCall[name] = function(prefixInclude, prefixSrc)

	prefixInclude = prefixInclude .. name
	prefixSrc = prefixSrc .. name
	
	--add_defines("LIGHTINK_AS_DLL")

	add_includedirs(prefixInclude)
		
end
end