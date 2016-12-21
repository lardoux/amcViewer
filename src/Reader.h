//
// Created by Nader Georgi on 19/12/2016.
//

#ifndef AMCVIEWER_READER_H
#define AMCVIEWER_READER_H

#include <string>


class Reader {
public:
    static void ReadWholeFile_relatif (std::string userFile);
    static void ReadWholeFile_absolu (std::string userFile);
    static std::string ReadFrame(std::string userFile, int givenFrame);

};


#endif //AMCVIEWER_READER_H
