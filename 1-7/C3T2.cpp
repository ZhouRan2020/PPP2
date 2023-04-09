#include    "../std_lib_facilities.h"
int main()
{
    cout << "Please enter a integer value.\n";
    int n;
    cin >> n;
    cout    << "n=="                    << n
            << "\nn+1=="                << n + 1
            << "\nthree times n=="      << 3 * n
            << "\nn squared=="          << n * n
            << "\nhalf of n=="          << (double)n / 2.0
            << "\nsquare root of n=="   << sqrt((double)n)
            << "\n";
    keep_window_open();
    return 0;
}

