#!/bin/bash
find /etc/rc?.d -name "S*"| while read f
do
  fichero=$(dirname $f)
  nombre=$(basename $f)

  echo "$fichero -> $nombre"
done | more
