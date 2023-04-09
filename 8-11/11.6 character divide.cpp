#include "std_lib_facilities.h"
double str2double(string s) 
{
    istringstream iss{ s };
    double d;
    iss >> d;
    if (!iss)
    	error("double format error", s);
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

