P = 2;

f = 40;

Rot_Res = 0.06;

Stand_Reac = 0.34;

k = (Rot_Res/Stand_Reac)

Nr = 2304;

Ns = 120*f/P

Sfl = 1 - (Nr/Ns)

ratio_max_full_load = (k^2 + Sfl^2)/(2*Sfl*k)