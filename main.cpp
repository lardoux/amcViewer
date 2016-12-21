#include <iostream>
#include  "src/Reader.h"




void readFile (std::string userInput, int frame) {

    std::string absolu = "/Users/nadergeorgi/Dev/amcViewer/data/HDM05_cut_amc/cartwheelLHandStart1Reps/HDM_bd_cartwheelLHandStart1Reps_";
    std::string amcExtension = ".amc";
    Reader::ReadFrame(absolu+userInput+amcExtension, frame-1);

}



int main() {

    std::string userInput;
    std::string frame;
    //Test Sequence HDM_bd_cartwheelLHandStart1Reps
    //readFile methode : absolu variable.  Adjust as needed.
    std::cout << "Please input sequence number : ";
    //ex : [sequence] [frame]
    //   : 001_120 2
    std::cin >> userInput >> frame;

    readFile(userInput, std::stoi(frame));

    return 0;
}
