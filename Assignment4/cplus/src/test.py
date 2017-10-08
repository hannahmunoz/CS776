import numpy as np
import matplotlib.pyplot as plt

File = 'Tours/burma14.bin'
data = np.loadtxt(File)
print data

quit()
# for f in os.listdir ('./Tours/'+File):
#     for sf in os.listdir (os.path.join (File,f)):
