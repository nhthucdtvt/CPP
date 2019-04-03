# De Bai : Chuyen Soruce Code viet bang C trong slide bai giang ly thuyet thanh Source Code viet bang hop ngu MIPS yeu cau dung thu tu - ham .
# Source Code viet bang C trong slide bai giang:
# int mult(int mcand,int mlier)
# {
#	int product=0;
#	while(mlier>0)
#	{
#		product=product+mcand;
#		mlier=mlier-1;
#	}
#	return product;
# }
# void main()
# {
#	int i,j,k,m; 
#	...
#	i=mult(j,k); ...
#	m=mult(i,i); ...
# }
# -----------------------------------------------------------------------------------------------------------------------------------
# --------------------------------------------------------- Bai Lam -----------------------------------------------------------------
.data
	Nhapj:.asciiz "Nhap Vao So Nguyen j = "
	Nhapk:.asciiz "Nhap Vao So Nguyen k = "
	KetQua:.asciiz "Ket Qua Tra Ve m = "
.text
main:
	# Xuat thong bao Nhapj 
	li $v0,4
	la $a0,Nhapj
	syscall
	# Nhap vao so nguyên j .
	li $v0,5
	syscall
	# Luu so nguyen j vua nhap vao thanh ghi luu tru $s0 (giu gia tri trong suot qua trinh goi ham ) .
	move $s0,$v0
	# Yeu cau cua chuong trinh la mlier > 0 roi moi tiep tuc di tinh product (product duoc khoi tao bang 0).Neu mlier <=0 => product tra ve gia tri khoi tao ban dau = 0 => noi cach khac o day neu 1 trong 2 gia tri j,k hay ca 2 gia tri cung bang 0 => tra ve product = 0.
	# Cach lam:Ta thuc hien phep so sanh kiem tra dieu kien neu gia tri j >= 0 => nhay den nhan "NhapTiepK" de tiep tuc nhap k roi lai tiep tuc thuc hien phep so sanh 1 lan nua xem k co >=0 hay khong ? Neu co thi nhay den nhan "XuLyDuLieu" di tinh va in ra ket qua cuoi cung,neu khong thi nhay den nhan "TraVeKetQua0" de tra ve ket qua m = 0 . Con neu gia tri j ban dau < 0 => nhay den nhan "TiepTucNhapKMacDuCuoiCungTraVeKetQua0" de tiep tuc nhap k theo nhu dung thong le roi sau do nhay tiep den nhan "TraVeKetQua0" de tra ve ket qua m = 0 .
	# Truong hop j >=0 => nhay den nhan "NhapTiepK"
	bgez $s0,NhapTiepK
	# Truong hop j < 0 => nhay den nhan "TiepTucNhapKMacDuCuoiCungTraVeKetQua0" de tiep tuc nhap k roi sau do nhay tiep den nhan "TraVeKetQua0" de in ra ket qua m = 0 .
	bltz $s0,TiepTucNhapKMacDuCuoiCungTraVeKetQua0
NhapTiepK:	
	# Xuat thong bao Nhapk
	li $v0,4
	la $a0,Nhapk
	syscall
	# Nhap vao so nguyen k .
	li $v0,5
	syscall
	# Luu so nguyen k vua nhap vao thanh ghi luu tru $s1 (giu gia tri trong suot qua trinh goi ham ) .
	move $s1,$v0
	# Truong hop k >= 0 => nhay den nhan "XuLyDuLieu" roi di tinh in ra ket qua .
	bgez $s1,XuLyDuLieu
	# Truong hop k < 0 => nhay thang luon den nhan "TraVeKetQua0" de in ra ket qua m = 0 .
	bltz $s1,TraVeKetQua0
XuLyDuLieu:	
	# Xu Ly i=mult(j,k) .
	move $a0,$s0 
	move $a1,$s1 
	jal mult # Luu dia chi tro ve vao $ra va nhay den nhan "mult"
	# Xu Ly m=mult(i,i) .
	move $a0,$v0
	move $a1,$v0
	jal mult # Luu dia chi tro ve vao $ra va nhay den nhan "mult"
	move $s2,$v0 # Luu gia tri cua m vao thanh ghi $s2 .
	# Xuat KetQua .
	li $v0,4
	la $a0,KetQua
	syscall
	# Xuat ra ket qua m .
	li $v0,1
	move $a0,$s2 # Luu gia tri cua m trong thanh ghi $s2 vao thanh ghi $a0 .
	syscall
	j Exit # Nhay den nhan "Exit" .
TiepTucNhapKMacDuCuoiCungTraVeKetQua0:
	# Xuat thong bao Nhapk
	li $v0,4
	la $a0,Nhapk
	syscall
	# Nhap vao so nguyen k .
	li $v0,5
	syscall
	# Luu so nguyen k vua nhap vao thanh ghi luu tru $s1 (giu gia tri trong suot qua trinh goi ham ) .
	move $s1,$v0
	j TraVeKetQua0 # Nhay tiep den nhan "TraVeKetQua0" de tra ve ket qua m = 0 .
TraVeKetQua0:	
	# Xuat KetQua .
	li $v0,4
	la $a0,KetQua
	syscall
	li $t3,0 # Khoi tao thanh ghi tam $t3 = 0 .
	move $a0,$t3 # Luu gia tri thanh ghi tam $t3 vao thanh ghi $a0 .
	# In ra ket qua
	li $v0,1
	syscall
Exit:
	# Thoat chuong trinh .
	li $v0,10
	syscall
mult:
	# Dau Thu Tuc :
	addi $sp,$sp,-4 # Khai bao kich thuoc cho stack .
	sw $ra,0($sp) # Cat dia chi tra ve cua thu tuc trong $ra vao ngan xep .
	# Than Thu Tuc : 
	# Khoi tao vong lap .
	move $t0,$a0 # Luu gia tri cua mcand trong thanh ghi $a0 vao thanh ghi tam $t0 .
	move $t1,$a1 # Luu gia tri cua mlier trong thanh ghi $a1 vao thanh ghi tam $t1 .
	li $t2,0 # Khoi tao product = 0 .
Lap:
	beq $t1,$0,KetThucLap # Dieu kien dau vao la mlier > 0 . Neu thoa roi moi tiep tuc tinh nhung dong lenh ben duoi và moi lan tinh xong thi mlier giam xuong (mlier = mlier - 1 ) roi lai lap lai qua trinh so sanh tren . Nen ta dat dieu kien neu mlier giam xuong mà bang 0 => ket thuc qua trinh lap .
	add $t2,$t2,$t0 # product = product + mcand
	sub $t1,$t1,1 # mlier = mlier - 1 
	j Lap # Lap lai qua trinh tren .
KetThucLap:
	# Cuoi Thu Tuc .
	move $v0,$t2 
	lw $ra,0($sp) # Lay dia chi tra ve $ra
	addi $sp,$sp,4
	jr $ra
# ---------------------------------------------------- THE END -------------------------------------------------------------------------