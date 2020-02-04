#!/bin/bash

echo '################ mouli test 12 (EXPECTED) ##########'
echo '{STRASBOURG, d} {STRASBOURG, p} {STRASBOURG, f} {STRASBOURG, l}$'
echo '=> Strasbourg, 34 rue de Faidherbe$'
echo '################ mouli test 12 (GOT) ###############'
../.././autoCompletion mouli_test12 2>/dev/null < input | cat -e