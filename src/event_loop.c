#include <assert.h>
#include <stddef.h>
#include "event_dispatcher.h"

int event_loop_run(struct event_loop *eventLoop){
    assert(eventLoop != NULL);

    struct event_dispatcher *dispatcher = eventLoop->eventDispatcher;
    if(eventLoop->owner_thread_id != pthread_self()){
        exit(1);
    }
    
}