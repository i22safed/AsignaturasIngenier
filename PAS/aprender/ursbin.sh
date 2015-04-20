#!/bin/bash

/usr/bin/[ 3 = 4 ]
echo $?

/usr/bin/[ 4 = 4 ]
echo $?

/usr/bin/[ 'asa' = 'asa' ]
echo $?

/usr/bin/[ 'asaa' = 'asa' ]
echo $?

read -p "Introduce una cadena: " s1
read -p "Introduce una cadena: " s2

/usr/bin/[ s1 == s2 ]
echo $?

/usr/bin/[ s1 != s2 ]
echo $?

/usr/bin/[ s1 ]
echo $?

/usr/bin/[ -n s1 ]
echo $?

/usr/bin/[ -z s2 ]
echo $?

/usr/bin/[[ s1 == s2* ]]
echo $?
