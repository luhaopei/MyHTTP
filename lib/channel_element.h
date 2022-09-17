#ifndef CHANNEL_ELEMENT_H__
#define CHANNEL_ELEMENT_H__
#include "channel.h"
#include "channel_element.h"

struct channel_element {
    int type; //1: add  2: delete
    struct channel *channel;
    struct channel_element *next;
};

#endif // !CHANNEL_ELEMENT_H__
