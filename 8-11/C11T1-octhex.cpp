#include "std_lib_facilities.h"

const int birth_year = 1998;

int main()
{
    int birth_in_dec, birth_in_oct, birth_in_hex;

   // cin >> dec >> birth_in_dec >> oct >> birth_in_oct >> hex >> birth_in_hex;

    cin.unsetf(ios::dec);
    cin.unsetf(ios::oct);
    cin.unsetf(ios::hex);

    cin>> birth_in_dec >>  birth_in_oct >>  birth_in_hex;

    cout << showbase << dec << setw(10) << birth_in_dec << "(decimal)\n";
    cout << showbase << oct << setw(10) << birth_in_oct << "(octal)\n";
    cout << showbase << hex << setw(10) << birth_in_hex << "(hexadec)\n";

    keep_window_open();
    return 0;

}

