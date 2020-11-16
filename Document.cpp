#include "Document.h"


// Edit functions:

// return the size of the vector file
int Document::getFileSize(){
    return file.size()-1;
}

// return the string at this line
string Document::getLine(int lineNum){
    return file.at(lineNum-1);
}

// function that adds "Add" line to the text.
void Document::addLine(int plus,string &Add){
    file.insert(file.begin()+plus,Add);
}

// function that adds NUMBER to line, to go to there..
void Document::goToLine(int goTo){
    lineNumber = lineNumber + goTo;
}

// function that minus NUMBER to line, to go to there..
void Document::goToLineMinus(int goTo){
    lineNumber = lineNumber - goTo;
}

// function that adds -NUMBER to line. to go to there.. for i case
void Document::goToLineMinusFORI(int goTo){
    if((lineNumber - goTo) < 0){
        lineNumber = 1;
        // string next="";
        // getline(cin,next);
        // file.emplace(file.begin()+lineNumber,next);
    }else{
        lineNumber= lineNumber - goTo;
        // string next="";
        // getline(cin,next);
        // file.emplace(file.begin()+lineNumber,next);
    }
}

// function that delete the "line" line.
void Document::deleteLine(int line){
    file.erase(file.begin()+line-1);
}

// find the index of the word in the text. (which line).
int Document::findLine(int begin, int end, string &word){
    for(int i=begin; i<end; i++){ 
        // text.find(word)--> function that checks if there a word in the text- if yes return the index, else return -1;
        int check = file.at(i).find(word);              // find in the string of the vector (line) the word "word".
        if(check != -1){
            return i+1; //return the line.
        }
    }
    for(int i=0; i<=begin; i++){
        int check = file.at(i).find(word);
        if(check != -1){
            return i+1; //return the line.
        }
    }
    return -1;
}

// function for "a" case, insert while is not dot ".".
void Document::insertHere(){
    if(file.empty()){
        lineNumber=0;
    }
    string next="";
    getline(cin,next);
    while(next!="."){
        file.insert(file.begin()+lineNumber,next);
        ++lineNumber;
        getline(cin,next);
    }
    return;
}


// function that change the String's old word by the new word.
void Document::changeWord(string &old_word, int old_length, string &new_word){
    // text.find(word)--> function that checks if there a word in the text- if yes return the index, else return -1;
    int check = file.at(lineNumber-1).find(old_word);                    // find in this string of the vector (line)- the word "old_word".
    if(check != -1){
        file.at(lineNumber-1).replace(check,old_length,new_word);   // go the the string- and replace the old word (delete his length) by new word.
    }
    return;
}

void Document::joinNext(){
    string thisText = file.at(lineNumber-1);
    thisText.append(file.at(lineNumber));
    deleteLine(lineNumber);
    deleteLine(lineNumber);    
    file.insert(file.begin()+lineNumber-1,thisText);
}

