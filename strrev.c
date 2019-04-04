#include<stdio.h>
#include <string.h>
 
int main() {
  char str[20];
  printf("Nhap chuoi: ");
  gets(str);
  printf("Chuoi da nhap: %s", str);
  printf("\nChuoi dao nguoc: %s", strrev(str));
  return 0;
}
