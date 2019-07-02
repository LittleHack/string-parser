#ifndef _TYPE_PARSER_H_
#define _TYPE_PARSER_H_

#include "util.h"
#include "common.h"

typedef struct
{
    DataType dataType;
    std::string dataTypeStr;
} TypeString;



// this class converts type string and type.
class TypeParser
{
public:
    static TypeParser* GetInstance()
    {
    }

private:
    TypeParser() {}
    static TypeParser* m_pInstance;

};


#endif

