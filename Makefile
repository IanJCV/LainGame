BIN      = bin
SRC      = src
CFILES   = $(shell find -name *.c)
CXXFILES = $(shell find -name *.cpp)
OBJECTS  = $(CFILES:.c=.o) $(CXXFILES:.cpp=.o)

DEFINE   = -DTESTING -DVERSION=\"0.0.0\"

CFLAGS   =
CXXFLAGS =
CPPFLAGS = -O3 -Iinclude -Idependencies -Wall -Wextra -lm -lpthread -lglfw -lopenal -lOpenGL

TARGET   = Lain

all: $(TARGET)

$(TARGET): $(OBJECTS)
	@mkdir -p $(BIN)
	$(CXX) -o $(BIN)/$(TARGET) $(OBJECTS) $(CXXFLAGS) $(CPPFLAGS)

clean:
	@$(RM) $(OBJECTS) $(TARGET)

.PHONY: clean all
