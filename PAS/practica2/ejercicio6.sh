#!/bin/bash

if [ $# -eq 1 ]
then
while read usuario;
do
  		conectado=0
      echo $usuario | sed -r -n 's/(.*):(.*):(.*):(.*):(.*):(.*):(.*)/==========\nLogname: \1 \n->UID:\3/p'

      nombreUsuario=$(echo $usuario | sed -r -n 's/(.*):(.*):(.*):(.*):(.*):(.*):(.*)/\1/p')

      grupoID=$(echo -n $usuario | sed -r -n 's/(.*):(.*):(.*):(.*):(.*):(.*):(.*)/\4/p')

      if [ "$grupoID" == "" ]
      then
            echo "->Grupo: Usuario sin grupo"
      else
        while read grupo;
        do
          numeroGrupo=$(echo $grupo |sed -r -n 's/(.*):(.*):(.*):(.*)/\3/p')

          nombreGrupo=$(echo $grupo |sed -r -n 's/(.*):(.*):(.*):(.*)/\1/p')

          if [ "$numeroGrupo" == "$grupoID" ]
            then
              echo "->Grupo: $nombreGrupo"
          fi

        done < <(cat /etc/group)
      fi

      echo $usuario | sed -r -n 's/(.*):(.*):(.*):(.*):(.*):(.*):(.*)/->GID: \4 \n->gecos: \5 \n->Home: \6 \n->Shell por defecto: \7/p'

      while read usuarioActual;
      do

        if [ "$nombreUsuario" == "$usuarioActual" ]
          then
          conectado=1
        fi
        
      done < <(who | sed -r -n 's/([^ ]*)[ ]*([^ ]*)[ ]*([^ ]*)[ ]*([^ ]*)[ ]*([^ ]*)/\1/p')
      echo "->Logeado: $conectado"
done < <(cat /etc/passwd | grep "$1" )
else
	echo "Error al introducir argumentos. La forma correcta es <$0> <Cadena Shell>"
fi
