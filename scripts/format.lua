-- This script is used to format the code using clang-format
-- You need to install clang-format and luafilesystem using luarocks to use this script

local lfs = require "lfs"

-- Function for concatenating two arrays
local function mergeArray(a, b)
    local result = {table.unpack(a)}
    table.move(b, 1, #b, #result + 1, result)
    return result
end  

-- Function for checking that a file exists
function directory_exists(path)
    local attributes = lfs.attributes(path)
    return attributes and attributes.mode == "directory"
end

-- Function for checking that a file exists
function file_exists(path)
    local attributes = lfs.attributes(path)
    return attributes and attributes.mode == "file"
end

-- Function for finding all the files with the specified extensions in the directory and all its subdirectories
function find_files_with_extensions(directory, extensions)
    local files = {}
    for file in lfs.dir(directory) do
        if file ~= "." and file ~= ".." then
            local path = directory .. "/" .. file
            local mode = lfs.attributes(path, "mode")
            if mode == "file" then
                local file_extension = path:match("%.([^%.]+)$")
                for _, ext in ipairs(extensions) do
                    if file_extension == ext then
                        table.insert(files, path)
                        break
                    end
                end
            elseif mode == "directory" then
                local subfiles = find_files_with_extensions(path, extensions)
                for _, subfile in ipairs(subfiles) do
                    table.insert(files, subfile)
                end
            end
        end
    end
    return files
end

-- Guarantee the package directory exists
if not (directory_exists("../packages")) then
    print("Source directory not found!")
    os.exit(74)
end

-- Guarantee the clang-format file exists
if not (file_exists("../.clang-format")) then
    print("Can not find formatting file!")
    os.exit(74)
end

-- The file extensions to format
local extensions = {"c", "cpp", "cc", "h", "hpp", "hh"}
-- Find all the files with the extensions in the packages directory and the editor directory
local files = mergeArray(find_files_with_extensions("../packages", extensions), find_files_with_extensions("../editor", extensions))
-- Formatting the files in both directories
os.execute("clang-format -i --style=file " .. table.concat(files, " "))