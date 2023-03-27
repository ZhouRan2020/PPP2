#pragma once
class vector
{
public:
	vector(int);

	~vector(void);

	int size(void);

	double get(int);

	void set(int, double);

private:
	int sz;
	double* elem;
};
