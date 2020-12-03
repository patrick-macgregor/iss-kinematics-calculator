# Define compiler and directories
CC := g++
SRCDIR := src
BUILDDIR := build
TARGET := bin/iss_kinematics_calculator

# Define objects
OBJECTS := 	$(BUILDDIR)/IKCMainFrame.o \
			$(BUILDDIR)/main.o \
			$(BUILDDIR)/IKCCanvas.o

CFLAGS := `root-config --cflags --glibs`
INC := -I include

$(TARGET) : $(OBJECTS)
	$(CC) -o $(TARGET) $(OBJECTS) $(CFLAGS)

$(BUILDDIR)/%.o : $(SRCDIR)/%.cpp
	$(CC) $(INC) -c $^ -o $@ $(CFLAGS)

clean:
	rm -f $(TARGET)
	rm -f $(BUILDDIR)/*
	rm -f bin/*

.PHONY : clean
