#!/bin/bash
gcc -Wall -pedantic -Werror -c -fPIC *.c
gcc -shared -o liball.so *.o
