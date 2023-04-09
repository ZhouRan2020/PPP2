#include "vector.h"
vector::vector(int s)
	:sz{ s }, elem{ new double[s] }
{
	for (int i = 0; i < s; ++i)
		elem[i] = 0;
}

vector::~vector()
{
	delete[] elem;
}

double vector::get(int n) 
{
	return vector::elem[n];
}

void vector::set(int n, double v) 
{
	vector::elem[n] = v;
}

int vector::size() 
{
	return vector::sz;
}