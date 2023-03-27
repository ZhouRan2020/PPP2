int main() {
	//int a = 8;

	const int* b = new int;

	int* p = const_cast<int*> (b);

	int* p2 = reinterpret_cast<int*>(0xffff0000ffff0000);

	void* p3 = new long;

	int* p4 = static_cast<int*> (p3);
}