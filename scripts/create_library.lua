-- Script for creating a new library in the packages folder

-- Function creates a new folder with the given name
function createDirectory(folderPath)
    local success, errormsg = os.execute("mkdir " .. folderPath)    
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
        print("Error creating file: " .. errormsg .. " (filename: " .. filename .. " filepath: " .. filepath .. ")")
        os.exit(1)
    end    
    -- write text to the file
    file:write(text)    
    -- close the file
    file:close()
end

-- Function for appending text to a file
function appendToFile(filename, filepath, text)
    -- open the file in append mode
    local file, errormsg = io.open(filepath .. "/" .. filename, "a")    
    -- check if the file was opened successfully
    if not file then
        print("Error opening file: " .. errormsg .. " (filename: " .. filename .. " filepath: " .. filepath .. ")")
        os.exit(1)
    end    
    -- write text to the end of the file
    file:write(text)    
    -- close the file
    file:close()
end

-- Function for checking if the library name is valid
function checkLibraryName(name) 
    if(name == nil or name == "") then
        print("Error: library name is empty")
        os.exit(1)
    end    
    if(not (string.sub(name, 1, 6) == "tobot-")) then
        print("Error: Libraries must start with the prefix 'tobot-'")
        os.exit(1)
    end    
    if(string.len(name) < 7) then
        print("Error: The library name must be at least 7 characters long")
        os.exit(1)
    end    
    if(string.find(name, "\\") or string.find(name, "/")) then
        print("Error: The library name cannot contain any slashes or backslashes")
        os.exit(1)
    end
end

function insertTextIntoFile(filename, filepath, targetString, insertText, insertAfterTargetString)
    local file = io.open(filepath .. "/" .. filename, "r")
    if file then
        local contents = file:read("*all")
        file:close()
        local position = contents:find(targetString)
        if position then
            if insertAfterTargetString then
                position = position + string.len(targetString)
            end
        contents = contents:sub(1, position - 1) .. insertText .. contents:sub(position)
        file = io.open(filepath .. "/" .. filename, "w")
        file:write(contents)
        file:close()
        else
            print("Target string not found in file.")
        end
    else
        print("Error opening file." .. " (filename: " .. filename .. " filepath: " .. filepath .. ")")
        os.exit(1)
    end
end

-- Create a CMakeLists.txt file for a library test directory
function createTestCMakeLists(libraryTestDirectory, libraryName, librarySourcePathVariable)
    createFile("CMakeLists.txt", libraryTestDirectory, "# include google test\n\
include(FetchContent)\n\
FetchContent_Declare(\n\
  googletest\n\
  URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip\n\
)\n\
\n\
# For Windows: Prevent overriding the parent project's compiler/linker settings\n\
set(gtest_force_shared_crt ON CACHE BOOL \"\" FORCE)\n\
FetchContent_MakeAvailable(googletest)\n\
add_executable(" .. libraryName .. "-test <PLACEHOLDER>)\n\
target_link_libraries(" .. libraryName .. "-tests " .. libraryName .. ")\n\
target_include_directories(" .. libraryName .. "-test PUBLIC \"${" .. librarySourcePathVariable .. "}/include\")\n")
end

-- Creating the CMakelists.txt file for the library in the source directory
function createSrcCMakeLists(librarySourceDirectory, libraryName)
    createFile("CMakeLists.txt", librarySourceDirectory, "add_library(" .. libraryName .. " <PLACEHOLDER>)\n\
# Precompiles dependencies to speed up compilation of the target\n\
if(MSVC)\n\
    # VisualStudio only accepts header files that also have a source file    \n\
    target_precompile_headers(" .. libraryName .. " PUBLIC pre_compiled_header.h pre_compled_header.cpp)\n\
else()\n\
    target_precompile_headers(" .. libraryName .. " PUBLIC pre_compiled_header.h)\n\
endif()\n")
end

function main(args)
    -- check if an argument was provided
    if #args < 1 then
        print("Usage: lua scriptname.lua libraryname")
        os.exit(1)
    end
    
    -- get the library name from the first argument
    local libraryName = args[1]

    -- check if the library name is valid
    checkLibraryName(libraryName)

    -- create the library name with underscores
    local libraryNameWithUnderScore = string.gsub(libraryName, "-", "_")

    -- create the path variables
    local libraryRootDirectory = "../tobot/" .. libraryNameWithUnderScore
    local librarySourceDirectory = "../tobot/" .. libraryNameWithUnderScore .. "/src"
    local libraryTestDirectory = "../tobot/" .. libraryNameWithUnderScore .. "/test"

    -- create the path variable for the CMakeLists.txt file
    local librarySourcePathVariable = "SOURCE_PATH" .. string.upper(string.sub(libraryNameWithUnderScore, 6))
    
    -- create the folder with the library name
    createDirectory(libraryRootDirectory)

    -- create the src and test folders
    createDirectory(librarySourceDirectory)
    createDirectory(libraryTestDirectory)

    -- create the CMakeLists.txt file for the root directory of the library
    createFile("CMakeLists.txt", libraryRootDirectory, "add_subdirectory(src)\n\
    add_subdirectory(test)\n")

    -- Creating the CMakeLists.txt file for the source directory
    createSrcCMakeLists(librarySourceDirectory, libraryName)

    -- Creating the precompiled header files
    createFile("pre_compiled_header.h", librarySourceDirectory, "#pragma once\n")

    -- Creating the precompiled header files
    createFile("pre_compiled_header.cpp", librarySourceDirectory, "#include \"pre_compiled_header.h\"\n")

    -- Creating the readme file
    createFile("README.md", libraryRootDirectory, "# " .. libraryName .. "\n")

    -- Creating the test CMakeLists.txt file for the test directory
    createTestCMakeLists(libraryTestDirectory, libraryName, librarySourcePathVariable)

    -- append the library to the CMakeLists.txt file in the root directory
    appendToFile("CMakeLists.txt", "../tobot", "add_subdirectory(" .. libraryNameWithUnderScore .. ")\n")

    -- Add the library to the documentation
    insertTextIntoFile("DoxyFile", "../tobot", "INPUT = ", "packages/" .. librarySourceDirectory, true)

    -- Adding the tests to our workflow
    insertTextIntoFile("tests.yaml", "../.github/workflows", "--target", " " .. libraryName .. "-tests", true)
end

-- Calling our main function
main(arg)