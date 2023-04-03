/*********************A calculater*********************/

#include "..\std_lib_facilities.h";

class Token{
public:
	char kind;
	double value;
};

class Token_stream {
public:
	Token get();
	void putback(Token t);
private:
	bool full{ false };
	Token buffer{};
};

void Token_stream::putback(Token t) {
	buffer = t;
	full = true;
}

Token Token_stream::get() {
	if (full) {
		full = false;
		return buffer;
	}

	char ch;
	cin >> ch;

	switch (ch) {
	case';':
	case'q':
	case'(':case')':case'+':case'-':case'*':case'/':
		return Token{ ch };
	case'.':
	case'0':case'1':case'2':case'3':case'4':
	case'5':case'6':case'7':case'8':case'9':
	{
		cin.putback(ch);
		double val;
		cin >> val;
		return Token{ '#',val};
	}
	default:error("bad token\n");

	}
}

Token_stream ts;

double polynomial();

double primary() {

	Token t = ts.get();
	switch (t.kind) {
	case'(': {
		double d = polynomial();
		t = ts.get();
		if (t.kind != ')')      
			error(")expected");
		return d;
		}
		
	case'#':
		return t.value;
	default:
		error("primary incorrect");
		
	}
}

double term() {

	double left = primary();
	Token t = ts.get();
	while (true) {
		switch (t.kind) {
		case'*':
			left *= primary();
			t = ts.get();
			break;
		case'/':
			left /= primary();
			t = ts.get();
			break;
		default:
			ts.putback(t);
			return left;
		}
	}
}

double polynomial() {

	double left = term();
	Token t = ts.get();
	while (true) {
		switch (t.kind) {
		case'+':
			left += term();
			t = ts.get();
			break;
		case'-':
			left -= term();
			t = ts.get();
			break;
		default:
			ts.putback(t);
			return left;
		}
	}
}

int main() 
try {
	while (true) { cout << polynomial() << '\n'; }
}
catch(exception& e){
	cerr << e.what() << '\n';
	return 1;
}
catch (...) {
	cerr << "exception\n";
	return 2;
}

