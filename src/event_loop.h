#ifndef EVENT_LOOP_H__
#define EVENT_LOOP_H__

#include <pthread.h>

#include "event_dispatcher.h"
#include "channel_map.h"

struct event_loop{
    int quit;
    const struct event_dispatcher *eventDispatcher;

     /** 对应的event_dispatcher的数据. */
    void *event_dispatcher_data;
    struct channel_map *channelMap;

    int is_handle_pending;
    struct channel_element *pending_head;
    struct channel_element *pending_tail;

    pthread_t owner_thread_id;
    pthread_mutex_t mutext;
    pthread_cond_t cond;

    int socketPair[2];
    char *thread_name;
    
};

#endif // !EVENT_LOOP_H__

