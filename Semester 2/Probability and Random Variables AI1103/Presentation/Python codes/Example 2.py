import numpy as np
import matplotlib.pyplot as plt

data = np.array([
    [8 , 1.4E-7],
    [10, 2.7E-7],
    [12, 4.0E-7],
    [14, 5.0E-7],
    [16, 5.27E-7],
    [18, 5.26E-7],
    [20, 5.21E-7],
    [22, 5.199E-7],
    [24, 5.204E-7],
    [26, 5.205E-7],
    [28, 5.204E-7],
    [30, 5.204E-7],
])
  
# x and y values
x, y = data.T
  
# plotting the points 
plt.plot(x, y, '-o', color ="blue", linewidth=0.8, label=r"$2x$")
  
# naming the x axis
plt.xlabel('Order of Highest Moment used')
# naming the y axis
plt.ylabel('Error Probablity using Minimax Approximation')
  
# giving a title to my graph
plt.title('Example 2')
  
# plotting
plt.grid(color='grey', ls='--')
plt.show()