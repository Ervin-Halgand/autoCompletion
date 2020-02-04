#!/bin/bash

echo '################ mouli test 4 (EXPECTED) ###########'
echo '{t} {l}$'
echo '=> Lille, 34 rue Faidherbe$'
echo '################ mouli test 4 (GOT) ################'
../.././autoCompletion mouli_test4 2>/dev/null < input | cat -e