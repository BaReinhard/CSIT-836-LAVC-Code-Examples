// Programmer:  Brett Reinhard
// Date :       8/29/2017
// Class:       CSIT 836 - Kent
// Details:     Custom Date Class, some functionality removed


#ifndef DATE_H
#define DATE_H
#include <iostream>
using std::cout;
using std::endl;

class Date
{
    
  public:
    
    // Default Constructor to allow for no params being passed
    Date()=default;
    // Sets the date being given 3 params, month, day, year
    void setDate(int m, int d, int y)
    {
        // check whether date is valid
        bool validDate = _isValid(m,d,y);
        if(validDate){
            // If valid set month, day, and year to private variables
            _month = m;
            _day = d;
            _year = y;
            
        }else{
            // If invalid , set default date (My Birthday!)
            _month = 8;
            _day = 19;
            _year = 1989;
            validDate = _isValid();
        }
        
    }
    void printDate() const
    {
        cout << endl << _month << "/" << _day << "/" << _year << endl;
    }
   
    // Private Variables and helper functions
  private:
    int _month{}, _day{}, _year{};
    bool _leap{};
    int _daysInMonth[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
    bool _valid{};
    bool _isLeapYear() 
    {
        // Hold leap value
        _leap =     (
                    // Check if year is divisible by 400 or 100
                    (_year % 400 == 0 || _year % 100 != 0) 
                    // and divisble by 4
                    && (_year % 4 == 0)
                    );
        // Adjust Feburary's number of days if its a leap year, otherwise assign 28
        _leap ? _daysInMonth[1] = 29: _daysInMonth[1]=28;
        return _leap;
        
    }
    // Same as above
    bool _isLeapYear(int y)
    {
        _leap = ((y % 400 == 0 || y % 100 != 0) && (y % 4 == 0));
        _leap ? _daysInMonth[1] = 29: _daysInMonth[1]=28;
        return _leap;
    }
    bool _isValid(int m, int d, int y)
    {
        // Set Leap Year
        _isLeapYear(y);

        // Return whether its valid or not
        return 
                (
                // Month is between 1 and 12 (inclusive)
                    (m < 13 && m > 0) 
                // And days are between allowable number based on month
                &&  (_daysInMonth[m-1] >= d && d > 0) 
                // Add Year is between 1900 and 3017. Because by then I will no longer plan to maintain this class, 1000 year guarantee it works
                &&  (y >= 1900 && y <= 3000)
                );
        
    }
    // Same as above just allows for using isValid without params
    bool _isValid()
    {
        // Set Valid variable and return it
        _valid =    (
                        (_month < 13 && _month > 0) 
                    &&  (_daysInMonth[_month-1] >= _day && _day > 0) 
                    &&  (_year >= 1900 && _year <= 3000)
                    ); 
        return _valid;       
    }

};
#endif

// Initial Date Class with more functionality, removed due to specific instructions


// class Date
// {
    
//   public:
//     // Date(){
//         // Set Cout Alpha to print booleans
//         // For Testing Only
//         // std::cout << std::boolalpha;
//     // }
//     // Default Constructor to allow for no params being passed
//     Date()=default;
    
//     // Constructor that allows for params to be passed during init
//     Date(int m, int d, int y){
//         // Sets Date with passed params
//         setDate(m,d,y);
//     }
//     // Sets the date being given 3 params, month, day, year
//     void setDate(int m, int d, int y)
//     {
//         // check whether date is valid
//         bool validDate = _isValid(m,d,y);
//         if(validDate){
//             // If valid set month, day, and year to private variables
//             _month = m;
//             _day = d;
//             _year = y;
            
//         }else{
//             // If invalid , set default date (My Birthday!)
//             _month = 8;
//             _day = 19;
//             _year = 1989;
//             validDate = _isValid();
//         }
        
//     }
//     void printDate() const
//     {
//         cout << endl << _month << "/" << _day << "/" << _year << endl;
//     }

//     // Testing - Dev Only
//     // void dateStatus() const
//     // {
//     //     cout    << endl 
//     //             << "********** STATUS **********\n"
//     //             << "Date: " << (_valid ? "is valid" : "is not valid") << endl
//     //             << "Year: " << (_leap ? "is leap year" : "is not leap year") << endl
//     //             << "****************************\n";
//     // }
   

//   private:
//     int _month{}, _day{}, _year{};
//     bool _leap{};
//     int _daysInMonth[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
//     bool _valid{};
//     bool _isLeapYear() 
//     {
//         // Hold leap value
//         _leap =     (
//                     // Check if year is divisible by 400 or 100
//                     (_year % 400 == 0 || _year % 100 != 0) 
//                     // and divisble by 4
//                     && (_year % 4 == 0)
//                     );
//         // Adjust Feburary's number of days if its a leap year, otherwise assign 28
//         _leap ? _daysInMonth[1] = 29: _daysInMonth[1]=28;
//         return _leap;
        
//     }
//     // Same as above
//     bool _isLeapYear(int y)
//     {
//         _leap = ((y % 400 == 0 || y % 100 != 0) && (y % 4 == 0));
//         _leap ? _daysInMonth[1] = 29: _daysInMonth[1]=28;
//         return _leap;
//     }
//     bool _isValid(int m, int d, int y)
//     {
//         // Set Leap Year
//         _isLeapYear(y);

//         // Return whether its valid or not
//         return 
//                 (
//                 // Month is between 1 and 12 (inclusive)
//                 (m < 13 && m > 0) 
//                 // And days are between allowable number based on month
//                 && (_daysInMonth[m-1] >= d && d > 0) 
//                 // Add Year is between 1900 and 3017. Because by then I will no longer plan to maintain this class, 1000 year guarantee it works
//                 && (y >= 1900 && y <= 3000)
//                 );
        
//     }
//     // Same as above just allows for using isValid without params
//     bool _isValid()
//     {
//         // Set Valid variable and return it
//         _valid =    (
//                     (_month < 13 && _month > 0) 
//                     && (_daysInMonth[_month-1] >= _day && _day > 0) 
//                     && (_year >= 1900 && _year <= 3000)
//                     ); 
//         return _valid;       
//     }

// };
