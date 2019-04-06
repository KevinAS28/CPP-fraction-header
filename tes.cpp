#include <iostream>
#include <string>
#include "fraction.h"
int main(){	
 fraction oke(1, 2), eko(3, 4);
 fraction hasil = oke + eko;
 print_fraction(hasil);
 return 0;
}
