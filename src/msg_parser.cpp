#include "type_parser.h"
#include "msg_parser.h"

MsgParser::MsgParser()
{
    m_msgStr = "";
    m_validity = false;
}
MsgParser::~MsgParser()
{
    clean();
}
bool MsgParser::parse(std::string input, const std::vector<TypeInfo>& format)
{
    m_msgStr = input;
    clean();
    m_validity = true;
    m_formatVec.assign(format.begin(), format.end());

    if (m_formatVec.size() != split(m_msgStr, m_splitedMsg, "&"))
    {
        clean();
        return false;
    }

    for (int msgIndex = 0; msgIndex < m_formatVec.size(); msgIndex++)
    {
        if (false == parseOneData(m_splitedMsg[msgIndex], m_formatVec[msgIndex].dataType, m_formatVec[msgIndex].arraySize))
        {
            clean();
            break;
        }
    }

    return m_validity;
}

bool MsgParser::parseOneData(std::string data, DataType dataType, int arraySize)
{
    DataParser* dataParser = NULL;

    switch (dataType)
    {
        case T_INT:
            dataParser = new IntParser();
            break;
        case T_SHORT:
            dataParser = new ShortParser();
            break;
        case T_STRING:
            dataParser = new StringParser();
            break;
        case T_DOUBLE:
            dataParser = new DoubleParser();
            break;
        case T_FLOAT:
            dataParser = new FloatParser();
            break;
        case T_INT_ARRAY:
            dataParser = new IntArrayParser(arraySize);
            break;
        case T_SHORT_ARRAY:
            dataParser = new ShortArrayParser(arraySize);
            break;
        case T_STRING_ARRAY:
            dataParser = new StringArrayParser(arraySize);
            break;
        case T_DOUBLE_ARRAY:
            dataParser = new DoubleArrayParser(arraySize);
            break;
        case T_FLOAT_ARRAY:
            dataParser = new FloatArrayParser(arraySize);
            break;
        default:
            return false;
    }

    m_parserVec.push_back(dataParser);
    return dataParser->parse(data);
}

bool MsgParser::getValidity()
{
    return m_validity;
}

void MsgParser::clean()
{
    for (int parserIndex = 0; parserIndex < m_parserVec.size(); parserIndex++)
    {
        if (m_parserVec[parserIndex] != NULL)
        {
            delete m_parserVec[parserIndex];
        }
    }
    m_parserVec.clear();
    m_splitedMsg.clear();
    m_formatVec.clear();
    m_validity = false;
}
std::string MsgParser::getParsedStr()
{
    if (m_validity == false || m_formatVec.size() != m_parserVec.size())
    {
        return "";
    }

    std::string parsedStr = "";
    for (int parserIndex = 0; parserIndex < m_parserVec.size(); parserIndex++)
    {
        parsedStr += "| " + TYPE2STR(m_formatVec[parserIndex]) + " | " \
                  + m_parserVec[parserIndex]->getDataStr() + "\n";
    }

    return parsedStr.substr(0, parsedStr.size() - 1);
}


