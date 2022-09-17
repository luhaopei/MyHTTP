cmake_minimum_required(VERSION 3.16)

# AUX_SOURCE_DIRECTORY(. SRC_LIST)
# # ADD_EXECUTABLE(MyHTTP  ${SRC_LIST})

# add_library(MyHTTP ${SRC_LIST})

# target_link_libraries(MyHTTP pthread)


# install(TARGETS MyHTTP DESTINATION lib)

# SET(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin)

if (EPOLL_EXISTS)
    set(myhttp_lib
            log.c
            sock_ntop.c
            read.c
            tcp_server.c
            tcp_client.c
            event_loop.c
            channel.c
            acceptor.c
            channel_map.c
            poll_dispatcher.c
            thread_pool.c
            event_loop_thread.c
            utils.c
            epoll_dispatcher.c
            buffer.c
            tcp_connection.c
            http_server.c
            http_request.c
            http_response.c
            )
else ()
    set(myhttp_lib
            log.c
            sock_ntop.c
            read.c
            tcp_server.c
            tcp_client.c
            event_loop.c
            channel.c
            acceptor.c
            channel_map.c
            poll_dispatcher.c
            thread_pool.c
            event_loop_thread.c
            utils.c
            buffer.c
            tcp_connection.c
            http_server.c
            http_request.c
            http_response.c
            )
endif ()


add_library(MyHTTP ${myhttp_lib})
target_link_libraries(MyHTTP pthread)

install(TARGETS MyHTTP DESTINATION lib)