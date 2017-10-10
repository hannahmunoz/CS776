#!/usr/bin/python
import numpy as np
import matplotlib.pyplot as plt
import os

File = './Tours/eil51'
title = "eil51"

plt.ylabel('Run')
plt.ylabel('Fitness')
plt.grid (True)
plt.title('Population Fitnesses of ' +  title)

data = np.loadtxt(os.path.join (File,'Averages'))
#x, y = data[:, 0],data[:, 1]
#plt.plot(x, y, linewidth=2.0, color= 'green', label='Average Minimum')

x, y = data[:, 0],data[:, 1]
plt.plot(x, y, linewidth=2.0,color='red', label='Average Average')

x, y = data[:, 0],data[:, 2]
plt.plot(x, y, linewidth=2.0, color='blue', label='Average Maximum')

plt.legend ()

plt.savefig (os.path.join (File,'plot.png'))
plt.clf()
        #plt.show()
quit()
