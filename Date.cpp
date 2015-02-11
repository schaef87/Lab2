/*
 * Date.cpp
 *
 *  Created on: Feb 9, 2015
 *      Author: Justin Schaefer, John Vandenoord, and Henry Uchenna
 */

#include "Date.h"
#include <ctime>
#include <iomanip>
#include <iostream>

Date::Date(){
	//	time_t  timev;
	//	time(&timev);


	time_t t = time(0);   // get time now
	struct tm * now = localtime( & t );
	year =(now->tm_year + 1900);
	month = (now->tm_mon + 1);
	day = (now->tm_mday);


}

Date::Date(int day, int month, int year) throw(logic_error){
	if (day < 0 || month < 0 || year < 0){
		throw logic_error("Date Cannot be Negative Number");
	} else if (day > 31){
		throw logic_error("Day Cannot be Greater than 31");
	} else if( month > 12){
		throw logic_error("Month Cannot be Greater than 12");
	}

	this -> day = day;
	this -> month = month;
	this -> year = year;
}

int Date::getDay() const{
	return day;
}

int Date::getMonth() const{
	return month;
}

int Date::getYear() const{
	return year;
}

void Date::showStructure() const{
	cout << day << " " << month << " " << year << endl;
}

ostream& operator<<(ostream& out, const Date& date){
	out << date.getDay() << " " << date.getMonth() << " " << date.getYear();

	return out;
}

bool Date::isLeapYear(int year){
	if( ( (year > 1901) && (year % 100 != 0) ) || (year % 400 == 0) ){
		return year % 4 == 0;
	} else {
		return false;
	}
}

int Date::daysInMonth(int month, int year){
	if(Date::isLeapYear(year)){
		if(month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12){
			return 31;
		} else if (month == 2){
			return 29;
		} else {
			return 30;
		}
	}else{
		if(month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12){
			return 31;
		} else if (month == 2){
			return 28;
		} else {
			return 30;
		}
	}
}
int Date::getDayOfWeek() const{
	int nYears=0;
	int nLeapYears=0;

	for (int x=1901; x < year;x++){
		nYears++;
		if(Date::isLeapYear(x)){
			nLeapYears++;
		}
	}

	int nDaysToMonth=0;
	for(int d=1;d<month;d++){
		nDaysToMonth+=daysInMonth(d, year);
	}
	int dayOfWeek = ((1 + nYears + nLeapYears + nDaysToMonth + day) % 7);
	return dayOfWeek;
}
bool Date::operator<(const Date& rhs) const{
	if(year<rhs.getYear())
		return true;
	else if(month<rhs.getMonth()&&year==rhs.getYear())
		return true;
	else if(day<rhs.getDay()&&month==rhs.getMonth()&&year==rhs.getYear())
		return true;

	return false;

}
bool Date::operator==(const Date& rhs) const{
	if(day==rhs.getDay()&&month==rhs.getMonth()&&year==rhs.getYear())
			return true;
	else return false;
}
bool Date::operator>(const Date& rhs) const{
	Date tst(day,month,year);
	return !(tst<rhs)&&!(tst==rhs);
}
