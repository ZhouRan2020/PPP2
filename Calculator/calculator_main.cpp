/*******************************************************
project: a simple command line calculator like matlab command line
author: moju
date:2022.3.11
version: v1.0
********************************************************/

#include "std_lib_facilities.h"

#include <limits>

/**************************************************************
* 键盘输入字符流
* 但是被类tokenstream封装成token流，用tokenstream读数据，我们读到的最小单位只能是token
* 有的字符就是token，而有的不一定，特别的，换行符是一个token。
* 用户每次输入的序列，称为一个calculation。calculation一定以token换行符结尾，这是由键盘输入特性决定的。
* 至此，语法树和课本相同。
* 
**************************************************************/

class Token {
public:
    char kind;
    double value;
    string name;

   // Token(char ch):kind{ch}{}
   //Token(char ch,double val):kind{ch},value{val}{}
   // Token(char ch,string n):kind{ch},name{n}{}
};

class Token_stream {
public:
    Token get();
    void putback(Token t);
    bool isfull();
    void set();
    char iswhat();
    bool enter{false};
private:
    bool full{ false };    
    Token buffer;
};

void Token_stream::set() {
    full = false;
    enter = false;
}
void Token_stream::putback(Token t) {
    if (full) error("内部缓冲区错误");
    buffer = t;
    full = true;
}
//将字符流动态地当成token流读取
/*对系统字符流的封装，理论上是本程序其他函数的可见的最底层，极其重要，必要时用枚举法描述所有情况*/
Token Token_stream::get() {

    double val{};

    if (full) {

        full = false;

        if (buffer.kind == '\n')
            enter = true;

        return buffer;
    }
    
    char ch = cin.get();

    switch (ch) {
    case '(':
    case ')':
    case '+':
    case '-':
    case '*':
    case '/':
    //case '=':
    case ';':
    case ',':
        return Token{ ch };

    case '0':case '1':case '2':case '3':case '4':case '5':case '6':case '7':case '8':case '9':
        cin.putback(ch);
        cin >> val;
        
        if (cin.fail()) {
            cin.clear();
          //  continue;
            error("数字格式错误或数字溢出");
        }

        return Token{ '#',val };

    /*case'.':
        cin.putback(ch);
        if(cin >> val){
            return Token{ '#',val };
        }
        else {
            while (cin.get() != '\n') {
            }
            enter = true;
            error("小数点后面必须有数字");
        }   
*/
    case'.':
        error("语法错误");

    case '\n':
        enter = true;
        return Token{ '\n' };

    default:
        error("不支持的字符或科学计数法格式错误");
    }

}

bool Token_stream::isfull() {

        return full;
}

char Token_stream::iswhat() {
    return buffer.kind;
}
Token_stream ts;

double expression();

double primary() {

    double val{};
    while (true) {
        Token t = ts.get();
        switch (t.kind) {
        case '#':
            return t.value;
        case '(':
            val = expression();
            t = ts.get();
            if (t.kind == ')')
                return val;
            else
                error("缺少 ')'");
        case '-':
            return -primary();
        case '+':
            return primary();
        default:
            error("语法错误或输入了空表达式");
        }
    }
}

double term() {

    double d{};
    double left = primary();
    Token t = ts.get();
    while (true) {
        switch (t.kind) {
        case '*':
            left *= primary();
            t = ts.get();
            break;
        case '/':
            d = primary();
            if (d == 0) error("0不能作为除数");
            left /= d;
            t = ts.get();
            break;
        default:
            ts.putback(t);
            return left;
        }
    }
}


double expression() {
    double left = term();
    Token t = ts.get();
    while (true) {
        switch (t.kind) {
        case '+': 
            left += term();
            t = ts.get();
            break;
        case '-':
            left -= term();
            t = ts.get();
            break;
        default:
            ts.putback(t);
            return left;
        }
    } 
}


double declaration() {
    return 0;
}


double statement() {



        return expression();
}


//EOF;


void clean_up_mess() {
}

//calculation是以换行结尾的序列
void calculation() try{

    ts.set();

    Token t=ts.get();
    if (t.kind == '\n') return;
    else ts.putback(t);

    double ans = statement();
    t = ts.get();
    while (true) {

            switch (t.kind) {
            case ',': 
                cout << '=' << ans << '\n';

                t = ts.get();

                if (t.kind == '\n')
                    return;
                else
                    ts.putback(t);

                ans = statement();
                t = ts.get();
                break;

            case';':  

                t = ts.get();

                if (t.kind == '\n')
                    return;
                else
                    ts.putback(t);

                ans = statement();
                t = ts.get();
                break;

            case '\n':

                cout << '=' << ans << '\n';
                return;

            default:
                error("不是完整的表达式");
            }
    }      
}
catch (exception& e) {
    cerr << e.what() << '\n';
    // numeric_limits::max() 返回输入缓冲的大小。
    // ignore 函数在此将把输入流中的数据清空。
    // 这两个函数的具体用法请读者自行查询。

    if (ts.enter == false)
        cin.ignore(65535, '\n');
    //std::numeric_limits<std::streamsize>::max()
     //   while (cin.get() != '\n');

}




int main()
{
    //使用户反复地输入calculation并计算calculation
    cout << "语法规则：\n";
    cout << "支持的运算：加减乘除。支持括号和负数。\n";
    cout << "支持一次输入多个表达式，用逗号或分号隔开。\n";
    cout << "用逗号结尾的式子会输出结果，分号则不会。\n";
    cout << "小数点左侧必须有数字。逗号和分号的左侧必须有非空的表达式。\n";
    cout << "支持科学计数法。\n";
    cout << "不支持空格，请输入紧凑的形式。按回车输出结果。\n";

    while (true) {
        cout << ">>>";  
        calculation();  
    }

    return 0;
}