#include "..\std_lib_facilities.h"

int main()
{
    while (true) {
        double num{};
        cin >> num;

        if (cin.fail()) {
            cin.clear();
            //  continue;
        //    error("���ָ�ʽ����");
        }

        cout << num << '\n';
    }
    
        keep_window_open();
        return 0;

}