#!/bin/bash
iter=0

make


mainfile="berlin52"
output="./Tours/$mainfile/output"

while [ $iter -le 30 ];
  do
    ./ga "./Tours/$mainfile.bin" $output$iter $iter
    let iter=iter+1
  done
