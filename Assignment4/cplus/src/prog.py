#!/usr/bin/python
import numpy as np
import matplotlib.pyplot as plt
import os


File = './Tours/lin105'
optimum = 14379
length = len(list(open(os.path.join(File,'output1'))))-2
std = 0
best = 0
for i in range(len(list(open(os.path.join(File,'output1'))))-1):
    minimum = 0
    average = 0
    maximum = 0

    run = 0
    for sf in os.listdir (File):
        if sf != 'Averages':
                #print (sf)
                data = np.loadtxt(os.path.join (File, sf))
            #print (i, '\t')
            #print (data[i,1])
                #minimum  += data[i,1]
                average  += data[i,2]
                maximum  += data[i,3]
                run +=1

                if (i == length):
                    best += 1/ data[length,3]
                    std += (1/data[length,3] - optimum) ** 2
    #
    #minimum = minimum/run
    average = average/run
    maximum = maximum/run
    fmin=open(os.path.join (File, 'Averages'), 'a')
    fmin.write ('%d' %i)
    fmin.write ('\t')
    #fmin.write ('%f' %minimum)
    #fmin.write ('\t')
    fmin.write ('%f' %average)
    fmin.write ('\t')
    fmin.write ('%f' %maximum)
    fmin.write ('\n')

std = (std ** (0.5))/29
best = best/30
#print (best)
#print (std)
print ("optimum: ")
o = optimum/(best+std)
print (o)


relirun = 0;
for sf in os.listdir (File):
        if sf != 'Averages':
            data = np.loadtxt(os.path.join (File, sf))
            if (1/data[length, 3] <= optimum * (o+1)):
                relirun += 1
print relirun
#print (optimum * (o+1))

speedrunTotal = 0;
for sf in os.listdir (File):
    for i in range(len(list(open(os.path.join(File,sf))))-1):
        if sf != 'Averages':
            data = np.loadtxt(os.path.join (File, sf))
            if (1/data[i, 3] <=  optimum * (o+1)):
                speedrunTotal += i
                break
print speedrunTotal/30
    #        #os.remove (os.path.join (os.path.join (File,f),sf))
quit()
