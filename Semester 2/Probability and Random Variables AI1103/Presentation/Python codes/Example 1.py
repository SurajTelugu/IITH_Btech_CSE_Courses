import numpy as np
import matplotlib.pyplot as plt

#Quadture rule
dataqr = np.array([
    [4 , 3.77E-5],
    [6 , 8.86E-4],
    [8 , 2.4E-3],
    [10, 2.9E-3],
    [12, 2.8E-3],
    [14, 2.74E-3],
    [16, 2.75E-3],
    [18, 2.766E-3],
    [20, 2.7617E-3],
    [22, 2.7615E-3],
    [24, 2.76164E-3],
])
  
# x and y values
x1, y1 = dataqr.T
  
# plotting the points 
plt.plot(x1, y1, '-o', color ="yellow", linewidth=0.8,label = "Quadature rule")

#Series Expansion
datase = np.array([
    [4 , 4.2E-6],
    [6 , 5.98E-5],
    [8 , 4.71E-4],
    [10, 2.14E-3],
    [12, 5.46E-3],
    [14, 6.56E-3],
    [16, 5.06E-4],
])
  
# x and y values
x2, y2 = datase.T
  
# plotting the points 
plt.plot(x2, y2, '-o', color ="red", linewidth=0.8,label = "Series Expansion")

#Minimax Approximation
datama = np.array([
    [4 , 2.9758E-3],
    [6 , 2.7650E-3],
    [8 , 2.7573E-3],
    [10, 2.7610E-3],
    [12, 2.7610E-3],
    [14, 2.761446E-3],
    [16, 2.761442E-3],
    [18, 2.761425E-3],
    [20, 2.761425E-3],
    [22, 2.761425E-3],
    [24, 2.761425E-3],
])
  
# x and y values
x3, y3 = datama.T
  
# plotting the points 
plt.plot(x3, y3, '-o', color ="blue", linewidth=0.4,label = "Minimax Approximation")
  
# naming the x axis
plt.xlabel('Order of Highest Moment used')
# naming the y axis
plt.ylabel('Error Probablity')
  
# giving a title to my graph
plt.title('Example 1')

# plotting
plt.grid(color='grey', ls='--')
plt.legend()
plt.show()