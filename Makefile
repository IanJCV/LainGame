CC       = x86_64-pc-linux-gnu-gcc
CXX      = x86_64-pc-linux-gnu-g++

MKDIR    = mkdir -p

BIN      = bin
SRC      = src
CFILES   = $(shell find $(SRC) -name *.c)
CXXFILES = $(shell find $(SRC) -name *.cpp)
OBJECTS  = $(CFILES:.c=.o) $(CXXFILES:.cpp=.o)

DEFINE   = -DTESTING -DVERSION=\"0.0.0\"

CFLAGS   = -std=c99
CXXFLAGS = -std=c++14
CPPFLAGS = -O3 -Iinclude -Idependencies -Wall -Wextra $(DEFINE) -lm -lpthread -lglfw -lopenal -lOpenGL

TARGET   = Lain

all: $(TARGET)

$(TARGET): $(OBJECTS)
	@$(MKDIR) $(BIN)
	$(CXX) -o $(BIN)/$(TARGET) $(OBJECTS) $(CXXFLAGS) $(CPPFLAGS)

clean:
	@$(RM) $(OBJECTS) $(TARGET)

.PHONY: clean all
