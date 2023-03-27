// 10.11 reading constructional file.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "..\std_lib_facilities.h"
const int not_a_reading = -7777;
const int not_a_month = -1;
const int hours_in_day = 24;
const int days_in_month = 32;
const int months_in_year = 12;
const int implausive_min = -200;
const int implausive_max = 200;

vector<string> month_input_table = {
    "jan","feb","mar","apr","may","jun","jul","aug","sep","oct","nov","dece"
};

//将月份转化为月的序号
int month_to_int(string s) {
    for (int i = 0; i < 12; ++i) {
        if (month_input_table[i] == s) { return i; }

    }
    return -1;
}


struct Day {
    vector<double>  hour{ vector<double>(hours_in_day,not_a_reading) };
};

struct Month {
    int month{ not_a_month };
    vector<Day> day{ days_in_month };
};

struct Year {
    int year{1};
    vector<Month> month{ months_in_year };
};

struct Reading {
    int day;
    int hour;
    double temperature;
};

//检查每个小时读数的正确性
bool is_valid(const Reading& r) {
    if (r.day < 1 || 31 < r.day) { return false; }
    if (r.hour < 0 || 23 < r.hour) { return false; }
    if (r.temperature < implausive_min || implausive_max < r.temperature) { return false; }

    return true;
}


//读1个小时的温度
istream& operator>> (istream& is, Reading& r) {

    char ch1;
    if (is >> ch1 && ch1 != '(') {
        is.unget();
        is.clear(ios_base::failbit);
        return is;
    }

    char ch2;
    int d;
    int h;
    double t;
    is >> d >> h >> t >> ch2;
    if (!is || ch2 != ')') { error("bad reading"); }

    r.day = d;
    r.hour = h;
    r.temperature = t;

    return is;
}

//输入循坏结尾标志
void end_of_loop(istream& ist, char term, const string& message) {
    if (ist.bad()) { error("bad ist"); }
    if (ist.eof()) { return; }
    if (ist.fail()) {
        ist.clear();
        char ch;
        if (ist >> ch && ch == term) { return; }

    }
    error(message);
}


//读每个月的温度记录
istream& operator>> (istream& is, Month& m) {
    char ch = 0;
    if (is >> ch && ch != '{') {
        is.unget();
        is.clear(ios_base::failbit);
        return is;
    }

    string month_marker;
    string mm;
    is >> month_marker >> mm;
    if (!is || month_marker != "month") { error("bad start of month"); }
    m.month = month_to_int(mm);


    int duplicates = 0;
    int invalids = 0;

    //反复调用读每天的读数记录
    for (Reading r; is >> r;) {
        if (is_valid(r)) {
            if (m.day[r.day].hour[r.hour] != not_a_reading) { ++duplicates; }

            m.day[r.day].hour[r.hour] = r.temperature;
        }
        else { ++invalids; }
    }
    if (invalids) { error("invalid readins in month", invalids); }
    if (duplicates) { error("duplicate readings in month", duplicates); }

    end_of_loop(is, '}', "bad end of month");

    return is;
}


//读每年的读数记录
istream& operator>>(istream& is, Year& y) {
    char ch;
    is >> ch;
    if (ch != '{') {
        is.unget();
        is.clear(ios::failbit);
        return is;
    }

    string year_marker;
    int yy;
    is >> year_marker >> yy;
    if (!is || year_marker != "year") { error("bad start of year"); }
    y.year = yy;

    //反复调用读每个月的读数记录
    while (true) {
        Month m;
        if (!(is >> m)) { break; }
        y.month[m.month] = m;
    }

    end_of_loop(is, '}', "bad end of year");
    return is;
}

bool print_day(Day dd,ofstream& ofs) {
    bool is_empty=true;
    for (int i = 0; i < hours_in_day - 1; ++i) {
        if (dd.hour[i] != not_a_reading) {
            ofs << dd.hour[i] <<' ';
            is_empty = false;
        }
        
        
    }
    return is_empty;
}

void print_month(Month mm,ofstream& ofs) {
    for (int i = 0; i < days_in_month - 1; ++i) {

        bool empty;
        empty=print_day(mm.day[i],ofs);
        if(!empty)
        ofs << "|\t";
    }
}

void print_year(Year yy, ofstream& ofs) {
    for (int i=0; i < months_in_year-1; ++i) {

        if (yy.month[i].month != not_a_month) {
            print_month(yy.month[i], ofs);
            ofs << '\n';
        }

    }
}

int main()
try{
    cout << "enter input file name\n";
    string iname;
    iname="sou.txt";
    ifstream ist{ iname };
    if (!ist) { error("can not open input file",iname); }

    ist.exceptions(ist.exceptions() | ios_base::badbit);

    cout << "please enter o file name\n";
    string oname;
    oname = "des.txt";
    ofstream ost{ oname };
    if (!ost) { error("cannot open o file",oname); }

    //读所有年的记录
    vector<Year> ys;
    while (true) {
        Year y;
        if (!(ist >> y)) { break; }
        ys.push_back(y);
    }
    cout << "read" << ys.size() << "years of readings\n";

    for (int i = 0; i < ys.size(); ++i) {
        print_year(ys[i],ost);
    }


    std::cout << "Hello World!\n";
}
catch (exception& e) {
    cout << e.what();
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
