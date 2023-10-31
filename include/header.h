#ifndef HEADER_H
#define HEADER_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "types.h"
#include "constants.h"

// Utils
int size_of_string_list(string *);
void trim(string, string);
void split(string, string *, char);
void merge_strings(string *, string);
bool str_equal(string, const string);
void clear_buffer();

// commands executer/runner
void run_command(string *command);

// Commands Handlers
void echo(string *);
void cat(string *);

#endif // HEADER_H