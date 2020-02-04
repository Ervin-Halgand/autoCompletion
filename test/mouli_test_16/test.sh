#!/bin/bash

echo '################ mouli test 16 (EXPECTED) ##########'
echo '{n} {m} {t}$'
echo '{NANc} {NANt}$'
echo '{1 : NANCY, 45 BOULEVARD DE LA MOSELLE} {2 : NANCY, 89 BOULEVARD DE LA MOSELLE}$'
echo '=> Nancy, 89 boulevard de la Moselle$'
echo '################ mouli test 16 (GOT) ###############'
../.././autoCompletion mouli_test16 2>/dev/null < input | cat -e