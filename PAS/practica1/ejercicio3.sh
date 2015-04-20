#!/bin/bash

numeroFicheros=0

for param in $(find *)
do
  if [ -f $param ]
  then

    let "numeroFicheros=$numeroFicheros+1"

  fi

done

echo "$numeroFicheros ficheros hay en la carpeta actual"

echo "Ahora vamos a ver que usuarios hay conectados"

who -u | cut -f1 -d ' '

read -t 5 -p "Introduce el caracter: " caracter

if [ -z caracter ]
  then

    caracter="a"
fi

veces=$(find . -name "*$caracter*" | wc -l)

echo "El $caracter aparece $veces en los diferentes ficheros"
