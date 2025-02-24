#ifndef MEMOIZE_H
#define MEMOIZE_H

#define MAX_SIZE 150000
#define NOT_PRESENT NULL

typedef char *(*char_func_ptr)(int);

extern char_func_ptr money_provider;

void init_cache(void);

#endif