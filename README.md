# rusage

## Brief

Show process rusage info of given command

## Sample

```shell
$ ./rusage ./test -d 3000 -m 1024
------------ rusage summary ------------
real time                       : 3.1 sec
user time                       : 0.1 sec
system time                     : 0.0 sec
maximum resident set size       : 1352
integral shared memory size     : 0
integral unshared data size     : 0
integral unshared stack size    : 0
page reclaims (soft page faults): 54
page faults (hard page faults)  : 0
swaps                           : 0
block input operations          : 1
block output operations         : 0
IPC messages sent               : 0
IPC messages received           : 0
signals received                : 0
voluntary context switches      : 2
involuntary context switches    : 0
----------------------------------------
```

```shell
$ ./rusage ./test -d 500 -m 8192000 
------------ rusage summary ------------
real time                       : 0.511 sec
user time                       : 0.0 sec
system time                     : 0.11 sec
maximum resident set size       : 9360
integral shared memory size     : 0
integral unshared data size     : 0
integral unshared stack size    : 0
page reclaims (soft page faults): 2055
page faults (hard page faults)  : 0
swaps                           : 0
block input operations          : 1
block output operations         : 0
IPC messages sent               : 0
IPC messages received           : 0
signals received                : 0
voluntary context switches      : 2
involuntary context switches    : 0
----------------------------------------
```