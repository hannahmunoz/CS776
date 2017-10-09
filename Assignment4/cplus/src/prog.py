#!/usr/bin/python
import numpy as np
import matplotlib.pyplot as plt
import os


File = './Tours/lin105'

for i in range(len(list(open(os.path.join(File,'output0'))))-1):
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

length = len(list(open(os.path.join(File,'output0'))))-2

relirun = 0;
for sf in os.listdir (File):
        if sf != 'Averages':
            data = np.loadtxt(os.path.join (File, sf))
            if (data[length, 3] >=  maximum):
                relirun += 1
print relirun

speedrunTotal = 0;
for sf in os.listdir (File):
    for i in range(len(list(open(os.path.join(File,sf))))-1):
        if sf != 'Averages':
            data = np.loadtxt(os.path.join (File, sf))
            if (data[i, 3] >=  maximum):
                speedrunTotal += i
                break
print speedrunTotal/30
    #        #os.remove (os.path.join (os.path.join (File,f),sf))
quit()
