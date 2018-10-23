#!/bin/bash

echo "【単体C】"
time ./pi

#echo "----------------------------------"
#echo "【openMP?】"
#time mpirun -n 2 -machinefile host.txt piOMP

echo "----------------------------------"
echo "【MPI】"
time mpirun -n 2 -machinefile host.txt piMPI

