import numpy as np
from pylab import *
import scipy 
import matplotlib.pyplot as plt 
#plotting data
x=linspace(-1,4,10000)    
y=zeros(10000)
y[x<2] = 0.21875*x[x<2]*x[x<2]*x[x<2]*x[x<2]*x[x<2]*x[x<2]*(2-x[x<2])
y[x>=2] = 0
y[x<=0] = 0
pos = np.where(np.abs(np.diff(y)) >= 2)[0]+1
x = np.insert(x, pos, np.nan)
y = np.insert(y, pos, np.nan)
#plotting
plt.grid(color='grey', ls='--')
plt.ylabel("f(x)")  
plt.xlabel("x")  
plt.title("Marginal probability density")
annotate("(1,7/32)",(1,0.21875))
plt.plot(x, y, '-o', color ="blue", linewidth=0.2, label=r"$2x$")
plt.show()