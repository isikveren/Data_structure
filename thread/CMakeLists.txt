project(thread_example)

add_executable(thread_example
 thread_example.cpp
 )

target_link_libraries(thread_example
 pthread
)