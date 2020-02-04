#!/bin/bash

echo '################ mouli test 8 (EXPECTED) ###########'
echo '{m} {d}$'
echo '{Mo} {Ma}$'
echo '{1 : MONT de marsan}$'
echo '=> Montpellier, 56 rue Gandhi$'
echo '################ mouli test 8 (GOT) ################'
../.././autoCompletion mouli_test8 2>/dev/null < input | cat -e