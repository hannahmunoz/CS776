#!/bin/bash
iter=0

make

mainfile="Dejong4"

while [ $iter -le 30 ];
  do
    #1
    output="$mainfile/Normal/outfile$iter"
    ./ga "infile" $output $iter 0.67 0.001

    #2
    output="$mainfile/LowCrossLowMutation/outfile$iter"
    ./ga "infile" $output $iter 0.2 0.0001

    #3
    output="$mainfile/LowCrossHighMutation/outfile$iter"
    ./ga "infile" $output $iter 0.2 0.01

    #4
    output="$mainfile/HighCrossHighMutation/outfile$iter"
    ./ga "infile" $output $iter 0.99 0.01

    #5
    output="$mainfile/HighCrossLowMutation/outfile$iter"
    ./ga "infile" $output $iter 0.99 0.0001

    #6
    output="$mainfile/LowCrossNormalMutation/outfile$iter"
    ./ga "infile" $output $iter 0.2 0.001

    #7
    output="$mainfile/HighCrossNormalMutation/outfile$iter"
    ./ga "infile" $output $iter 0.99 0.001

    #8
    output="$mainfile/NormalCrossHighMutation/outfile$iter"
    ./ga "infile" $output $iter 0.67 0.01

    #9
    output="$mainfile/NormalCrossLowMutation/outfile$iter"
    ./ga "infile" $output $iter 0.67 0.0001

    let iter=iter+1
  done
