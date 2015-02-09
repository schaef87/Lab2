/*
 * TestFile.cpp
 *
 *  Created on: Feb 9, 2015
 *      Author: schaeferj
 */

using namespace std;
#include <iostream>
#include <ctime>


int main(){
    time_t t = time(0);   // get time now
    struct tm * now = localtime( & t );
    cout << (now->tm_year + 1900) << '-'
         << (now->tm_mon + 1) << '-'
         <<  now->tm_mday
         << endl;

}
