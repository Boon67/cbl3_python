# the compiler to use
CC = clang

# compiler flags:
#  -g    adds debugging information to the executable file
#  -Wall turns on most, but not all, compiler warnings
CFLAGS  = -g -Wall -MM
  
#files to link:
LFLAGS = ./lib/libcbl_helper.so
  
# the name to use for both the target source file, and the output file:
TARGET = main_debug

all: $(TARGET) 
  
$(TARGET): $(TARGET).c cbl_helper.c
	$(CC) $(CFLAGS) -o $(TARGET) $(TARGET).c $(LFLAGS)

main_debug: /usr/bin/clang -fcolor-diagnostics -fansi-escape-codes -g /Users/terryboon/Documents/code/python_c/src/c/main_debug.c -o /Users/terryboon/Documents/code/python_c/src/c/main_debug ./lib/libcbl_helper.so


