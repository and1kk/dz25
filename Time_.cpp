#include "Time_.h"
#include <ctime>


void Time_::normalizeTime() {
    if (minutes >= 60) {
        hours += minutes / 60;
        minutes %= 60;
    }
    if (hours >= 24) {
        hours %= 24;
    }
}


Time_::Time_() {
    time_t now = time(0);
    struct tm tim;
    localtime_s(&tim, &now);

    hours = tim.tm_hour;
    minutes = tim.tm_min;
    format = true; 
}


Time_::Time_(int h, int m, bool f) : hours(h), minutes(m), format(f) {
    normalizeTime();
}


Time_::Time_(const Time_& obj) : hours(obj.hours), minutes(obj.minutes), format(obj.format) {}


Time_& Time_::operator=(const Time_& obj) {
    if (this == &obj)
        return *this;
    hours = obj.hours;
    minutes = obj.minutes;
    format = obj.format;
    return *this;
}


Time_::~Time_() {}


void Time_::setHour(int h) { hours = h; normalizeTime(); }
int Time_::getHour() const { return hours; }

void Time_::setMinutes(int m) { minutes = m; normalizeTime(); }
int Time_::getMinutes() const { return minutes; }

void Time_::setFormat(bool f) { format = f; }
bool Time_::getFormat() const { return format; }


bool Time_::valid() const {
    return hours >= 0 && hours < 24 && minutes >= 0 && minutes < 60;
}


void Time_::tickTime() {
    minutes++;
    normalizeTime();
}

void Time_::untickTime() {
    minutes--;
    if (minutes < 0) {
        minutes += 60;
        hours--;
        if (hours < 0) {
            hours += 24;
        }
    }
}

void Time_::showTime() const {
    int displayHour = hours;
    string period = "";
    if (!format) {
        if (hours == 0) {
            displayHour = 12;
            period = " AM";
        }
        else if (hours < 12) {
            period = " AM";
        }
        else if (hours == 12) {
            period = " PM";
        }
        else {
            displayHour = hours - 12;
            period = " PM";
        }
    }

    cout << (displayHour < 10 ? "0" : "") << displayHour << ":"
        << (minutes < 10 ? "0" : "") << minutes << period;
}


Time_& Time_::operator--() {
    untickTime();
    return *this;
}

Time_ Time_::operator--(int) {
    Time_ temp = *this;
    --(*this);
    return temp;
}

Time_& Time_::operator++() {
    tickTime();
    return *this;
}

Time_ Time_::operator++(int) {
    Time_ temp = *this;
    ++(*this);
    return temp;
}


bool Time_::operator==(const Time_& obj) const {
    return hours == obj.hours && minutes == obj.minutes && format == obj.format;
}

bool Time_::operator!=(const Time_& obj) const {
    return !(*this == obj);
}

bool Time_::operator>(const Time_& obj) const {
    if (hours > obj.hours) return true;
    if (hours < obj.hours) return false;
    return minutes > obj.minutes;
}

bool Time_::operator<(const Time_& obj) const {
    return obj > *this;
}

bool Time_::operator>=(const Time_& obj) const {
    return !(*this < obj);
}

bool Time_::operator<=(const Time_& obj) const {
    return !(*this > obj);
}

// Assignment operators
Time_& Time_::operator+=(int m) {
    minutes += m;
    normalizeTime();
    return *this;
}

Time_& Time_::operator-=(int m) {
    minutes -= m;
    normalizeTime();
    return *this;
}

Time_& Time_::operator+=(double h) {
    hours += static_cast<int>(h);
    minutes += static_cast<int>((h - static_cast<int>(h)) * 60);
    normalizeTime();
    return *this;
}

Time_& Time_::operator-=(double h) {
    hours -= static_cast<int>(h);
    minutes -= static_cast<int>((h - static_cast<int>(h)) * 60);
    normalizeTime();
    return *this;
}

// Arithmetic operators
Time_ Time_::operator+(int m) const {
    Time_ temp = *this;
    temp += m;
    return temp;
}

Time_ Time_::operator-(int m) const {
    Time_ temp = *this;
    temp -= m;
    return temp;
}

Time_ operator+(int m, const Time_& a) {
    Time_ temp = a;
    temp += m;
    return temp;
}

Time_ operator-(int m, const Time_& a) {
    Time_ temp = a;
    temp -= m;
    return temp;
}

Time_ Time_::operator+(double h) const {
    Time_ temp = *this;
    temp += h;
    return temp;
}

Time_ Time_::operator-(double h) const {
    Time_ temp = *this;
    temp -= h;
    return temp;
}

Time_ operator+(double h, const Time_& a) {
    Time_ temp = a;
    temp += h;
    return temp;
}

Time_ operator-(double h, const Time_& a) {
    Time_ temp = a;
    temp -= h;
    return temp;
}


ostream& operator<<(ostream& os, const Time_& t) {
    int displayHour = t.hours;
    string period = "";
    if (!t.format) {
        if (t.hours == 0) {
            displayHour = 12;
            period = " AM";
        }
        else if (t.hours < 12) {
            period = " AM";
        }
        else if (t.hours == 12) {
            period = " PM";
        }
        else {
            displayHour = t.hours - 12;
            period = " PM";
        }
    }

    os << (displayHour < 10 ? "0" : "") << displayHour << ":"
        << (t.minutes < 10 ? "0" : "") << t.minutes << period;

    return os;
}

istream& operator>>(istream& is, Time_& t) {
    char ignore;
    is >> t.hours >> ignore >> t.minutes;
    t.normalizeTime();
    return is;
}
