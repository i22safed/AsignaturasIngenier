#!/bin/bash

read -p "Introduzca un primer numero:" num
read -p "Introduzca un segundo numero:" num2

let suma=$num+$num2
echo "Suma: $suma"

echo "Resta: $(($num-$num2))"

multiplicacion=$[$num*$num2]
echo "Multiplicación: $multiplicacion"

let division=$num/$num2
echo "División: $division"

echo "Módulo: $[$num%$num2]"
