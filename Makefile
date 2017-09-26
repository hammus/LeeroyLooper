#Compiler command
CC=g++
#Compiler flags
CFLAGS=-v -Wall -std=c++11
#Preprocessor definitions
DFLAG_MAC=-D__MACOSX_CORE__
DFLAG_NIX=-D__LINUX_ALSA__

#I/O Files
OUT=-o ./bin/audioprobe.out
SOURCES=./*.cpp ./src/*.cpp ../rtaudio/RtAudio.cpp
INCLUDES=-I../rtaudio -I../rtaudio/include -I./src
LIBFLAGS_MAC=-framework CoreAudio -framework CoreFoundation -lpthread
LIBFLAGS_NIX=-lasound -lpthread

mac:
	$(CC) $(CFLAGS) $(DFLAG_MAC) $(OUT) $(SOURCES) $(INCLUDES) $(LIBFLAGS_MAC)

linux:
	$(CC) $(CFLAGS) $(DFLAG_NIX) $(OUT) $(SOURCES) $(INCLUDES) $(LIBFLAGS_NIX)

