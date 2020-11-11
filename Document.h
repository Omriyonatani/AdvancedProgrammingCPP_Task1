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
    string temp;
    int filePointer;

    public:
    // Constructor
    Document():file(),filePointer(1){}

    // Constructor from ifstream 
    Document(std::ifstream& fileStream):file(),filePointer(1){
        while(getline(fileStream,temp));
        file.push_back(temp);
    }

    ~Document(){}

    int getFileSize();
    string getLine(int lineNum);
    int currentLine();
    void changeCurrentLine(int cl);
    int findLine(string word);
    void addLine(int plus);
    void goTo(int lineToGo);
    void deleteLine(int line);
    void deleteThisLine();
    void changeWord(string old_word,int old_length, string new_word);
    void addCurrentLine();
    void insertHere(string s);
};