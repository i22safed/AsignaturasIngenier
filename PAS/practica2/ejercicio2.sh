#!/bin/bash

cat peliculas.txt | sed -r -e 's/(.{50,50}).*/\1.../g' | sed -r -e 's/\(([0-9]*)\) \[(.*)\]/\1, \2/g'
