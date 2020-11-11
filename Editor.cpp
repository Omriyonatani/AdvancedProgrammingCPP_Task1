#include "Editor.h"
#include "Document.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>


using namespace std;

bool is_number(const string& s){
    string::const_iterator it = s.begin();
    while (it != s.end() && isdigit(*it)) ++it;
    return !s.empty() && it == s.end();
}

void Editor::loop(){
    while(true){
        string s=" ";
        getline(cin,s);

        // take the first and the last letters for check the cases
        const char* fl=&s[0];
        const char* ll=&s[s.length()-1];

        // case Number,Int,Digit.
        if(is_number(s)){
            int Digit1=atoi((const char*) fl);
            int Digit2=atoi((const char*) ll);
            int Digit3=Digit1*10+Digit2;
            if(Digit2==0){
                Digit3=Digit3/10;
            }
            if(Digit3>0 && Digit3<Doc.getFileSize()){
                Doc.changeCurrentLine(Digit3);
            }
        }
        // +Num case
        else if(fl == "+"){
            const char* sc = s.c_str();
            int plus = atoi(sc);
            Doc.addLine(plus);
        }

        // -Num case
        else if(fl == "-"){
            const char* sc = s.c_str();
            int minus = atoi(sc);
            Doc.addLine(minus*(-1));
        }
        // case $
        else if(s == "$"){
            Doc.changeCurrentLine(Doc.getFileSize());
        }
        // case a
        else if(s == "a"){
            while(true){
                Doc.insertHere(s);
            }
        }
        // case i
        else if(s == "i"){
            Doc.addLine(-1);
            while(true){
                Doc.insertHere(s);
            }
        }
        // case c
        else if(s == "c"){
            Doc.deleteThisLine();
            while(true){
                Doc.insertHere(s);
            }
        }
        // case d
        else if(s == "d"){
            Doc.deleteThisLine();
        }
        // case j
        else if(s=="j"){
            Doc.addCurrentLine();
        }
        // case s/old/new/
        else if(fl == "s" && ll == "/"){
            string temp = s.substr(2,s.length()-2);   // temp = s, without "s/" and the last "/"
            int checkIndex= temp.find("/"); // checkIndex is the index of the middle "/"
            string old_word = temp.substr(0,checkIndex); // cut the old word
            string new_word = temp.substr((checkIndex,temp.length()-1)); // cut the new word
            this->Doc.changeWord(old_word,old_word.length(),new_word);
        }
        // case /text/
        else if(fl == "/" && ll == "/"){
            string s2=s.substr(1,s.length()-1); // s2 = the word that i need to searc
            int newFP = this->Doc.findLine(s2);
            this->Doc.changeCurrentLine(newFP);
        }
        // case w file
        else if(fl == "w"){
            // save the file name
            string fileName=s.substr(1,s.length()-1);
            // new ofstream
            std::ofstream out(fileName);
            if(!out){ // check Err, file couldnt be open
                cerr << "Error: the file could not be open" << endl;
                exit(1);
            }
            for(int i=0; i< Doc.getFileSize(); i++){
                out<<Doc.getLine(i)<<'\n';
            }
            // close the file.
            out.close();
        }
        // case q
        else if(s=="q") {
            return;
        }else{
            printf("?");
        }
    }
}