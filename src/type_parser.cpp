#include "data_parser.h"
#include "type_parser.h"

const TypeString TypeStringList[] =
{
    {T_INT, "int"},
    {T_INT_ARRAY, "array:int:"},
    {T_SHORT, "short"},
    {T_SHORT_ARRAY, "array:short:"},
    {T_STRING, "const char*"},
    {T_STRING_ARRAY, "array:const char*:"},
    {T_DOUBLE, "double"},
    {T_DOUBLE_ARRAY, "array:double:"},
    {T_FLOAT, "float"},
    {T_FLOAT_ARRAY, "array:float:"}
};

TypeParser* TypeParser::m_pInstance = NULL;

