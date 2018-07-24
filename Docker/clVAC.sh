#!/bin/bash

# Usage:
# Go into cmd loop: sudo ./clVAC.sh
# Run single cmd:  sudo ./clVAC.sh <clVAC paramers>

PREFIX="docker-compose exec nodVACd clVAC"
if [ -z $1 ] ; then
  while :
  do
    read -e -p "clVAC " cmd
    history -s "$cmd"
    $PREFIX $cmd
  done
else
  $PREFIX "$@"
fi
