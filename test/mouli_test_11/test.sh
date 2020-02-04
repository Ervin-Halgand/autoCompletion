#!/bin/bash

echo '################ mouli test 11 (EXPECTED) ##########'
echo '{Li} {Ly}$'
echo '{LILLE, f} {LILLE, j} {LILLE, p}$'
echo '=> Lille, 54 rue Popol$'
echo '################ mouli test 11 (GOT) ###############'
../.././autoCompletion mouli_test11 2>/dev/null < input | cat -e