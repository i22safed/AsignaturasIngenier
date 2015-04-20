#!/bin/bash

if [ $# -eq 0 ]
  then

    echo "error, el formato es: $0 [carpeta] [cadena]"

  else
    if [ $# == 2 ]
      then

        ruta=$(find "$1" -type f -name "*$2*" | xargs ls -li | sort -n -k 6)
    else

        ruta=$(find "$1" -type f | xargs ls -li | sort -n -k 6)
    fi

    echo "ruta; tamaño del fichero; referencias; cadena de permisos; permiso de ejecucion"

    for param in $(echo "$ruta" | awk -F ' ' '{ print $10 }')
    do
      fichero=$(stat -c%s "$param")
      referencias=$(stat -c%i "$param")
      permisos=$(stat -c%A "$param")

      if [ -x "$param" ]
        then
          permisoEjecucion=1
      else
          permisoEjecucion=0
      fi

      echo "$param; $fichero; $referencias; $permisos; $permisoEjecucion"
    done
fi
