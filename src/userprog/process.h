#ifndef USERPROG_PROCESS_H
#define USERPROG_PROCESS_H

#include "threads/thread.h"
#include "threads/synch.h"
#include "filesys/file.h"
#include "filesys/directory.h"
#include "../lib/user/syscall.h"

tid_t process_execute(const char *file_name);
int process_wait(tid_t);
void process_exit(void);
void process_activate(void);

struct process_init_info {
	char *file_name;
	struct semaphore init_done;
	bool success;
};

struct file_descriptor {
	struct file *file;
	struct dir* dir;
	int fdn;
	struct list_elem fd_elem;
};

struct mmap {
	mapid_t id;

	void *vPage;
	struct file *file;
	size_t size;

	struct list_elem mmap_elem;
};

#define STACK_MAX 0x800000

#endif /* userprog/process.h */
