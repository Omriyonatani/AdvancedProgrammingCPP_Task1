#include "Document.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

// Edit functions:

// return the current line
int Document::currentLine(){
    // return the number of line.         (this address place - first address place) / sizeof(file)
    // return (&file[filePointer]-&file[0])/sizeof(file);
    return filePointer;
}


// method that change the current line.
void Document::changeCurrentLine(int cl){
    filePointer=cl;
}


// return the size of the vector file
int Document::getFileSize(){
    return file.size()-1;
}


// return the string at this line
string Document::getLine(int lineNum){
    return file.at(lineNum);
}


// function that adds number of lines to the filePointer
void Document::addLine(int plus){
    filePointer+=plus;
}

// function that changes the filePointer to be NUM
void Document::goTo(int lineToGo){
    filePointer=lineToGo;
}


// function that delete the current line.
void Document::deleteThisLine(){
    file.erase(file.begin()+filePointer);
}


// function that delete the "line" line.
void Document::deleteLine(int line){
    file.erase(file.begin()+line);
}


// find the index of the word in the text. (which line).
int Document::findLine(string word){
    for(int i=filePointer+1; i<file.size()-1; i++){
        // text.find(word)--> function that checks if there a word in the text- if yes return the index, else return -1;
        int check = file[i].find(word); // find in the string of the vector (line) the word "word".
        if(check != -1){
            return i; //return the line.
        }
    }
    for(int i=0; i<filePointer; i++){
        int check = file[i].find(word);
        if(check != -1){
            return i; //return the line.
        }
    }
    return filePointer;
}


// function that change the String's old word by the new word.
void Document::changeWord(string old_word, int old_length, string new_word){
    // text.find(word)--> function that checks if there a word in the text- if yes return the index, else return -1;
    int check = file[filePointer].find(old_word); // find in this string of the vector (line)- the word "old_word".
    if(check != -1){
        file[filePointer].replace(check,old_length,new_word); // go the the string- and replace the old word (delete his length) by new word.
    }
    return;
}


// function that adds the current line to the next one. J Case
void Document::addCurrentLine(){
    string take = file[filePointer+1]; // i am taking the next line
    file[filePointer] = file[filePointer] + take;
    deleteLine(filePointer+1);
}


// function for "a" case, insert while is not dot ".".
void Document::insertHere(string s){
    if(s=="."){
        return;
    }else{
        file.insert(file.begin()+filePointer+1,s);
    }
}
