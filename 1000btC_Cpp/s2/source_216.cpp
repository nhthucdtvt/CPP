
#include <stdio.h>
#include <conio.h>
#include <math.h>
#define MAX 10
void main()
{
int a[MAX], b[MAX];
int j = 0, temp;
bool bl;
// nhập mảng
for (int i = 0; i < MAX; i++)
{
printf("nhap 1 so nguyen: ");
scanf("%d", & a[i]);
}
// in ra mảng trước khi sắp xếp
printf("mang truoc sap xep: ");
for (int i = 0; i < MAX; i++)
printf(" %d", a[i]);
// Kiểm tra số nào là số nguyên tố, gán vị trí của nó vào mảng b
for (int i = 0; i < MAX; i++)
{
bl = true;	
for (int z = 2; z <= sqrt((float)a[i]); z++) 
{
if (a[i] % z == 0)
{
bl = false;
break;
}
}
if (bl)
{
b[j] = i;
j++;
}
}
// Sắp xếp các phần tử là số nguyên tố (vị trí đã được lưu trong mảng b) theo thứ tự giảm dần
for (int i = 0; i < j - 1; i++)
{
for (int k = i + 1; k < j; k++)
{
if(a[b[i]] > a[b[k]])
{
temp = a[b[i]];
a[b[i]] = a[b[k]];
a[b[k]] = temp;
}
} 
}
// in mảng sau khi sắp xếp
printf("\nmang sau khi sap xep: ");
for (int i = 0; i < MAX; i++)
printf(" %d", a[i]);
getch();
}
#include <stdio.h>
#include <conio.h>
#include <math.h>
#define MAX 10
void main()
{
int a[MAX], b[MAX];
int j = 0, temp;
bool bl;
// nhập mảng
for (int i = 0; i < MAX; i++)
{
printf("nhap 1 so nguyen: ");
scanf("%d", & a[i]);
}
// in ra mảng trước khi sắp xếp
printf("mang truoc sap xep: ");
for (int i = 0; i < MAX; i++)
printf(" %d", a[i]);
// Kiểm tra số nào là số nguyên tố, gán vị trí của nó vào mảng b
for (int i = 0; i < MAX; i++)
{
bl = true;	
for (int z = 2; z <= sqrt((float)a[i]); z++) 
{
if (a[i] % z == 0)
{
bl = false;
break;
}
}
if (bl)
{
b[j] = i;
j++;
}
}
// Sắp xếp các phần tử là số nguyên tố (vị trí đã được lưu trong mảng b) theo thứ tự giảm dần
for (int i = 0; i < j - 1; i++)
{
for (int k = i + 1; k < j; k++)
{
if(a[b[i]] > a[b[k]])
{
temp = a[b[i]];
a[b[i]] = a[b[k]];
a[b[k]] = temp;
}
} 
}
// in mảng sau khi sắp xếp
printf("\nmang sau khi sap xep: ");
for (int i = 0; i < MAX; i++)
printf(" %d", a[i]);
getch();
}