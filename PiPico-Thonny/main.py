from machine import Pin
import utime

# LEDの設定を辞書で管理
leds = {
    'green': Pin(0, Pin.OUT),
    'yellow': Pin(1, Pin.OUT),
    'red': Pin(2, Pin.OUT),
    'hito_green': Pin(3, Pin.OUT),
    'hito_red': Pin(4, Pin.OUT)
}

def led_on(led_name):
    leds[led_name].value(1)

def led_off(led_name):
    leds[led_name].value(0)

# 最初にすべてのLEDを消す
for led_name in leds:
    led_off(led_name)

while True:
    # 緑色LEDを10秒間点灯
    led_on('green')
    led_on('hito_green')
    utime.sleep(10)
    led_off('green')    
    led_off('hito_green')

    # 黄色LEDを5秒間点灯
    led_on('yellow')
    led_on('hito_green')
    utime.sleep(1)
    led_off('hito_green')
    utime.sleep(1)
    led_on('hito_green')
    utime.sleep(1)
    led_off('hito_green')
    utime.sleep(1)
    led_on('hito_green')
    utime.sleep(1)    
    led_off('yellow')
    led_off('hito_green')
    
    # 赤色LEDを5秒間点灯
    led_on('hito_red')
    led_on('red')
    utime.sleep(5)
    led_off('red')
    led_off('hito_red')
