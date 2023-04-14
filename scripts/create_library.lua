-- Script for creating a new library in the packages folder

-- Function creates a new folder with the given name
function createDirectory(folderPath)
    local success, errormsg = os.mkdir(folderPath)
    if not success then
        print("Error creating folder: " .. errormsg)
        os.exit(1)
    end
end

-- Function for creating a file
function createFile(filename, filepath, text)
    -- open the file in write mode
    local file, errormsg = io.open(filepath .. "/" .. filename, "w")
    
    -- check if the file was opened successfully
    if not file then
        print("Error creating file: " .. errormsg)
        return false
    end
    
    -- write text to the file
    file:write(text)
    
    -- close the file
    file:close()
    
    print("File created successfully!")
    return true
end

-- Function for appending text to a file
function appendToFile(filename, filepath, text)
    -- open the file in append mode
    local file, errormsg = io.open(filepath .. "/" .. filename, "a")
    
    -- check if the file was opened successfully
    if not file then
        print("Error opening file: " .. errormsg)
        return false
    end
    
    -- write text to the end of the file
    file:write(text)
    
    -- close the file
    file:close()
    
    print("Text appended to file successfully!")
    return true
end

-- Function for checking if the library name is valid
function checkLibraryName(name) 
    if(libraryname == nil or libraryname == "") then
        print("Error: library name is empty")
        os.exit(1)
    end
    
    if(string.sub(libraryname, 1, 6) != "tobot-") then
        print("Libraries must start with the prefix 'tobot-'")
        os.exit(1)
    end
    
    if(string.len(libraryname) < 7) then
        print("The library name must be at least 7 characters long")
        os.exit(1)
    end
    
    if(string.find(libraryname, "\\") or string.find(libraryname, "/")) then
        print("The library name cannot contain any slashes or backslashes")
        os.exit(1)
    end
end
  
  

-- check if an argument was provided
if #arg < 1 then
    print("Usage: lua scriptname.lua libraryname")
    os.exit(1)
end
  
-- get the library name from the first argument
local libraryName = arg[1]

checkLibraryName(libraryName)

local libraryNameWithUnderScore = string.gsub(libraryname, "-", "_")

local libraryRootDirectory = "../packages/" .. libraryNameWithUnderScore
local librarySourceDirectory = "../packages/" .. libraryNameWithUnderScore .. "/src"
local libraryTestDirectory = "../packages/" .. libraryNameWithUnderScore .. "/test"
local librarySourcePathVariable = "SOURCE_PATH_" .. string.upper(str.sub(libraryNameWithUnderScore, 6))
  
-- create the folder with the library name
createDirectory(libraryRootDirectory)

-- create the src and test folders
createDirectory(librarySourceDirectory)
createDirectory(libraryTestDirectory)

-- create the CMakeLists.txt files
createFile("CMakeLists.txt", libraryRootDirectory, "add_subdirectory(src)\n\
add_subdirectory(test)\n")
createFile("CMakeLists.txt", librarySourceDirectory, "add_library(" .. libraryname .. " <PLACEHOLDER>)\n\
# Precompiles dependencies to speed up compilation of the target\n\
if(MSVC)\n\
    # VisualStudio only accepts header files that also have a source file    \n\
    target_precompile_headers(" .. libraryname .. " PUBLIC pre_compiled_header.h pre_compled_header.cpp)\n\
else()\n\
    target_precompile_headers(" .. libraryname .. " PUBLIC pre_compiled_header.h)\n\
endif()\n")
createFile("pre_compiled_header.h", librarySourceDirectory, "#pragma once\n")
createFile("pre_compiled_header.cpp", librarySourceDirectory, "#include \"pre_compiled_header.h\"\n"")
createFile("CMakeLists.txt", libraryTestDirectory, "# include google test\n\
include(FetchContent)\n\
FetchContent_Declare(\n\
  googletest\n\
  URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip\n\
)\n\
\n\
# For Windows: Prevent overriding the parent project's compiler/linker settings\n\
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)\n\
FetchContent_MakeAvailable(googletest)\n\
add_executable(" .. libraryname .. "-test <PLACEHOLDER>)\n\
target_link_libraries(" .. libraryname .. "-test " .. libraryname .. ")\n\
target_include_directories(" .. libraryname .. "-test " PUBLIC \"${" .. librarySourcePathVariable .."}/include\"\n")

-- append the library to the CMakeLists.txt file in the root directory
appendToFile("CMakeLists.txt", "../packages", "add_subdirectory(" .. libraryNameWithUnderScore .. ")\n")

-- Create a variable that contains the path to the source directory of the library
appendToFile("CMakeLists.txt", "..", "get_filename_component(" .. librarySourcePathVariable .." ${PROJECT_SOURCE_DIR}/packages/tobot_core/src ABSOLUTE)\n")