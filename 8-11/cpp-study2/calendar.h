//#pragma once

#include "std_lib_facilities.h"





namespace calendar {

    const int big_month = 31;
    const int small_month = 30;
    const int com_feb = 28;
    const int run_feb = 29;
    const vector<string> month_table{ "January","Feburary","March","April","May","June","July","August","Sepemter","October","November","December" };
    const vector<string> week_table{ "Monday","Tuesday","Wednesday","Thusday","Friday","Satuerday","Sunday" };

    const enum class Week {
        mon = 1, tue, wed, thu, fri, sat, sun

    };



    const enum class Month {
        jan = 1, feb, mar, apr, may, jun, jul, aug, sep, oct, nov, dece

    };







    class Date {


    public:

        class Invalid_date {};


        Date(int, Month, int);
        Date();

        void add_one_day();
        void add_day(int n);

        int get_year() const { return year; }
        Month get_month() const { return month; }
        int get_day() const { return day; }


    private:



        int year;
        Month month;
        int day;


    };

    Week what_day(Date&);

    Week operator ++ (Week& m);

    ostream& operator << (ostream& output_stream, Week w);

    Month operator ++ (Month& m);

    ostream& operator << (ostream& output_stream, Month m);

    ostream& operator << (ostream& output_stream, Date d);



    bool leap_year(int);
    bool is_date(int, int, int);





}

