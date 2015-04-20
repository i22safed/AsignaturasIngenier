#!/bin/bash

pasarFichero()
{

  dato=$(stat -c%Y "$1")

  fechaSistema=$(date +%s)

  diferencia=$[fechaSistema-dato]

    if [ $diferencia -gt 20 ]
    then

      cp "$1" "$carpetaTemporal"
    else
      echo "Desde la creacion del fichero $1 no pasaron 20 segundos"
    fi
}

recorrerCarpetas()
{
  cd $1

  for x in *
  do
    if [ -d  $x ]
    then
      recorrerCarpetas $x
    else
      pasarFichero $x
    fi
  done

  cd ..
}

if [ $# -eq 1 ] || [ $# -eq 2 ]
then
  carpetaTemporal=$(mktemp -d)

  if [ -d "$1" ]
  then
    cd $1

    for x in *
    do
      if [ -d $x ]
      then
        recorrerCarpetas $x
      else
        pasarFichero $x
      fi
    done

    cd ..

    if [ $# -eq 2 ]
    then
      comprimir="$2.tar.gz"
      tar czvf "$comprimir" "$carpetaTemporal"
      echo "Archivo $comprimir creado correctamente"
    else
      comprimir="$1.tar.gz"
      tar czvf "$comprimir" "$carpetaTemporal"
      echo "Archivo $comprimir creado correctamente"
    fi
  else
    echo "No existe $1"
    exit 1
  fi
  rm -r "$carpetaTemporal"

else
  echo "Error, el formato es $0 nombreCarpeta nombreArchivoComprimido(Este ultimo es opcional)"

  exit 1

fi
