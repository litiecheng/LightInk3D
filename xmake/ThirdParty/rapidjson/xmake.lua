

local name = "rapidjson"

if ThirdPartyCall then
ThirdPartyCall[name] = function(prefixInclude, prefixSrc)

	prefixInclude = prefixInclude .. name
	prefixSrc = prefixSrc .. name


	-- add headers
	add_headers(prefixInclude .. "/**.h")

		
	-- add files

end
end
	

if LightInk3DCall then
LightInk3DCall[name] = function(prefixInclude, prefixSrc)

	prefixInclude = prefixInclude .. name
	prefixSrc = prefixSrc .. name


end
end