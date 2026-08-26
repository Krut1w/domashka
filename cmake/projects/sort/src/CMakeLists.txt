target_sources(${SORT_LIB} 
	PRIVATE
		bubble_sort.cpp
		shell_sort.cpp
)

target_include_directories(${SORT_LIB} PUBLIC
	"${CURRENT_SOURCE_DIR}"
)