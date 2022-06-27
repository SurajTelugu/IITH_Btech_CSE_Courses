P = 6;

f = 50;

Rot_Res = 0.14;

Stand_Reac = 0.86;

k = (Rot_Res/Stand_Reac)

Nr = 950;

Ns = 120*f/P

Sfl = 1 - (Nr/Ns)

ratio_strt_full_load = (k^2 + Sfl^2)/(Sfl*(k^2 + 1))