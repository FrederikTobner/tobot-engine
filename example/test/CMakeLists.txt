set(SOURCES
"example.cpp"
)

add_executable("${PROJECT_NAME}_Example_Tests" ${SOURCES})

target_link_libraries("${PROJECT_NAME}_Example_Tests" PUBLIC tobot-tooling)

target_include_directories("${PROJECT_NAME}_Example_Tests" PUBLIC "${SOURCE_PATH_TOOLING}/include")