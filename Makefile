BIN      = bin
SRC      = src
CFILES   = $(shell find -name *.c)
CXXFILES = $(shell find -name *.cpp)
OBJECTS  = $(CFILES:.c=.o) $(CXXFILES:.cpp=.o)

CFLAGS   =
CXXFLAGS =
CPPFLAGS = -O3 -Iinclude -Idependencies -Wall -Wextra -Wpedantic

TARGET   = Lain

all: $(TARGET)

$(TARGET): $(OBJECTS)
	@mkdir -p $(BIN)
	$(CXX) -o $(BIN)/$(TARGET) $(OBJECTS) $(CXXFLAGS) $(CPPFLAGS)

clean:
	@$(RM) $(OBJECTS) $(TARGET)

.PHONY: clean all
