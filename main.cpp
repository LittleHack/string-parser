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

    return 0;
}

