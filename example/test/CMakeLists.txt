set(SOURCES
"example.cpp"
)

add_executable("${PROJECT_NAME}_Example_Tests" ${SOURCES})

target_link_libraries("${PROJECT_NAME}_Example_Tests" PUBLIC ${PROJECT_NAME})

add_compile_definitions(TOBOT_TEST_APPLICATION)

target_include_directories("${PROJECT_NAME}_Example_Tests" PUBLIC "${SOURCEPATH}/include" "${SOURCE_DIR}/packages/tobot_tooling/src/include/" "${SOURCE_DIR}/packages/tobot_math/src/include/")