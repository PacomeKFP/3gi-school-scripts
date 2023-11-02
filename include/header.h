#ifndef HEADER_H
#define HEADER_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <signal.h>
#include <unistd.h>
#include <sys/wait.h>
#include "types.h"
#include "constants.h"

// Utils
bool file_exists(string);
void trim(string, string);
void clear_buffer();
bool n_compare(string, string);
void add_process(ChildProcess);
void remove_process(ChildProcess);

// commands executer/runner
void run_command(string);
bool file_exists(string);

// Commands Handlers
void echo(string);
void cat(string);
void clear();
void close_shell();
void call_extern(string, bool);
void ps();

// Signals Handlers

#endif // HEADER_H