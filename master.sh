#!/bin/sh

cd /home/pi/RaspberryPiSoftware

cd dtmf_seperation 
./manager &

cd ../therm_pow_logging
sudo python timlemetry.py &


#cd ..
#namuru/namuruLog.sh

