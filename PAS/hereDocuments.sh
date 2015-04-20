#!/bin/bash
cat << EOF
Información del uso del programa
Lista y/o borra todos los enlaces de un directorio
USO : $0 [-d] [-oD ficheroLog] [-l] [-h] [directorio]
-d borrar los enlaces
-l listar los enlaces (por defecto)
-o escribir los enlaces encontrados en un fichero de log
-D borrar los enlaces que haya dentro de un fichero de log
-h mostrar este mensaje
EOF

