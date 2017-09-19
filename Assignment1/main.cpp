// Programmer:  Brett Reinhard
// Date :       8/29/2017
// Class:       CSIT 836 - Kent
// Details:     Implements the usage of a custom Date Class, sets and prints Date


#include <iostream>
#include "date.h"
using namespace std;

int main()
{
    Date AssignmentDate;
    int m,d,y;

    // Wait for Month
    cout    << "Enter a Month :";
    cin     >> m;

    // Wait for Day
    cout    << "\nEnter a day: ";
    cin     >> d;

    // Wait for Year
    cout    << "\nEnter a Year: ";
    cin     >> y;

    cout    << endl;    

    // Set and Print Date
    AssignmentDate.setDate(m, d, y);
    AssignmentDate.printDate();
}
