#pragma once
#include <iostream>
#include <string>

class Date {
private:
    int *month ;
    int *day ;
    int *year ;

public:
    Date() ;
    ~Date() ;
    int getMonth() ;
    void setMonth(int) ;
    int getDay() ;
    void setDay(int) ;
    int getYear() ;
    void setYear(int) ;
    void setDate() ;
    static bool isValidDate(int, int, int) ;
    void printDate_format1() ;
    void printDate_format2() ;
    void displayFutureDate() ;
    void displayPastDate() ;
    void daysPassed() ;
    void daysRemaining() ;
    static bool isLeapYear(int) ;
    void compareDates() ;
    void increment() ;
    void decrement() ;
    void displayCalender() ;
    static int calcMartinLutherDay(int) ;
    static int calcPresidentDay(int) ;
    static int calcMemorialDay(int) ;
    static int calcLaborDay(int) ;
    static int calcColumbusDay(int) ;
    static int calcThanksGiving(int) ;
    static void printHolidays() ;
    static int dayOfWeek(int, int, int) ;
    static std::string getMonthName(int) ;
    static std::string getDayName(int) ;
};
Date::Date() {
    month = new int ;
    day   = new int ;
    year  = new int ;

    *month = 1 ;
    *day = 1 ;
    *year = 1753 ;
}
Date::~Date() {
    delete month ;
    delete day ;
    delete year ;
}
int Date::getDay() {
    return *day ;
}

int Date::getMonth() {
    return *month ;
}

int Date::getYear() {
    return *year ;
}

void Date::setDay(int d) {
    *day = d ;
}

void Date::setMonth(int m) {
    *month = m ;
}

void Date::setYear(int y) {
    *year = y ;
}

void Date::setDate() {
    int d, m, y ;

    std::cout << "\nEnter the month: " ;
    std::cin >> m ;

    std::cout << "Enter the day: " ;
    std:: cin >> d ;

    std::cout << "Enter the year: " ;
    std::cin >> y ;

    if (isValidDate(d, m, y)) {
        setDay(d) ;
        setMonth(m) ;
        setYear(y) ;
        std::cout << "\nDate Updated!\n" << std::endl ;
    } else {
        std::cout << "\nDate is not Valid!\n" << std::endl ;
    }
}

bool Date::isValidDate(int d, int m, int y) {
    if (d <= 0 || d > 31)
        return false ;
    if (m <= 0 || m > 12)
        return false ;
    if (y < 0)
        return false ;
    if (m == 2) {

        if (d > 29)
            return false ;
        if (!isLeapYear(y) && d == 29) {
            return false ;
        }
    }
    else if (m == 4 || m == 6 || m == 9 || m == 11) {
        if (d == 31)
            return false ;
    }
    return true ;
}

bool Date::isLeapYear(int year) {
    if (year % 400 == 0)
        return true ;
    else {
        if (year % 100 == 0)
            return false ;
        else if (year % 4 == 0)
            return true ;
    }
    return false ;
}

void Date::printDate_format1() {
    std::cout << "\nDate: " << getMonth() << "/" << getDay() << "/" << getYear() << "\n" << std::endl ;
}
void Date::printDate_format2() {
    int dn = dayOfWeek(getDay(), getMonth(), getYear()) ;

    std::string mn = getMonthName(getMonth()) ;
    std::cout << "\n"<<getDayName(dn) << ", " << mn << " " << getDay() << ", " << getYear() << std::endl ;
}
void Date::displayFutureDate() {
    int i = 1, n, d, m, y ;

    std::cout << "\nEnter the number of days to add: " ;
    std::cin >> n ;
    d = getDay() ;
    m = getMonth() ;
    y = getYear() ;
    while(i <= n) {
        d++ ;
        if(d == 31 && m == 12){
            y = y + 1 ;
            d = 0 ;
            m = 1 ;
        }
        else if(d == 30 && (m == 4 || m == 6 || m == 9 || m == 11)) {
            d = 0 ;
            m++ ;
        }
        else if(d == 31){
            d = 0 ;
            m++ ;
        }
        else if(m == 2){
            if(isLeapYear(y)){
                if(d == 29){
                    d = 0 ;
                    m++ ;
                }
            }
            else if(d == 28){
                d = 0 ;
                m++ ;
            }
        }
        i++ ;
    }
    int dn = dayOfWeek(d, m, y) ;
    std::string mn = getMonthName(m) ;

    std::cout << "\n" << n <<" days from now, the date will be " ;
    std::cout << getDayName(dn) << ", " << mn << " " << d << ", " << y << "\n" << std::endl ;
}

void Date::displayPastDate(){
    int i = 1, n, d, m, y ;

    std::cout << "\nEnter the number of days to subtract: " ;
    std::cin >> n ;

    d = getDay() ;
    m = getMonth() ;
    y = getYear() ;

    while(i <= n){
        d-- ;
        if(d == 1 && m == 1){
            y = y - 1 ;
            d = 32 ;
            m = 12 ;
        }
        else if(d == 1 && (m == 5 || m == 7 || m == 10 || m == 12)){
            d = 31 ;
            m-- ;
        }
        else if(d == 1 && m!=3) {
            d = 32;
            m--;
        }
        else if(m == 3){
            if(isLeapYear(y)){
                if(d == 1){
                    d = 30;
                    m--;
                }
            }
            else if(d == 1){
                d = 29;
                m--;
            }
        }
        i++;
    }
    int dn = dayOfWeek(d, m, y);

    std::string mn = getMonthName(m);

    std::cout <<"\n"<<n<<" days past now, the date was ";
    std::cout << getDayName(dn) << ", " << mn << " " << d << ", " << y << "\n" << std::endl;
}

void Date::daysPassed(){
    int i = -1, d, m, y ;

    d = getDay() ;
    m = getMonth() ;
    y = getYear() ;


    while(!(d == 31 && m == 12 && y == getYear() - 1)){
        d-- ;
        if(d == 1 && m == 1){
            y = y - 1 ;
            d = 32 ;
            m = 12 ;
        }
        else if(d == 1 && (m == 5 || m == 7 || m == 10 || m == 12)){
            d = 31 ;
            m-- ;
        }
        else if(d == 1 && m!=3){
            d = 32 ;
            m-- ;
        }
        else if(m == 3){
            if(isLeapYear(y)){
                if(d == 1){
                    d = 30 ;
                    m-- ;
                }
            }
            else if(d == 1){
                d = 29 ;
                m-- ;
            }
        }
        i++ ;
    }
    std::cout << "\n" << i << " days have passed this year\n" << std::endl ;
}

void Date::daysRemaining(){
    int i = -1, d, m, y ;

    d = getDay() ;
    m = getMonth() ;
    y = getYear() ;

    while(!(d == 1 && m == 1 && y == getYear() + 1)) {
        d++;
        if(d == 31 && m == 12){
            y = y + 1 ;
            d = 0 ;
            m = 1 ;
        }
        else if(d == 30 && (m == 4 || m == 6 || m == 9 || m == 11)) {
            d = 0 ;
            m++ ;
        }
        else if(d == 31) {
            d = 0 ;
            m++ ;
        }
        else if(m == 2){
            if(isLeapYear(y)){
                if(d == 29){
                    d = 0 ;
                    m++ ;
                }
            }
            else if(d == 28){
                d = 0 ;
                m++ ;
            }
        }
        i++ ;
    }
    std::cout << "\n" << i << " days left this year\n" << std::endl ;
}


void Date::compareDates(){
    int i = 0, d, m, y, dd, mm, yy ;
    int status = 0 ;

    std::cout << "\nEnter the month: " ;
    std::cin >> m ;
    std::cout << "Enter the day: " ;
    std::cin >> d ;
    std::cout << "Enter the year: " ;
    std::cin >> y ;

    if (!isValidDate(d, m, y)) {
        std::cout << "\nDate is not Valid!\n" << std::endl ;
        return ;
    }
    if(y > getYear())
        status = 1 ;
    else if(y < getYear())
        status = -1 ;
    else if(m > getMonth())
        status = 1 ;
    else if(m < getMonth())
        status = -1 ;
    else if(d > getDay())
        status = 1 ;
    else if(d < getDay())
        status = -1 ;
    if(status == 1){
        dd = d ;
        mm = m ;
        yy = y ;

        d = getDay() ;
        m = getMonth() ;
        y = getYear() ;
    }
    else if(status == -1){
        dd = getDay() ;
        mm = getMonth() ;
        yy = getYear() ;
    }

    if(status == 0)
        std::cout << "\nThe date is today!\n" << std::endl ;
    else{
        while(!(d == dd && m == mm && y == yy)){
            d++ ;
            if(d == 31 && m == 12) {
                y = y + 1 ;
                d = 0 ;
                m = 1 ;
            }
            else if(d == 30 && (m == 4 || m == 6 || m == 9 || m == 11)) {
                d = 0 ;
                m++ ;
            }
            else if(d == 31){
                d = 0 ;
                m++ ;
            }
            else if(m == 2){
                if(isLeapYear(y)){
                    if(d == 29){
                        d = 0 ;
                        m++ ;
                    }
                }
                else if(d == 28){
                    d = 0 ;
                    m++ ;
                }
            }
            i++ ;
        }
        if(status == 1)
            std::cout << "\nThe date entered will be reached in " << i << " days!" << "\n" << std::endl ;
        else
            std::cout << "\nThe date entered has passed " << i << " days ago!" << "\n" << std::endl ;
    }
}


void Date::increment(){
    int d, m, y ;
    d = getDay() ;
    m = getMonth() ;
    y = getYear() ;
    d++;
    if(d == 31 && m == 12){
        y = y + 1 ;
        d = 0 ;
        m = 1 ;
    }
    else if(d == 30 && (m == 4 || m == 6 || m == 9 || m == 11)){
        d = 0 ;
        m++ ;
    }
    else if(d == 31){
        d = 0 ;
        m++ ;
    }
    else if(m == 2){
        if(isLeapYear(y)){
            if(d == 29){
                d = 0 ;
                m++ ;
            }
        }
        else if(d == 28){
            d = 0 ;
            m++ ;
        }
    }
    int dn = dayOfWeek(d, m, y) ;
    std::string mn = getMonthName(m) ;

    std::cout << "\nDate incremented!\n" << std::endl;
    std::cout << "\n" << getDayName(dn) << ", " << mn << " " << d << ", " << y << "\n" << std::endl ;

    setDay(d) ;
    setMonth(m) ;
    setYear(y) ;
}

void Date::decrement(){
    int d, m, y ;

    d = getDay() ;
    m = getMonth() ;
    y = getYear() ;
    d-- ;
    if(d == 1 && m == 1){
        y = y - 1 ;
        d = 32 ;
        m = 12 ;
    }
    else if(d == 1 && (m == 5 || m == 7 || m == 10 || m == 12)){
        d = 31 ;
        m-- ;
    }
    else if(d == 1 && m!=3){
        d = 32 ;
        m-- ;
    }
    else if(m == 3){
        if(isLeapYear(y)){
            if(d == 1){
                d = 30 ;
                m-- ;
            }
        }
        else if(d == 1){
            d = 29 ;
            m-- ;
        }
    }

    int dn = dayOfWeek(d, m, y) ;
    std::string mn = getMonthName(m) ;

    std::cout << "\nDate decremented!\n" << std::endl ;
    std::cout << "\n"<< getDayName(dn) << ", " << mn << " " << d << ", " << y << "\n" << std::endl;

    setDay(d);
    setMonth(m);
    setYear(y);
}

void Date::displayCalender() {

    int i, notDays;
    int index;

    index = dayOfWeek(1, getMonth(), getYear());

    if(*month == 2){
        if(isLeapYear(getYear()))
            notDays = 29;
        else
            notDays = 28;
    }
    else if(getMonth() == 4 || getMonth() == 6 || getMonth() == 9 || getMonth() == 11)
        notDays = 30;
    else
        notDays = 31;

    std::cout << "\n\t\t" << getMonthName(getMonth()) << " " << getYear() << std::endl;
    std::cout << "\nSu\tMo\tTu\tWe\tTh\tFr\tSa" << std::endl;
    for (i = 1; i <= notDays + index; i++) {
        if (i <= index)
            std::cout << "  \t";
        else
            std::cout << i - index << "\t";
        if (i % 7 == 0)
            std::cout << std::endl;
    }
}

int Date::calcMartinLutherDay(int y) {
    int i = 20 ;
    while (getDayName(dayOfWeek(i ,1 , y)) != "Monday" ) {
        i-- ;
        getDayName(dayOfWeek(i,1,y)) ;
    }
    return i ;
}

int Date::calcPresidentDay(int y) {
    int i = 21 ;
    while (getDayName(dayOfWeek(i ,3 , y)) != "Monday" ) {
        i-- ;
        getDayName(dayOfWeek(i,3,y)) ;
    }
    return i ;
}

int Date::calcMemorialDay(int y) {
    int i = 31 ;
    while (getDayName(dayOfWeek(i ,5 , y)) != "Monday" ) {
        i-- ;
        getDayName(dayOfWeek(i,5,y)) ;
    }
    return i ;
}

int Date::calcLaborDay(int y) {
    int i = 1 ;
    while (getDayName(dayOfWeek(i ,9, y)) != "Monday" ) {
        i++ ;
        getDayName(dayOfWeek(i,9,y)) ;
    }
    return i ;
}

int Date::calcColumbusDay(int y) {
    int i = 15 ;
    while (getDayName(dayOfWeek(i ,10 , y)) != "Monday" ) {
        i-- ;
        getDayName(dayOfWeek(i,10,y)) ;
    }
    return i ;
}

int Date::calcThanksGiving(int y) {
    int i = 27 ;
    while (getDayName(dayOfWeek(i ,11 , y)) != "Thursday" ) {
        i-- ;
        getDayName(dayOfWeek(i,11,y)) ;
    }
    return i ;
}

void Date::printHolidays() {
    int y = 0 ;
    std::cout << "\nEnter the year:" ;
    std::cin >> y ;

    std::cout << "\n" << getDayName(dayOfWeek(1 ,1 , y )) << ", January 1\t-New Year's Day" ;
    std::cout << "\nMonday, " << "January " <<  calcMartinLutherDay(y)  << "\t-Martin Luther King, Jr.Day" ;
    std::cout << "\nMonday, " << "February " <<  calcPresidentDay(y)  << "\t-President's day" ;
    std::cout << "\nMonday, " << "March " << calcMemorialDay(y) << "\t-Memorial day " ;
    std::cout << "\n" << getDayName(dayOfWeek(4,7 , y )) << ", July 4\t\t-Independence Day" ;
    std::cout << "\nMonday, " << "September " << calcLaborDay(y) << "\t-Labor Day " ;
    std::cout << "\nMonday, " << "October " << calcColumbusDay(y) << "\t-Columbus Day " ;
    std::cout << "\n" << getDayName(dayOfWeek(4,11 , y )) << ", November 11\t-Independence Day" ;
    std::cout << "\nThursday, " << "November " << calcThanksGiving(y) << "\t-Thanksgiving Day " ;
    std::cout << "\n" << getDayName(dayOfWeek(4,11 , y )) << ", December 25\t-Christmas Day" ;
}

int Date::dayOfWeek(int day, int month, int year) {
    int t[] = {0, 3, 2, 5, 0, 3, 5, 1, 4, 6, 2, 4};
    year -= month < 3;
    return ((year + int(year / 4) - int(year / 100) + int(year / 400) + t[month - 1] + day) % 7);
}

std::string Date::getMonthName(int index) {
    if (index == 1)
        return "January";
    else if (index == 2)
        return "February";
    else if (index == 3)
        return "March";
    else if (index == 4)
        return "April";
    else if (index == 5)
        return "May";
    else if (index == 6)
        return "June";
    else if (index == 7)
        return "July";
    else if (index == 8)
        return "August";
    else if (index == 9)
        return "September";
    else if (index == 10)
        return "October";
    else if (index == 11)
        return "November";
    else if (index == 12)
        return "December";
    return "";
}
std::string Date::getDayName(int index) {
    if (index == 0)
        return "Sunday";
    else if (index == 1)
        return "Monday";
    else if (index == 2)
        return "Tuesday";
    else if (index == 3)
        return "Wednesday";
    else if (index == 4)
        return "Thursday";
    else if (index == 5)
        return "Friday";
    else if (index == 6)
        return "Saturday";

    return "";
}
