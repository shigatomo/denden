## Raspberry Pi Pico のファームウェアをにMicroPythonに書き換える
- BOOT　SELを押したまま、リセット（USB　ケーブルを挿しこむ：リセットスイッチがあると確実）
 * RPI-RP2(E:) のUSBデバイスが表示される<br>環境によって　D: や　F:になります。
 * RPI_PICO-20240222-v1.22.2.uf2　ファイルをRPI-RP2(E:)にCOPYする。

micropython
<https://micropython.org/download/RPI_PICO/>

　
## Thonnyセットアップ

|マイコン|言語|開発環境|URL|
|------|--------|---|-|
|Raspberry Pi Pico |Micro Python|Thonny|<https://thonny.org/>|

<https://github.com/thonny/thonny/releases/download/v4.1.4/thonny-py38-4.1.4-windows-portable.zip>
- 解凍したフォルダー内のthonny.exe を起動させる
  * 初回のみ<br>Language:日本語<br>Initial setting:Standard<br>Let's go!
  
  * ツール　→　オプション →　インタプリタ<br>MicroPython (Raspberry Pi Pico) を選択　
  * ポート　USB　シリアル　デバイス @ COM3 (COM3は環境によって変わる)

LEDチカチカサンプル
```
from machine import Pin
led=Pin(25, Pin.OUT)

while True:
  led.value(1)
  machine.lightsleep(1000)
  led.value(0)
  machine.lightsleep(1000)
```

- 実行手順
 画面上のSTOP（バックエンドをストップ・リスタート）<br>Pi Picoのリセットスイッチ<br>現在のスクリプトを実行


- サンプル　
```
from machine import Pin
led_red=Pin(13, Pin.OUT)
led_yel=Pin(12, Pin.OUT)
led_grn=Pin(11, Pin.OUT)

def ledon():
  led_red.value(1)
  led_grn.value(1)
  led_yel.value(1)

def ledoff():
  led_red.value(0)
  led_grn.value(0)
  led_yel.value(0)

while True:
    for i in range(5):
        ledon()
        machine.lightsleep(100)
        ledoff()
        machine.lightsleep(100)

    for i in range(10):
        led_grn.value(1)
        machine.lightsleep(100)
        led_grn.value(0)
        led_yel.value(1)
        machine.lightsleep(100)
        led_yel.value(0)
        led_red.value(1)
        machine.lightsleep(100)
        led_red.value(0)
```