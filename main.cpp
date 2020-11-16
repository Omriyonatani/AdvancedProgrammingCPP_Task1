#include "Editor.h"
#include "Document.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

int main(int argc, char* argv[]) {

    // ./ed fileName
    if(argc==2){
        string fileName = argv[1];      // the name of the file "fileName".
        std::ifstream myFile(fileName); // check if exists and read from file named "myFile"
        
        if(myFile.good()){              // checks if the file is good?
            //std::ofstream myFileOut(fileName);
            Document Doc(myFile);
            Editor Edit(Doc);
            Edit.loop();
        }else{
            // if the file is not good- open a new file with this name.
            // myFile.good == FALSE
            //std::ofstream myFileOut(fileName);
            Editor Edit;                // my editor constructor make a new Doc
            Edit.loop();
        }
    }
    // ./ed fileName and other garbage..
    else if(argc>2){
        cout<<"Invalid arguments"<<endl;
    }
    // ./ed
    else{
        //std::ofstream myFileOut("myFile.txt");
        Editor Edit;
        Edit.loop();
    }
    return 0;
}