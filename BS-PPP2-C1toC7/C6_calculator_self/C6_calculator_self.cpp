//calculater
#include "..\std_lib_facilities.h"

class Token {
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
		return Token{ '#',val };
	}
	default:error("bad token\n");

	}
}

Token_stream ts{};
//自底向上声明，自顶向下调用

//多项式求值，返回结果

Token t{};


double expression();

//常量或者括号里的多项式求值，返回结果
double primary() {

	Token t = ts.get();

	switch (t.kind) {
	case'#': 
	{
		return t.value;
	}
	case'(': 
	{
		double d=expression();
		t=ts.get();
		if (t.kind != ')') {
			error("')'expected\n");
		}
		else {
			
			return d;
		}
	}
	default:
	{
		//error("invalid sign\n");
	}
	}

}



//项求值，返回结果
double term() {
	
	double left=primary();
	Token t = ts.get();

		switch (t.kind) {
		case'*':
		{
			left *= term();
			break;
		}
		case'/':
		{
			left /= term();
			break;
		}
		default:
		{

			ts.putback(t);
			return left;
		}
		}
}




//多项式求值，返回结果
double expression() {

	double left = term();

	Token t = ts.get();

	switch (t.kind) {
	case'+':
	{
		left += expression();
		break;
	}
	case'-':
	{
		left -= expression();
		break;
	}
	default:
	{
		ts.putback(t);
		return left;
	}
	}

}


//主程序，打印结果
int main() try{
	while (true) {
		cout << '=' << expression() << '\n';
	}
	return 0;
}
catch (exception& e)
{
	cerr << e.what() << '\n';
	return 1;
}
catch (...)
{
	cerr << "Exception" << '\n';
	return 2;
}
