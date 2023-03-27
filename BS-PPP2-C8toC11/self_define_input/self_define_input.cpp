// self_define_input.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "..\std_lib_facilities.h"

enum class Month {
    january = 1, february, march, april, may, june, july, august, september, october, november, december
};

struct Date {
    int y{-1};
    Month m{Month::january};
    int d{-1};
};



istream& operator>> (istream&, Date&);

ostream& operator<< (ostream&, Date&);

void fill_from_file(vector<Date>&, ifstream&);

void  end_of_loop(istream& ist, char term, const string& );

int main()
try{
  //  std::cout << "Hello World!\n";

    vector<Date> calendar;

  //  ifstream& ist{"table.txt"};

    ifstream ist{ "table.txt"};
    ist.exceptions(ist.exceptions() | ios_base::badbit);

    fill_from_file(calendar, ist);
    end_of_loop(ist, '|', "bad termination");
    

for (int i = 0; i <= calendar.size() - 1; ++i) { cout << calendar[i]; }
keep_window_open();
    return 0;

}
catch (exception& e) {
    cout << e.what();
    return -1;
}


void fill_from_file(vector<Date>& points, ifstream& ist) {

    Date mid;
   // double temperature;
    while (ist >> mid ) {
        points.push_back(mid);
    }
}

void end_of_loop(istream& ist, char term, const string& message) {
    if (ist.bad()) { error("bad ist"); }
    if (ist.eof()) { return ; }
    if (ist.fail()) {
        ist.clear();
        char ch;
        if (ist >> ch && ch == '|') { return; }
         
    }
    error("bad termination");
}

istream& operator>> (istream& ist, Date& dd) {
    int y, m, d;
    char ch1, ch2, ch3, ch4;
    ist >> ch1 >> y >> ch2 >> m >> ch3 >> d >> ch4;

    if (!ist) return ist;
    
    if (ch1 != '(' || ch2 != ',' || ch3 != ',' || ch4 != ')') {
        ist.clear(ios_base::failbit);
        return ist;
    }

    dd = Date{ y,Month(m),d };

    return ist;
}

ostream& operator<< (ostream& ost, Date& dd) {
    return ost << dd.y << int(dd.m) << dd.d;
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
