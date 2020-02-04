#!/bin/bash

echo '################ mouli test 2 (EXPECTED) ###########'
echo '{l} {t}$'
echo '=> Lille, 34 rue Faidherbe$'
echo '################ mouli test 2 (GOT) ################'
../.././autoCompletion mouli_test2 2>/dev/null < input | cat -e
