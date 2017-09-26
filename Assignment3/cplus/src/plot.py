#!/usr/bin/python
import numpy as np
import matplotlib.pyplot as plt
import os

File = 'Dejong1'

for f in os.listdir (File):
    for sf in os.listdir (os.path.join (File,f)):
        data = np.loadtxt(os.path.join (os.path.join (File,f),'max'))
        x, y = data[:, 0],data[:, 1]

        plt.ylabel('Run')
        plt.ylabel('Fitness')
        plt.plot(x, y, linewidth=2.0)
        plt.grid (True)
        plt.title('Average Maximum Population Fitness of ' + f)
        plt.savefig (os.path.join (os.path.join (File,f),'max.png'))
        plt.clf()

        data = np.loadtxt(os.path.join (os.path.join (File,f),'min'))
        x, y = data[:, 0],data[:, 1]

        plt.ylabel('Run')
        plt.ylabel('Fitness')
        plt.plot(x, y, linewidth=2.0)
        plt.grid (True)
        plt.title('Average Minimum Population Fitness of ' + f)
        plt.savefig (os.path.join (os.path.join (File,f),'min.png'))
        plt.clf()

        data = np.loadtxt(os.path.join (os.path.join (File,f),'average'))
        x, y = data[:, 0],data[:, 1]

        plt.ylabel('Run')
        plt.ylabel('Fitness')
        plt.plot(x, y, linewidth=2.0)
        plt.grid (True)
        plt.title('Average Average Population Fitness of ' + f)
        plt.savefig (os.path.join (os.path.join (File,f),'average.png'))
        plt.clf()
        #plt.show()
quit()
