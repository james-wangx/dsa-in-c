add_executable(selection_sort selection_sort.c)
add_executable(bubble_sort bubble_sort.c)
add_executable(bucket_sort bucket_sort.c)
add_executable(bubble_sort_recursive bubble_sort_recursive.c)
add_executable(selection_sort_recursive selection_sort_recursive.c)
add_executable(radix_sort radix_sort.c)
target_link_libraries(radix_sort m)
add_executable(radix_sort_list radix_sort_list.c list.c)
target_link_libraries(radix_sort_list m)
