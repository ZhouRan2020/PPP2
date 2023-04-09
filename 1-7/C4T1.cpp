#include "../std_lib_facilities.h"
int main()
{
    constexpr double usd_per_jpy = 0.0091;
    constexpr double usd_per_uer = 1.2352;
    constexpr double usd_per_gbp = 1.3310;
    constexpr double usd_per_cny = 0.1565;
    cout << "Please enter money, followed by a unit(j, u, g, c)\n";
    double money;
    char unit;
    cin >> money >> unit;
    switch (unit) {
    case'j':cout << "You have " << money << " JPY equal to " << usd_per_jpy * money << " USD!!!"; break;
    case'u':cout << "You have " << money << " UER equal to " << usd_per_uer * money << " USD!!!"; break;
    case'g':cout << "You have " << money << " GBP equal to " << usd_per_gbp * money << " USD!!!"; break;
    case'c':cout << "You have " << money << " CNY equal to " << usd_per_cny * money << " USD!!!"; break;
    default:cout << "invalid input.\n";
    }
    keep_window_open();
    return 0;
}
