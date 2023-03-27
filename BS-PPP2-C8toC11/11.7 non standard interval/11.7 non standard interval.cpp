// 11.7 non standard interval.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "..\C9SE1\std_lib_facilities.h"

class Punct_stream {
public:
    Punct_stream(istream& is) : source{is}, sensitive{true} { }

    void whitespace(const string& s) { white = s; }

    void add_white(char c) { white += c; }

    bool is_whitespace(char c);

    void case_sensitive(bool b) { sensitive = b; }

    bool is_case_sensitive() { return sensitive; }

    Punct_stream& operator>> (string& s);

    operator bool ();

private:
    istream& source;
    istringstream buffer;
    string white;
    bool sensitive;
};

int main()
{
    //std::cout << "Hello World!\n";
    Punct_stream ps { cin };

    ps.whitespace(";:,.?!()\"{}<>/&$@#%^*|~");

    ps.case_sensitive(false);

    vector<string>  vs;

    for (string word; ps >> word;)
        vs.push_back(word);

    sort(vs.begin(), vs.end());

    for (int i=0 ; i < vs.size(); ++i)

        if (i == 0 || vs[i] != vs[i - 1])  
            cout << vs[i] << '\n';

    keep_window_open();
    return 0;
}

bool Punct_stream::is_whitespace(char c) {
    for (char w : white) 

        if (c == w)
            return true;

    return false;
    
}

Punct_stream& Punct_stream::operator>> (string& s) {

    while (!(buffer >> s)) {

        if (buffer.bad() || !source.good()) 
            return *this;

        buffer.clear();

        string line;

        getline(source, line);

        for (char& ch : line) 

            if (is_whitespace(ch))
                ch = ' ';
            else if (!sensitive)
                ch = tolower(ch);
        

        buffer.str(line);
    }

    return *this;
}

Punct_stream::operator bool() {
    return !(source.fail()|| source.bad()) && source.good();
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
