#!/bin/bash

echo -n "16 numbers -> "
./a.out "4 3 2 1 1 2 2 2 4 3 2 1 1 2 2 2" | cat -e
echo -n "16 numbers -> "
./a.out "2 2 3 1 2 3 1 2 2 2 1 2 1 3 4 2" | cat -e
echo -n "16 numbers -> "
./a.out "1 2 3 2 3 1 2 2 1 3 2 2 3 1 2 2" | cat -e
echo -n "16 numbers -> "
./a.out "2 3 2 1 3 2 1 3 3 1 2 3 1 2 3 2" | cat -e
echo -n "16 numbers -> "
./a.out "3 2 1 3 2 2 4 1 3 2 1 2 2 3 2 1" | cat -e
echo -n "16 numbers -> "
./a.out "2 4 2 1 2 1 2 4 3 1 3 2 1 2 2 3" | cat -e
echo -n "16 numbers -> "
./a.out "2 2 1 4 2 2 4 1 3 2 1 2 2 3 2 1"| cat -e
echo -n "15 numbers -> "
./a.out "4 3 2 1 1 2 2 2 4 3 2 1 1 2 2" | cat -e
echo -n "17 numbers -> "
./a.out "4 3 2 1 1 2 2 2 4 3 2 1 1 2 2 2 4" | cat -e
echo -n "Zero start -> "
./a.out "0 3 2 1 1 2 2 2 4 1 2 1 1 2 2 2" | cat -e
echo -n "123 end -> "
./a.out "4 3 2 1 1 2 2 2 4 1 2 1 1 2 2 123" | cat -e
echo -n "8 middle -> "
./a.out "4 3 2 1 1 2 2 8 4 3 2 1 1 2 2 2" | cat -e 
echo -n "a middle -> "
./a.out "4 3 2 1 1 2 2 a 4 3 2 1 1 2 2 2" | cat -e
echo -n "+ middle -> "
./a.out "4 3 2 1 1 2 2 2 4 3 2 + 1 2 2 2" | cat -e
echo -n "No arg -> "
./a.out | cat -e

