#!/bin/bash

echo '################ mouli test 5 (EXPECTED) ###########'
echo '{m} {d}$'
echo '=> Mont de Marsan, 34 rue Faidherbe$'
echo '################ mouli test 5 (GOT) ################'
../.././autoCompletion mouli_test5 2>/dev/null < input | cat -e