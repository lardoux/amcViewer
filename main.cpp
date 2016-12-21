#include <iostream>
#include  "src/Reader.h"




void readFile (std::string userInput, int frame) {

    std::string absolu = "/Users/nadergeorgi/Dev/amcViewer/data/HDM05_cut_amc/cartwheelLHandStart1Reps/HDM_bd_cartwheelLHandStart1Reps_";
    std::string amcExtension = ".amc";
    Reader::ReadFrame(absolu+userInput+amcExtension, frame-1);

}



int main() {

    std::string userInput;
    std::string line;
    std::string frame;
    std::cout << "Please input your file's location : ";
    std::cin >> userInput >> frame;

    readFile(userInput, std::stoi(frame));

    return 0;
}
