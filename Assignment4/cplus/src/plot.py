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

        data = np.loadtxt(os.path.join (os.path.join (File,f),'Averages'))
        x, y = data[:, 0],data[:, 1]
        plt.plot(x, y, linewidth=2.0, color= 'green', label='Average Minimum')

        x, y = data[:, 0],data[:, 2]
        plt.plot(x, y, linewidth=2.0,color='red', label='Average Average')

        x, y = data[:, 0],data[:, 3]
        plt.plot(x, y, linewidth=2.0, color='blue', label='Average Maximum')

        plt.legend ()

        plt.savefig (os.path.join (os.path.join (File,f),'plot.png'))
        plt.clf()
        #plt.show()
quit()
