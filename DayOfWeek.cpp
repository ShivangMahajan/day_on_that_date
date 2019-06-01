/* Made by Sabbey.......
*/
#include <iostream>
#include <math.h>
using namespace std;

// To calculate the numbers of leap years
int noOfLeapYears(int end)
{
    int res = 0;
    int start = 2019;
    if (end < start)
    {
        start = end;
        end = 2019;
    }
    for (int i = start; i < end; i++)
    {
        if (i % 4 == 0 && i % 100 != 0)
            res++;
        else 
        if (i % 4 == 0 && i % 100 == 0)
        {
            if (i % 400 == 0)
                res++;
        }
    }

    return res;
}

// To check if the year is leap year
bool isLeapYear(int year)
{
    if (year % 4 == 0 && year % 100 != 0)
            return true;
        else 
        if (year % 4 == 0 && year % 100 == 0)
        {
            if (year % 400 == 0)
               return true;
        }

        return false;
}

int main(){

    int date, month, year, res;
    cout<<"Date : ";
    cin>>date;
    cout<<"Month : ";
    cin>>month;
    cout<<"Year : ";
    cin>>year;

    int monthDays[] = {31,28,31,30,31,30,31,31,30,31,30,31};

    if (month >=2 && isLeapYear(year) == true)
        monthDays[1] = 29;
    
    //Checking input
    if (date > monthDays[month-1])
       { 
           cout<<"Wrong input";
           exit(-1);
       }

    int totalDays = 0;
    // To calculate the total number of days from 1st jan
    for (int i = 0; i < month; i++)
    {   
        if (i == month - 1)
            totalDays = totalDays + date - 1;
        else        
            totalDays = totalDays + monthDays[i];
    }

    /*  For future addition is done beacuse on next year the day will increase by 1 day.
        But in case of past, the day in previous year is decreased by one day, so subtraction is done.
    */
    //Here 1 is taken because I have used 1st jan 2019 as reference and the day on that date is Tuesday (1)
    int leapYears = noOfLeapYears(year);
    if (year >= 2019)
        res = 1 + leapYears + (year - 2019) + totalDays;
    else
        res = (2019 - year) + leapYears;
        
    res = res % 7;

    if (year < 2019)
        {   totalDays = totalDays % 7;
            res = 1 - res + totalDays;      //Here years result is subtracted from the total days
            res = res % 7;
            if (res < 0)
                res = 7 + res;
        }

    string day;
    switch(res)
    {
        case 0 : day = "Monday";
                 break;
        case 1: day = "Tuesday";
                break;
        case 2: day = "Wednesday";
                break;
        case 3: day = "Thursday";
                break;
        case 4: day = "Friday";
                break;
        case 5: day = "Saturday";
                break;
        case 6: day = "Sunday";
                break;

    }

    cout <<day<<endl; 
    
}