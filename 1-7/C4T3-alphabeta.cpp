#include "../std_lib_facilities.h"
int main()
{
    int lower = 97;
    constexpr int lower2upper = 32;
    for (int i = 0; i < 26; ++i) {
        cout << char( lower + i ) << '\t' << lower +i << '\t'
            << char( lower - lower2upper + i) << '\t' << lower - lower2upper +i << '\n';
    }
    keep_window_open();
    return 0;
}
