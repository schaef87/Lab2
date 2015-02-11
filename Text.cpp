#include "Text.h"
#include <cstring>
#include <iomanip>
#include <iostream>
//John Vande Noord
//Dani Breon
Text::Text(const char *charSeq)
{
    bufferSize=strlen(charSeq)+1;
    buffer=new char[bufferSize];
    strcpy(buffer,charSeq);
    //return;
}


Text::Text(const Text &other)
{
    bufferSize=other.getLength()+1;
    buffer=new char[bufferSize];
    strcpy(buffer,other.getText());
    //return;
}


Text::~Text()
{
    delete buffer;
    bufferSize=0;
   // return;
}


int Text::getLength () const{
    return bufferSize-1;
}


char* Text::getText() const{
    return buffer;
}


void Text::operator = ( const Text &other ){
Text tst(buffer);
    if(!(tst==other)){
        bufferSize=other.getLength()+1;
        buffer=new char[bufferSize];
        strcpy(buffer,other.getText());
    }
}


char Text::operator [] ( int n ) const{
    if(n<bufferSize-1)
        return buffer[n];
    else
        return '\0';
}


void Text::clear (){
    buffer="";
}


void Text::showStructure () const{
    cout<<buffer<<'\0'<<endl;
}


Text Text::toUpper( ) const{
    char b2[bufferSize];
    for(int i=0;buffer[i]!='\0';i++){
        b2[i]=toupper(buffer[i]);
    }
    Text bb2(b2);
    return bb2;
}


Text Text::toLower( ) const{
    char b2[bufferSize];
    for(int i=0;buffer[i]!='\0';i++){
        b2[i]=tolower(buffer[i]);
    }
    Text bb2(b2);
    return bb2;
}


bool Text::operator == ( const Text& other ) const{
    int plan=-1;
    if(bufferSize==other.getLength()+1){
        plan=0;
       for(int i=0;buffer[i]!='\0';i++){
            if(buffer[i]==other.getText()[i]){
                plan++;
            }
        }
    }
    return plan==bufferSize-1;
}


bool Text::operator < ( const Text& other ) const{
if(bufferSize<other.getLength()+1){
    return true;
}
Text tst(buffer);
if(tst==other){
    return false;
}

char b1[bufferSize];
    for(int i=0;buffer[i]!='\0';i++){
        b1[i]=toupper(buffer[i]);
    }

        char b2[other.getLength()+1];
    for(int i=0;other.getText()[i]!='\0';i++){
        b2[i]=toupper(other.getText()[i]);
    }

    for(int i=0;b1[i]!='\0';i++){
            if(b1[i]>b2[i]){
                return false;
            }
    }
    return true;
}


bool Text::operator > ( const Text& other ) const{
    Text tst(buffer);
    return !(tst<other)&&!(tst==other);
}


istream & operator >> ( istream &input, Text &inputText )

// Text input function. Extracts a string from istream input and
// returns it in inputText. Returns the state of the input stream.

{
    const int textBufferSize = 256;     // Large (but finite)
    char textBuffer [textBufferSize];   // text buffer

    // Read a string into textBuffer, setw is used to prevent buffer
    // overflow.

    input >> setw(textBufferSize) >> textBuffer;

    // Apply the Text(char*) constructor to convert textBuffer to
    // a string. Assign the resulting string to inputText using the
    // assignment operator.

    inputText = textBuffer;

    // Return the state of the input stream.

    return input;
}

//--------------------------------------------------------------------

ostream & operator << ( ostream &output, const Text &outputText )

// Text output function. Inserts outputText in ostream output.
// Returns the state of the output stream.

{
   output << outputText.buffer;
   return output;
}


