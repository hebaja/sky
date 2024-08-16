#!/bin/bash

echo "4 3 2 1 1 2 2 2 4 3 2 1 1 2 2 2"
echo
./rush01 "4 3 2 1 1 2 2 2 4 3 2 1 1 2 2 2" | cat -e
echo
echo "2 2 3 1 2 3 1 2 2 2 1 2 1 3 4 2"
echo
./rush01 "2 2 3 1 2 3 1 2 2 2 1 2 1 3 4 2" | cat -e
echo
echo "1 2 3 2 3 1 2 2 1 3 2 2 3 1 2 2"
echo
./rush01 "1 2 3 2 3 1 2 2 1 3 2 2 3 1 2 2" | cat -e
echo
echo "2 3 2 1 3 2 1 3 3 1 2 3 1 2 3 2"
echo
./rush01 "2 3 2 1 3 2 1 3 3 1 2 3 1 2 3 2" | cat -e
echo
echo "3 2 1 3 2 2 4 1 3 2 1 2 2 3 2 1"
echo
./rush01 "3 2 1 3 2 2 4 1 3 2 1 2 2 3 2 1" | cat -e
echo
echo "2 4 2 1 2 1 2 4 3 1 3 2 1 2 2 3"
echo
./rush01 "2 4 2 1 2 1 2 4 3 1 3 2 1 2 2 3" | cat -e
echo
echo "2 2 1 4 2 2 4 1 3 2 1 2 2 3 2 1"
echo
./rush01 "2 2 1 4 2 2 4 1 3 2 1 2 2 3 2 1"| cat -e
echo
echo "1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1"
echo
./rush01 "1 1 1 1 1 1 1 1 1 1 1 1 1 1 1"| cat -e
echo
echo -n "15 numbers -> "
./rush01 "4 3 2 1 1 2 2 2 4 3 2 1 1 2 2" | cat -e
echo -n "17 numbers -> "
./rush01 "4 3 2 1 1 2 2 2 4 3 2 1 1 2 2 2 4" | cat -e
echo -n "Zero start -> "
./rush01 "0 3 2 1 1 2 2 2 4 1 2 1 1 2 2 2" | cat -e
echo -n "123 end -> "
./rush01 "4 3 2 1 1 2 2 2 4 1 2 1 1 2 2 123" | cat -e
echo -n "8 middle -> "
./rush01 "4 3 2 1 1 2 2 8 4 3 2 1 1 2 2 2" | cat -e 
echo -n "a middle -> "
./rush01 "4 3 2 1 1 2 2 a 4 3 2 1 1 2 2 2" | cat -e
echo -n "+ middle -> "
./rush01 "4 3 2 1 1 2 2 2 4 3 2 + 1 2 2 2" | cat -e
echo -n "No arg -> "
./rush01 | cat -e

