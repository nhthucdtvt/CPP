# Lam Yeu Cau 1 - 2 - 5 - 7 - 8 - 9 Cua Chuong Trinh .
.data  
a: .word 0
tb1: .asciiz "\nNhap so phan tu mang: "
tb2: .asciiz "a["
tb3: .asciiz "]: "
tb4: .asciiz "Mang Vua Nhap La: "
khoangtrang: .asciiz " "
menu1: .asciiz "\n----------------------------Menu----------------------------------\n1. Nhap mang so nguyen\n2. Xuat mang\n5. Liet ke so nguyen to trong mang\n7. Liet ke so hoan thien trong mang\n8. Liet ke so doi xung trong mang\n9. Sap xep mang tang dan\n10. Thoat\n------------------------------------------------------------------"
chon: .asciiz "\n       Moi Nhap Vao Lua Chon Cua Ban: "
chonlai: .asciiz "\nMoi Ban Chon (0) De Tiep Tuc Thuc Hien Cac Yeu Cau Khac: "
ngto: .asciiz "\nCac So Nguyen To Co Trong Mang La: "
hthien: .asciiz "\nCac so hoan thien trong mang la: "
dxung: .asciiz "\nCac so doi xung trong mang la: "
sort: .asciiz " \nMang sau khi sap xep tang dan la: "
tb9: .asciiz "\n-----Nhap lai mang-------\nNhap so phan tu mang:  "
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
	addi $t0,$v0,-8 # Khoi tao thanh ghi $t0 = gia tri thanh ghi $v0 + (-8) .
	beq $t0,$0,Cau8 # Sau do so sanh dieu kien neu ket qua cua thanh ghi $t0 ma = 0 => thanh ghi $v0 = 8 => lua chon la 8 => liet ke cac so doi xung trong mang .
	addi $t0,$v0,-9 # Khoi tao thanh ghi $t0 = gia tri thanh ghi $v0 + (-9) .
	beq $t0,$0,Cau9 # Sau do so sanh dieu kien neu ket qua cua thanh ghi $t0 ma = 0 => thanh ghi $v0 = 9 => lua chon la 9 => sap xep mang tang dan .
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
Cau8:
	jal Hamdoixung
	j Th
Cau9:
	la $a0,sort
	addi $v0,$0,4
	syscall
	jal Hamsort
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
KiemTraDoiXung:
	add $t6,$0,$0
	addi $t7,$0,10
	add $t4,$0,$a0
Lap3:
	beq $t4,$0,SoSanhDieuKien
	div $t4,$t7
	mfhi $t5
	mflo $t4
	mult $t6,$t7
	mflo $t6
	add $t6,$t6,$t5
	j Lap3
SoSanhDieuKien:
	beq $t6,$a0,DoiXung
	bne $t6,$a0,KhongDoiXung 
DoiXung:
	add $v0,$0,1
	jr $ra
KhongDoiXung:
	add $v0,$0,0
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
#------------------------------------------------
Hamdoixung:
	addi $v0, $0, 4
	la $a0, dxung
	syscall
	add $t0, $0, $0		#i=0
	add $t1,$0,$a1
	la $s1, a # mang? la s1
Lap_dx:
	# Dau Thu Tuc .
	beq $t0, $a1, Ket_dx
	addi $sp,$sp,-4
	sw $ra,0($sp)
	lw $a0,0($s1)
	# Than Thu Tuc .
	jal KiemTraDoiXung
	beq $v0,$0,boquadx
	la $a0,khoangtrang
	addi $v0,$0,4
	syscall
	lw $a0,0($s1)
	addi $v0,$0,1
	syscall
	# Cuoi Thu Tuc .
boquadx:
	lw $ra,0($sp)
	addi $sp,$sp,4
	add $s1, $s1, 4
	addi $t0, $t0, 1
	j  Lap_dx
Ket_dx:
	jr $ra
#-------------------------------------------
#-------------------------------------------
Hamsort1:
	la $s1,a
	addi $t0,$0,1
Big_Loop:
	beq $t0,$a1,exit_sort
	addi $t1,$0,1
	la $s1,a
Small_Loop:
	beq $t1,$a1,exit_small
	lw $a2,0($s1)
	lw $a3,4($s1)
	slt $t2,$a2,$a3
	bne $t2,$0,boqua_sort
	add $a0,$0,$a2
	sw $a3,0($s1)
	sw $a0,4($s1)
boqua_sort:
	addi $s1,$s1,4
	addi $t1,$t1,1
	j Small_Loop
exit_small: 
	addi $t0,$0,1
	j Big_Loop
exit_sort:
	la $a0,sort
	addi $v0,$0,4
	syscall
	jal Hamxuat
	jr $ra
#-------------------------------------------
Hamsort:
	la $a0,tb9 
	addi $v0,$0,4
	syscall
	addi $v0,$0,5
	syscall
	add $s0,$0,$v0 
	add $s1, $0,$s0 
begin_loop_1:
	beq $s1, $zero, end_loop_1
	addi $v0,$0,5
	syscall
	add $a0, $0,$v0
	jal stack_push
	addi $s1, $s1, -1 
	j begin_loop_1
end_loop_1:
	addi $a0, $zero, 1
	add $a1, $0,$s0
	jal insert_sort
	la $a0,sort 
	addi $v0,$0,4
	syscall
	add $s1,$0, $s0 
begin_loop_2:
	beq $s1, $0, end_loop_2 
	jal stack_pop
	add $a0, $0,$v0
	addi $v0,$0,1
	syscall
	addi $a0,$zero, 32
	addi $v0,$0, 11
	syscall
	addi $s1, $s1, -1 
	j begin_loop_2
end_loop_2:
	j end_program
stack_push:
	addi $sp, $sp, -4 
	sw $a0, 0($sp)
	jr $ra
stack_pop:
	lw $v0, 0($sp)
	addi $sp, $sp, 4
	jr $ra
insert_sort:
	beq $a0, $a1, end_sort
	add $t0,$0,$sp
	add $t1,$0,$a0
begin_loop:
	beq $t1, $zero, end_loop
	addi $t0, $t0, 4
	addi $t1, $t1, -1
	j begin_loop
end_loop:
	lw $t1,0($t0)
for:
	beq $t0, $sp, next
	lw $t2, -4($t0)
	slt $t7,$t2,$t1 
	bne $t7,$0,next
	sw $t2,0($t0)
	addi $t0, $t0, -4
	j for
next:
	sw $t1,0($t0)
	addi $a0, $a0, 1
	j insert_sort
end_sort:
	jr $ra
#-------------------------------------------
#---------------------------------------------------------
Thanks:
	# Hien Thi Loi Chao 
	li $v0,4
	la $a0,LoiChao
	syscall
	j Exit # Nhay den nhan Exit de thoat chuong trinh .
#---------------------------------------------------------
#---------------------------------------------------------
end_program:
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