#include <iostream>
#include "kpk_fpb.h"
#include <math.h>

#ifndef fraction_H
#define fraction_H
class fraction
{
 public:
  int ang0;
  int ang1;

  fraction(double a, double b):ang0(a), ang1(b) {}
  // a
  //--- 
  // b
  fraction operator+(fraction &obj)
  {
   int bawa[] = {this->ang1, obj.ang1};
   int bawah = kpk(bawa, 2);
   return fraction(((bawah/this->ang1)*(this->ang0)) + ((bawah/obj.ang1)*(obj.ang0)), bawah);
  }

  fraction operator-(fraction &obj1)
  {
   int bawa[] = {(*this).ang1, obj1.ang1};
   int bawah =  kpk(bawa, 2);
   return fraction( (bawah/(*this).ang1) * ((*this).ang0) - (bawah/obj1.ang1) * obj1.ang0, bawah );
  }
  double angka()
  {cout <<this-> ang0 << "  " << this->ang1 << endl;return ((double) this->ang0) / ((double) this->ang1);}
  
  
  fraction operator*(fraction &obj2)
  {
   return fraction((*this).ang0 * obj2.ang0, (*this).ang1 * obj2.ang1);
  }
  fraction operator/(fraction &obj3)
  {
   return fraction(this->ang0 * obj3.ang1, this->ang1 * obj3.ang0);
  }
  

};
#endif
double pow_fraction(fraction a, fraction b)
  {
   double hasil = pow(a.angka(), b.angka());
   return hasil;
  }
void print_fraction(fraction yay)
{
   std::cout << yay.ang0 << " / " << yay.ang1 << endl;
}
fraction shrink(fraction obj)
{
 double ang0 = obj.ang0;
 double ang1 = obj.ang1;
 int bd[] = {2, 3, 5, 7}; //yang bisa dibagi <==
 bool finish = false;
 bool lanjut = true;
 while (not finish)
 {
  for (double x:bd)
  {
   lanjut = false;
   if ((not pecornot(ang0/x)) && (not pecornot(ang1/x)) && (not ang0/x < 1) && (not ang1/x < 1))
   {
    ang0/=x;ang1/=x;lanjut=true;break;
   }
  }
  if (not lanjut){break;}
 }
 return fraction(ang0, ang1);
}

fraction be_fraction(double nilai)
  {
   int temp = 0;
   if (pecornot(nilai))
   {
    while (true)
    {
     nilai*=10;
     temp += 10;
     if (!pecornot(nilai))
     {
      break;
     }    
    }
   }
   if (temp==0){temp = 1;}
   return fraction(nilai, temp);
  }

/*
int main()
{
 cout << "Oke\n";
 fraction oke(1, 2), eko(3, 4);
 fraction hasil = oke + eko;
 cout << hasil.angka() << endl;
 fraction wow(5, 4), oww(2, 3);
 cout << (wow / oww).angka() << endl;

}*/













