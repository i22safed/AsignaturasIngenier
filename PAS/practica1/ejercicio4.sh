#!/bin/bash

if [ "$#" -eq 2 ] && [ -f "$1" ]
	then

		cabeza=1

		for param in $(grep -n $2 < $1 | cut -d ":" -f1 )
		do

			echo "--------------------------------------"
			echo "Emparejamiento número: $cabeza"

			posicion=0

			while read cadena
			do
				let "posicion=$posicion+1"

				if [ $param -eq $((posicion+1)) ] || [ $param -eq $posicion ] || [ $param -eq $((posicion-1)) ]
					then

					echo $cadena

				fi
			done < $1

			let "cabeza=$cabeza+1"

		done

		echo "--------------------------------------"

else

	echo "--------------------------------------"

	echo "error, formato a introducir: $0 [fichero] [comando]"

	echo "--------------------------------------"
fi
