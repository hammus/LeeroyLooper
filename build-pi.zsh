# AUTHOR'S NOTE: This is very specific to my setup and will not work if you have cloned this repo

###################################################
# Remotely Fetch and Build the project on the RPI #
###################################################

# This script is passed to ssh so all of the below are executed on the pi itself
source /home/pi/.zshrc
cd /home/pi/LeeroyLooper
echo $(pwd)
git pull
g++ -v -std=c++11 -Wall -D__LINUX_ALSA__ -o ./bin/audioprobe ./*.cpp ../rtaudio/RtAudio.cpp -I../rtaudio -I../rtaudio/include -lasound -lpthread