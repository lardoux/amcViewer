//
// Created by Nader Georgi on 19/12/2016.
//

#include "Reader.h"
#include <iostream>
#include <fstream>



bool DEBUG=false;

void Reader::ReadWholeFile_relatif (std::string userFile) {
    std::string line;

    if (DEBUG) std::cout << "DEBUG : userInput : " << userFile << std::endl;

    std::ifstream file (userFile);
    if(file.is_open()) {
        while (getline(file, line)) {
            std::cout << line << std::endl;
        }
        file.close();
    } else std::cout << "Unable to open file";
}


void Reader::ReadWholeFile_absolu (std::string userFile) {
    std::string line;

    if (DEBUG) std::cout << "DEBUG : userInput : " << userFile << std::endl;

    std::ifstream file (userFile);
    if(file.is_open()) {
        while (getline(file, line)) {
            std::cout << line << std::endl;
        }
        file.close();
    } else std::cout << "Unable to open file";
}

std::string Reader::ReadFrame(std::string userFile, int givenFrame) {

    std::string line;
    std::string data="";
    std::ifstream file(userFile);
    int i = 3;
    while (i!=0) {
        getline(file,line);
        i--;
    }

    i=givenFrame*30;

    while (i!=0) {
        getline(file,line);
        i--;
    }

    std::cout << data <<std::endl;
    i=30;
    while (i!=0) {
        getline(file,line);
        data += line;
        i--;
        std::cout << "Line "<< line <<std::endl;
        std::cout << "Data "<< line <<std::endl;
    }

    std::cout << data <<std::endl;

    return data;

}