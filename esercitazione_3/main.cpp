#include <iostream>
#include "rational.hpp"

int main(void) 
{
	/* Definisco due numeri razionali qualsiasi */
	rational<int> r1(3,6);
	rational<int> r2(5,4);
	
	/* Testo le operazioni */
	rational<int> r3 = r1+r2;
	rational<int> r4 = r1-r2;
	rational<int> r5 = r2-r1;
	rational<int> r6 = r1*r2;
	rational<int> r7 = r1/r2;
	
	/* Testo la gestione dei valori critici */
	rational<int> r8(5, 0);
	rational<int> r9(0, 0);
	rational<int> r10(0, 12);
	rational<int> r11(15, 1);
	rational<int> r12(12, -9);
	rational<int> r13(-32, -8);
	rational<int> r14(-5, 0);
	
	/* Stampo quanto fatto per vedere che sia tutto corretto */
	std::cout << r1 << "\n";
	std::cout << r2 << "\n";
	std::cout << r3 << "\n";
	std::cout << r4 << "\n";
	std::cout << r5 << "\n";
	std::cout << r6 << "\n";
	std::cout << r7 << "\n";
	std::cout << r8 << "\n";
	std::cout << r9 << "\n";
	std::cout << r10 << "\n";
	std::cout << r11 << "\n";
	std::cout << r12 << "\n";
	std::cout << r13 << "\n";
	std::cout << r14 << "\n";
	
	return 0;
}