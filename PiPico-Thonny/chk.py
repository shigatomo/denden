import machine
import time
ON=1
OFF=0
plist=[0,1,2,3,4]
po=[]
pos=0
print('Start 001')
for pin in plist:
    po.append(machine.Pin(pin, machine.Pin.OUT))
timing=[]



while True:
    for pin in po:
        pin.value(ON)
        time.sleep(1)
        pin.value(OFF)
