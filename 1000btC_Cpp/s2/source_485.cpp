# Lam Yeu Cau 1 - 2 - 5 - 7 Cua Chuong Trinh .
.data  
a: .word 0
tb1: .asciiz "\nNhap so phan tu mang: "
tb2: .asciiz "a["
tb3: .asciiz "]: "
tb4: .asciiz "Mang Vua Nhap La: "
khoangtrang: .asciiz " "
menu1: .asciiz "\n----------------------------Menu----------------------------------\n1. Nhap mang so nguyen\n2. Xuat mang\n5. Liet ke so nguyen to trong mang\n7. Liet ke so hoan thien trong mang\n10. Thoat\n------------------------------------------------------------------"
chon: .asciiz "\n       Moi Nhap Vao Lua Chon Cua Ban: "
chonlai: .asciiz "\nMoi Ban Chon (0) De Tiep Tuc Thuc Hien Cac Yeu Cau Khac: "
ngto: .asciiz "\nCac So Nguyen To Co Trong Mang La: "
hthien: .asciiz "\nCac so hoan thien trong mang la: "
LoiChao:.asciiz "\nThanks You For Using The Program ! GoodBye And See You Later ! "
.text
main:
	# Dau vao truoc tien chuong trinh phai bat nguoi dung nhap vao du lieu truoc roi moi tiep tuc di tinh cac yeu cau sau do .
	jal Hamnhap
	# Sau khi chon xong 1 yeu cau thi chuong trinh cho phep nguoi dung nhap vao lua chon tiep theo !	
Chonlai:
	jal menu
	la $a0,chon
	addi $v0,$0,4
	syscall
	addi $v0,$0,5
	syscall
	addi $t0,$v0,-1 # Khoi tao thanh ghi $t0 = gia tri thanh ghi $v0 + (-1) .
	beq $t0,$0,Cau1 # Sau do so sanh dieu kien neu ket qua cua thanh ghi $t0 ma = 0 => thanh ghi $v0 = 1 => lua chon la 1 => nhap mang cac so nguyen .
	addi $t0,$v0,-2 # Khoi tao thanh ghi $t0 = gia tri thanh ghi $v0 + (-2) .
	beq $t0,$0,Cau2 # Sau do so sanh dieu kien neu ket qua cua thanh ghi $t0 ma = 0 => thanh ghi $v0 = 2 => lua chon la 2 => xuat mang cac so nguyen .
	addi $t0,$v0,-5 # Khoi tao thanh ghi $t0 = gia tri thanh ghi $v0 + (-5) .
	beq $t0,$0,Cau5 # Sau do so sanh dieu kien neu ket qua cua thanh ghi $t0 ma = 0 => thanh ghi $v0 = 5 => lua chon la 5 => liet ke cac so nguyen to trong mang .
	addi $t0,$v0,-7 # Khoi tao thanh ghi $t0 = gia tri thanh ghi $v0 + (-7) .
	beq $t0,$0,Cau7 # Sau do so sanh dieu kien neu ket qua cua thanh ghi $t0 ma = 0 => thanh ghi $v0 = 7 => lua chon la 7 => liet ke cac so hoan thien trong mang .
	addi $t0,$v0,-10 # Khoi tao thanh ghi $t0 = gia tri thanh ghi $v0 + (-10) .
	beq $t0,$0,Cau10 # Sau do so sanh dieu kien neu ket qua cua thanh ghi $t0 ma = 0 => thanh ghi $v0 = 10 => lua chon la 10 => Hien thi loi chao va thoat chuong trinh .
	j Exit 
Cau1:
	# Xuat tb1
	addi $v0,$0,4
	la $a0, tb1
	syscall
	# Nhap gia tri 
	addi $v0,$0,5
	syscall
	add $a1,$0,$v0
	jal Hamnhap
	j Th
Cau2:
	jal Hamxuat
	j Th
Cau5:
	jal Hamngto
	j Th
Cau7:
	jal Hamhthien
	j Th
Cau10:
	jal Thanks
#------------------------------------------------
KiemTraNguyenTo:
	addi $t1,$0,2
	beq $a0,1,KhongLaNguyenTo
Lap1:
	beq $t1,$a0,LaNguyenTo
	div $a0,$t1
	mfhi $t2
	beq $t2,$0,KhongLaNguyenTo
	addi $t1,$t1,1
	j Lap1
LaNguyenTo:
	addi $v0,$0,1 
	jr $ra	
KhongLaNguyenTo:
	addi $v0,$0,0
	jr $ra
#------------------------------------------------
#------------------------------------------------
KiemTraHoanThien:
	addi $t1,$0,1
	add $t2,$0,$0
Lap2:
	beq $a0,$t1,sosanh
	div $a0,$t1
	mfhi $t3
	beq $t3,$0,cong
	j boqua7
cong: 
	add $t2,$t2,$t1
boqua7:
	addi $t1,$t1,1
	j Lap2
sosanh:
	beq $t2,$a0,th1
	bne $t2,$a0,th2
th1:
	addi $v0,$0,1
	jr $ra
th2:
	addi $v0,$0,0
	jr $ra
#------------------------------------------------
#------------------------------------------------
menu:
	la $a0,menu1
	addi $v0,$0,4
	syscall
	jr $ra
#-------------------------------------------------
#-------------------------------------------------
Hamnhap:
	add $t0,$a1,$0 
	add $t1,$0,$0 # Khoi tao i = 0
	la $t2, a 
Loop1:
	beq $t0, $t1,Out
	#Xuat tb2
	addi $v0,$0,4
	la $a0, tb2
	syscall
	#Xuat chi so i
	addi $v0,$0,1
	move $a0,$t1
	syscall
	#Xuat tb3
	addi $v0,$0,4
	la $a0, tb3
	syscall
	#Nhap gia tri 
	li $v0,5
	syscall
	#Luu vao a[i]
	sw $v0, ($t2)
	addi $t2, $t2,4
	addi $t1,$t1,1
	j Loop1
Out:
	jr $ra
#----------------------------------------------
#-------------------------------------------
Hamxuat:
	#Xuat tb4
	addi $v0,$0,4
	la $a0, tb4
	syscall
	#Khoi tao gia tri vong lap xuat
	add $t0,$0,$a1
	addi $t1,$0,0 # i = 0
	la $t2, a 
Loop2:
	beq $t0,$t1,Out2
	#Xuat a[i]
	addi $v0,$0,1
	lw $a0,($t2)
	syscall
	#Xuat khoang trang
	li $v0,4
	la $a0, khoangtrang
	syscall
	addi $t2, $t2,4
	addi $t1,$t1,1
	j Loop2
Out2:
	jr $ra
#----------------------------------------------
#---------------------------------------------------
Hamngto:
	addi $v0, $0, 4
	la $a0, ngto
	syscall
	add $t0, $0, $0		#i=0
	add $t1,$0,$a1
	la $s1, a # mang? la s1
Lap_ngto:
	# Dau Thu Tuc .
	beq $t0, $a1, Ket_ngto
	addi $sp,$sp,-4
	sw $ra,0($sp)
	lw $a0,0($s1)
	# Than Thu Tuc .
	jal KiemTraNguyenTo
	beq $v0,$0,boquant
	la $a0,khoangtrang
	addi $v0,$0,4
	syscall
	lw $a0,0($s1)
	addi $v0,$0,1
	syscall
	# Cuoi Thu Tuc .
boquant:
	lw $ra,0($sp)
	addi $sp,$sp,4
	add $s1, $s1, 4
	addi $t0, $t0, 1
	j  Lap_ngto
Ket_ngto:
	jr $ra
#---------------------------------------------------------
#----------------------------------------------------
Hamhthien:
	addi $v0, $0, 4
	la $a0, hthien
	syscall
	add $t0, $0, $0		#i=0
	add $t1,$0,$a1
	la $s1, a # mang? la s1
Lap_ht:
	# Dau Thu Tuc .
	beq $t0, $a1, Ket_ht
	addi $sp,$sp,-4
	sw $ra,0($sp)
	lw $a0,0($s1)
	# Than Thu Tuc .
	jal KiemTraHoanThien
	beq $v0,$0,boquaht
	la $a0,khoangtrang
	addi $v0,$0,4
	syscall
	lw $a0,0($s1)
	addi $v0,$0,1
	syscall
	# Cuoi Thu Tuc .
boquaht:
	lw $ra,0($sp)
	addi $sp,$sp,4
	add $s1, $s1, 4
	addi $t0, $t0, 1
	j  Lap_ht
Ket_ht:
	jr $ra
#------------------------------------------------
#---------------------------------------------------------
Thanks:
	# Hien Thi Loi Chao 
	li $v0,4
	la $a0,LoiChao
	syscall
	j Exit # Nhay den nhan Exit de thoat chuong trinh .
#---------------------------------------------------------
#---------------------------------------------------------
Th:
	la $a0,chonlai
	addi $v0,$0,4
	syscall
	addi $v0,$0,5
	syscall
	beq $v0,$0,Chonlai
Exit:
	# The End 
	li $v0,10
	syscall
#------------------------ THE END -------------------------