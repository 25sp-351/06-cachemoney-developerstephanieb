#include "memoize.h"
#include <stdio.h>
#include <stdlib.h>

extern char *money_text(int cents);

char_func_ptr money_provider = NULL;

static char_func_ptr original_provider = NULL;

static char *results[MAX_SIZE];

static char *cache(int val) {
  if (val >= 0 && val < MAX_SIZE) {
    if (results[val] == NOT_PRESENT) {
      results[val] = (*original_provider)(val);
    }
    return results[val];
  } else {
    return (*original_provider)(val);
  }
}

void init_cache(void) {
  for (int i = 0; i < MAX_SIZE; i++) {
    results[i] = NOT_PRESENT;
  }

  original_provider = money_text;
  money_provider = cache;
}