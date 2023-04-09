#pragma once
class vector{
public:
	vector(int);

	~vector();

	int size();

	double get(int);

	void set(int, double);

private:
	int sz;
	double* elem;
};
