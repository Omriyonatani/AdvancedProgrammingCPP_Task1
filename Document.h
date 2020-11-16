#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

class Document{
    // the file is vector of strings, every row is a string. the cols is the vector index'es.
    // private:
    vector<string> file;

    public:
    int lineNumber;
    // Constructor
    Document():file(), lineNumber(1){}

    // Constructor from ifstream 
    Document(std::ifstream &fileStream):file(),lineNumber(1){
        string tempDoc;
        while(getline(fileStream,tempDoc)){
            file.push_back(tempDoc);
        }
    }

    ~Document(){}

    int getFileSize();
    string getLine(int lineNum);
    int findLine(int begin, int end, string &word);
    void addLine(int plus,string &Add);
    void deleteLine(int line);
    void insertHere();
    void changeWord(string &old_word, int old_length, string &new_word);
    void goToLine(int goTo);
    void goToLineMinus(int goTo);
    void goToLineMinusFORI(int goTo);
    void joinNext();
};