#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/resource.h>
#include <sys/time.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

static pid_t pid = 0;

void handler(int sig) 
{
    kill(pid, sig);
}

int main(int argc, char **argv)
{
  int wstatus = 0;
  struct rusage r;
  struct sigaction act;

  act.sa_handler = handler;
  sigaction(SIGINT, &act, NULL);

  if (argc < 2) {
    fprintf(stderr, "Usage: %s command ...\n", argv[0]);
    return -EXIT_FAILURE;
    }

    switch (pid = vfork()) {
    case -1:
        fprintf(stderr, "vfork error: %d\n", errno);
        return -EXIT_FAILURE;

    case 0:
        if (execvp(argv[1], argv + 1))
        {
          fprintf(stderr, "vfork error: %d\n", errno);
          return -EXIT_FAILURE;
        }
        return 0;
    }

    wait4(pid, &wstatus, 0, &r);

    printf("------------ rusage summary ------------\n");
    printf("user time                       : %ld.%ld\n", r.ru_utime.tv_sec, r.ru_utime.tv_usec * 1000);
    printf("system time                     : %ld.%ld\n", r.ru_stime.tv_sec, r.ru_stime.tv_usec * 1000);
    printf("maximum resident set size       : %ld\n", r.ru_maxrss);
    printf("integral shared memory size     : %ld\n", r.ru_ixrss);
    printf("integral unshared data size     : %ld\n", r.ru_idrss);
    printf("integral unshared stack size    : %ld\n", r.ru_isrss);
    printf("page reclaims (soft page faults): %ld\n", r.ru_minflt);
    printf("page faults (hard page faults)  : %ld\n", r.ru_majflt);
    printf("swaps                           : %ld\n", r.ru_nswap);
    printf("block input operations          : %ld\n", r.ru_inblock);
    printf("block output operations         : %ld\n", r.ru_oublock);
    printf("IPC messages sent               : %ld\n", r.ru_msgsnd);
    printf("IPC messages received           : %ld\n", r.ru_msgrcv);
    printf("signals received                : %ld\n", r.ru_nsignals);
    printf("voluntary context switches      : %ld\n", r.ru_nvcsw);
    printf("involuntary context switches    : %ld\n", r.ru_nivcsw);
    printf("----------------------------------------\n");
    return 0;
}

