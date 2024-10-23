#pragma once
#include <iostream>

using namespace std;

class Time_ {
private:
    int hours;
    int minutes;
    bool format; // true = 24-hour, false = 12-hour

    void normalizeTime();

public:
    Time_(); // Current local time
    Time_(int hours, int minutes, bool format = true);
    Time_(const Time_& obj);
    Time_& operator=(const Time_& obj);
    ~Time_();

    void setHour(int hours);
    int getHour() const;
    void setMinutes(int minutes);
    int getMinutes() const;
    void setFormat(bool format);
    bool getFormat() const;

    bool valid() const;
    void tickTime();
    void untickTime();
    void showTime() const;

    Time_& operator--(); // previous minute
    Time_ operator--(int); // previous minute
    Time_& operator++(); // next minute
    Time_ operator++(int); // next minute

   
    bool operator==(const Time_& obj) const;
    bool operator!=(const Time_& obj) const;
    bool operator>(const Time_& obj) const;
    bool operator<(const Time_& obj) const;
    bool operator>=(const Time_& obj) const;
    bool operator<=(const Time_& obj) const;

   
    Time_& operator+=(int m);  // add minutes
    Time_& operator-=(int m);
    Time_& operator+=(double h); // add hours
    Time_& operator-=(double h);


    Time_ operator+(int m) const;  // add minutes
    Time_ operator-(int m) const;
    friend Time_ operator+(int m, const Time_& a);
    friend Time_ operator-(int m, const Time_& a);

    Time_ operator+(double h) const; // add hours
    Time_ operator-(double h) const;
    friend Time_ operator+(double h, const Time_& a);
    friend Time_ operator-(double h, const Time_& a);


    friend ostream& operator<<(ostream& os, const Time_& t);
    friend istream& operator>>(istream& is, Time_& t);
};
