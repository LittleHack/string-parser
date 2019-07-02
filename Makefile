CC = g++ -g

PRG = parser
CFLAGS = -Iinc
SOURCE = $(wildcard src/*.cpp)
INC = $(wildcard inc/*.h)
OBJ = $(SOURCE:.cpp=.o)
OBJ += main.o


$(PRG):$(OBJ)
	$(CC) -o $@ $^ $(LIBS)

${OBJ}: %.o:%.cpp $(INC)
	$(CC) $(CFLAGS) -c -o $@ $<


