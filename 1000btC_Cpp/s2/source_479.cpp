
.data
	A:.asciiz "Nhap Vao So Nguyen A:"
	B:.asciiz "Nhap Vao So Nguyen B:"
	Tong:.asciiz "Tong Hai So La:"
	Hieu1:.asciiz "Hieu A - B La:"
	Hieu2:.asciiz "Hieu B - A La:"
	Tich:.asciiz "Tich Hai So La:"
	Thuong1:.asciiz "Thuong A/B La:"
	Thuong2:.asciiz "Thuong B/A La:"
	Du1:.asciiz "Chia Du A%B La:"
	Du2:.asciiz "Chia Du B%A La:"
	ErrorThuong1:.asciiz "Thuong A/B La:Do Mau So Khong Hop Le Nen Khong Thuc Hien Viec Tinh Toan Duoc!\n"
	ErrorThuong2:.asciiz "Thuong B/A La:Do Mau So Khong Hop Le Nen Khong Thuc Hien Viec Tinh Toan Duoc!\n"
	ErrorDu1:.asciiz "Chia Du A%B La:Do Mau So Khong Hop Le Nen Khong Thuc Hien Viec Tinh Toan Duoc!\n"
	ErrorDu2:.asciiz "Chia Du B%A La:Do Mau So Khong Hop Le Nen Khong Thuc Hien Viec Tinh Toan Duoc!\n"
	XuongDong:.asciiz "\n"
.text
main:
	# Xuat A
	li $v0,4
	la $a0,A
	syscall
	# Nhap so A
	li $v0,5
	syscall
	move $s0,$v0 # Dua gia tri A vua nhap vao thanh ghi $s0 .
	# Xuat B
	li $v0,4
	la $a0,B
	syscall
	# Nhap so B
	li $v0,5
	syscall
	move $s1,$v0 # Dua gia tri B vua nhap vao thanh ghi $s1 .
	# Tinh ket qua Tong
	add $s2,$s1,$s0 # $s2 = $s1 + $s0 .
	# Xuat Tong
	li $v0,4
	la $a0,Tong
	syscall
	move $a0,$s2 # Luu gia tri trong thanh ghi $s2 vao thanh ghi $a0 .
	# Xuat gia tri ket qua
	li $v0,1
	syscall
	# Xuong Dong
	li $v0,4
	la $a0,XuongDong
	syscall
	# Tinh ket qua Hieu A - B
	sub $s2,$s0,$s1 # $s2 = $s0 - $s1 .
	# Xuat Hieu A - B
	li $v0,4
	la $a0,Hieu1
	syscall
	move $a0,$s2 # Luu gia tri trong thanh ghi $s2 vao thanh ghi $a0 .
	# Xuat gia tri ket qua
	li $v0,1
	syscall
	# Xuong Dong
	li $v0,4
	la $a0,XuongDong
	syscall
	# Tinh ket qua Hieu B - A
	sub $s2,$s1,$s0 # $s2 = $s1 - $s0 .
	# Xuat Hieu B - A
	li $v0,4
	la $a0,Hieu2
	syscall
	move $a0,$s2 # Luu gia tri trong thanh ghi $s2 vao thanh ghi $a0 .
	# Xuat gia tri ket qua	
	li $v0,1
	syscall
	# Xuong Dong
	li $v0,4
	la $a0,XuongDong
	syscall
	# Tinh Tich A*B 
	mult $s0,$s1
	mflo $s2 # $s2 = $s0 * $s1
	# Xuat ket qua Tich
	li $v0,4
	la $a0,Tich
	syscall
	move $a0,$s2 # Luu gia tri trong thanh ghi $s2 vao thanh ghi $a0 .
	# Xuat gia tri ket qua
	li $v0,1
	syscall
	# Xuong Dong
	li $v0,4
	la $a0,XuongDong
	syscall
	# Tinh Thuong A/B 
	div $s0,$s1
	mflo $s2 # $s2 = $s0/$s1
	beq $s1,$0,FalseThuong1 # Neu mau so luu trong thanh ghi $s1 == 0 => khong hop le => bao loi .
	bne $s1,$0,TrueThuong1 # Neu mau so luu trong thanh ghi $s1 != 0 => hop le => in ra ket qua .
TrueThuong1:
	# Xuat ket qua Thuong A/B
	li $v0,4
	la $a0,Thuong1
	syscall
	move $a0,$s2 # Luu gia tri trong thanh ghi $s2 vao thanh ghi $a0 .
	# Xuat gia tri ket qua
	li $v0,1
	syscall
	# Xuong Dong
	li $v0,4
	la $a0,XuongDong
	syscall
	j TinhThuong2 # Sau khi thuc hien in ra ket qua thi chuong trinh nhay den nhan "TinhThuong2" roi tiep tuc tinh toan tiep tuc nhung yeu cau cua chuong trinh . Ta phai thuc hien buoc nhay vi neu khong chuong trinh se chay tuan tu xuong duoi va in ra cau thong bao co loi mac du mau so ta khong vi pham !
FalseThuong1:
	# Bao Loi Phep Chia A/B
	li $v0,4
	la $a0,ErrorThuong1
	syscall
TinhThuong2:	
	# Tinh Thuong B/A 
	div $s1,$s0
	mflo $s2 # $s2 = $s1/$s0
	beq $s0,$0,FalseThuong2 # Neu mau so luu trong thanh ghi $s0 == 0 => khong hop le => bao loi .
	bne $s0,$0,TrueThuong2  # Neu mau so luu trong thanh ghi $s0 != 0 => hop le => in ra ket qua .
TrueThuong2:			
	# Xuat ket qua Thuong B/A
	li $v0,4
	la $a0,Thuong2
	syscall
	move $a0,$s2 # Luu gia tri trong thanh ghi $s2 vao thanh ghi $a0 .
	# Xuat gia tri ket qua
	li $v0,1
	syscall
	# Xuong Dong
	li $v0,4
	la $a0,XuongDong
	syscall
	j TinhChiaDuAChoB  # Sau khi thuc hien in ra ket qua thi chuong trinh nhay den nhan "TinhChiaDuAChoB" roi tiep tuc tinh toan tiep tuc nhung yeu cau cua chuong trinh . Ta phai thuc hien buoc nhay vi neu khong chuong trinh se chay tuan tu xuong duoi va in ra cau thong bao co loi mac du mau so ta khong vi pham !
FalseThuong2:
	# Bao loi phep chia B/A
	li $v0,4
	la $a0,ErrorThuong2
	syscall
TinhChiaDuAChoB:	
	# Tinh Chia Du A%B  
	div $s0,$s1
	mfhi $s2 # $s2 = $s0%$s1
	beq $s1,$0,FalseChiaDuAChoB # Neu mau so luu trong thanh ghi $s1 == 0 => khong hop le => bao loi .
	bne $s1,$0,TrueChiaDuAChoB  # Neu mau so luu trong thanh ghi $s1 != 0 => hop le => in ra ket qua .		
TrueChiaDuAChoB:			
	# Xuat ket qua Chia Du A%B
	li $v0,4
	la $a0,Du1
	syscall
	move $a0,$s2 # Luu gia tri trong thanh ghi $s2 vao thanh ghi $a0 .
	# Xuat gia tri ket qua
	li $v0,1
	syscall
	# Xuong Dong
	li $v0,4
	la $a0,XuongDong
	syscall
	j TinhChiaDuBChoA
FalseChiaDuAChoB:
	# Bao loi phep chia A%B
	li $v0,4
	la $a0,ErrorDu1
	syscall
TinhChiaDuBChoA:
	# Tinh Chia Du B%A  
	div $s1,$s0
	mfhi $s2 # $s2 = $s1%$s0
	beq $s0,$0,FalseChiaDuBChoA
	bne $s0,$0,TrueChiaDuBChoA
TrueChiaDuBChoA:						
	# Xuat ket qua Chia Du B%A
	li $v0,4
	la $a0,Du2
	syscall
	move $a0,$s2 # Luu gia tri trong thanh ghi $s2 vao thanh ghi $a0 .
	# Xuat gia tri ket qua
	li $v0,1
	syscall
	# Xuong Dong
	li $v0,4
	la $a0,XuongDong
	syscall
	j Exit
FalseChiaDuBChoA:
	# Bao loi phep chia B%A
	li $v0,4
	la $a0,ErrorDu2
	syscall
Exit:
	li $v0,10
	syscall