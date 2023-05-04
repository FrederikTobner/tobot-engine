-- Build script for Tobot

-- Find vcvars64.bat
local function find_vcvars64_bat()
    local search_paths = { os.getenv("ProgramFiles(x86)"), os.getenv("ProgramFiles") }
    
    for _, path in ipairs(search_paths) do
        local vcvars64_path = path .. "\\Microsoft Visual Studio\\20*\\*\\VC\\Auxiliary\\Build\\vcvars64.bat"
      
        for file in io.popen('dir "' .. vcvars64_path .. '" /B /A:-D 2^>nul'):lines() do
            return vcvars64_path:gsub("%*", file)
        end
    end    
    return nil
end

-- Check if we are running on Windows
local is_windows = package.config:sub(1,1) == '\\'

-- Run vcvars64.bat if we are on Windows
if is_windows then  
    local vcvars64_path = find_vcvars64_bat()
    if vcvars64_path then
        print("Found vcvars64.bat at " .. vcvars64_path)
        os.execute('"' .. vcvars64_path .. '"')
    else
        print("Could not find vcvars64.bat")
        exit(1)
    end
end

-- The default build type is Release
local buildType = arg[1] or "Release"
-- The default build target is all
local buildTarget = arg[2] or "all"
-- The default generator is Ninja
local generator = arg[3] or "Ninja"


-- We should make the compiler that is used for building the project configurable as well
print("Configuring CMake ...")
os.execute(string.format("cmake -B ../build -DCMAKE_BUILD_TYPE=%s -G \"%s\" ..", buildType, generator))
print("Building Tobot ...")
os.execute(string.format("cmake --build ../build --config %s --target %s", buildType, buildTarget))
