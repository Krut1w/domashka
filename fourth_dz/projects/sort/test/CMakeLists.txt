set(SOURCES 
	test_bubble.cpp
)

add_executable(test_bubble ${SOURCES})

target_link_libraries(test_bubble 
	gtest
	${SORT_LIB}
)

add_test(test_bubble test_bubble)

set(SOURCES_SHELL
    test_shell.cpp
)

add_executable(test_shell ${SOURCES_SHELL})

target_link_libraries(test_shell
    gtest
    ${SORT_LIB}
)

add_test(test_shell test_shell)

