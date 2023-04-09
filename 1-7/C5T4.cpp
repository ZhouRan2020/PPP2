#include "..\std_lib_facilities.h"
int area(int length, int wide);
int main()
{
    try {
        int l{ 0 };
        int w{ 0 };
        cout << "enter l and w.\n";
        cin >> l >> w;
        cout << area(l, w);
        keep_window_open();
        return 0;
    }
    catch (exception& e) {
        cerr <<"error: " <<e.what();
        return 1;
    }
}
int area(int length, int wide) {
    if (!(length > 0 && wide > 0)) {
        error("para incorrect\n");
    }
    return length * wide;
}
