#include <iostream>
#include <string>
#include "Date.h"

void printMenu() {
    std::cout << "-----------------------------------------" << std::endl ;
    std::cout << "\t\tCALENDAR MENU" << std::endl;
    std::cout << "-----------------------------------------" << std::endl ;
    std::cout << "A) Set Date" << std::endl;
    std::cout << "B) Display date (mm/dd/yyyy)" << std::endl;
    std::cout << "C) Display date (Weekday, Month day, Year)" << std::endl ;
    std::cout << "D) Display future date" << std::endl ;
    std::cout << "E) Display past date" << std::endl ;
    std::cout << "F) Number of days passed in current year" << std::endl ;
    std::cout << "G) Number of days remaining in current year" << std::endl ;
    std::cout << "H) Compare dates" << std::endl ;
    std::cout << "I) Increment current date" << std::endl ;
    std::cout << "J) Decrement current date" << std::endl ;
    std::cout << "K) Display current monthly calender" << std::endl ;
    std::cout << "L) Display Holidays" << std::endl ;
    std::cout << "M) Exit the program" << std::endl ;
}



int main() {

    char choice ;
    Date cldr ;

    do {
        printMenu() ;
        fflush(stdin);

        std::cout << "\n\nEnter your choice: " ;
        std::cin >> choice ;
        choice = std::toupper(choice) ;

        switch (choice) {
            case 'A':
                cldr.setDate() ;
                break ;
            case 'B':
                cldr.printDate_format1() ;
                break ;
            case 'C':
                cldr.printDate_format2() ;
                break ;
            case 'D':
                cldr.displayFutureDate() ;
                break ;
            case 'E':
                cldr.displayPastDate() ;
                break ;
            case 'F':
                cldr.daysPassed() ;
                break ;
            case 'G':
                cldr.daysRemaining() ;
                break ;
            case 'H':
                cldr.compareDates() ;
                break;
            case 'I':
                cldr.increment() ;
                break ;
            case 'J':
                cldr.decrement() ;
                break ;
            case 'K':
                cldr.displayCalender() ;
                break ;
            case 'L':
                cldr.printHolidays() ;
                break ;
            case 'M':
                break;
            default:
                std::cout << "\nWrong choice!\n" << std::endl ;
        }
        std::cout << "\n"<<std::endl ;
    } while (choice != 'M') ;

    return 0 ;
}