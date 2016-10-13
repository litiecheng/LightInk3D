

local name = "FreeType"
local srcList = {
	"/autofit/autofit.c",
    "/base/ftbase.c",
    "/base/ftbbox.c",
    "/base/ftbitmap.c",
    "/base/ftfstype.c",
    "/base/ftgasp.c",
    "/base/ftglyph.c",
    "/base/ftgxval.c",
    "/base/ftinit.c",
    "/base/ftlcdfil.c",
    "/base/ftmm.c",
    "/base/ftotval.c",
    "/base/ftpatent.c",
    "/base/ftpfr.c",
    "/base/ftstroke.c",
    "/base/ftsynth.c",
    "/base/ftsystem.c",
    "/base/fttype1.c",
    "/base/ftwinfnt.c",
    "/bdf/bdf.c",
    "/bzip2/ftbzip2.c",
    "/cache/ftcache.c",
    "/cff/cff.c",
    "/cid/type1cid.c",
    "/gxvalid/gxvalid.c",
    "/gzip/ftgzip.c",
    "/lzw/ftlzw.c",
    "/otvalid/otvalid.c",
    "/pcf/pcf.c",
    "/pfr/pfr.c",
    "/psaux/psaux.c",
    "/pshinter/pshinter.c",
    "/psnames/psmodule.c",
    "/raster/raster.c",
    "/sfnt/sfnt.c",
    "/smooth/smooth.c",
    "/truetype/truetype.c",
    "/type1/type1.c",
    "/type42/type42.c",
    "/winfonts/winfnt.c",

}

local prefixInclude = "../../../include/ThirdParty/" .. name
local prefixSrc = "../../../src/ThirdParty/" .. name

add_defines("FT2_BUILD_LIBRARY=1")

add_includedirs(prefixInclude)

-- add headers
add_headers(prefixInclude .. "/*.h", prefixInclude .. "/freetype/*.h")

-- add files
for k, v in ipairs(srcList) do
	add_files(prefixSrc .. v)
end

	

