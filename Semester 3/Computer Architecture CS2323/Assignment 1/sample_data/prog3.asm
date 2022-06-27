lw $t0, 4($gp)
mult $t0, $t0, $t0
mult $t0, $t0, $t0
lw $t1, 4($gp)
ori $t2, $s1, 5
mult $t1, $t1, $t2
add $t2, $t0, $t1
sw $t2, 0($gp)