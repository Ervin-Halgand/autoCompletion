#!/bin/bash

echo '################ test 1 (ABORT) ################'
.././autoCompletion exampleDict 2>/dev/null < test1 | cat -e
echo $? '= return value'
echo '################ test 4 (One letter) ###########'
.././autoCompletion exampleDict 2>/dev/null < test4 | cat -e
echo $? '= return value'
echo '################ test 9 (Two choices) ##########'
.././autoCompletion exampleDict 2>/dev/null < test9 | cat -e
echo $? '= return value'
echo '################ test Error (bad input) ########'
echo x | .././autoCompletion exampleDict 1>/dev/null
echo $? '= return value'
echo '################ test street_type marseille ####'
.././autoCompletion exampleDict 2>/dev/null < test2 | cat -e
echo $? '= return value'
echo '################ test 8 (multiple choice) ######'
.././autoCompletion exampleDict 2>/dev/null < test8
echo $? '= return value'
echo '################ test 5 (tree choice) ######'
.././autoCompletion exampleDict 2>/dev/null < test5
echo $? '= return value'