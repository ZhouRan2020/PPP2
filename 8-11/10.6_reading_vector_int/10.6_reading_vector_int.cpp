#include "std_lib_facilities.h"
void fill_from_file(vector<int>&, string&,char);
int main()
try{
    vector<int> list;
    std::cout << "please enter input file name:";
    string iname;
    cin >> iname;
    fill_from_file(list,iname,'*');
    for (int i=0;i<=list.size()-1;++i)
    	cout << list[i];
    keep_window_open();
    return 0;
}
catch(exception& e)
{
    cout << e.what();
}

void fill_from_file(vector<int>& points, string& name,char terminator) {
    ifstream ist{ name };
    int hour;
   // double temperature;
    while (ist >> hour ) {
        points.push_back(hour);
    }
        if (ist.eof()) { return; }
        if (ist.bad()) { error("ist is bad"); }
        if (ist.fail()) {
            ist.clear();
            char c;
            ist >> c;
            if (c != terminator) {
                ist.unget();
                ist.clear(ios_base::failbit);//÷√Œª
                //error("ist is bad");
            }
        }
}
