#!/bin/bash

echo '################ mouli test 10 (EXPECTED) ##########'
echo '{LILLE, FAIDHe} {LILLE, FAIDHi}$'
echo '=> Lille, 34 rue Faidherbe$'
echo '################ mouli test 10 (GOT) ###############'
../.././autoCompletion mouli_test10 2>/dev/null < input | cat -e