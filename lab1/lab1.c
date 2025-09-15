#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Used help from chatgpt to explain return values of strtok_r to determine loop
// break.
int main() {
  char *buff = NULL;
  size_t size = 0;
  char *saveptr;

  printf("Please enter some text:\n");
  ssize_t num_char = getline(&buff, &size, stdin);
  if (num_char == -1) {
    perror("getline failed");
    exit(EXIT_FAILURE);
  }

  printf("Tokens:\n");
  char *ret = strtok_r(buff, " ", &saveptr);
  printf("%s\n", ret);
  char *ret2 = strtok_r(NULL, " ", &saveptr);
  while (ret2 != NULL) {
    printf("%s\n", ret2);
    ret2 = strtok_r(NULL, " ", &saveptr);
  }

  free(buff);
}
