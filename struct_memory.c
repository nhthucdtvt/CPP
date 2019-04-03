#include <stdio.h>

struct Normal_t
{
  char cdata; //1
  int idata; //4
  double ddata; //8
  float  fdata; //4
};// 12

struct Aligned_t
{
  char cdata;
  int idata;
  double ddata;
  float fdata;
}__attribute__ ((aligned (8))); // 12 == align 8 ==> 16

struct Packed_t
{
  char cdata; //1
  int idata; //4
  double ddata; //4
  float fdata; //8
}__attribute__((packed));// == minimum ==> 17


int main(int argc, char **argv)
{
  printf("sizeof(char): %d\n", (int)sizeof(char));
  printf("sizeof(int): %d\n", (int)sizeof(int));
  printf("sizeof(double): %d\n", (int)sizeof(double));
 // printf("sizeof(long): %d\n", (int)sizeof(long));
  printf("sizeof(float): %d\n",(int)sizeof(float));
  printf("\n\n");

  struct Normal_t m1;
  struct Aligned_t m2;
  struct Packed_t m3;

  printf("sizeof(Normal_t): %d\n", (int)sizeof(m1));
  printf("sizeof(Aligned_t): %d\n", (int)sizeof(m2));
  printf("sizeof(Packed_t): %d\n\n", (int)sizeof(m3));

  printf("address Normal cdata: %x\n",&m1.cdata);
  printf("address Normal idata: %x\n",&m1.idata);
  printf("address Normal ddata: %x\n",&m1.ddata);
  printf("address Normal fdata: %x\n\n",&m1.fdata);

  printf("address Aligned_t cdata: %x\n",&m2.cdata);
  printf("address Aligned_t idata: %x\n",&m2.idata);
  printf("address Aligned_t ddata: %x\n",&m2.ddata);
  printf("address Aligned_t fdata: %x\n\n",&m2.fdata);

  printf("address Packed_t cdata: %x\n",&m3.cdata);
  printf("address Packed_t idata: %x\n",&m3.idata);
  printf("address Packed_t ddata: %x\n",&m3.ddata);
  printf("address Packed_t fdata: %x\n",&m3.fdata);

  return 0;
}
