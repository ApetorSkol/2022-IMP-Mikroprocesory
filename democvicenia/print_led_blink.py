from machine import Pin
from time import sleep_ms

p2 = Pin(2, Pin.OUT) # create output pin on GPIO2

x = 0

while 1:
    p2.on()          # set pin to "on" (high) level
    print("x = %d" % x)
    sleep_ms(500)
    p2.off()         # set pin to "off" (low) level
    sleep_ms(500)
    x = x + 1
