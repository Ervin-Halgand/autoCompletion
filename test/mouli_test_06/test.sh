#!/bin/bash

echo '################ mouli test 6 (EXPECTED) ###########'
echo '{m} {d}$'
echo '{Mo} {Ma}$'
echo '=> Mont de Marsan, 34 rue Faidherbe$'
echo '################ mouli test 6 (GOT) ################'
../.././autoCompletion mouli_test6 2>/dev/null < input | cat -e