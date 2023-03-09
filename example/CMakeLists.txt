set(SOURCES
example.cpp
)

add_executable("${PROJECT_NAME}_Example" ${SOURCES})

target_link_libraries("${PROJECT_NAME}_Example" PUBLIC ${PROJECT_NAME})

target_include_directories("${PROJECT_NAME}_Example" PUBLIC "${PROJECT_SOURCE_DIR}/src/include")