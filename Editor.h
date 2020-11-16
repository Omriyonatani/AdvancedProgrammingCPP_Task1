#pragma once
#include "Document.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

class Editor{
    // private:
    Document Doc;

    public:
    Editor():Doc(){}

    Editor(Document Docum):Doc(Docum){}

    ~Editor(){};

    void loop();

};