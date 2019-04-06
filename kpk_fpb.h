//#include <iostream>
//#include "kev.h"
using namespace std;

//kev object;
bool pecornot(double ang)
{
 int a = ang;
 if (ang == a)
 {
  return 0;
 }
 return 1;
}
bool ganjil(double ang)
{
 //ganjil artinya hanya tidak bisa dibagi dua
 if (pecornot(ang/2))
 {
  return true;
 }
 return false;
}
bool genap(double ang)
{
 //ganjil artinya hanya tidak bisa dibagi dua
 if (pecornot(ang/2))
 {
  return false;
 }
 return true;
}
int max_array(int ang[], int jumlah)
{
 int a = 0;
 for (int i = 0; i < jumlah; i++)
 {
  if (a < ang[i])
  {
   a = ang[i];
  }
 }
 return a;
}
int kpk(int ang[], int jumlah)
{
 int maximal_answer = 9999;
 //angka yang sama, pangkat terbesar, tapi...pake modulus aja lah
 int temp = 0;
 auto maxx = max_array(ang, jumlah);
 int jawab = 1;
 while (true)
 {
  for (int i = 0;i < jumlah; i++)
  {
   if (((maxx*jawab)%ang[i]) == 0)
   {
    temp += 1;
   }
  }
  //kalo lebih 9999(max), stop aja lah...
  if (jawab>maximal_answer)
  {
   return 0;
  }
  if (temp == jumlah)
  {
   return jawab*maxx;
  }
  jawab+=1;
  temp = 0;
 }
}

int fpb(int ang[], int jumlah, int maximal_answer = 0)
{
 //angka yang sama, pangkat terbesar, tapi...pake modulus aja lah
 int temp = 0;
 auto maxx = max_array(ang, jumlah);
 int jawab = max_array(ang, jumlah);
 while (true)
 {
  for (int i = 0;i < jumlah; i++)
  {
   if ((ang[i]%(maxx*jawab)) == 0)
   {
    temp += 1;
   }
  }
  //kalo lebih 9999(max), stop aja lah...
  if (jawab>maximal_answer)
  {
   return 0;
  }
  if (temp == jumlah)
  {
   return jawab*maxx;
  }
  jawab-=1;
  temp = 0;
 }
}
