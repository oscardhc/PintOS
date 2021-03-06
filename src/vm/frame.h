//
// Created by sheepp on 2020/6/26.
//

#ifndef PINTOS_FRAME_H
#define PINTOS_FRAME_H

#include "../threads/palloc.h"
#include "../lib/kernel/hash.h"
#include "../threads/thread.h"

struct frame_entry {
    void *frame;
    void *upage;
    struct thread *thread;
    struct hash_elem hash_elem;
    struct list_elem list_elem;
    bool pinned;
};

void frame_init();

void* frame_get(enum palloc_flags flag, void *upage);

void frame_free(void *frame);
void frame_remove_entry(void *frame); //Remove entry but keep the frame

bool frame_if_pinned(void *frame);
void frame_pin(void *frame);
void frame_release_pinned(void *frame);

#endif //PINTOS_FRAME_H
