//
// Created by Nader Georgi on 19/12/2016.
//

#include "Reader.h"
#include <iostream>
#include <fstream>
#include <sstream>  //split string


bool DEBUG = false;


struct oneValue {
    float X;
} ltibia, rtibia, lradius, lwrist, rradius, rwrist;


struct twoValue {
    float X;
    float Y;
} lclavicle, lhand, rclavicle, rhand;

struct threeValue {
    float X;
    float Y;
    float Z;

} lfemur, rfemur, lowerback, upperback, thorax, lhumerus, rhumerus;


struct sixValue {
    float TX = 0;
    float TY = 0;
    float TZ = 0;
    float RX = 0;
    float RY = 0;
    float RZ = 0;
} root;


void Reader::ReadWholeFile_relatif(std::string userFile) {
    std::string line;
    if (DEBUG) std::cout << "DEBUG : userInput : " << userFile << std::endl;

    std::ifstream file(userFile);
    if (file.is_open()) {
        while (getline(file, line)) {
            std::cout << line << std::endl;
        }
        file.close();
    } else std::cout << "Unable to open file";
}


void Reader::ReadWholeFile_absolu(std::string userFile) {
    std::string line;

    if (DEBUG) std::cout << "DEBUG : userInput : " << userFile << std::endl;

    std::ifstream file(userFile);
    if (file.is_open()) {
        while (getline(file, line)) {
            std::cout << line << std::endl;
        }
        file.close();
    } else std::cout << "Unable to open file";
}

std::string Reader::ReadFrame(std::string userFile, int givenFrame) {

    std::string line;
    std::string data = "";
    std::ifstream file(userFile);

    //Jump the first 3 lines
    int i = 3;
    while (i != 0) {
        getline(file, line);
        i--;
    }

    i = givenFrame * 30;

    i = 29;

    //Jump the frame number
    getline(file, line);

    //Get Frame Data
    while (i != 0) {
        bool keyword = true;
        getline(file, line);

        //parse string into multiple strings
        std::stringstream ss(line);
        std::string token;

        while (std::getline(ss, token, ' ')) {
            //if (token == "root") {  //Todo - array of struct to distinguishe multiple frames? vector?
            if (keyword) { // if for test purposes only
                std::cout << "Keyword : " + token << std::endl;
                keyword = false;
            }
        }

        i--;

    }

    return data;

}