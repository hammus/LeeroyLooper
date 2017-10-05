#Compiler command
CC=g++
MGW=i686-w64-mingw32-gcc
#Compiler flags
CFLAGS=-v -Wall -std=c++11
#Preprocessor definitions
DFLAG_MAC=-D__MACOSX_CORE__
DFLAG_NIX=-D__LINUX_ALSA__
DFLAG_WIN=-D__WINDOWS_ASIO__

#Binaries
BINARIES=./bin/LeeroyLooper.out
WIN_BINARY=./bin/LeeroyLooper.exe

#I/O Files
OUT=-o $(BINARIES)
SOURCES=./*.cpp ./src/*.cpp ../rtaudio/RtAudio.cpp
WIN_SOURCES=../rtaudio/include/asio.cpp ../rtaudio/include/asiolist.cpp ../rtaudio/include/asiodrivers.cpp ../rtaudio/include/iasiothiscallresolver.cpp
INCLUDES=-I../rtaudio -I../rtaudio/include -I./src

# Libaries and Include Paths
LIBFLAGS_MAC=-framework CoreAudio -framework CoreFoundation -lpthread
LIBFLAGS_NIX=-lasound -lpthread
LIBFLAGS_WIN=-lole32
mac: clean
	$(CC) $(CFLAGS) $(DFLAG_MAC) $(OUT) $(SOURCES) $(INCLUDES) $(LIBFLAGS_MAC)

linux: clean
	$(CC) $(CFLAGS) $(DFLAG_NIX) $(OUT) $(SOURCES) $(INCLUDES) $(LIBFLAGS_NIX)

win: clean
	$(MGW) $(CFLAGS) $(DFLAG_WIN) -o $(WIN_BINARY) $(SOURCES) $(WIN_SOURCES) $(INCLUDES) 

clean: 
	rm -f ./bin/*.out

