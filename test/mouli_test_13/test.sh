#!/bin/bash

echo '################ mouli test 13 (EXPECTED) ##########'
echo '{STRASBOURG, d} {STRASBOURG, p} {STRASBOURG, f} {STRASBOURG, l}$'
echo '{STRASBOURG, Pe} {STRASBOURG, Po}$'
echo '=> Strasbourg, 4 boulevard des perdus$'
echo '################ mouli test 13 (GOT) ###############'
../.././autoCompletion mouli_test13 2>/dev/null < input | cat -e