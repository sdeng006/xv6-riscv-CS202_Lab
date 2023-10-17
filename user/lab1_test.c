#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"

struct pinfo {
    int ppid;
    int syscall_count; 
    int page_useage;
};

int main(int argc, char *argv[])
{
    int p1; 
    p1 = get_sys_procinfo();
    print(p1);
    exit(0);
}

