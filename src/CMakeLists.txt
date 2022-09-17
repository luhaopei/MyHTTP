cmake_minimum_required(VERSION 3.16)

add_executable(http_server main.c)
target_link_libraries(http_server MyHTTP)

add_executable(http_server_test http_server_test.c)
target_link_libraries(http_server_test MyHTTP)