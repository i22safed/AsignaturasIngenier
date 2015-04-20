#!/bin/bash

mostrarHtml()
{

  let profundidad=1

  echo -e "<ul>" >> "$1.html"

  for param in $(find $2 -maxdepth $profundidad)
  do

    if [ $param != $2 ]
      then

      if [ -d $param ]
        then
        echo -e "<strong><li>./$param<li></strong>\n" >> "$1.html"

        mostrarHtml $1 $param

        echo -e "</ul>\n">>"$1.html"
      else
        echo -e "<li>./$param</li>\n" >> "$1.html"
      fi

    fi

  done
}

if [ $# -eq 1 ]
then

  if [ -d $1 ]
    then

    echo -e "<html>\n<head>\n<title>$1</title>\n</head>\n<body>\n<h1>Listado del directorio ./$1/</h1>" >"$1.html"

    mostrarHtml $1 $1

    echo -e "<body><style type="text/css"> body { font-family: sans-serif;} </style>">>"$1.html"
  else
    echo "error, no hay carpeta"

  fi

else

  echo "Error $0 nombreCarpeta"

fi
