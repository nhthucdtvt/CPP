# De Bai : Nhap vao 2 so nguyen va tim ra Min,Max cua chung
.data
	tb1:.asciiz "Nhap vao so nguyen a:"
	tb2:.asciiz "Nhap vao so nguyen b:"
	Max:.asciiz "Max la:"
	Min:.asciiz "Min la:"
	BangNhau:.asciiz "Hai so bang nhau"
	XuongDong:.asciiz "\n"
.text
main:
	# Xuat tb1
	li $v0,4
	la $a0,tb1
	syscall
	# Nhap a
	li $v0,5
	syscall
	move $s0,$v0 # Luu gia tri cua a vao thanh ghi $s0 .
	# Xuat tb2
	li $v0,4
	la $a0,tb2
	syscall
	# Nhap b
	li $v0,5
	syscall
	move $s1,$v0 # Luu gia tri cua b vao thanh ghi $s1 .
	# Truong hop a = b
	beq $s0,$s1,ABangB
	# Thuc hien phep so sanh di tinh a - b
	 sub $s2,$s0,$s1 # ket qua a - b luu vao thanh ghi $s2 .
	# Truong hop a > b => a - b > 0
	   bgtz $s2,Maxa
	# Truong hop a < b => a - b < 0
	   bltz $s2,Maxb
Maxa:
	# Xuat Max
	li $v0,4
	la $a0,Max
	syscall
	move $a0,$s0 # Gan gia tri cua a vao thanh ghi $a0 .
	# Xuat ra Max la a
	li $v0,1
	syscall
	j Minb
Minb:
	# Xuong dong
	li $v0,4
	la $a0,XuongDong
	syscall
	# Xuat Min
	li $v0,4
	la $a0,Min
	syscall
	move $a0,$s1 # Gan gia tri cua b vao thanh ghi $a0 .
	# Xuat ra Min la b
	li $v0,1
	syscall
	j Exit
Maxb:
	# Xuat Max
	li $v0,4
	la $a0,Max
	syscall
	move $a0,$s1 # Gan gia tri cua b vao thanh ghi $a0 .
	# Xuat ra Max la b
	li $v0,1
	syscall
	j Mina
Mina:
	# Xuong dong
	li $v0,4
	la $a0,XuongDong
	syscall
	# Xuat Min
	li $v0,4
	la $a0,Min
	syscall
	move $a0,$s0 # Gan gia tri cua a vao thanh ghi $a0 .
	# Xuat ra Min la a
	li $v0,1
	syscall
	j Exit
ABangB:
	# Xuat Bang Nhau
	li $v0,4
	la $a0,BangNhau
	syscall
Exit:
	li $v0,10
	syscall
	