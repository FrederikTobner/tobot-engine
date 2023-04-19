-- This scripts generates the documentation for all the subprojects of the tobot project.

local lfs = require("lfs")

-- Determine if we are running on Windows or Linux
local is_windows = package.config:sub(1,1) == "\\"

-- Function for getting all the subdirectories in a directory
function get_subdirectories(path)
    local subdirectories = {}
    for dir in lfs.dir(path) do
        if dir ~= "." and dir ~= ".." then
            local subdir = path .. "/" .. dir
            if lfs.attributes(subdir, "mode") == "directory" then
                table.insert(subdirectories, subdir)
            end
        end
    end
    return subdirectories
end
  
-- Function for generating the documentation for a project
function document_project(name)
    if is_windows then
      os.execute("cd ..\\" .. name)
      os.execute("rmdir /s /q .\\docs\\html")
    else
      os.execute("cd ../" .. name)
      os.execute("rm -rf ./docs/html")
    end

    print("Generating Documentation ...")
    os.execute("doxygen")

    print("Moving generated content out of the html folder ...")
    if is_windows then
      os.execute("xcopy .\\docs\\html .\\docs /E /Y")
    else
      os.execute("mv ./docs/html/* ./docs/")
    end

    print("Removing html folder ...")
    if is_windows then
      os.execute("rmdir /s /q .\\docs\\html")
    else
      os.execute("rm -rf ./docs/html")
    end
end

-- Find all the subdirectories in the packages folder
if is_windows then
    local subdirs = get_subdirectories("..\\packages")
else
    local subdirs = get_subdirectories("../packages")
end

-- Document each project
for _, subdir in ipairs(subdirs) do
    document_project(subdir .. "/src")
end


