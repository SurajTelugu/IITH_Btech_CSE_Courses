P = 8;

f = 50;

Ns = 120*f/P

Pin_rotor = 5700;

Cu_Loss_Phase = 114; # Copper loss per phase

Cu_Loss = Cu_Loss_Phase*3 
# Total copper loss for 3 phase induction motor

slip = Cu_Loss/Pin_rotor

Nr = Ns*(1 - slip)