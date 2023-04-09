
#include "calendar.h"
namespace calendar {

    Date::Date(int yy, Month mm, int dd)
        :year{ yy }, month{ mm }, day{ dd }
    {
        if (!is_date(yy, int(mm), dd)) { throw(Invalid_date{}); }
    }



    const Date default_date() {
        const Date dd{ 2001, Month::jan, 1 };

        return dd;
    }


    Date::Date() : year{ default_date().get_year() }, month{ default_date().get_month() }, day{ default_date().get_day() }
    {

    }





    void Date::add_one_day() {
        if (leap_year(year)) {
            switch (month) {
            case Month::jan: case Month::mar: case Month::may: case Month::jul: case Month::aug: case Month::oct:
                if (day == big_month) {
                    day = 1;
                    ++month;
                }

                else { day++; }
                break;
            case Month::dece:
                if (day == big_month) {
                    day = 1;
                    ++month;
                    year++;
                }
                else { day++; }
                break;

            case Month::apr: case Month::jun: case Month::sep: case Month::nov:
                if (day == small_month) {
                    day = 1;
                    ++month;
                }
                else { day++; }
                break;

            case Month::feb:
                if (day == run_feb) {
                    day = 1;
                    ++month;
                }
                else { day++; }
                break;
            }
        }
        else {

            switch (month) {
            case Month::jan: case Month::mar: case Month::may: case Month::jul: case Month::aug: case Month::oct:
                if (day == big_month) {
                    day = 1;
                    ++month;

                }

                else { day++; }
                break;
            case Month::dece:
                if (day == big_month) {
                    day = 1;
                    ++month;
                    year++;
                }

                else { day++; }
                break;

            case Month::apr: case Month::jun: case Month::sep: case Month::nov:
                if (day == small_month) {
                    day = 1;
                    ++month;
                }
                else { day++; }
                break;

            case Month::feb:
                if (day == com_feb) {
                    day = 1;
                    ++month;
                }
                else { day++; }
                break;
            }


        }

    }

    void Date::add_day(int n) {

        for (int i = 0; i <= n - 1; i++)
            add_one_day();
    }

    Week what_day(Date&) {
        return Week::mon;
    }

    Week operator ++ (Week& m) {
        m = (m == Week::sun) ? Week::mon : Week(int(m) + 1);
        return m;
    }

    ostream& operator << (ostream& output_stream, Week w) {
        return output_stream << week_table[int(w) - 1];
    }


    Month operator ++ (Month& m) {
        m = (m == Month::dece) ? Month::jan : Month(int(m) + 1);
        return m;
    }

    ostream& operator << (ostream& output_stream, Month m) {
        return output_stream << month_table[int(m) - 1];
    }

    ostream& operator << (ostream& output_stream, Date d) {
        return std::cout << d.get_year() << '.' << d.get_month() << '.' << d.get_day();
    }

    bool leap_year(int n) {
        return (n % 400 == 0) || (n % 4 == 0 && n % 100 != 0);
    }

    bool is_date(int y, int m, int d) {
        if (y >= 1 && m >= 1 && m <= 12 && d >= 1 && d <= 31) {
            return true;
        }
        else { return false; }
    }
}