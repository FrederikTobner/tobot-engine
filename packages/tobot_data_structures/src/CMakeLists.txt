

add_library(tobot-data-structures INTERFACE)

target_sources(tobot-data-structures INTERFACE include/tobot_data_structures.h red_black_tree.h)
set_target_properties(tobot-data-structures PROPERTIES LINKER_LANGUAGE CXX)