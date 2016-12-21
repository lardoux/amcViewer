//
// Created by Nader Georgi on 19/12/2016.
//

#include "Reader.h"
#include <iostream>
#include <fstream>
#include <sstream>  //split string


bool DEBUG = false;
const int frames = 1000; //had to put a value...

struct oneValue {
    float X;
} ltibia[frames], rtibia[frames], lradius[frames], lwrist[frames], rradius[frames], rwrist[frames];

struct twoValue {
    float X;
    float Y;
} lclavicle[frames], lhand[frames], rclavicle[frames], rhand[frames];

struct threeValue {
    float X;
    float Y;
    float Z;

} lfemur[frames], rfemur[frames], lowerback[frames], upperback[frames], thorax[frames], lhumerus[frames], rhumerus[frames];

struct sixValue {
    float TX = 0;
    float TY = 0;
    float TZ = 0;
    float RX = 0;
    float RY = 0;
    float RZ = 0;
} root[frames];

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

void Reader::ReadFrame(std::string userFile, int givenFrame) {

    std::string line;
    std::string data = "";
    std::ifstream file(userFile);

    //Jump the first 3 lines
    int i = 3;
    while (i != 0) {
        getline(file, line);
        i--;
    }

    //go to the specified frame
    if (givenFrame != 0) {
        i = givenFrame * 30;
        while (i != 0) {
            getline(file, line);
            i--;
        }
    }

    //Jump the frame number
    getline(file, line);

    //29 lines per frame
    i = 29;

    //Get Frame Data
    while (i != 0) {
        bool keyword = true;
        getline(file, line);

        //parse string into multiple strings
        std::stringstream ss(line);
        std::string token;

        while (std::getline(ss, token, ' ')) {
            if (token == "root") {
                std::getline(ss, token, ' ');
                root[givenFrame].TX = stof(token);


                std::getline(ss, token, ' ');
                root[givenFrame].TY = stof(token);

                std::getline(ss, token, ' ');
                root[givenFrame].TZ = stof(token);

                std::getline(ss, token, ' ');
                root[givenFrame].RX = stof(token);

                std::getline(ss, token, ' ');
                root[givenFrame].RY = stof(token);

                std::getline(ss, token, ' ');
                root[givenFrame].RZ = stof(token);
            } else if (token == "lowerback") {
                std::getline(ss, token, ' ');
                lowerback[givenFrame].X = stof(token);

                std::getline(ss, token, ' ');
                lowerback[givenFrame].Y = stof(token);

                std::getline(ss, token, ' ');
                lowerback[givenFrame].Z = stof(token);
            } else if (token == "upperback") {
                std::getline(ss, token, ' ');
                upperback[givenFrame].X = stof(token);

                std::getline(ss, token, ' ');
                upperback[givenFrame].Y = stof(token);

                std::getline(ss, token, ' ');
                upperback[givenFrame].Z = stof(token);
            } else if (token == "thorax") {
                std::getline(ss, token, ' ');
                thorax[givenFrame].X = stof(token);

                std::getline(ss, token, ' ');
                thorax[givenFrame].Y = stof(token);

                std::getline(ss, token, ' ');
                thorax[givenFrame].Z = stof(token);
            } else if (token == "rclavicle") {
                std::getline(ss, token, ' ');
                rclavicle[givenFrame].X = stof(token);

                std::getline(ss, token, ' ');
                rclavicle[givenFrame].Y = stof(token);

            } else if (token == "rhumerus") {
                std::getline(ss, token, ' ');
                rhumerus[givenFrame].X = stof(token);

                std::getline(ss, token, ' ');
                rhumerus[givenFrame].Y = stof(token);

                std::getline(ss, token, ' ');
                rhumerus[givenFrame].Z = stof(token);

            } else if (token == "rradius") {
                std::getline(ss, token, ' ');
                rradius[givenFrame].X = stof(token);

            } else if (token == "rwrist") {
                std::getline(ss, token, ' ');
                rwrist[givenFrame].X = stof(token);

            } else if (token == "rhand") {
                std::getline(ss, token, ' ');
                rhand[givenFrame].X = stof(token);

                std::getline(ss, token, ' ');
                rhand[givenFrame].Y = stof(token);

                //TODO - 5.11871e-014 , e value?
            } else if (token == "lclavicle") {
                std::getline(ss, token, ' ');
                lclavicle[givenFrame].X = stof(token);

                std::getline(ss, token, ' ');
                rhand[givenFrame].Y = stof(token);

            } else if (token == "lhumerus") {
                std::getline(ss, token, ' ');
                lhumerus[givenFrame].X = stof(token);

                std::getline(ss, token, ' ');
                lhumerus[givenFrame].Y = stof(token);

                std::getline(ss, token, ' ');
                lhumerus[givenFrame].Z = stof(token);

            } else if (token == "lradius") {
                std::getline(ss, token, ' ');
                lradius[givenFrame].X = stof(token);

            } else if (token == "lwrist") {
                std::getline(ss, token, ' ');
                lwrist[givenFrame].X = stof(token);

            } else if (token == "lhand") {
                std::getline(ss, token, ' ');
                lhand[givenFrame].X = stof(token);

                std::getline(ss, token, ' ');
                thorax[givenFrame].Y = stof(token);

            } else if (token == "rfemur") {
                std::getline(ss, token, ' ');
                rfemur[givenFrame].X = stof(token);

                std::getline(ss, token, ' ');
                rfemur[givenFrame].Y = stof(token);

                std::getline(ss, token, ' ');
                rfemur[givenFrame].Z = stof(token);

            } else if (token == "rtibia") {
                std::getline(ss, token, ' ');
                rtibia[givenFrame].X = stof(token);


            } else if (token == "lfemur") {
                std::getline(ss, token, ' ');
                lfemur[givenFrame].X = stof(token);

                std::getline(ss, token, ' ');
                lfemur[givenFrame].Y = stof(token);

                std::getline(ss, token, ' ');
                lfemur[givenFrame].Z = stof(token);

            } else if (token == "ltibia") {
                std::getline(ss, token, ' ');
                ltibia[givenFrame].X = stof(token);
            }

        }// while (std::getline(ss, token, ' '))

        i--;
    }
    file.close();
}

void Reader::CompareTwoFrames(std::string userFile, int startFrame, int endFrame) {
    ReadFrame(userFile, startFrame);
    ReadFrame(userFile, endFrame);


    //print struct
    std::cout << "root " << root[startFrame].TX << " " << \
    root[startFrame].TY << " " << root[startFrame].TZ << " " << \
    root[startFrame].RX << " " << root[startFrame].RY << " " << \
    root[startFrame].RZ << " " << std::endl;

    std::cout << "lowerback " << lowerback[startFrame].X << " " << \
    lowerback[startFrame].Y << " " << lowerback[startFrame].Z << " " << std::endl;

    //print struct
    std::cout << "root " << root[endFrame].TX << " " << \
    root[endFrame].TY << " " << root[endFrame].TZ << " " << \
    root[endFrame].RX << " " << root[endFrame].RY << " " << \
    root[endFrame].RZ << " " << std::endl;

    std::cout << "lowerback " << lowerback[endFrame].X << " " << \
    lowerback[endFrame].Y << " " << lowerback[endFrame].Z << " " << std::endl;


}