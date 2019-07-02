#include "fmt_parser.h"
#include "msg_parser.h"

#define FORMAT_FILE  "./fmt.txt"
#define MESSAGE_FILE "./msg.txt"

int main()
{
    std::cout << "******  PARSE STARTED  ******" << std::endl << std::endl;

    std::ifstream fmtFile(FORMAT_FILE);
    std::ifstream msgFile(MESSAGE_FILE);
    if (!fmtFile.good() || !msgFile.good())
    {
        return -1;
    }

    std::string fmtStr;
    if (!getline(fmtFile, fmtStr))
    {
        std::cout << "****  READ FORMAT FILE FAILED  ****" << std::endl;
        return -1;
    }

    FormatParser fmtParser;
    if (false == fmtParser.parse(fmtStr))
    {
        std::cout << "****  PARSE FORMAT FILE FAILED  ****" << std::endl;
        return -1;
    }

    std::string msgStr;
    MsgParser msgParser;
    int lineNum = 1;
    while (getline(msgFile, msgStr))
    {
        std::cout << "*************************************" << std::endl;
        if (true == msgParser.parse(msgStr, fmtParser.getFormat()))
        {
            std::cout << "* LINE[" << lineNum << "] PARSE SUCCESS" << std::endl;
            std::cout << msgParser.getParsedStr() << std::endl;
        }
        else
        {
            std::cout << "* LINE[" << lineNum << "] PARSE FAILED" << std::endl;
        }
        std::cout << "*************************************" << std::endl << std::endl;

        lineNum++;
    }

    std::cout << "****  PARSE FINISHED  ****" << std::endl;

    return 0;
}

