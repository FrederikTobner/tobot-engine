set(DATA_STRUCTURES_HEADER_FILES
"enum.h"
"graph/undirected_graph.h"
"include/tobot_data_structures.h"
"tree/avl_tree.h"
"tree/binary_search_tree.h"
"tree/binary_tree_traversal.h"
"tree/red_black_tree.h"
"tree/tree.h"
"tree/tree_node.h"
)

add_library(tobot-data-structures INTERFACE)

target_sources(tobot-data-structures INTERFACE ${DATA_STRUCTURES_HEADER_FILES})

set_target_properties(tobot-data-structures PROPERTIES LINKER_LANGUAGE CXX)

# Precompiles dependencies to speed up compilation of the target
if(MSVC)
    # VisualStudio only accepts header files that also have a source file    
    target_precompile_headers(tobot-data-structures INTERFACE pre_compiled_header.h pre_compiled_header.cpp) 
else()
    target_precompile_headers(tobot-data-structures INTERFACE pre_compiled_header.h)
endif()