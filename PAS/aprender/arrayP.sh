#!/bin/bash

miNuevoArray[0]="Gran"
miNuevoArray[1]="Array"
miNuevoArray[2]="Triunfador"

echo ${miNuevoArray[2]}

miNuevoArray=( "Gran" "Array" "Triunfador" )

echo ${miNuevoArray[1]}
echo ${miNuevoArray[*]}
  
echo ${#miNuevoArray[@]}
