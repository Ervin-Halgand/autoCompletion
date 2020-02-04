#!/bin/bash

echo '################ mouli test 9 (EXPECTED) ###########'
echo '{LILLE, f} {LILLE, p}$'
echo '=> Lille, 34 rue Faidherbe$'
echo '################ mouli test 9 (GOT) ################'
../.././autoCompletion mouli_test9 2>/dev/null < input | cat -e