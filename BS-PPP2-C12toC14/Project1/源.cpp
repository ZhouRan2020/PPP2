int increase_value(int n) {
	n++;
	return n;
}

int increase_reference(int& n) {
	n++;
	return n;
}

int increase_pointer(int* n) {
	(*n)++;
	return *n;
}

int main() {
	int x = 0;

	int b = increase_value(x);

	int c = increase_reference(x);

	int d = increase_pointer(&x);
}