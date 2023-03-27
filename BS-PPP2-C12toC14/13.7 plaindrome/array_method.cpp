#include <string>
#include <iostream>

bool string_m(std::string);

int main() {

	std::string s{};
	while (std::cin >> s) {
		if (string_m(s)) {
			std::cout << "plaindrome"<<std::endl;
		}
		else {
			std::cout << "not plaindrome"<<std::endl;
		}
	}

	return 0;
}

bool string_m(std::string s) {
	if (s.length() == 0) {
	}
	else if (s.length() == 1) {
	}
	else if (s.length() % 2 == 0) {
		for (int i = 0; i <= s.length() / 2; ++i)
			if (s[i] != s[s.length() - 1 - i])
				return false;
	}
	else if (s.length() % 2 == 1) {
		for (int i = 0; i <= (s.length() - 1) / 2; ++i)
			if (s[i] != s[s.length() - 1 - i])
				return false;
	}
	else
		std::cout << "wrong!";

	return true;
}