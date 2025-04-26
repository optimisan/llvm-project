	.abicalls
	.option	pic0
	.section	.mdebug.abi32,"",@progbits
	.nan	legacy
	.text
	.file	"a.ll"
	.globl	main                            # -- Begin function main
	.p2align	2
	.type	main,@function
	.set	nomicromips
	.set	nomips16
	.ent	main
main:                                   # @main
	.cfi_startproc
	.frame	$sp,72,$ra
	.mask 	0xc0ff0000,-4
	.fmask	0x00000000,0
	.set	noreorder
	.set	nomacro
	.set	noat
# %bb.0:                                # %entry
	addiu	$sp, $sp, -72
	.cfi_def_cfa_offset 72
	sw	$ra, 68($sp)                    # 4-byte Folded Spill
	sw	$fp, 64($sp)                    # 4-byte Folded Spill
	sw	$23, 60($sp)                    # 4-byte Folded Spill
	sw	$22, 56($sp)                    # 4-byte Folded Spill
	sw	$21, 52($sp)                    # 4-byte Folded Spill
	sw	$20, 48($sp)                    # 4-byte Folded Spill
	sw	$19, 44($sp)                    # 4-byte Folded Spill
	sw	$18, 40($sp)                    # 4-byte Folded Spill
	sw	$17, 36($sp)                    # 4-byte Folded Spill
	sw	$16, 32($sp)                    # 4-byte Folded Spill
	.cfi_offset 31, -4
	.cfi_offset 30, -8
	.cfi_offset 23, -12
	.cfi_offset 22, -16
	.cfi_offset 21, -20
	.cfi_offset 20, -24
	.cfi_offset 19, -28
	.cfi_offset 18, -32
	.cfi_offset 17, -36
	.cfi_offset 16, -40
	addiu	$2, $zero, 0
	addiu	$3, $sp, 0
	addiu	$5, $zero, 33
$BB0_1:                                 # %loop
                                        # =>This Inner Loop Header: Depth=1
	addu	$1, $3, $2
	addiu	$2, $2, 1
	bne	$2, $5, $BB0_1
	sb	$zero, 0($1)
# %bb.2:                                # %end.loop
	lbu	$2, 3($sp)
	lbu	$1, 2($sp)
	lbu	$3, 27($sp)
	lbu	$5, 31($sp)
	lbu	$6, 10($sp)
	lbu	$7, 9($sp)
	lbu	$8, 8($sp)
	lbu	$9, 7($sp)
	lbu	$10, 6($sp)
	lbu	$11, 5($sp)
	lbu	$12, 4($sp)
	lbu	$13, 26($sp)
	lbu	$14, 30($sp)
	lbu	$15, 17($sp)
	lbu	$24, 16($sp)
	lbu	$25, 15($sp)
	lbu	$gp, 14($sp)
	lbu	$16, 13($sp)
	lbu	$17, 12($sp)
	lbu	$18, 11($sp)
	lbu	$19, 22($sp)
	lbu	$20, 21($sp)
	lbu	$21, 20($sp)
	lbu	$22, 19($sp)
	lbu	$23, 18($sp)
	andi	$14, $14, 1
	andi	$5, $5, 1
	lbu	$fp, 23($sp)
	andi	$13, $13, 1
	andi	$3, $3, 1
	andi	$1, $1, 1
	andi	$2, $2, 1
	andi	$12, $12, 1
	andi	$11, $11, 1
	andi	$10, $10, 1
	andi	$9, $9, 1
	andi	$8, $8, 1
	andi	$7, $7, 1
	andi	$6, $6, 1
	andi	$18, $18, 1
	andi	$17, $17, 1
	andi	$16, $16, 1
	andi	$gp, $gp, 1
	andi	$25, $25, 1
	andi	$24, $24, 1
	andi	$15, $15, 1
	andi	$23, $23, 1
	andi	$22, $22, 1
	andi	$21, $21, 1
	andi	$20, $20, 1
	andi	$19, $19, 1
	andi	$fp, $fp, 1
	lbu	$ra, 24($sp)
	andi	$ra, $ra, 1
	sb	$5, 31($4)
	lbu	$5, 25($sp)
	andi	$5, $5, 1
	sb	$14, 30($4)
	lbu	$14, 29($sp)
	andi	$14, $14, 1
	sb	$14, 29($4)
	lbu	$14, 28($sp)
	andi	$14, $14, 1
	sb	$14, 28($4)
	sb	$3, 27($4)
	sb	$13, 26($4)
	sb	$5, 25($4)
	sb	$ra, 24($4)
	sb	$fp, 23($4)
	sb	$19, 22($4)
	sb	$20, 21($4)
	sb	$21, 20($4)
	sb	$22, 19($4)
	sb	$23, 18($4)
	sb	$15, 17($4)
	sb	$24, 16($4)
	sb	$25, 15($4)
	sb	$gp, 14($4)
	sb	$16, 13($4)
	sb	$17, 12($4)
	sb	$18, 11($4)
	sb	$6, 10($4)
	sb	$7, 9($4)
	sb	$8, 8($4)
	sb	$9, 7($4)
	sb	$10, 6($4)
	sb	$11, 5($4)
	sb	$12, 4($4)
	sb	$2, 3($4)
	sb	$1, 2($4)
	lbu	$1, 1($sp)
	andi	$1, $1, 1
	sb	$1, 1($4)
	lbu	$1, 0($sp)
	andi	$1, $1, 1
	sb	$1, 0($4)
	lw	$16, 32($sp)                    # 4-byte Folded Reload
	lw	$17, 36($sp)                    # 4-byte Folded Reload
	lw	$18, 40($sp)                    # 4-byte Folded Reload
	lw	$19, 44($sp)                    # 4-byte Folded Reload
	lw	$20, 48($sp)                    # 4-byte Folded Reload
	lw	$21, 52($sp)                    # 4-byte Folded Reload
	lw	$22, 56($sp)                    # 4-byte Folded Reload
	lw	$23, 60($sp)                    # 4-byte Folded Reload
	lw	$fp, 64($sp)                    # 4-byte Folded Reload
	lw	$ra, 68($sp)                    # 4-byte Folded Reload
	jr	$ra
	addiu	$sp, $sp, 72
	.set	at
	.set	macro
	.set	reorder
	.end	main
$func_end0:
	.size	main, ($func_end0)-main
	.cfi_endproc
                                        # -- End function
	.section	".note.GNU-stack","",@progbits
	.text
