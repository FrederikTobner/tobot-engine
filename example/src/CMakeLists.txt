set(SOURCES
"example.cpp"
)

add_executable("${PROJECT_NAME}_Example" ${SOURCES})

target_link_libraries("${PROJECT_NAME}_Example" PUBLIC ${PROJECT_NAME})

target_include_directories("${PROJECT_NAME}_Example" PUBLIC "${SOURCEPATH}/include" "${SOURCE_DIR}/packages/tobot_tooling/src/include/" "${SOURCE_DIR}/packages/tobot_math/src/include/")

# Copies assets to the build dir
FILE(COPY ../assets/inspirational_picture.png DESTINATION "${CMAKE_BINARY_DIR}/example/src/assets")