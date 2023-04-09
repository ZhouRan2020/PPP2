#include "std_lib_facilities.h"

int main()
{
    double f = 12345.67890;
    cout << defaultfloat << f << '\n'
         << fixed        << f << '\n'
         << scientific   << f << '\n';
    cout << defaultfloat << setprecision(7) << f << '\n';
    cout << defaultfloat << setw(18)        << f << '\n';

    keep_window_open();
    return 0;
}

