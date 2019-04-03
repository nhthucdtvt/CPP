
#				Do An Thuc Hanh Cuoi Ky
#		          Bo Mon:Kien Truc May Tinh & Hop Ngu		    
#		|------------------------------------------------------|
#		| Ho Ten Sinh Vien 1 : Tran Van Nghia		       |
#		| Ma So Sinh Vien 1  : 1261026			       |
#		| Ho Ten Sinh Vien 2 : Nguyen Viet Nam Son 	       |
#		| Ma So Sinh Vien 2  : 1261031			       |
#		| Ho Ten Sinh Vien 3 : Chu Anh Anh		       |
#		| Ma So Sinh Vien 3  : 1261001			       |
#		| Lop 		     : 12CK1  			       |
#		|------------------------------------------------------|
#----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
# Day la bai lam cuoi cung cua mon hoc thu vi nay !!! Chung em xin chan thanh gui loi cam on sau sac den Thay : Le Viet Long - giang vien huong dan thuc hanh da tan tinh chi dan chung em trong suot 10 tuan qua...Tu 1 mon hoc duoc xem la kho khan nhung Thay da mang lai cam hung den voi tui em...that la hanh phuc khi chung em duoc hoc Thay.Chung em cung khong biet noi gi hon ngoai viec gui loi cam on Thay va chuc cho Thay co that nhieu suc khoe de tiep tuc la nguoi truyen dat kien thuc den voi nhung the he tre chung em,la nguoi lai do dua chung em sang 1 ben bo kien thuc rong mo !!!
#----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
.data
a: .space 400
n: .word 0
chon: .word 0
tbc:.float 0.0
menu: .asciiz"\n----------------------------Menu----------------------------------\n1. Nhap mang so nguyen\n2. Xuat mang\n3. Tong mang\n4. Trung binh cong mang\n5. Liet ke so nguyen to trong mang\n6. Liet ke so chinh phuong trong mang\n7. Liet ke so hoan thien trong mang\n8. Liet ke so doi xung trong mang\n9. Sap xep mang tang dan\n10.Thoat\n------------------------------------------------------------------\nChon: "
tb1_1: .asciiz "Nhap n: "
tb1_2: .asciiz "a["
tb1_3: .asciiz "]: "
khoangtrang: .asciiz " "
xdong:.asciiz "\n"
tb2_1: .asciiz "Mang vua nhap la: "
tb3_1: .asciiz "Tong mang la: "
tb4_1: .asciiz "Trung binh cong mang la: "
tb5_1: .asciiz "Cac so nguyen to trong mang la: "
tb6_1: .asciiz "Cac so chinh phuong trong mang la: "
tb7_1:.asciiz "Cac so hoan thien trong mang la: "
tb8_1:.asciiz "Cac so doi xung trong mang la: "
tb9: .asciiz "\n------------------------- Yeu Cau Nhap Lai Mang ----------------------\nMoi Ban Nhap Vao So Luong Phan Tu Cua Mang:  "
tb9_1:.asciiz "Mang sau khi sap xep tang dan: "
Loi:.asciiz "Lua chon cua ban khong hop le!Xin vui long nhap lai! "
LoiChao:.asciiz "\nThanks You For Using The Program ! GoodBye And See You Later ! "
.text
main:
Menu: 
	# Xuat menu
	li $v0,4
	la $a0,menu
	syscall
	# Nhap gia tri so nguyen
	li $v0,5
	syscall
	#Luu vao bien chon
	sw $v0,chon
	# Kiem tra gia tri chon
	lw $t0, chon # Chep gia tri chon vao trong thanh ghi $t0
	li $t1,1 # Khoi tao thanh ghi $t1 = 1 .
	beq $t0, $t1, XL1 # Neu gia tri chon = 1 => Xu Ly Yeu Cau 1
	li $t1,2 # Khoi tao thanh ghi $t1 = 2 .
	beq $t0, $t1, XL2 # Neu gia tri chon = 2 => Xu Ly Yeu Cau 2
	li $t1,3 # Khoi tao thanh ghi $t1 = 3 .
	beq $t0, $t1, XL3 # Neu gia tri chon = 3 => Xu Ly Yeu Cau 3
	li $t1,4 # Khoi tao thanh ghi $t1 = 4 .
	beq $t0, $t1, XL4 # Neu gia tri chon = 4 => Xu Ly Yeu Cau 4
	li $t1,5 # Khoi tao thanh ghi $t1 = 5 .	
	beq $t0, $t1, XL5 # Neu gia tri chon = 5 => Xu Ly Yeu Cau 5
	li $t1,6 # Khoi tao thanh ghi $t1 = 6 .	
	beq $t0, $t1, XL6 # Neu gia tri chon = 6 => Xu Ly Yeu Cau 6
	li $t1,7 # Khoi tao thanh ghi $t1 = 7 .	
	beq $t0, $t1, XL7 # Neu gia tri chon = 7 => Xu Ly Yeu Cau 7
	li $t1,8 # Khoi tao thanh ghi $t1 = 8 .	
	beq $t0, $t1, XL8 # Neu gia tri chon = 8 => Xu Ly Yeu Cau 8
	li $t1,9 # Khoi tao thanh ghi $t1 = 9 .	
	beq $t0, $t1, XL9 # Neu gia tri chon = 9 => Xu Ly Yeu Cau 9
	li $t1,10 # Khoi tao thanh ghi $t1 = 10 .	
	beq $t0, $t1, Exit # Neu gia tri chon = 10 => Xu Ly Yeu Cau 10 => Thoat
	# Cac Truong hop lua chon con lai thi se xuat ra thong bao bao loi va hien ra lai bang MeNu
	# Xuat thong bao loi
	li $v0,4
	la $a0,Loi
	syscall
	# Xuat ra lai bang MeNu
	j Menu
XL1:
	jal NhapMang
	j Menu 
XL2:
	jal XuatMang
	j Menu
XL3:
	jal TongMang
	# Lay gia tri tra ve
	move $t0,$v0
	# xuat tb3_1
	li $v0,4
	la $a0, tb3_1
	syscall
	# Xuat tong
	li $v0, 1
	move $a0, $t0
	syscall
	j Menu
XL4:
	jal TBCong
	# Lay gia tri tra ve
	lwc1 $f0,tbc # Doc gia tri thuc luu vao thanh ghi $f0 .
	# xuat tb4_1
	li $v0,4
	la $a0, tb4_1
	syscall
	# Xuat tbcong
	li $v0, 2
	mov.s $f12, $f0
	syscall
	j Menu
XL5:
	# xuat tb5_1
	li $v0,4
	la $a0, tb5_1
	syscall
	#Khoi tao vong lap
	lw $s0,n
	li $s1,0 # i=0
	la $s2,a
Lap5_1:
	beq $s0,$s1,KTLap5_1
	lw $a1,($s2)
	jal KTNT
	move $s3,$v0
	beq $s3,$0,Sai
	# Xuat gia tri
	li $v0,1
	lw $a0,($s2)
	syscall
	# Xuat ktrang
	li $v0,4
	la $a0,khoangtrang
	syscall
Sai:
	#Tang chi so
	addi $s1,$s1,1
	addi $s2,$s2,4
	j Lap5_1
KTLap5_1:
	#Xuong dong
	li $v0,4
	la $a0,xdong
	syscall
	j Menu
XL6:
	# xuat tb6_1
	li $v0,4
	la $a0, tb6_1
	syscall
	# Khoi tao vong lap
	lw $s0,n # 
	li $s1,0 # i=0
	la $s2,a
Lap6_1:
	beq $s0,$s1,KTLap6_1
	lw $a1,($s2)
	jal KTCP
	move $s3,$v0
	beq $s3,$0,Sai6
	# Xuat gia tri
	li $v0,1
	lw $a0,($s2)
	syscall
	# Xuat ktrang
	li $v0,4
	la $a0,khoangtrang
	syscall
Sai6:
	#Tang chi so
	addi $s1,$s1,1
	addi $s2,$s2,4
	j Lap6_1
KTLap6_1:
	#Xuong dong
	li $v0,4
	la $a0,xdong
	syscall
	j Menu
XL7:
	# xuat tb7_1
	li $v0,4
	la $a0, tb7_1
	syscall
	#Khoi tao vong lap
	lw $s0,n
	li $s1,0 # i=0
	la $s2,a
Lap7_1:
	beq $s0,$s1,KTLap7_1
	lw $a1,($s2)
	jal HoanThien
	move $s3,$v0
	beq $s3,$0,Sai7
	# Xuat gia tri
	li $v0,1
	lw $a0,($s2)
	syscall
	# Xuat ktrang
	li $v0,4
	la $a0,khoangtrang
	syscall
Sai7:
	#Tang chi so
	addi $s1,$s1,1
	addi $s2,$s2,4
	j Lap7_1
KTLap7_1:
	#Xuong dong
	li $v0,4
	la $a0,xdong
	syscall
	j Menu
XL8:
	# xuat tb8_1
	li $v0,4
	la $a0, tb8_1
	syscall
	#Khoi tao vong lap
	lw $s0,n
	li $s1,0 # i=0
	la $s2,a
Lap8_1:
	beq $s0,$s1,KTLap8_1
	lw $a1,($s2)
	jal DoiXung
	move $s3,$v0
	beq $s3,$0,Sai8
	# Xuat gia tri
	li $v0,1
	lw $a0,($s2)
	syscall
	# Xuat ktrang
	li $v0,4
	la $a0,khoangtrang
	syscall
Sai8:
	#Tang chi so
	addi $s1,$s1,1
	addi $s2,$s2,4
	j Lap8_1
KTLap8_1:
	#Xuong dong
	li $v0,4
	la $a0,xdong
	syscall
	j Menu
XL9:
	la $a0,tb9_1
	addi $v0,$0,4
	syscall
	jal Hamsort
	syscall
	j Menu
Exit:
	# Hien thi loi chao
	li $v0,4
	la $a0,LoiChao
	syscall
	 # The End . 
	li $v0, 10
	syscall
	# Dau thu tuc:
	NhapMang:
	addi $sp, $sp, -4
	sw $ra, 0($sp)
	#Than thu tuc:
	#Xuat tb1
	li $v0,4
	la $a0, tb1_1
	syscall
	#Nhap gia tri
	li $v0,5
	syscall
	#Luu vao n
	sw $v0, n
	#Khoi tao gia tri vong lap
	lw $t0, n
	li $t1, 0 # i = 0
	la $t2, a
Lap1:
	beq $t0, $t1,KTLap1
	#Xuat tb2
	li $v0,4
	la $a0, tb1_2
	syscall
	#Xuat chi so i
	li $v0,1
	move $a0,$t1
	syscall
	#Xuat tb3
	li $v0,4
	la $a0, tb1_3
	syscall
	#Nhap gia tri
	li $v0,5
	syscall
	#Luu vao a[i]
	sw $v0, ($t2)
	addi $t2, $t2,4
	addi $t1,$t1,1
	j Lap1
KTLap1:
	# Cuoi thu tuc : 
	lw $ra, 0($sp) #Lay dia chi tra ve
	addi $sp,$sp,4 # Xoa vung nho stack
	jr $ra
XuatMang:
	addi $sp,$sp,-4
	sw $ra,0($sp)
	#Xuat 2_tb1
	li $v0,4
	la $a0,tb2_1
	syscall
	#Khoi tao vong lap
	lw $t0,n
	li $t1,0 # i=0
	la $t2,a
Lap2:
	beq $t0,$t1,KTLap2
	#Xuat a[i]
	li $v0,1
	lw $a0,($t2)
	syscall
	#Xuat ktrang
	li $v0,4
	la $a0,khoangtrang
	syscall
	#Tang chi so
	addi $t1,$t1,1
	addi $t2,$t2,4
	j Lap2
KTLap2:
	#Xuong dong
	li $v0,4
	la $a0,xdong
	syscall
	lw $ra,0($sp)
	addi $sp,$sp,4
	jr $ra
TongMang:
	addi $sp,$sp,-4
	sw $ra,0($sp)
	#Khoi tao vong lap
	lw $t0,n
	li $t1,0 # i=0
	la $t2,a
	li $t3,0 #Tong
Lap3:
	beq $t0,$t1,KTLap3
	lw $t4,($t2)
	add $t3,$t3,$t4
	#Tang chi so
	addi $t1,$t1,1
	addi $t2,$t2,4
	j Lap3
KTLap3:
	move $v0,$t3
	lw $ra,0($sp)
	addi $sp,$sp,4
	jr $ra
TBCong:
	addi $sp,$sp,-4
	sw $ra,0($sp)
	#Khoi tao vong lap
	lw $t0,n
	li $t1,0 # i=0
	la $t2,a
	li $t3,0 #Tong
Lap4:
	beq $t0,$t1,KTLap4
	lw $t4,($t2)
	add $t3,$t3,$t4
	#Tang chi so
	addi $t1,$t1,1
	addi $t2,$t2,4
	j Lap4
KTLap4:
	#Chuyen $t3 thanh float
	mtc1 $t3,$f0
	cvt.s.w $f0,$f0
	#Chuyen n thanh float
	mtc1 $t0,$f1
	cvt.s.w $f1,$f1
	div.s $f2,$f0,$f1
	swc1 $f2,tbc
	lw $ra,0($sp)
	addi $sp,$sp,4
	jr $ra
KTNT:
	addi $sp,$sp,-4
	sw $ra,0($sp)
	#Khoi tao vong lap
	li $t1,2
	beq $a1,1,False
Lap5:
	beq $t1,$a1,True
	div $a1,$t1
	mfhi $t2
	beq $t2,$0,False
	addi $t1,$t1,1
	j Lap5
False:
	li $v0,0
	j KThucHam
True:
	li $v0,1
KThucHam:
	lw $ra,0($sp)
	addi $sp,$sp,4
	jr $ra
KTCP:
	addi $sp,$sp,-4
	sw $ra,0($sp)
	#Khoi tao vong lap
	move $t1,$a1
	li $t0,2
	div $t1,$t0
	mflo $t3
	addi $t3,$t3,1
	li $t4,1 #i=1
Lap6:
	beq $t3,$t4,KTLap6
	mult $t4,$t4
	mflo $t5
	beq $t5,$t1,Cp
	addi $t4,$t4,1
	j Lap6
KTLap6:
	li $v0,0
	j KTHam6
Cp:
	li $v0,1
KTHam6:
	lw $ra,0($sp)
	addi $sp,$sp,4
	jr $ra
HoanThien:
	addi $sp,$sp,-4
	sw $ra,0($sp)
	#Khoi tao vong lap
	li $t0,1 # i=1
	li $t1,0 # tong=0
Lap7:
	beq $t0,$a1,KTLap7 
	div $a1,$t0
	mfhi $t2
	beq $t2,$0,TangT7
	j Tangi7
TangT7:
	add $t1,$t1,$t0
Tangi7:
	addi $t0,$t0,1
	j Lap7
KTLap7:
	beq $t1,$a1,True7
	#False
	li $v0,0
	j KThucHam7
True7:
	# True
	li $v0,1
KThucHam7:
	lw $ra,0($sp)
	addi $sp,$sp,4
	jr $ra
DoiXung:
	addi $sp,$sp,-4
	sw $ra,0($sp)
	#khoi tao gia tri trong vao lap
	li $t0,10
	move $t1,$a1 #k
	move $t2,$a1
	li $t3,0 #m
	li $t4,0
	li $t5,0
Lap8:
	blez $t1, KTLap8
	div  $t1,$t0
	mfhi $t5
	mflo $t1
	mult $t3,$t0
	mflo $t4
	add $t3,$t4,$t5
	j Lap8
KTLap8:
	beq $t2,$t3,True8
	#False
	li $v0,0
	j KThucHam8
True8:	
	#True
	li $v0,1
KThucHam8:
	lw $ra,0($sp)
	addi $sp,$sp,4
	jr $ra
#---------------------------------------------------------------------------------
#---------------------------------- Sap Tang Dan ---------------------------------
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
	la $a0,tb9_1 
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
	j Exit
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
# P/s : Ham sap tang dan nay chi mang tinh chat tham khao do chung em muon y tuong tu 1 nhom ben lop 12CK3 .
#-------------------------------------------- THE END ------------------------------------------------------