-- Install dependencies for building the project under Linux

local is_windows = package.config:sub(1,1) == '\\'

if(is_windows) then
    print("This script is not supported on Windows.")
    exit(1)
end

-- Checks if the given package is installed
local function check_dependency(package_name)
    local handle = io.popen("which " .. package_name)
    local result = handle:read("*a")
    handle:close()    
    return result ~= ""
end

-- Determines the available package manager and returns the command to install a package
local function determinePackageManagerCommand()
    if os.execute("which pacman >/dev/null 2>&1") then
        return "sudo pacman -S "
    elseif os.execute("which apt-get >/dev/null 2>&1") then
        return "sudo apt-get install "
    else
        print("Could not determine package manager.")
        os.exit(1)
    end
end
  
local dependencies = {
    "cmake",
    "file",
    "fonts-dejavu-core",
    "libfreetype-dev",
    "libharfbuzz-dev",
    "libflac-dev",
    "libfluidsynth-dev",
    "libgme-dev",
    "libmpg123-dev",
    "libopusfile-dev",
    "libvorbis-dev",
    "libxmp-dev",
    "libwavpack-dev",
    "ninja-build",
    "pkg-config"
}

local command = determinePackageManager()
  
for _, dependency in ipairs(dependencies) do
    if not check_dependency(dependency) then
        print("Installing dependency:", dependency)
        os.execute(command .. package_name)
    end
end
  