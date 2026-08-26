set(SOURCES 
    test_long_number.cpp
)

add_executable(long_number_test ${SOURCES})
target_link_libraries(long_number_test
    gtest_main
    gmock_main
    ${LIBRARY}
)

add_test(long_number_test long_number_test)