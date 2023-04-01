set(DATA_STRUCTURES_HEADER_FILES
"include/tobot_data_structures.h"
"tree/avl_tree.h"
"tree/red_black_tree.h"
"tuple.h"
)

add_library(tobot-data-structures INTERFACE)

target_sources(tobot-data-structures INTERFACE)
set_target_properties(tobot-data-structures PROPERTIES LINKER_LANGUAGE CXX)