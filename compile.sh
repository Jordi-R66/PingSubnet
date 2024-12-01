#!/usr/bin/bash

clear
gcc --std=c17 -Oz -s main.c headers/*.c -o a.out -lm