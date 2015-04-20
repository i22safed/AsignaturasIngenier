#!/bin/bash

read user

if [ $user == $USER ]
  then

  echo "Bienvenido \"$user\""

else

  echo "Eso es mentira!"

fi
