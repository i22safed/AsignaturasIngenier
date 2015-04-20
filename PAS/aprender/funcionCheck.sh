#!/bin/bash

function chequea()
{
  if [ -e "$1" ]
    then

    return 0
  else

    return 1
  fi
}

read -p "Introduzca el nombre del archivo: " fichero

if chequea $fichero
  then

    echo "El archivo $fichero existe!"
  else

    echo "El archivo $fichero no existe"
fi
