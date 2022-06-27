import numpy as np 

# Random Variates 
R = uniform .rvs(0, 2, size = 8) 
print ("Random Variates : \n", R) 
  
# PDF 
x = np.linspace(uniform.ppf(0.01, 0, 2),
                uniform.ppf(0.99, 0, 2), 8)
R = uniform.pdf(x,0,2)
print ("\nProbability Distribution : \n", R) 