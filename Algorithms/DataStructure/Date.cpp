#include <iostream>
using namespace std;

class Date {
    int year_;
    int month_;
    int day_;

public:
    void SetDate(int year, int month, int date);
    void AddDay(int inc);
    void AddMonth(int inc);
    void AddYear(int inc);
    void ShowData();
}

void Date::SetDate(int year, int month, int date){
    year_ = year;
    month_ = month;
    day_ = day;
}
void Date::AddDay(int inc){
    day_ += inc;
    if (day_ > 30){
        AddMonth(day_ / 30);
        day_ %= 30;
    }
}
void Date::AddMonth(int inc){
    month_ += inc;
    if (month_ > 12){
        year_ += month_ / 12;
        month_ %= 12;
    }
}
void Date::AddYear(int inc){
    year_ += inc;
}
void Date::ShowData(){
    std::cout << "오늘은 " << year_ << " 년 " << month_ << " 월 " << day_
            << " 일 입니다\n";
}