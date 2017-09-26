#!/bin/bash
iter=0

make

while [ $iter -le 30 ];
  do
    #1
    output="Dejong1/Normal/outfile$iter"
    ./ga "infile" $output $iter 0.67 0.001

    #2
    output="Dejong1/LowCrossLowMutation/outfile$iter"
    ./ga "infile" $output $iter 0.2 0.0001

    #3
    output="Dejong1/LowCrossHighMutation/outfile$iter"
    ./ga "infile" $output $iter 0.2 0.01

    #4
    output="Dejong1/HighCrossHighMutation/outfile$iter"
    ./ga "infile" $output $iter 0.99 0.01

    #5
    output="Dejong1/HighCrossLowMutation/outfile$iter"
    ./ga "infile" $output $iter 0.99 0.0001

    #6
    output="Dejong1/LowCrossNormalMutation/outfile$iter"
    ./ga "infile" $output $iter 0.2 0.001

    #7
    output="Dejong1/HighCrossNormalMutation/outfile$iter"
    ./ga "infile" $output $iter 0.99 0.001

    #8
    output="Dejong1/NormalCrossHighMutation/outfile$iter"
    ./ga "infile" $output $iter 0.67 0.01

    #9
    output="Dejong1/NormalCrossLowMutation/outfile$iter"
    ./ga "infile" $output $iter 0.67 0.0001

    let iter=iter+1
  done
