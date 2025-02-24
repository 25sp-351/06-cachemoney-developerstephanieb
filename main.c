#include "memoize.h"
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *money_text(int cents) {
  if (cents < 0) {
    char *negativeMsg = (char *)malloc(32);
    strcpy(negativeMsg, "Negative not supported");
    return negativeMsg;
  }

  int dollarPart = cents / 100;
  int centPart = cents % 100;

  char temp[128];
  snprintf(temp, sizeof(temp), "%d dollar%s and %d cent%s", dollarPart,
           (dollarPart == 1 ? "" : "s"), centPart, (centPart == 1 ? "" : "s"));

  char *result = (char *)malloc(strlen(temp) + 1);
  strcpy(result, temp);
  return result;
}

int parse_cents(const char *input, int *cents) {
  char extra;

  if (sscanf(input, "%d%c", cents, &extra) != 1) {
    return 1;
  }

  if (*cents < 0) {
    return 2;
  }

  return 0;
}

int main(int argc, char *argv[]) {
  init_cache();

  if (argc != 2) {
    fprintf(stderr, "Usage: %s <amount_in_cents>\n", argv[0]);
    return 1;
  }

  int cents;
  int status = parse_cents(argv[1], &cents);

  if (status == 1) {
    fprintf(stderr, "Invalid integer input: %s\n", argv[1]);
    return 1;
  } else if (status == 2) {
    fprintf(stderr, "Amount cannot be negative: %d\n", cents);
    return 1;
  }

  char *text = (*money_provider)(cents);

  printf("Text for %d cents: %s\n", cents, text);

  free(text);

  return 0;
}