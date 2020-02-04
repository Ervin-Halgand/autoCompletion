#!/bin/bash

echo '################ mouli test 17 (EXPECTED) ##########'
echo '{n} {m} {t}$'
echo '{1 : MARSEILLE, 34 place CHAMPOLLION} {2 : MARSEILLE, 34 rue CHAMPOLLION}$'
echo '=> Marseille, 34 rue Champollion$'
echo '################ mouli test 17 (GOT) ###############'
../.././autoCompletion mouli_test17 2>/dev/null < input | cat -e