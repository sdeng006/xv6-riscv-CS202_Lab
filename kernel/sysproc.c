#include "types.h"
#include "riscv.h"
#include "defs.h"
#include "param.h"
#include "memlayout.h"
#include "spinlock.h"
#include "proc.h"

uint64
sys_exit(void)
{
  int n;
  argint(0, &n);
  exit(n);
  return 0;  // not reached
}

uint64
sys_getpid(void)
{
  return myproc()->pid;
}

uint64
sys_fork(void)
{
  return fork();
}

uint64
sys_wait(void)
{
  uint64 p;
  argaddr(0, &p);
  return wait(p);
}

uint64
sys_sbrk(void)
{
  uint64 addr;
  int n;

  argint(0, &n);
  addr = myproc()->sz;
  if(growproc(n) < 0)
    return -1;
  return addr;
}

uint64
sys_sleep(void)
{
  int n;
  uint ticks0;

  argint(0, &n);
  acquire(&tickslock);
  ticks0 = ticks;
  while(ticks - ticks0 < n){
    if(killed(myproc())){
      release(&tickslock);
      return -1;
    }
    sleep(&ticks, &tickslock);
  }
  release(&tickslock);
  return 0;
}

uint64
sys_kill(void)
{
  int pid;

  argint(0, &pid);
  return kill(pid);
}

// return how many clock tick interrupts have occurred
// since start.
uint64
sys_uptime(void)
{
  uint xticks;

  acquire(&tickslock);
  xticks = ticks;
  release(&tickslock);
  return xticks;
}

uint64
sys_info(void)
{
  
  // lab1 part1

  return 0;
}

struct pinfo {
    int ppid;
    int syscall_count; 
    int page_useage;
};

int
sys_procinfo(struct pinfo *p) 
{
  float ppid; 
  int sys_call_count;
  float page_usage; 
  ppid = getppid();
  sys_call_count = get_sys_calls_count(); 

  struct proc *curproc = myproc();
  uint sz_aligned = PGROUNDUP(curproc->sz);
  page_usage = sz_aligned / PGSIZE; // Calculate the memory usage in terms of pages

  // return 0 if successful else return -1
  if (*p )
  {
    return 0;
  }
  else
  {
    return -1;
  }
}