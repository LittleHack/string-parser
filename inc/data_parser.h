#ifndef _DATA_PARSER_H_
#define _DATA_PARSER_H_


#define INT_MAX   ((int)((~((unsigned int)0)) >> 1))
#define INT_MIN   (-(int)((~((unsigned int)0)) >> 1) - 1)
#define SHORT_MAX ((short)((~((unsigned short)0)) >> 1))
#define SHORT_MIN (-(short)((~((unsigned short)0)) >> 1) - 1)


class DataParser
{
public:
    DataParser();
    virtual ~DataParser() {}
    bool getValidity();

protected:
    std::string m_dataStr;
    bool m_validity;

    // Following part need realization in child classes.
public:
    virtual bool parse(std::string input) = 0;
    virtual std::string getDataStr() = 0;

};

#endif

