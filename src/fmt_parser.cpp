#include "fmt_parser.h"

FormatParser::FormatParser()
{
    m_validity = false;
    m_fmtStr = "";
}

bool FormatParser::parse(std::string input)
{
    m_fmtStr = input;
    clean();

    if (0 == split(input, m_splitedFmt, ","))
    {
        clean();
        return false;
    }

    for (int fmtIndex = 0; fmtIndex < m_splitedFmt.size(); fmtIndex++)
    {
        if (STR2TYPE(m_splitedFmt[fmtIndex]).dataType == T_UNDEFINED)
        {
            clean();
            return false;
        }
        else
        {
            m_formatVec.push_back(STR2TYPE(m_splitedFmt[fmtIndex]));
        }
    }

    m_validity = true;
    return m_validity;
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


