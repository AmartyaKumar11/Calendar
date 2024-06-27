#include <iostream> 
#include <iomanip>  // To access setw for output width
#include <string>   // To implement to_string function
using namespace std;

// Global Constant Initialization
const string PROGRAM_TITLE = "Day Predictor";
const string AUTHOR_LINE = "By Amartya Kumar";
const int MAX_DAYS_IN_MONTH = 31;

// Prototype(s) to notify compiler
bool continueProgram();
bool isLeapYear(int year);
int getMonthValue(int month, int year);
int getCenturyValue(int year);
int getYearValue(int year);

int main()
{
    // Dynamic Variable Initialization
    int monthNum, dayNum, totalDays, yearNum;
    int dayValue, monthValue, yearValue, centuryValue;
    bool isValidDay = false, isValidMonth = true;
    bool isValidDate = false;
    bool isLeapYearBool = false;
    bool continueLoop = true;

    cout << PROGRAM_TITLE << endl
         << AUTHOR_LINE << endl;

    // Program Logic
    while (isValidDate!= 1 || continueLoop!= 0)
    {
        // Reset values on each loop iteration
        monthNum = 0, dayNum = 0, totalDays = 31, yearNum = 0;
        dayValue = 0, monthValue = 0; yearValue = 0; centuryValue = 0;
        cout << endl << "Please enter a date in  DD MM YYYY format."
             << endl << "Example: 27 06 2024" << endl << endl;

        // Read date from user input
        cin  >> dayNum >> monthNum >> yearNum;

        // Visibility of program status
        cout << endl << left << setw(15) << "Day entered: " << dayNum;
        cout << endl << left << setw(15) << "Month entered: " << monthNum;
        cout << endl << left << setw(15) << "Year entered: " << yearNum
             << endl << endl;

        // Month validation
        if (monthNum > 0 && monthNum <= 12)
        {
            isValidMonth = 1;
        }
        else {
            cout << "Invalid month." << endl
                 << "(The month should be an integer from 1 to 12)"
                 << endl;
            isValidMonth = 0;
            continue;
        }

        // Day validation
        if (dayNum <= 0 || dayNum > 31)
        {
            cout << "Invalid day." << endl
                 << "(The day should be an integer from 1 to 31)"
                 << endl;
            isValidDay = 0;
            continue;
        }
        else {
            // Cases 1, 3, 5, 7, 8, 10, 12
            // have 31 days
            totalDays = MAX_DAYS_IN_MONTH;
            switch (monthNum)
            {
            case 1:
                break;
            case 2: 
                if (isLeapYearBool == 1)
                {
                    totalDays -= 2;
                }
                else
                {
                    totalDays -= 3;
                }
                break;
            case 3:
                break;
            case 4:
                totalDays -= 1;
                break;
            case 5:
                break;
            case 6: 
                totalDays -= 1;
                break;
            case 7:
                break;
            case 8:
                break;
            case 9:
                totalDays -= 1;
                break;
            case 10:
                break;
            case 11:
                totalDays -= 1;
                break;
            case 12:
                break;
            default:
                totalDays = 0;
            }

            if (totalDays >= dayNum) {
                isValidDay = 1;
            }
            else {
                cout << "Invalid days for the month entered." << endl;
                isValidDay = 0;
                continue;
            }
        }
        // Check for Leap Year/Day
        if (isLeapYearBool == 1)
        {
            cout << "It's a valid Leap Year!" << endl << endl;
        }
        if (dayNum >= 29 && monthNum == 2)
        {
            if (dayNum == 29 && isLeapYearBool == 1)
            {
                cout << "Happy Leap Day!" << endl << endl;
            }
            else
            {
                isValidDay = 0;
                cout << "February cannot have more than 28 days,"
                     << endl << "except for Leap Year (29 days)."
                     << endl;
                continue;
            }
        }
        // Year validation
        if (yearNum < 0)
        {
            cout << "Invalid year." << endl
                 << "The year must be an integergreater than"
                 << endl << "or equal to 0 (YYYY)."
                 << endl;
            continue;
        }
        else {
            if (isValidDay == 1 && isValidMonth == 1)
            {
                cout << "Date is valid :)" << endl
                     << endl;
                isValidDate = 1;

                // Function calls
                monthValue = getMonthValue(monthNum, yearNum);
                isLeapYearBool = isLeapYear(yearNum);
                yearValue = getYearValue(yearNum);
                centuryValue = getCenturyValue(yearNum);

                // Calculate the day value to determine day of week
                dayValue = dayNum + monthValue + yearValue + centuryValue;
                // Get the remainder of sum divided by 7
                // Resulting int is the day of the week
                // 0 - Sun, 1 - Mon, etc.
                dayValue %= 7;

                cout << "Day of the week: ";
                // Switch actions based on dayValue (0-6)
                switch (dayValue)
                {
                case 0:
                    cout << "Sunday" << endl << endl;
                    break;
                case 1:
                    cout << "Monday" << endl << endl;
                    break;
                case 2:
                    cout << "Tuesday" << endl << endl;
                    break;
                case 3:
                    cout << "Wednesday" << endl << endl;
                    break;
                case 4:
                    cout << "Thursday" << endl << endl;
                    break;
                case 5:
                    cout << "Friday" << endl << endl;
                    break;
                case 6:
                    cout << "Saturday" << endl << endl;
                    break;
                default:
                    cout << "ERROR" << endl << endl;
                    break;
                }
            }
        }
        // Reset bool variables
        isValidDay = 0;
        isValidMonth = 0;
        isValidDate = 0;
        continueLoop = continueProgram();
        // Keep looping if users enters y
        if (continueLoop == 0)
        {
            break;
        }
    }
}
// Returns boolean value designating leap year
// 0 - Not Leap Year, 1 - Leap Year
bool isLeapYear(int year)
{
    static bool isLeap = 0;
    if (year % 400 == 0 || 
        (year % 4 == 0 && year % 100!= 0))
    {
        isLeap = 1;
    }
    return isLeap;
}
// Returns integer for calculated month value
int getMonthValue(int month, int year)
{
    static int monthVal = 0;
    static bool isLeap = 0;
    isLeap = isLeapYear(year);

    switch (month)
    {
        // Month values are affected on leap years
        // only in Jan and Feb
    case 1:
        if (isLeap == 0)
        {
            monthVal = 0;
        }
        else {
            monthVal = 6;
        }
        break;
    case 2:
        if (isLeap == 0)
        {
            monthVal = 3;
        }
        else {
            monthVal = 2;
        }
        break;
    case 3:
        monthVal = 3;
        break;
    case 4:
        monthVal = 6;
        break;
    case 5:
        monthVal = 1;
        break;
    case 6:
        monthVal = 4;
        break;
    case 7:
        monthVal = 6;
        break;
    case 8:
        monthVal = 2;
        break;
    case 9:
        monthVal = 5;
        break;
    case 10:
        monthVal = 0;
        break;
    case 11:
        monthVal = 3;
        break;
    case 12:
        monthVal = 5;
        break;
    default:
        monthVal = 0;
        break;
    }
    return monthVal;
}
// Returns integer for calculated year value
int getYearValue(int year)
{
    static int yearVal = 0;
    static int quarterVal = 0;
    // Remove first 2 digits
    yearVal = year % 100;
    quarterVal = yearVal / 4;
    // Account for Leap Year
    yearVal += quarterVal;
    return yearVal;
}
// Returns integer for calculated century value
int getCenturyValue(int year)
{
    static int centuryVal = 0;
    static int remainder = 0;
    // Remove last 2 digits 
    centuryVal = year / 100;
    // Find remainder after dividing by 4
    remainder = centuryVal % 4;
    // Subtract remainder from 3, 
    // multiply result by 2
    centuryVal = (3 - remainder) * 2;
    return centuryVal;
}

// Returns boolean value (0 stop, 1 keep looping)
bool continueProgram()
{
    static bool continueLoopBool;
    static bool validEntry = 0;
    static char userInputChar;
    // Loop until entry is valid
    while (validEntry == 0)
    {
        cout << "Would you like to enter another date?"
             << endl << "(Y for yes, N for no)"
             << endl << endl;
        cin >> userInputChar;
        // User enters Y or y
        if (userInputChar == 'y'
            || userInputChar == toupper('y'))
        {
            validEntry = 1;
            continueLoopBool = 1;
        }
        // User enters N or n
        else if (userInputChar == 'n'
            || userInputChar == toupper('n')) {
            validEntry = 1;
            cout << endl << "Closing the program..." << endl
                 << "Until next time!" << endl;
            continueLoopBool = 0;
        }
        // Invalid data handling
        else {
            cout << endl << "Invalid entry." << endl;
        }
    }
    // Reset valid entry bool after loop finishes
    validEntry = 0;
    return continueLoopBool;
}