#include <memory>
#include <vector>
//using T = double;
std::allocator<double> alloc_obj;

int main() {
	size_t a = 26;
	std::vector<bool> useful{};
	//auto ms=alloc_obj.max_size();
	size_t count(128);
	auto ptr=alloc_obj.allocate(count);
	//alloc_obj.construct(ptr, 7.0);
	//alloc_obj.destroy(ptr);
	alloc_obj.deallocate(ptr, count);
	
	return 0;
}

