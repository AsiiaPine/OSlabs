#!bin/bash

if ![ -f ex2.txt ]
then
   echo 1> ex2.txt
fi

while [ 1 ]
do

  while [ -f ex2.lock ]
  do
    sleep 1
  done

  if ln ex2.sh ex2.lock
        then
        last=$(tail -n 1 < ex2.txt)
        last=$((last+1))
        echo "$last" >> ex2.txt
        rm ex2.lock
  fi
done
