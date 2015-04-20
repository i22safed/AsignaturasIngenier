#!/bin/bash

echo '1) Lineas con la duracion de las películas:'
cat peliculas.txt | grep -E '[0-9]*\ min\.*'
echo '------------------------------------'

echo '2) Lineas con el país de las películas'
cat peliculas.txt | grep -E '\[\]*'
echo '------------------------------------'

echo '3) Solo el país de las películas'
cat peliculas.txt | grep -E -o '\[.*\]+'
echo '------------------------------------'

pelicula1=$(cat peliculas.txt | grep -E -o -c '(2014)')
pelicula2=$(cat peliculas.txt | grep -E -o -c '(2015)')

echo '4) Hay peliculas '$pelicula1' del 2014 y '$pelicula2' del 2015'
echo '------------------------------------'

echo '5) Eliminar lineas vacias:'
cat peliculas.txt | grep -E  '^[^ ]+'
echo '------------------------------------'

echo '6) Lineas que empiezan la letra C (con o sin espacios antes):'
cat peliculas.txt | grep -E -i '^\ *c'
echo '------------------------------------'

echo '7) Lineas que contienen d, l o t, una vocal y la misma letra:'
cat peliculas.txt | grep -E '([tdl])[aeiou]\1'
echo '------------------------------------'

echo '8) Lineas que contienen ocho aes o más:'
cat peliculas.txt | grep -E '(.*[a].*){8,}'
echo '------------------------------------'

echo '9) Lineas que terminan con tres puntos y no empiezan por espacio:'
cat peliculas.txt | grep -E '^[[:alnum:]].*[.]{3,}$'
echo '------------------------------------'

echo '10) Mostrar entre comillas las vocales con tilde:'
cat peliculas.txt | sed -r -n -e 's/([ÁÉÍÓÚáéíóú])/"\1"/p'
