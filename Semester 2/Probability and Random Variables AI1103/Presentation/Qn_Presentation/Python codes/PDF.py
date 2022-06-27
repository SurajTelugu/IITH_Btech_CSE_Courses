import numpy as np
from pylab import *
import scipy 
import matplotlib.pyplot as plt 
#plotting data
x=linspace(-1,3,1000)    
y=zeros(1000)
y[x<2] = 0.5
y[x>=2] = 0
y[x<=0] = 0
pos = np.where(np.abs(np.diff(y)) >= 2)[0]+1
x = np.insert(x, pos, np.nan)
y = np.insert(y, pos, np.nan)
#plotting
plt.grid(color='grey', ls='--')
plt.ylabel("f(x)")  
plt.xlabel("x")  
plt.title("Probability density function")
plt.plot(x, y, '-o', color ="blue", linewidth=0.2, label=r"$2x$")
plt.show()