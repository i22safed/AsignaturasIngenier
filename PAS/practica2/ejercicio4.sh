#!/bin/bash

if [ $# -eq 2 ]
then
	while read ip;
	do

	tiempoRespuesta=$(ping -c1 $ip -w $2 | grep 'time=.* ' -o | sed 's/time=//')

	if [ "$tiempoRespuesta" == "" ]
	then
		echo "La IP $ip no respondió tras $2 segundos">> registroIP.tmp
	else
		echo "La IP $ip respondió, en $tiempoRespuesta milisegundos">> registroIP.tmp
	fi
	done < <(cat $1)
	cat registroIP.tmp | sort -k6
	rm registroIP.tmp

else
	echo "Error al introducir argumentos. La forma correcta es <$0><IPs.txt><Segundos a ejecutar el programa>"
fi
