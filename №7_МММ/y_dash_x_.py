import pylab
import numpy as np
import matplotlib.pyplot as plt
pylab.minorticks_on()
pylab.grid(color="black", which="major", linewidth=1)
pylab.grid(color="k", which="minor", linestyle=":", linewidth=0.5)
data=np.loadtxt ("ans1.dat")
plt.plot(data[:,0], data[:,2],color= 'blue')
plt.title(" y'(x) ")
plt.ylabel("y'(x)")
plt.xlabel("x")

pylab.show()

