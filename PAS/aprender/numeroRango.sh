#!/bin/bash

read -p "Introduzca un numero (1 <= x < 10): " n

if [ $n -ge 1 -a $n -lt 10 ]
  then

  echo "El numero $n es correcto!"

else

  echo "Fuera de rango!"

fi
