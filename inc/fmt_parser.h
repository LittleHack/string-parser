#ifndef _FMT_PARSER_H_
#define _FMT_PARSER_H_

#include "util.h"
#include "common.h"
#include "type_parser.h"


// this class can parse the input format string
// input format string, output format vector
class FormatParser
{
public:
    FormatParser();
    bool parse(std::string input);
    const std::vector<TypeInfo>& getFormat();
    bool getValidity();

private:
    void clean();

    std::string m_fmtStr;
    bool m_validity;
    std::vector<std::string> m_splitedFmt;
    std::vector<TypeInfo> m_formatVec;

};



#endif

