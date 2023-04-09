#include "std_lib_facilities.h"
int get_int(int, int , const string& , const string& );
int get_int();
void skip2int();
int main()
{
    int k=get_int(1, 10, "enter", "must");
    cout << "we have got " << k<<'\n';
    keep_window_open();
    return 0;
}

int get_int(int low, int high, const string& greeting, const string& sorry) {
    cout << greeting << ":[" << low << ',' << high << "]\n";
    while (true) {
        int n = get_int();
        if (low <= n && n <= high) { return n; }
        cout << sorry << ":[" << low << '.' << high << "]\n";
    }
}

int get_int() 
{
    int n = 0;
    while (true) {
        if (cin >> n) 
		return n;
        skip2int();
    }
}

void skip2int() 
{
    if (cin.fail()) {
        cin.clear();
        for (char ch; cin >> ch;) {
            if (isdigit(ch)) {
                cin.unget();
                return;
            }
        }
    }
    error("no input");
}
