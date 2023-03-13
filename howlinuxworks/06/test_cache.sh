#!/bin/bash
mkdir out
cc -O3 -o out/cache cache.c
for i in 4 8 16 32 64 128 256 512 1024 2048 4096 8192 16384 32768 65536 131072;
  do 
    echo "[ $i ]"
    out/cache $i;  
  done