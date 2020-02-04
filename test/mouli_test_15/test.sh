#!/bin/bash

echo '################ mouli test 15 (EXPECTED) ##########'
echo '{n} {m} {t}$'
echo '=> Toulouse, 45 rue verte$'
echo '################ mouli test 15 (GOT) ###############'
../.././autoCompletion mouli_test15 2>/dev/null < input | cat -e