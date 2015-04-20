#/bin/bash -x
#como argumentos se le pasa la ruta de los dos ficheros
funcion(){
  if [ -e $2 ]
    then
    echo "¿Desea sobreescribir el archivo $1 en la ruta $2? s/n"
    read -n 1 opc
    if [ $opc == 's' ]
      then
        cp "$1" "$3"
        contar=1
      else
        echo "No se sobreescribirá"
        contar=0
    fi
  else
    cp "$1" "$3"
    contar=1
  fi
}
recursiva(){
  cd $1
  #ls $x | while read f
  for f in *
  do
    if [ -d $f ]
      then
      recursiva $f
    else
    aux=$(basename $f)
    ejec=$(ls -l $f | cut -c 4)
    if [ $ejec == "x" ]   #aqui tratamos con los ejecutables
      then
      #no debería de contar si ya existe
        funcion "$aux" "$ejecutables/$aux" $ejecutables
        if [ $contar == 1 ]
          then
          contadorej=$[$contadorej+1]
        fi
    fi

    lib="lib"
    if [[ $aux == lib* ]]
    then
      #no debería de contar si ya existe
      funcion "$aux" "$librerias/$aux" $librerias
      if [ $contar == 1 ]
        then
      contadorlib=$[$contadorlib+1]
      fi

    fi

    if [[ $aux == *.c ]]
      then
      funcion "$aux" "$codigos/$aux" $codigos
      if [ $contar == 1 ]
        then
        contadorcod=$[$contadorcod+1]
      fi
      otro=$(ls $aux | cut -f1 -d ".")
      touch "$otro.txt"
      fecha=$(date +%d/%s/%y)
      hora=$(date +%h:%m:%s)
      echo "La fecha es :$fecha" >> $otro.txt
      echo "La hora es :$hora" >> $otro.txt
      gcc "$aux" -o "$ejecutables/$otro"
      if [ $? != 0 ]
        then
          echo "$aux dio error al compilar"
        else
          contadorej=$[$contadorej+1]
          #no debería de contar si ya existe

      fi
      gcc "$aux" -o "$ejecutables/$otro" &>> $otro.txt
      #mv $otro.txt "$codigos/$otro.txt" $codigos

    fi
    if [[ $aux == *.cpp ]]
      then
        funcion "$f" "$codigos/$aux" $codigos
        if [ $contar == 1 ]
          then
            contadorcod=$[$contadorcod+1]
        fi

        otro=$(ls $aux | cut -f1 -d ".")
        touch "$otro.txt"
        fecha=$(date +%d/%s/%y)
        echo "La fecha es :$fecha" >> $otro.txt
        g++ "$aux" -o "$ejecutables/$otro"
        if [ $? != 0 ]
          then
          echo "$aux dio error al compilar"
        else
          contadoej=$[contadorej+1]
        fi
        g++ "aux" -o "$ejecutables/$otro" &>> $otro.txt

      #  mv $otro.txt "$codigos/$otro.txt" $codigos
    fi

    if [[ $aux == *.h ]]
      then
        funcion "$f" "$cabeceras/$aux" "$cabeceras"
        if [ $contar == 1 ]
          then
            contadorcabe=$[$contadorcabe+1]
        fi

    fi
  fi
  done
  cd ..
}

numarg=$#
#mkdir /home/jose/ejecutables
#mkdir /home/jose/librerias
#mkdir /home/jose/codigo
#mkdir /home/jose/cabeceras

#Pedimos los nombres de las carpetas

echo "Introduce el nombre y la direccion de la carpeta donde se almacenaran los ejecutables"
read -t 2 ejecutables
echo "Introduce el nombre y la direccion de la carpeta donde se almacenaran los librerias"
read -t 2 librerias
echo "Introduce el nombre y la direccion de la carpeta donde se almacenaran los codigos"
read -t 2 codigos
echo "Introduce el nombre y la direccion de la carpeta donde se almacenaran los cabeceras"
read -t 2 cabeceras

#Comprobamos que se ha escrito algo, si no se le aplica
#el valor por defecto

if [ -z $ejecutables ]
  then ejecutables="/home/jose/ejecutables"
  #"$HOME/bin"
fi
if [ -z $librerias ]
  then librerias="/home/jose/librerias"
  #"$HOME/lib"
fi
if [ -z $codigos ]
  then codigos="/home/jose/codigo"
  #"$HOME/src"
fi
if [ -z $cabeceras ]
  then cabeceras="/home/jose/cabeceras"
  #"$HOME/include"
fi

echo "El directorio para almacenar ejecubales es: $ejecutables"
echo "El directorio para almacenar librerias es: $librerias"
echo "El directorio para almacenar codigos es: $codigos"
echo "El directorio para almacenar cabeceras es: $cabeceras"

#recorremos los archivos
contadorej=0
contadorlib=0
contadorcod=0
contadorcabe=0
contadordirectorios=0
for x in $*
do
  recursiva $x
done
echo "Número de archivos procesados $[$contadorej+$contadorlib+$contadorcod+$contadorcabe]"
echo "numero de ejecutables: $contadorej"
echo "numero de librerias: $contadorlib"
echo "numero de codigos: $contadorcod"
echo "numero de cabeceras: $contadorcabe"
