# AUTHORS NOTE: This is very specific to my setup and will not work if you have cloned this repo

###################################################
# Remotely Fetch and Build the project on the RPI #
###################################################

# This script is passed to ssh so all of the below are executed on the pi itself
source /home/pi/.zshrc
cd /home/pi/LeeroyLooper
echo $(pwd)
git pull
make linux