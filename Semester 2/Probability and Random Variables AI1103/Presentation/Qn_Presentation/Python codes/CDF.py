import numpy as np
import scipy 
import matplotlib.pyplot as plt 
# data to be plotted 
x = np.arange(0,4)  
y =[0,0.5,1,1]
# plotting 
plt.grid(color='grey', ls='--')
plt.ylabel("F(x)")  
plt.xlabel("x")  
plt.title("Cumulative distribution function")
plt.plot(x, y, color ="blue")  
plt.show()