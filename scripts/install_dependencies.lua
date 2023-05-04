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

-- Installs the given package using the available package manager
local function install_dependency(package_name)
    local command
    if os.execute("which pacman >/dev/null 2>&1") then
        command = "sudo pacman -S --noconfirm " .. package_name
    elseif os.execute("which apt-get >/dev/null 2>&1") then
        command = "sudo apt-get install -y " .. package_name
    else
        print("Could not find a supported package manager.")
        return
    end
    os.execute(command)
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
  
for _, dependency in ipairs(dependencies) do
    if not check_dependency(dependency) then
        print("Installing dependency:", dependency)
        install_dependency(dependency)
    end
end
  