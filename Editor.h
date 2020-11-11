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
    int line;

    public:
    Editor():Doc(), line(0){}

    Editor(Document Docum):Doc(Docum), line(Docum.getFileSize()){}

    ~Editor(){};

    void loop();
};