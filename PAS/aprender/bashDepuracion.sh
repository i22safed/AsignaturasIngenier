#!/bin/bash -x

read -p "Introduzca un número: " x

let sum=0

for (( i=1 ; $i<$x ; i=$i+1 ))
do

  let "sum=$sum+$i"
done

echo "la suma de los $x primeros números es :$sum"
