# Define compiler and directories
CC := g++
SRCDIR := src
BUILDDIR := build
TARGET := bin/iss_geometry

# Define objects
OBJECTS := 	$(BUILDDIR)/IGMainFrame.o \
			$(BUILDDIR)/main.o \
			$(BUILDDIR)/IGCanvas.o
CFLAGS := `root-config --cflags --glibs`
INC := -I include

$(TARGET) : $(OBJECTS)
	$(CC) -o $(TARGET) $(OBJECTS) $(CFLAGS)

$(BUILDDIR)/%.o : $(SRCDIR)/%.cpp
	$(CC) $(INC) -c $^ -o $@ $(CFLAGS)

clean:
	rm -f $(TARGET)
	rm -f $(BUILDDIR)/*

.PHONY : clean
