import numpy as np
from scipy.stats import bernoulli

sample_size = 100000

prob_F = 1/3
prob_G = 1/3
prob_H = 1/3
prob_F_and_G_and_H= 1/4


sample_F = bernoulli.rvs(size = sample_size , p = prob_F)
sample_G = bernoulli.rvs(size = sample_size , p = prob_G)
sample_H = bernoulli.rvs(size = sample_size , p = prob_H)
sample_F_and_G_and_H = bernoulli.rvs(size = sample_size , p = prob_F_and_G_and_H)

F=0
G=0
H=0
F_and_G_and_H=0

for i in range(sample_size):
  if sample_F[i]==1:
    F+=1
for i in range(sample_size):
  if sample_G[i]==1:
    G+=1   
for i in range(sample_size):
  if sample_H[i]==1:
    H+=1
for i in range(sample_size):
  if sample_F_and_G_and_H[i]==1:
    F_and_G_and_H+=1

calc_prob_F=F/sample_size
calc_prob_G=G/sample_size
calc_prob_H=H/sample_size
calc_prob_F_and_G_and_H=F_and_G_and_H/sample_size

def ind_pr(prob_x,prob_y):
#for independent events 
  prob_x_and_y = prob_x*prob_y 
  return prob_x_and_y

prob_F_or_G_or_H=calc_prob_F + calc_prob_G + calc_prob_H - ind_pr(calc_prob_F,calc_prob_G) - ind_pr(calc_prob_G,calc_prob_H) - ind_pr(calc_prob_H,calc_prob_F) + calc_prob_F_and_G_and_H
print("Theoritical probability of Pr(F U G U H) : 0.9166666667")
print("Simulated probability of Pr(F U G U H) :",prob_F_or_G_or_H)