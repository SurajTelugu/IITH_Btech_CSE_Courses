import numpy as np
from pylab import *
import scipy 
import matplotlib.pyplot as plt 
#plotting data
x=linspace(-1,2,10000)    
y=zeros(10000)
y[x<1] = 56*x[x<1]*x[x<1]*x[x<1]*x[x<1]*x[x<1]*x[x<1]*(1-x[x<1])
y[x>=1] = 0
y[x<=0] = 0
pos = np.where(np.abs(np.diff(y)) >= 2)[0]+1
x = np.insert(x, pos, np.nan)
y = np.insert(y, pos, np.nan)
#plotting
plt.grid(color='grey', ls='--')
plt.ylabel("f(t)")  
plt.xlabel("t") 
annotate("(0.5,7/16)",(0.5,0.4375)) 
plt.plot(x, y, '-o', color ="blue", linewidth=0.2, label=r"$2x$")
plt.show()