#!/bin/bash

echo '################ mouli test 1 (EXPECTED) ###########'
echo '=> Lille, 34 rue Faidherbe$'
echo '################ mouli test 1 (GOT) ################'
../.././autoCompletion mouli_test1 2>/dev/null | cat -e