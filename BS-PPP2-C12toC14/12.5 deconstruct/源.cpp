#include "vector.h"
int main() 
{
		vector a{ 100 };
		vector* p{ &a };
		p->set(49, 3.14);
		return 0;
}