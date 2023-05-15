# imgui doesn't have a CMakeLists.txt, so we need to create one ourselves
set(IMGUI_SOURCES
imgui_dir/imconfig.h 
imgui_dir/imgui.h 
imgui_dir/imgui.cpp
imgui_dir/imgui_demo.cpp 
imgui_dir/imgui_draw.cpp 
imgui_dir/imgui_internal.h 
imgui_dir/imgui_tables.cpp
imgui_dir/imgui_widgets.cpp 
imgui_dir/imstb_rectpack.h 
imgui_dir/imstb_textedit.h
imgui_dir/imstb_truetype.h
imgui_dir/backends/imgui_impl_sdl2.h
imgui_dir/backends/imgui_impl_sdl2.cpp
imgui_dir/backends/imgui_impl_sdlrenderer.h
imgui_dir/backends/imgui_impl_sdlrenderer.cpp
)

add_library(imgui STATIC ${IMGUI_SOURCES})

target_include_directories(imgui PUBLIC imgui_dir ../SDL/include)