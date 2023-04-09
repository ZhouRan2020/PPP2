#include "../std_lib_facilities.h"
int main()
{
    cout << "enter expression\n";
    int lval{ 0 };
    int rval{ 0 };
    char operate { '\0' };
    int result{ 0 };
    cin >> lval >> operate >> rval;
    switch (operate) {
    case'+':result = lval + rval; break;
    case'-':result = lval - rval; break;
    default:cout << "invalid\n"; break;
    }
    cout << "result==" << result;
    keep_window_open();
    return 0;
}
