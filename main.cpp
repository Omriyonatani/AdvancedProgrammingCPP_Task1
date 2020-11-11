#include "Editor.h"
#include "Document.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

int main(int argc, char* argv[]) {

    // ./ed fileName
    if(argc==2){
        std::ifstream myFile(argv[1]);

        if(myFile.good()){
            Document Doc(myFile);
            Editor Edit(Doc);
            Edit.loop();
        }else{
            // myFile.good == FALSE
            Editor Edit; // my editor constructor make a new Doc
            Edit.loop();
        }
    }else{
        Editor Edit;
        Edit.loop();
    }
    return 0;
}