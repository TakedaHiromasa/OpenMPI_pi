#!/bin/sh  -x

cc -o pi pi.c
mpicc -o piOMP piOMP.c
mpicc -o piMPI piMPI.c

scp -r ~/PItest-C pi@172.16.148.232:~/
