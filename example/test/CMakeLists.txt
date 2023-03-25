set(SOURCES
"example.cpp"
)

add_executable("${PROJECT_NAME}_Example_Tests" ${SOURCES})

target_link_libraries("${PROJECT_NAME}_Example_Tests" PUBLIC tobot-test)

target_include_directories("${PROJECT_NAME}_Example_Tests" PUBLIC "${SOURCE_PATH_TEST}/include")