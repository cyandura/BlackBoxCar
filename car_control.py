import serial
import time
import sys


val = sys.argv[1]

arduino = serial.Serial(port= "/dev/ttyUSB0", baudrate=9600, timeout=1)
time.sleep(2)

print(arduino.read(arduino.inWaiting()))

arduino.write("{}\n".format(val).encode("utf`-8"))
