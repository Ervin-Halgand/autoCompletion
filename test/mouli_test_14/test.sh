#!/bin/bash

echo '################ mouli test 14 (EXPECTED) ##########'
echo '{STRASBOURG, d} {STRASBOURG, p} {STRASBOURG, f} {STRASBOURG, l}$'
echo '{1 : STRASBOURG, 34 rue DE faidherbe} {2 : STRASBOURG, 54 rue DE la porte}$'
echo '=> Strasbourg, 4 boulevard des perdus$'
echo '################ mouli test 14 (GOT) ###############'
../.././autoCompletion mouli_test14 2>/dev/null < input | cat -e