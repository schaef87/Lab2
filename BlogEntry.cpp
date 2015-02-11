/*
 * BlogEntry.cpp
 *
 *  Created on: Feb 9, 2015
 *      Author: schaeferj
 */
#include "BlogEntry.h"

BlogEntry::BlogEntry(){
	author = "Anonymous";
	created = Date();
	modified = Date();
	contents = "";
}

BlogEntry::BlogEntry(const Text& initAuthor, const Text& initContents){
	author = initAuthor;
	created = Date();
	modified = Date();
	contents = initContents;
}

Text BlogEntry::getAuthor() const{
	return author;
}

Text BlogEntry::getContents() const{
	return contents;
}

Date BlogEntry::getCreateDate() const{
	return created;
}

Date BlogEntry::getModifyDate() const{
	return modified;
}

void BlogEntry::setAuthor(const Text& newAuthor){
	author = newAuthor;
}

void BlogEntry::setContents(const Text& newContents){
	contents = newContents;
}

void BlogEntry::showStructure() const{
	cout << "Posted by: ";
	cout << author << endl;
	cout << "Created on: ";
	created.showStructure();
	cout << "Last Modified on: ";
	modified.showStructure();
	cout << contents <<  endl;
}

void BlogEntry::printHTML(ostream& out) const{
	cout << "<html>" << endl;
	cout << "<body>" << endl;
	cout << "<h1>" << author << "</h1>" << endl;
	cout << "<p>" << endl;
	cout << contents << endl;
	cout << "</p>" << endl;
	cout << "<p>" << endl;
	cout << "Created: " << created << endl;
	cout << "</p>" << endl;
	cout << "<p>" << endl;
	cout << "Last modified: "<< modified << endl;
	cout << "</p>" << endl;
	cout << "</body>" << endl;
	cout << "</html>" << endl;
}
