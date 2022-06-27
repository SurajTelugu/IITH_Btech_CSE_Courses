add $t0, $gp, $zero
lw $t1, 4($gp)
sll $t1, $t1, 2
add $t1, $t1, $gp
ori $t2, $zero, 256
beq $t3, $zero, 2792
sw $t2, 28($t0)
addi $t0, $t0, 4
j 4895