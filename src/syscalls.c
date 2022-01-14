#include "types.h"
#include "stat.h"
#include "user.h"

int
main(int argc, char **argv)
{
  int i, mypid;
  if(argc < 3){
    printf(2, "usage: syscalls N g...\n");
    exit();
  }
  int totalcalls = atoi(argv[1]);
  int successfulcalls = atoi(argv[2]);
  int badCalls = totalcalls - successfulcalls;
  // Good calls
  for(i=0; i < successfulcalls - 1; i++){
    getpid();
  }
  // Bad calls
  for(i=0; i < badCalls; i++){
    kill(-1);
  }
  mypid = getpid();
  printf(2, "%d %d\n", getnumsyscalls(mypid), getnumsyscallsgood(mypid));
  exit();
}
