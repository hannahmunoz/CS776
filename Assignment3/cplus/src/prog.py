#!/usr/bin/python
import numpy as np
import matplotlib.pyplot as plt
import os


for f in os.listdir ('Dejong1/'):
    os.remove (os.path.join (os.path.join ('Dejong1/',f), 'min'))
    os.remove (os.path.join (os.path.join ('Dejong1/',f), 'average'))
    os.remove (os.path.join (os.path.join ('Dejong1/',f), 'max'))
    for sf in os.listdir (os.path.join ('Dejong1/',f)):
       data = np.loadtxt(os.path.join (os.path.join ('Dejong1/',f),sf))
       gen, minimum, average, maximum = data[:, 0],data[:, 1],data[:, 2],data[:,3]

       fmin=open(os.path.join (os.path.join ('Dejong1/',f), 'min'), 'a')
       fmin.write ('%f' %np.mean (minimum))
       fmin.write ('\n')

       fmin=open(os.path.join (os.path.join ('Dejong1/',f), 'average'), 'a')
       fmin.write ('%f' %np.mean (average))
       fmin.write ('\n')

       fmin=open(os.path.join (os.path.join ('Dejong1/',f), 'max'), 'a')
       fmin.write ('%f' %np.mean (maximum))
       fmin.write ('\n')
       os.remove (os.path.join (os.path.join ('Dejong1/',f),sf))

quit()

#plt.plot(x, y, linewidth=2.0)
#plt.show()
