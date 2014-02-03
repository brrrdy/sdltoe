#compiler used
CXX=g++

#compiler flags
CFLAGS=-c -Wall -std=c++11

#libraries
LDFLAGS= -lmingw32 -lSDL2main -lSDL2

#source files
SOURCES= main.cpp Game.cpp Gfx.cpp GameState.cpp GameStateSplash.cpp GameStatePlaying.cpp

#object files
OBJECTS=$(SOURCES:.cpp=.o)

#executable name
EXECUTABLE= ttt.exe


all:	$(SOURCES) $(EXECUTABLE)

$(EXECUTABLE) : $(OBJECTS)
	$(CXX) $(OBJECTS) $(LDFLAGS) -o $@
	
.cpp.o:
	$(CXX) $(CFLAGS) $< -o $@
	
clean:
	cmd /c del $(EXECUTABLE) $(OBJECTS)
