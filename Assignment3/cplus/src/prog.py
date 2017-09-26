#!/usr/bin/python
import numpy as np
import matplotlib.pyplot as plt
import os


File = 'Dejong1'

for f in os.listdir (File):
    run = 0
    for sf in os.listdir (os.path.join (File,f)):
           data = np.loadtxt(os.path.join (os.path.join (File,f),sf))
           gen, minimum, average, maximum = data[:, 0],data[:, 1],data[:, 2],data[:,3]

           fmin=open(os.path.join (os.path.join (File,f), 'min'), 'a')
           fmin.write ('%d' %run)
           fmin.write ('\t')
           fmin.write ('%f' %np.mean (minimum))
           fmin.write ('\n')

           fmin=open(os.path.join (os.path.join (File,f), 'average'), 'a')
           fmin.write ('%d' %run)
           fmin.write ('\t')
           fmin.write ('%f' %np.mean (average))
           fmin.write ('\n')

           fmin=open(os.path.join (os.path.join (File,f), 'max'), 'a')
           fmin.write ('%d' %run)
           fmin.write ('\t')
           fmin.write ('%f' %np.mean (maximum))
           fmin.write ('\n')
           os.remove (os.path.join (os.path.join (File,f),sf))

           run = run + 1

    #plt.ylabel('Run')
    #plt.ylabel('Fitness')
    #plt.plot(x, y, linewidth=2.0)
    #plt.show()
quit()
