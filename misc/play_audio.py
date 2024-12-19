from serial import Serial
from pygame import mixer  # Load the popular external library

arduinoComPort = "\\.\COM6"
baudRate = 9600
serialPort = Serial(arduinoComPort, baudRate, timeout=5)

while True:
    serialPort.flushInput()
    lineOfData = serialPort.readline().decode()

    if lineOfData == 1:
        mixer.init()
        mixer.music.load("recording.mp3")
        mixer.music.play()
    else:
        mixer.init()
        mixer.music.stop()
