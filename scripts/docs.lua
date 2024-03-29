-- This scripts generates the documentation for all the subprojects of the tobot project.

local lfs = require("lfs")

-- Determine if we are running on Windows or Linux
local is_windows = package.config:sub(1,1) == "\\"
if is_windows then
  os.execute("rmdir /s /q ..\\docs")
else
  os.execute("rm -rf ../docs")
end
if is_windows then
  os.execute("cd .. && doxygen")
else
  os.execute("cd .. && doxygen")
end

print("Moving generated content out of the html folder ...")
if is_windows then
  os.execute("xcopy ..\\docs\\html ..\\docs /E /Y")
else
  os.execute("mv ../docs/html/* ../docs/")
end
print("Removing html folder ...")
if is_windows then
  os.execute("rmdir /s /q ..\\docs\\html")
else
  os.execute("rm -rf ../docs/html")
end
