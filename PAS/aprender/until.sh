#!/bin/bash

read -p "Introduzca un número: " x

until [ $x -le 0 ]
do
  echo $x

  let "x=$x-1"
  sleep 1

done

echo "TERMINADO"
