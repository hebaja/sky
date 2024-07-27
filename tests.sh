#!/bin/bash

echo -n "16 numbers -> "
./a.out "4 3 2 1 1 2 2 2 4 3 2 1 1 2 2 2"
echo -n "15 numbers -> "
./a.out "4 3 2 1 1 2 2 2 4 3 2 1 1 2 2"
echo -n "17 numbers -> "
./a.out "4 3 2 1 1 2 2 2 4 3 2 1 1 2 2 2 4"
echo -n "Zero start -> "
./a.out "0 3 2 1 1 2 2 2 4 1 2 1 1 2 2 2"
echo -n "123 end -> "
./a.out "4 3 2 1 1 2 2 2 4 1 2 1 1 2 2 123"
echo -n "8 middle -> "
./a.out "4 3 2 1 1 2 2 8 4 3 2 1 1 2 2 2"
echo -n "a middle -> "
./a.out "4 3 2 1 1 2 2 a 4 3 2 1 1 2 2 2"
echo -n "+ middle -> "
./a.out "4 3 2 1 1 2 2 2 4 3 2 + 1 2 2 2"
echo -n "No arg -> "
./a.out

