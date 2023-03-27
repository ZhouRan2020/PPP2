// C11T1-octhex.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include"..\C9SE1\std_lib_facilities.h"

const int birth_year = 1998;

int main()
{
    std::cout << "Hello World!\n";

    int birth_in_dec, birth_in_oct, birth_in_hex;

   // cin >> dec >> birth_in_dec >> oct >> birth_in_oct >> hex >> birth_in_hex;

    cin.unsetf(ios::dec);
    cin.unsetf(ios::oct);
    cin.unsetf(ios::hex);

    cin>> birth_in_dec >>  birth_in_oct >>  birth_in_hex;

    cout << showbase << dec << setw(10) << birth_in_dec << "(decimal)\n";
    cout << showbase << oct << setw(10) << birth_in_oct << "(octal)\n";
    cout << showbase << hex << setw(10) << birth_in_hex << "(hexadecimal)\n";

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
