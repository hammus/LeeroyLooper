#Compiler command
CC=g++
#Compiler flags
CFLAGS=-v -Wall -std=c++11
#Preprocessor definitions
DFLAG_MAC=-D__MACOSX_CORE__
DFLAG_NIX=-D__LINUX_ALSA__

BINARIES=./bin/LeeroyLooper.out
#I/O Files
OUT=-o $(BINARIES)
SOURCES=./*.cpp ./src/*.cpp ../rtaudio/RtAudio.cpp
INCLUDES=-I../rtaudio -I../rtaudio/include -I./src
LIBFLAGS_MAC=-framework CoreAudio -framework CoreFoundation -lpthread
LIBFLAGS_NIX=-lasound -lpthread

mac: clean
	$(CC) $(CFLAGS) $(DFLAG_MAC) $(OUT) $(SOURCES) $(INCLUDES) $(LIBFLAGS_MAC)

linux: clean
	$(CC) $(CFLAGS) $(DFLAG_NIX) $(OUT) $(SOURCES) $(INCLUDES) $(LIBFLAGS_NIX)

clean: 
	rm -f ./bin/*.out

