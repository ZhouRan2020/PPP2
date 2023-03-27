// 11.6 character divide.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "..\std_lib_facilities.h"

double str2double(string s) {
    istringstream iss{ s };
    double d;
    iss >> d;
    if (!iss) { error("double format error", s); }

    return d;
}

class Token {
public :
    Token(char tt,double vv,string nn):type{ tt }, value{ vv }, name{ nn }{}

    Token():type{ '\0' }, value{ 0 }, name{ "" }{}
    
    Token(double vv) :type{ 'd' }, value{ vv }, name{ "" }{}

    Token(string nn) :type{ 'n' }, value{ 0 }, name{ nn }{}

    Token(char tt) :type{ tt }, value{ 0 }, name{ "" }{}

    void print_token();

private:
    char type;
    double value;
    string name;
};



Token get_token_number(istringstream& iss) {
    double num;
    iss >> num;
    Token temp{ num };
    return temp;
}

Token get_token_name(istringstream& iss) {
    string name;
    iss >> name;
    Token temp{ name };
    return temp;
}

void Token::print_token() {
    switch (type) {
    case('d'):
        cout << value;
        break;
    case('n'):
        cout << name;
        break;
    default:
        cout << type;
    }
}


string get_command() {
    string command;
    getline(cin, command);
    return command;
}


int main()
{
    istringstream command{ get_command() };
    vector<Token> tokentable;

    for (char ch; command.get(ch);) {
        if (isspace(ch)) {

        }
        if (isdigit(ch)) {
            command.putback(ch);
            Token temp=get_token_number(command);
            tokentable.push_back(temp);
        }
        else if (isalpha(ch)) {
            command.putback(ch);
            Token temp=get_token_name(command);
            tokentable.push_back(temp);
        }
        else {

            Token temp{ch};
            
            tokentable.push_back(temp);
        }
    }

    for (int i=0; i < tokentable.size(); ++i) {
        tokentable[i].print_token();
        cout << '|';
    }

    keep_window_open();
    return 0;
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
