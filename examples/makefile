# project name and also the name of the executable to build
PROJECT = myapp
# the program to compile and link
CC = g++
# the program to remove files
RM = rm
# compiler flags:
#  -g    adds debugging information to the executable file
#  -Wall turns on most, but not all, compiler warnings
CFLAGS  = -L/usr/lib -L/usr/local/lib -I/home/ernis/Downloads/glm/include/ -I/home/ernis/Downloads/freetype-2.13.1/include/ -lglfw -lrt -lm -ldl -lX11 -lpthread -lxcb -lXau -pthread -lfreetype
# remove flags:
# -f     ignore nonexistent files and don't prompt for them
RMFLAGS = -f
# libraries to link
LIBS=-lbasicGUI
# all target. for building the entire application.
# - optional, because the first target in a Makefile is assumed to be the
#   'all' target.
# - marked phony, because it's just a recipe and not a file
.PHONY: all
all: $(PROJECT)
# project target.
# - $@ means the file of the rule's target, $(PROJECT) in this case
# - $^ means the name of all prerequisites, just myapp.o in this case
$(PROJECT): test.o
	$(CC) $(CFLAGS) -o $@ $^ $(LIBS)
# pattern rule defining how to create a .o file from a .c file
# - $@ means the file of the rule's target, the .o object file in this case
# - $< means the name of the first prerequisite, the .c source file in this case
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@
# clean target.
# - removes the .o object files and the project's executable
# - marked phony, because it's just a recipe and not a file
.PHONY: clean
clean:
	$(RM) $(RMFLAGS) *.o $(PROJECT)
