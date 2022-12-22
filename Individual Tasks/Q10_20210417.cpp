#include <iostream>
#include <exception>
using namespace std;
class MonthError : public exception{
    private:
    const char* message = "MonthError: Invalid Month number ";

    public:
    MonthError() = default;

    MonthError(const char * m):message(m){}
        const char* what() const throw(){
            return message;
        }
};

class DayError : public exception{
    private:
        const char* message = "MonthError: Invalid Day number ";
    public:
    DayError() = default;
    DayError(const char * m):message(m){}
        const char* what() const throw(){
            return message;
        }
};

int main(){
    int month, day;
    cout << "Enter month number: ";
    cin >> month;
    if (month < 1 || month > 12){
        throw MonthError();
    }
    cout << "Enter day number: ";
    cin >> day;
    if ((month == 2 && (day > 29)) || (day < 1 || day > 31))
        throw DayError();

}