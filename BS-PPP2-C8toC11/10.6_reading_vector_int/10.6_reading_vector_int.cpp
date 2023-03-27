// 10.6_reading_vector_int.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "..\std_lib_facilities.h"

void fill_from_file(vector<int>&, string&,char);
int main()
try{
    std::cout << "Hello World!\n";
    vector<int> list;
    std::cout << "please enter input file name:";
    string iname;
    cin >> iname;

    fill_from_file(list,iname,'*');

    for (int i=0;i<=list.size()-1;++i)
    cout << list[i];

    keep_window_open();
    return 0;

}
catch(exception& e)
{
    cout << e.what();
}


void fill_from_file(vector<int>& points, string& name,char terminator) {

    ifstream ist{ name };
    int hour;
   // double temperature;
    while (ist >> hour ) {
        points.push_back(hour);
    }

        if (ist.eof()) { return; }

        if (ist.bad()) { error("ist is bad"); }

        if (ist.fail()) {

            ist.clear();


            char c;
            ist >> c;


            if (c != terminator) {
                ist.unget();
                ist.clear(ios_base::failbit);//置位
                //error("ist is bad");
            }
        }



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
