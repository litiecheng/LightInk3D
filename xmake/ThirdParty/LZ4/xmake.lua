

local name = "LZ4"

if ThirdPartyCall then
ThirdPartyCall[name] = function(prefixInclude, prefixSrc)

	prefixInclude = prefixInclude .. name
	prefixSrc = prefixSrc .. name

	add_includedirs(prefixInclude)

	-- add headers
	add_headers(prefixInclude .. "/*.h")

		
	-- add files
	add_files( prefixSrc .. "/*.c")


end
end


if LightInk3DCall then
LightInk3DCall[name] = function(prefixInclude, prefixSrc)

	prefixInclude = prefixInclude .. name
	prefixSrc = prefixSrc .. name

	add_includedirs(prefixInclude)


end
end