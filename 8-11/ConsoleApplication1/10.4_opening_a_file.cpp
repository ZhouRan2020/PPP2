#include "std_lib_facilities.h"
struct Reading {
    int hour;
    double temperature;
};
void fill_from_file(vector<Reading>&, string&);
void fill_into_file(vector<Reading>&, string&);
int main()
{
    std::cout << "please enter input file name:";
    string iname;
    cin >> iname;
    vector<Reading> temps;
    fill_from_file(temps,iname);
    cout << "please enter name of output file:";
    string oname;
    cin >> oname;
    fill_into_file(temps,oname);
}
void fill_from_file(vector<Reading>& points,string& name) 
{
    ifstream ist{ name };
    int hour;
    double temperature;
    while (ist >> hour >> temperature) {
        points.push_back(Reading{hour,temperature});
    }
}
void fill_into_file(vector<Reading>& points, string& name) {
    ofstream ost{ name };
    for (int i = 0; i <= points.size() - 1; ++i) {
        ost << '(' << points[i].hour << ',' << points[i].temperature << ")\n";
    }
}