#!/bin/bash
gcc -fPIC -Wall -c *.c
gcc -shared *.o -o liball.so
