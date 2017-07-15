#!/bin/bash

i=0

while [ $i -lt $1 ] ; do
    ./zappy_ai -p 4242 -n $2 -h 127.0.0.1 &
    i=$(($i+1))
done
