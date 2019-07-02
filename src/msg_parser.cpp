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

bool MsgParser::getValidity()
{
    return m_validity;
}



