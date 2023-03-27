#include "vector.h"
//#include<stdio.h>

int main() {
	if (true) {
		vector a{ 100 };

		vector* p{ &a };

		p->set(49, 3.14);
	}
	
	//getchar();
	return 0;
}