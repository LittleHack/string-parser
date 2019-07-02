#ifndef __COMMON_H__
#define __COMMON_H__

typedef enum
{
    T_ELEMENT_MIN = 0,
    T_INT,
    T_SHORT,
    T_STRING,
    T_DOUBLE,
    T_FLOAT,
    T_ELEMENT_MAX,      //ELEMENT TYPE MAX

    T_ARRAY_MIN = 101,
    T_INT_ARRAY,
    T_SHORT_ARRAY,
    T_STRING_ARRAY,
    T_DOUBLE_ARRAY,
    T_FLOAT_ARRAY,
    T_ARRAY_MAX,         //ARRAY TYPE MAX

    T_UNDEFINED

} DataType;

typedef struct
{
    DataType dataType;
    int arraySize;
} TypeInfo;

#endif
