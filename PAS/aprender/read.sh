#!/bin/bash

echo -n "Introduzca nombre de fichero a borrar:"

read fichero

rm -i $fichero #la opcion -i pide confirmación

echo "fichero $fichero borrado!"
