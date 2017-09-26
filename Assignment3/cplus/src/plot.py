#!/usr/bin/python
import numpy as np
import matplotlib.pyplot as plt
import os

File = 'Dejong4'

for f in os.listdir (File):
    for sf in os.listdir (os.path.join (File,f)):
        plt.ylabel('Run')
        plt.ylabel('Fitness')
        plt.grid (True)
        plt.title('Population Fitnesses of ' + f)

        data = np.loadtxt(os.path.join (os.path.join (File,f),'max'))
        x, y = data[:, 0],data[:, 1]
        plt.plot(x, y, linewidth=2.0, color= 'green', label='Average Maximum')

        data = np.loadtxt(os.path.join (os.path.join (File,f),'min'))
        x, y = data[:, 0],data[:, 1]
        plt.plot(x, y, linewidth=2.0,color='red', label='Average Minimum')

        data = np.loadtxt(os.path.join (os.path.join (File,f),'average'))
        x, y = data[:, 0],data[:, 1]
        plt.plot(x, y, linewidth=2.0, color='blue', label='Average Average')

        plt.legend ()

        plt.savefig (os.path.join (os.path.join (File,f),'plot.png'))
        plt.clf()
        #plt.show()
quit()
