#include"../std_lib_facilities.h"
#include "calendar.h"

int main()
try{
    std::cout << "Hello World!\n";

    using calendar::Date;

    Date today{};

    Date tomorrow{ today };

    tomorrow.add_day(36524);

    std::cout << Date{} << std::endl;

    std::cout << today << calendar::what_day(today) << std::endl;

    std::cout << tomorrow << calendar::what_day(tomorrow) << std::endl;
    keep_window_open();
}
catch (calendar::Date::Invalid_date) {
   

    error("invalid date");
}


