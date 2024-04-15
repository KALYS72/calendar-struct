#include <bits/stdc++.h>
using namespace std;


struct Calendar {
    int day, month, year;
    bool isValidDate() {
        bool valid = true;
        if (month > 12 or month < 1) {
            valid = false;
        }
        if (month == 2) {
            if (year % 4 == 0) {
                if (day > 29 or day < 1) {
                    valid = false;
                }
            }
            else {
                if (day > 28 or day < 1) {
                    valid = false;
                }
            }
        }
        else {
            if (month % 2 == 0) {
                if (month == 8) {
                    if (day > 31 or day < 1) {
                        valid = false;
                    }
                }
                else {
                    if (day > 30 or day < 1) {
                        valid = false;
                    }
                }
            } 
            else {
                if (day > 31 or day < 1) {
                    valid = false;
                }
            }
        }
        return valid;
    }

    void newDay(int d, int m, int y) {
        int old_d = day;
        int old_m = month;
        int old_y = year;
        day = d;
        month = m;
        year = y;
        if (isValidDate()) {
            cout << "Done! " << month << " " << day << " " << year;
        }
        else {
            day = old_d;
            month = old_m;
            year = old_y;
            cout << "Inputs are wrong! Try again!";
        }
    }
    void getDayOfWeek() {
        map <int, string> week;
        week[1] = "Monday";
        week[2] = "Tuesday";
        week[3] = "Wednesday";
        week[4] = "Thursday";
        week[5] = "Friday";
        week[6] = "Saturday";
        week[7] = "Sunday";
        int dayOfWeek;
        if (day % 7 == 0) {
            dayOfWeek = 7;
        }
        else {
            dayOfWeek = day % 7;
        }
        cout << "This is " << week[dayOfWeek];
    }

    int calculateDifference (int d, int m, int y) {
        int difference = 0;
        map<int, int> Months;
        Months[1] = 31;
        Months[2] = 28; 
        Months[3] = 31; 
        Months[4] = 29;
        Months[5] = 31;
        Months[6] = 30;
        Months[7] = 31;
        Months[8] = 31;
        Months[9] = 30;
        Months[10] = 31;
        Months[11] = 30;
        Months[12] = 31;
        if (y == year) {
            if (m == month) {
                if (d == day) {
                    return 0;
                }
                else {
                    return abs((d - day));
                }
            }
            else {
                int lower_month, higher_month, low_d, high_d, cur_year = y;
                if (m > month) {
                    lower_month = month;
                    higher_month = m;
                    low_d = day;
                    high_d = d;
                }
                else {
                    lower_month = m;
                    higher_month = month;
                    low_d = d;
                    high_d = day;
                }            
                if (higher_month - lower_month != 1) {
                    for (int i = lower_month+1; i < higher_month; i++) {
                        if (i == 2 and cur_year % 4 == 0) {
                            difference += Months[i]+1;
                        }
                        else {
                            difference += Months[i];
                        }
                    }
                }   
                if (lower_month == 2 and cur_year % 4 == 0) {
                    difference += (Months[lower_month]+1 - low_d);
                }
                else {
                    difference += (Months[lower_month] - low_d);
                }
                difference += high_d;
                return difference;
                }
            }
        else {
            int lower_year, higher_year, lower_month, higher_month, low_d, high_d;
            if (y > year || (y == year && m > month)) {
                lower_year = year;
                higher_year = y;
                lower_month = month;
                higher_month = m;
                low_d = day;
                high_d = d;
            } else {
                lower_year = y;
                higher_year = year;
                lower_month = m;
                higher_month = month;
                low_d = d;
                high_d = day;
            }
            if (higher_year - lower_year != 1) {
                for (int year_iter = lower_year+1; year_iter < higher_year; ++year_iter) {
                    for (int i = 1; i <= 12; ++i) {
                        if (i == 2 and year_iter % 4 == 0) {
                            difference += Months[i]+1;
                        }
                        else {
                            difference += Months[i];
                        }
                    }
                }
            }
            for (int i = lower_month + 1; i <= 12; ++i) {
                if (i == 2 and lower_year % 4 == 0) {
                    difference += Months[i]+1;
                }
                else {
                    difference += Months[i];
                } 
            }
            for (int i = 1; i < higher_month; ++i) {
                if (i == 2 and higher_year % 4 == 0) {
                    difference += Months[i]+1;
                }
                else {
                    difference += Months[i];
                } 
            }
            difference += low_d + high_d;
            return difference;
        }
    }
    

    void printDate() {
        map<int, string> Months;
        Months[1] = "January";
        Months[2] = "February"; 
        Months[3] = "March"; 
        Months[4] = "April";
        Months[5] = "May";
        Months[6] = "June";
        Months[7] = "July";
        Months[8] = "August";
        Months[9] = "September";
        Months[10] = "October";
        Months[11] = "November";
        Months[12] = "December";
        cout << endl << Months[month] << " " << day << ", " << year;
    }
};






int main() {
    Calendar me;
    me.day = 29;
    me.month = 2;
    me.year = 2024;
    cout << me.calculateDifference(28, 2, 2023);
}