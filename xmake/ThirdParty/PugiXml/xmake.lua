

local name = "PugiXml"

if ThirdPartyCall then
ThirdPartyCall[name] = function(prefixInclude, prefixSrc)

	prefixInclude = prefixInclude .. name
	prefixSrc = prefixSrc .. name

	add_includedirs(prefixInclude)

	-- add headers
	add_headers(prefixInclude .. "/*.hpp")

		
	-- add files
	add_files(prefixSrc .. "/*.cpp")


end
end
	

if LightInk3DCall then
LightInk3DCall[name] = function(prefixInclude, prefixSrc)

	prefixInclude = prefixInclude .. name
	prefixSrc = prefixSrc .. name
	
	add_includedirs(prefixInclude)


end
end