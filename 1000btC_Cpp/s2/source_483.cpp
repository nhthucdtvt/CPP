# De Bai : Nhap vao mot so nguyen n,di tinh ra ket qua : + Cac so chan tu 1 -> n , + Cac so le tu 1 -> n
.data
	tb1:.asciiz "Nhap vao so nguyen n = "
	tb2:.asciiz "Tong cac so chan tu 1 -> n = "
	tb3:.asciiz "Tong cac so le tu 1 -> n = "
	XuongDong:.asciiz "\n"
	n:.word 0
.text
main:
	# Xuat tb1
	li $v0,4
	la $a0,tb1
	syscall
	# Nhap so nguyen
	li $v0,5
	syscall
	# Luu tru vao n
	sw $v0,n
	# Khoi tao gia tri vong lap tinh cac gia tri chan
	li $t0,0 # Tong = 0
	li $t1,2 # i = 2
	lw $t2,n # Chep gia tri n vao thanh ghi tam $t2 
LapChan:
	sub $t3,$t2,$t1 # $t3 = n - i
	bltz $t3,KetThucLapChan
	add $t0,$t0,$t1 # Tong = Tong + i
	addi $t1,$t1,2 # i = i + 2
	j LapChan
KetThucLapChan:
	# Xuat tb2
	li $v0,4
	la $a0,tb2
	syscall
	move $a0,$t0 # Dua gia tri Tong trong thanh ghi tam $t0 vao trong thanh ghi $a0 .
	# Xuat Tong
	li $v0,1
	syscall
	# Xuong Dong
	li $v0,4
	la $a0,XuongDong
	syscall
	# Khoi tao gia tri vong lap tinh cac gia tri le
	li $t0,0 # Tong = 0
	li $t1,1 # i = 1
	lw $t2,n # Chep gia tri n vao thanh ghi tam $t2 
LapLe:
	sub $t3,$t2,$t1 # $t3 = n - i
	bltz $t3,KetThucLapLe
	add $t0,$t0,$t1 # Tong = Tong + i
	addi $t1,$t1,2 # i = i + 2
	j LapLe
KetThucLapLe:
	# Xuat tb3
	li $v0,4
	la $a0,tb3
	syscall
	move $a0,$t0 # Dua gia tri Tong trong thanh ghi tam $t0 vao trong thanh ghi $a0 .
	# Xuat Tong
	li $v0,1
	syscall
Exit:
	li $v0,10
	syscall
	