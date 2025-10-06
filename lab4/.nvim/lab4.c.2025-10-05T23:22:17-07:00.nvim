#define _DEFAULT_SOURCE
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

struct header {
  uint64_t size;
  struct header *next;
};

// Got from Lab 4 printing details
void print_out(char *format, void *data, size_t data_size) {
  int BUF_SIZE = 32;
  char buf[BUF_SIZE];
  ssize_t len =
      snprintf(buf, BUF_SIZE,
               format data_size == sizeof(uint64_t) ? *(uint64_t *)data
                                                    : *(void **)data);
}

int main() {

  void *newBreak = sbrk(256);

  struct header *block_1 = (struct header *)newBreak;
  block_1->size = 128;
  block_1->next = NULL;

  newBreak = newBreak + 128;
  struct header *block_2 = (struct header *)newBreak;
  block_2->size = 128;
  block_2->next = block_1;

  print_out("first block", block_1, sizeof(block_1));
  print_out("Second block", block_2, sizeof(block_2));
  print_out("First block size", &block_1->size, sizeof(&block_1->size));
  print_out("First block next", block_1->next, sizeof(block_1->next));
  print_out("Second block size", &block_2->size, sizeof(&block_2->size));
  print_out("Second block next", block_2->next, sizeof(block_2->next));
}
