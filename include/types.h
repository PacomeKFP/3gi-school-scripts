#ifndef TYPES_H
#define TYPES_H

typedef char *string;
typedef enum bool
{
    false,
    true
} bool;
typedef enum process_status
{
    RUNNING,
    SUSPENDED,
    TERMINATED
} process_status;
typedef struct ChildProcess
{
    pid_t pid;
    pid_t ppid;
    process_status status;
    string command;
} ChildProcess;




#define INIT_CHILD_PROCESS(pid, command, child) ChildProcess child = {.pid = pid, .status = RUNNING, .command = command};
#endif // TYPES_H