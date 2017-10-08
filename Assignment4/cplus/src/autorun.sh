#!/bin/bash
iter=0

make


mainfile="burma14"
output="$mainfile/output$iter"

while [ $iter -le 30 ];
  do
    ./ga "$mainfile.bin" $output $iter
    let iter=iter+1
  done
