#!/bin/bash

echo '################ mouli test 3 (EXPECTED) ###########'
echo '{Li} {Ly}$'
echo '=> Lyon, 43 rue Guillotin$'
echo '################ mouli test 3 (GOT) ################'
../.././autoCompletion mouli_test3 2>/dev/null < input | cat -e