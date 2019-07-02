#ifndef _MSG_PARSER_H_
#define _MSG_PARSER_H_

#include "util.h"
#include "common.h"
#include "data_parser.h"

// this class parse the input message string
// input format vector, msg str.
class MsgParser
{
public:
    MsgParser();
    ~MsgParser();

    bool parse(std::string input, const std::vector<TypeInfo>& format);

    bool getValidity();
    std::string getParsedStr();

private:
    void clean();

    std::string m_msgStr;
    std::vector<std::string> m_splitedMsg;
    bool m_validity;

};

#endif

