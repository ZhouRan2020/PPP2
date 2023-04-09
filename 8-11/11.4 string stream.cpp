#include "std_lib_facilities.h"
double str2double(string s) {
    istringstream iss{ s };
    double d;
    iss >> d;
    if (!iss) { error("double format error", s); }

    return d;
}
int main()
{
    ostringstream os;
    os<<str2double("123467.65873453");
    cout<<os.str().c_str();
    string command;
    getline(cin, command);
    stringstream ss{ command };
    vector<string> words;
    for (string s; ss >> s;) {
        words.push_back(s);
    }
    for (string s : words) {
        cout << s<<'|';
    }
    keep_window_open();
    return 0;
}
