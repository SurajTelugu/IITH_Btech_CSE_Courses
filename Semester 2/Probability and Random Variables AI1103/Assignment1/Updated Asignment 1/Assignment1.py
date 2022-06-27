
import random as rand

N=6
# number of experiments or simulations
siml_size=1000000

j=0
a=0
b=0
c=0
while (j<siml_size):
  X1=rand.randint(1,6)
  X2=rand.randint(1,6)
  if(X1==6 and X2==6):
    a+=1
  elif(X1==6 and X2!=6)or(X2==6 and X1!=6) :
   b+=1
  else:
   c+=1

  j+=1

Exp_val_X= (0+1*b+2*a)/siml_size

print("The Expectation value obtained by simulation is : ",Exp_val_X)
print("The Expectation value is : 0.3333333 ")
print("Hence value obtained by simulation is nearly equals to the Expectation value")
