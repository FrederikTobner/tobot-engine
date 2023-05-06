set(DATA_STRUCTURES_HEADER_FILES
"enum.hpp"
"concepts.hpp"
"graph/undirected_graph.hpp"
"include/tobot_data_structures.hpp"
"tree/avl_tree.hpp"
"tree/binary_search_tree.hpp"
"tree/binary_tree_algorithms.hpp"
"tree/red_black_tree.hpp"
"tree/tree.hpp"
"tree/tree_node.hpp"
)

add_library(tobot-data-structures INTERFACE)

target_sources(tobot-data-structures INTERFACE ${DATA_STRUCTURES_HEADER_FILES})

set_target_properties(tobot-data-structures PROPERTIES LINKER_LANGUAGE CXX)

# Precompiles dependencies to speed up compilation of the target
if(MSVC)
    # VisualStudio only accepts header files that also have a source file    
    target_precompile_headers(tobot-data-structures INTERFACE pre_compiled_header.hpp pre_compiled_header.cpp) 
else()
    target_precompile_headers(tobot-data-structures INTERFACE pre_compiled_header.hpp)
endif()