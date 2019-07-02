#include "fmt_parser.h"

FormatParser::FormatParser()
{
    m_validity = false;
    m_fmtStr = "";
}


const std::vector<TypeInfo>& FormatParser::getFormat()
{
    return m_formatVec;
}

bool FormatParser::getValidity()
{
    return m_validity;
}

void FormatParser::clean()
{
    m_splitedFmt.clear();
    m_formatVec.clear();
    m_validity = false;
}


