include_directories(../src)

add_executable(test_aweather
    test.cpp
)

target_compile_definitions(test_aweather PRIVATE TEST_DIR="${PROJECT_SOURCE_DIR}/test")
