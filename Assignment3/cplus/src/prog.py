#!/usr/bin/python
import numpy as np
import matplotlib.pyplot as plt
import os


File = 'Dejong4'

for f in os.listdir (File):
    for i in range(len(list(open(os.path.join (File, os.path.join ('HighCrossHighMutation','outfile0')))))-1):
        minimum = 0
        average = 0
        maximum = 0
        run = 0
        for sf in os.listdir (os.path.join (File,f)):
            if sf != 'Averages':
                #print (sf)
                data = np.loadtxt(os.path.join (File,(os.path.join (f,sf))))
            #print (i, '\t')
            #print (data[i,1])
                minimum  += data[i,1]
                average  += data[i,2]
                maximum  += data[i,3]
                run +=1
    #
        minimum = minimum/run
        average = average/run
        maximum = maximum/run
        fmin=open(os.path.join (os.path.join (File,f), 'Averages'), 'a')
        fmin.write ('%d' %i)
        fmin.write ('\t')
        fmin.write ('%f' %minimum)
        fmin.write ('\t')
        fmin.write ('%f' %average)
        fmin.write ('\t')
        fmin.write ('%f' %maximum)
        fmin.write ('\n')
    # #        #os.remove (os.path.join (os.path.join (File,f),sf))
quit()
