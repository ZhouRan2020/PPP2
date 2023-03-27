// C10-guess-number.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "..\std_lib_facilities.h"

int get_int(int, int , const string& , const string& );

int get_int();

void skip2int();

int main()
{

    std::cout << "Hello World!\n";

    int k=get_int(1, 10, "enter", "must");

    cout << "we have got " << k<<'\n';

    keep_window_open();

    return 0;
}

int get_int(int low, int high, const string& greeting, const string& sorry) {
    cout << greeting << ":[" << low << ',' << high << "]\n";

    while (true) {
        int n = get_int();
        if (low <= n && n <= high) { return n; }

        cout << sorry << ":[" << low << '.' << high << "]\n";

    }
}

int get_int() {
    int n = 0;
    while (true) {
        if (cin >> n) { return n; }
        skip2int();
    }
}

void skip2int() {
    if (cin.fail()) {
        cin.clear();
        for (char ch; cin >> ch;) {
            if (isdigit(ch)) {
                cin.unget();
                return;
            }
        }
    }
    error("no input");
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
