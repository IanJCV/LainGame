CC       = x86_64-pc-linux-gnu-gcc
CXX      = x86_64-pc-linux-gnu-g++

BIN      = bin
SRC      = src
CFILES   = $(shell find -name $(SRC)/*.c)
CXXFILES = $(shell find -name $(SRC)/*.cpp)
OBJECTS  = $(CFILES:.c=.o) $(CXXFILES:.cpp=.o)

DEFINE   = -DEDITOR -DVERSION=\"0.0.0\"

CFLAGS   = -std=c99
CXXFLAGS = -std=c++14
CPPFLAGS = -O3 -Iinclude -Idependencies -Wall -Wextra -lm -lpthread -lglfw -lopenal -lOpenGL

TARGET   = editor

all: $(TARGET)

$(TARGET): $(OBJECTS)
	@mkdir -p $(BIN)
	$(CXX) -o $(BIN)/$(TARGET) $(OBJECTS) $(CXXFLAGS) $(CPPFLAGS)

clean:
	@$(RM) $(OBJECTS) $(TARGET)

.PHONY: clean all
