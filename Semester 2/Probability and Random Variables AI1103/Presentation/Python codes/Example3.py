import numpy as np
import matplotlib.pyplot as plt

data = np.array([
    [2 , 3.19E-3],
    [4 , 4.17E-3],
    [6 , 4.115E-3],
    [8 , 4.119E-3],
    [10, 4.118E-3],
    [12, 4.119E-3],
    [14, 4.119E-3],
    [16, 4.119E-3],
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
plt.title('Example 3')
  
# plotting
plt.grid(color='grey', ls='--')
plt.show()