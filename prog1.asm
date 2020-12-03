add	$3, $4, $8
sub	$4, $5, $9
addi $2, $3, 0
beq	$1, $2, end
j	0x400020
add	$3, $4, $8
slt	$1, $2, $3
addi $4, $0, 0
slt	$1, $2, $4
lw	$1, 0($31)
beq	$2, $3, end
sub	$4, $5, $9
addi $2, $3, 0
end: sw $17, 4($31)