#include <iostream>
#include <string>

class Link {
public:

	Link(const char& v);
	Link();

	Link* insert(Link*);

	Link* add(Link*);

	Link* next();

	Link* last();

	Link* erase();
	//void print_link(Link*);

	char value;

private:

	Link* previous;
	Link* successive;

	//Link* insert(Link*, Link*);
};

Link::Link(const char& v)
	:value{ v }, previous{ nullptr }, successive{ nullptr }{}

Link::Link()
	:value{ '\0' }, previous{ nullptr }, successive{ nullptr }{}

Link* Link::insert(Link* n) {
	if (!n)
		return this;

	if (!this)
		return n;

	if (previous)
		previous->successive = n;

	n->previous = previous;

	n->successive = this;

	previous = n;

	return n;
}

Link* Link::add(Link* n) {
	if (!n)
		return this;

	if (!this)
		return n;

	if (successive)
		successive->previous = n;

	n->previous = this;

	n->successive = successive;

	successive = n;

	return n;
}

Link* Link::erase() {
	if (!this) {
		return nullptr;
	}

	if (previous)
		previous->successive = successive;

	if (successive)
		successive->previous = previous;

	return successive;
}

Link* Link::next() {
	if (!this) {
		return nullptr;
	}
	return successive;
}

Link* Link::last() {
	if (!this) {
		return nullptr;
	}
	return previous;
}

void print_link_forward(Link* p) {
	std::cout << '{';

	for (Link* temp = p; temp; temp = temp->next())
		std::cout << temp->value << ',';

	std::cout << '}';
}

void print_link_backward(Link* p) {
	std::cout << '{';

	for (Link* temp = p; temp; temp = temp->last()) {
		std::cout << temp->value;
		if (temp->next() != nullptr) { std::cout << ','; }
	}


	std::cout << '}';
}

int main() {
	//链表的灵魂是一根指针
	//链表就是一根指向Link类型的指针Link*
	Link* alphabet = nullptr;

	for (char i = 'z'; i >= 'a'; --i) {
		alphabet = alphabet->insert(new Link{ i });
	}

	print_link_forward(alphabet);

	getchar();
	return 0;
}