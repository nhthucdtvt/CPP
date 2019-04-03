# De Bai : Nhap vao 1 so nguyen n va tinh n! 
.data
	tb1:.asciiz "Nhap vao so nguyen n = "
	tb2:.asciiz "n! = "
	n:.word 0
.text
main:
	# Xuat tb1
	li $v0,4
	la $a0,tb1
	syscall
	# Nhap so nguyen n
	li $v0,5
	syscall
	# Luu tru vao n
	sw $v0,n
	# Khoi tao gia tri vong lap
	li $t0,1 # Tich = 1 
	li $t1,1 # i = 1
	lw $t2,n # Chep gia tri cua n vao thanh ghi tam $t2 
Lap:
	# Qua trinh lap i se chay den = n thi dung lai,neu i > n <=> n - i < 0 => ket thuc lap
	sub $t3,$t2,$t1 
	bltz $t3,KetThucLap
	mult $t0,$t1 #  Tich * i
	mflo $t0 # Tich = Tich * i 
	addi $t1,$t1,1 # i = i + 1 
	j Lap # Lap lai qua trinh tren
KetThucLap:
	# Xuat tb2
	li $v0,4
	la $a0,tb2
	syscall
	move $a0,$t0 # Ghi gia tri tong trong thanh ghi tam $t0 vao thanh ghi $a0 .
	# Xuat Tong
	li $v0,1
	syscall
Exit:
	li $v0,10
	syscall