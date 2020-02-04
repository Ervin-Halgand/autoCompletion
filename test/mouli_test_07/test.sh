#!/bin/bash

echo '################ mouli test 7 (EXPECTED) ###########'
echo '{m} {d}$'
echo '{Mo} {Ma}$'
echo '{1 : MONT de marsan}$'
echo '=> Mont de Marsan, 34 rue Faidherbe$'
echo '################ mouli test 7 (GOT) ################'
../.././autoCompletion mouli_test7 2>/dev/null < input | cat -e