-- This script is used to delete all the files in the logs folder
-- You need to install the luafilesystem using luarocks to use this script

local lfs = require("lfs")

local folder = "../logs"

-- Iterating over all files in the folder and deleting them
for file in lfs.dir(folder) do
    if file ~= "." and file ~= ".." then
        local filePath = folder .. "/" .. file
        os.remove(filePath)
    end
end
os.exit(0)