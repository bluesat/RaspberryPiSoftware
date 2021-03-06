# Program designed to record information from sensors and write it to text files in csv format every second

# Further Implementations:
#	- add raspberry pi sensors
#	- determine how to save data

# created 08-11-14: Declan Walsh
# last updated 08-11-14: Declan Walsh - added multiple text files that respond to data conditions



import time
from datetime import datetime

# creates two text files for writing
file_object = open('data.txt', 'w')
file_object_crit = open('data_crit.txt', 'w')

count = 0


while True:

		# pulls in the neccessary data from sensors
		time0 = datetime.now()
		tempC = int(open('/sys/class/thermal/thermal_zone0/temp').read())/1e3	
		timeStamp = time0.strftime("%Y/%m/%d %H:%M:%S:%f")
		count = count + 1
		
		# outputs the data to appropriate file
		if tempC > 40:
			# critical temp exceeded writes to critical file and normal file
			file_object_crit.write(repr(count) + ',' + repr(timeStamp) + ',' + repr(tempC) + '\n')
			file_object.write(repr(count) + ',' + repr(timeStamp) + ',' + repr(tempC) + '\n')
		else:
			# normal temp only writes to normal file
			file_object.write(repr(count) + ',' + repr(timeStamp) + ',' + repr(tempC) + '\n')
		print count

		# repeat logging after 1 second interval
		time.sleep(1)
	
