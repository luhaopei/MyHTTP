#ifndef CHANNEL_H__
#define CHANNEL_H__

typedef int (*event_read_callback)(void *data);
typedef int (*event_write_callback)(void *data);

struct channel
{
    int fd;
    int events; //表示event类型

    event_read_callback eventReadCallback;
    event_write_callback eventWriteCallback;

    void *data; 
};


#endif // !CHANNEL_H__
