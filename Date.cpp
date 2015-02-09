/*
 * Date.cpp
 *
 *  Created on: Feb 9, 2015
 *      Author: Justin Schaefer, John Vandenoord, and Henry Uchenna
 */

#include "Date.h"
#include <ctime>

Date::Date(){

	time_t t = time(0);   // get time now
	struct tm * now = localtime( & t );
	int year =(now->tm_year + 1900);
	int month = (now->tm_mon + 1);
	int day = (now->tm_mday);

}

Date::Date(int day, int month, int year) throw(logic_error){
	if (day < 0 || month < 0 || year < 0){
		throw logic_error;
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

static bool isLeapYear(int year){
	if((year > 1901) && (year % 100 != 0) || (year % 400 == 0)){
		return year % 4 == 0;
	} else {
		return false;
	}
}

static int daysInMonth(int month, int year){
	if(isLeapYear(year)){
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
