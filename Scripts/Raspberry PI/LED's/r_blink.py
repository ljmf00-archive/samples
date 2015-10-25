import RPi.GPIO as GPIO ## Import GPIO library
import time ## Import Time library  for timeout command
GPIO.setmode(GPIO.BOARD) ## Use board pin numbering
GPIO.setup(7, GPIO.OUT)  ## Setup GPIO Pin 13 to OUT
GPIO.output(7,True) ## Turn on GPIO pin 13
time.sleep(.1) ## Timeout 0.1 sec's
GPIO.output(7,False) ## Turn off GPIO pin 13
time.sleep(.1) ## ...
GPIO.output(7,True)
time.sleep(.1)
GPIO.output(7,False)
time.sleep(.1)
GPIO.output(7,True)
time.sleep(.1)
GPIO.output(7,False)
time.sleep(.1)
GPIO.output(7,True)
time.sleep(.1)
GPIO.output(7,False)
time.sleep(.1)
GPIO.output(7,True)
time.sleep(.1)
GPIO.output(7,False)
time.sleep(.1)