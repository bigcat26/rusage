#include <getopt.h>
#include <malloc.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char **argv) {
  int c;
  void *mem = NULL;
  int sleep_ms = 0;
  int free_flag = 0;

  while ((c = getopt(argc, argv, "d:m:f")) != EOF) {
    switch (c) {
    case 'd':
      sleep_ms = strtoul(optarg, NULL, 10);
      break;
    case 'm':
      mem = calloc(strtoul(optarg, NULL, 10), 1);
      break;
    case 'f':
      free_flag = 1;
      break;
    }
  }

  if (sleep_ms > 0) {
    usleep(sleep_ms * 1000);
  }

  if (free_flag && mem) {
    free(mem);
  }
  return 0;
}