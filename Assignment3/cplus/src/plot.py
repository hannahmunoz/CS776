#!/usr/bin/python
import numpy as np
import matplotlib.pyplot as plt
import os

for f in os.listdir ('Dejong1/'):
    for sf in os.listdir (os.path.join ('Dejong1/',f)):
        data = np.loadtxt(os.path.join (os.path.join ('Dejong1/',f),'min'))
        x, y = data[:, 0],data[:, 1]

        plt.ylabel('Run')
        plt.ylabel('Fitness')
        plt.plot(x, y, linewidth=2.0)
        plt.grid (True)
        plt.title('Average Minimum Fitness of ' + f)
        plt.savefig (os.path.join (os.path.join ('Dejong1/',f),'min.png'))
        #plt.show()
quit()
