#include "util.h"

unsigned int split(const std::string& in, std::vector<std::string>& out, const std::string& seperator)
{
    unsigned int count = 0;

    std::string::size_type pos1, pos2;
    pos2 = in.find(seperator);
    pos1 = 0;
    while (std::string::npos != pos2)
    {
        out.push_back(in.substr(pos1, pos2 - pos1));
        count++;
        pos1 = pos2 + seperator.size();
        pos2 = in.find(seperator, pos1);
    }

    if (pos1 != in.length())
    {
        out.push_back(in.substr(pos1));
        count++;
    }

    return count;
}


