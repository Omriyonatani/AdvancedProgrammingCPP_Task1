#include "Editor.h"

using namespace std;

bool is_number(const string& s){
    string::const_iterator it = s.begin();
    while (it != s.end() && isdigit(*it)) ++it;
    return !s.empty() && it == s.end();
}

void Editor::loop(){
    string s;
    //const char* pointer;

    while(true){
        getline(cin,s);

        // case Number,Int,Digit.
        if(is_number(s)){
            int Digit = stoi(s);
            if(Digit<1 || Digit > Doc.getFileSize()+1){
                cout<<"?"<<endl;
                continue;
            }
            Doc.lineNumber=Digit;
            cout<< Doc.getLine(Doc.lineNumber)<<endl;
        }

        // +Num case
        else if(s.at(0) == '+' && is_number(s.substr(1))){
            string s1=s.substr(1);
            int DigitPlus = stoi(s1);
            if((Doc.lineNumber + DigitPlus) > Doc.getFileSize()+1){
                cout<<"?"<<endl;
            }else{
                Doc.goToLine(DigitPlus);
                cout<< Doc.getLine(Doc.lineNumber)<<endl;
            }
        }

        // -Num case
        else if(s.at(0) == '-' && is_number(s.substr(1))){
            string s1=s.substr(1);
            int DigitMinus = stoi(s1);
            if((Doc.lineNumber - DigitMinus) <=0){
                cout<<"?"<<endl;
            }else{
                Doc.goToLineMinus(DigitMinus);      
                cout<< Doc.getLine(Doc.lineNumber)<<endl;      
            }
        }

        // case $
        else if(s == "$"){
            Doc.lineNumber = Doc.getFileSize()+1;
            cout<< Doc.getLine(Doc.lineNumber)<<endl;   
        }
        // case a
        else if(s == "a"){
            Doc.insertHere();
        }
        // case i
        else if(s == "i"){
            Doc.goToLineMinusFORI(1);           // go 1 reverse
            Doc.insertHere();
        }
        // case c
        else if(s == "c"){
            Doc.deleteLine(Doc.lineNumber);
            Doc.lineNumber--;
            Doc.insertHere();
        }
        // case d
        else if(s == "d"){
            Doc.deleteLine(Doc.lineNumber);
        }
        // case j
        else if(s=="j"){
            if(Doc.lineNumber<=Doc.getFileSize()){
                Doc.joinNext();
            }else{
                cout<<"?"<<endl;
            }
        }
        // case s/old/new/
        else if(s.at(0) == 's' && s.at(1) == '/' && s.at(s.length()-1) == '/'){
            string temp = s.substr(2,s.length()-3);                                      // temp = s, without "s/" and the last "/"- only "old/new"
            int checkIndex= temp.find("/");                                              // checkIndex is the index of the middle "/"
            string old_word = temp.substr(0,checkIndex);                                 // cut the old word
            string new_word = temp.substr((checkIndex+1));                                // cut the new word
            Doc.changeWord(old_word,old_word.length(),new_word);
        }
        // case /text/
        else if(s.at(0) == '/' && s.at(s.length()-1) == '/'){
            string s2=s.substr(1,s.length()-2);                                         // s2 = the word that i need to search
            int newFP = Doc.findLine(Doc.lineNumber,Doc.getFileSize(),s2);            // new FilePointer (the index.)
            if(newFP != -1){                                                            // if this word exist, if the "findLine" method didnt found the word- return -1 ! 
                Doc.lineNumber = newFP;                                                 // change to there. 
                cout<< Doc.lineNumber <<endl;
            }
            cout<< Doc.getLine(Doc.lineNumber)<<endl;
        }
        // case w file
        else if(s.at(0) == 'w' && s.at(1)== ' '){
            string fileName=s.substr(2);                                    // save the file name
            std::ofstream out(fileName);                                    // new ofstream
            if(!out){                                                       // check Err, file couldnt be open
                cerr << "Error: the file could not be open" << endl;
                exit(1);
            }
            for(int i=1; i< Doc.getFileSize()+2; i++){
                out<<Doc.getLine(i)<<'\n';
            }
            out.close();                                                    // close the file.
        }

        // case q
        else if(s=="q"){
            return;
        }
        else{
            if(s!="\n"){
                cout<<"?"<<endl;
            }
        }
    }
}