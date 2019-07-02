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

TypeInfo TypeParser::convertTypeStrToType(std::string input)
{
    TypeInfo type = {T_UNDEFINED, 0};
    int typeListSize = sizeof(TypeStringList) / sizeof(TypeString);
    for (int stringIndex = 0; stringIndex < typeListSize; stringIndex++)
    {
        if (input.find(TypeStringList[stringIndex].dataTypeStr) != 0)
        {
            continue;
        }

        if (TypeStringList[stringIndex].dataType > T_ELEMENT_MIN &&
            TypeStringList[stringIndex].dataType < T_ELEMENT_MAX &&
            input == TypeStringList[stringIndex].dataTypeStr)
        {
            type.dataType = TypeStringList[stringIndex].dataType;
        }
        else if (TypeStringList[stringIndex].dataType > T_ARRAY_MIN &&
                 TypeStringList[stringIndex].dataType < T_ARRAY_MAX)
        {
            IntParser tmp;
            if (true == tmp.parse(input.substr(TypeStringList[stringIndex].dataTypeStr.size())))
            {
                type.dataType = TypeStringList[stringIndex].dataType;
                type.arraySize = tmp.getData();
            }
        }

        break;
    }

    return type;
}

std::string TypeParser::convertTypeToTypeStr(TypeInfo input)
{
    std::string str = "";
    int typeListSize = sizeof(TypeStringList) / sizeof(TypeString);
    for (int stringIndex = 0; stringIndex < typeListSize; stringIndex++)
    {
        if (input.dataType != TypeStringList[stringIndex].dataType)
        {
            continue;
        }

        if (input.dataType > T_ELEMENT_MIN &&
            input.dataType < T_ELEMENT_MAX &&
            input.arraySize == 0)
        {
            str = TypeStringList[stringIndex].dataTypeStr;
        }
        else if (input.dataType > T_ARRAY_MIN &&
                 input.dataType < T_ARRAY_MAX &&
                 input.arraySize >= 0)
        {
            std::ostringstream stream;
            stream << input.arraySize;
            str = TypeStringList[stringIndex].dataTypeStr + stream.str();
        }

        break;
    }

    return str;
}

