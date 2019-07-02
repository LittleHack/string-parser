## String parser

The task is to parse a given string using a format.  
The format will be provided in manner :   
*type*,*type*,...
Example :  
const char*,float,array:long:4  
float,short  
double,int  

The message will be provided in manner :  
*msg*&*msg*&...  
Example :   
b b p p eee&3:1,9900,338  (const char*, array:int:3)  
ss t e aaaa&5:1,2,3,4,5  (const char*, array:short:5)


## How to run
make in local dir  
./parser  
the tests are fmt.txt and msg.txt  


## Architecture
The following structs are defined :  
TypeInfo - identifies one single unit of data in the message  

The following classes are used for parsing the message :

data_parser  -> base class for all data. Split in ElementParser and FormatParser, which are for parsing elements of type int, short, string, double and float and array of each, respectively.  

type_parser -> Singleton class. Used for converting type string to TypeInfo and vice-versa.  Used by msg_parser and format_parser.  

format_parser -> parses format. Reads the format string (fmt.txt) and parses it into a vector of "TypeInfo" (format vector)  

msg_parser -> parses message. Reads the format vector(from format_parser) and the message string, parse and save data  
