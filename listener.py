from pynput import keyboard
from recorder import recorder
from player import player
from serial import Serial
from threading import Thread
import sounddevice as sd
import pydub
from whisper_live import transcription


arduinoComPort = "/dev/ttyACM0"
baudRate = 9600
serialPort = Serial(arduinoComPort, baudRate, timeout=5)


class listener:
    def __init__(self, recorder, player):
        serialPort.flushInput()

        self.recorder = recorder
        self.player = player

    def record(self):

        while True:
            serialPort.flushInput()
            lineOfData = serialPort.readline().decode()
            # print(lineOfData)
            try:
                if int(lineOfData) == 0:
                    self.recorder.start()
                elif int(lineOfData) == 1 and self.recorder.recording:
                    self.recorder.stop()
                    transcribed_text = transcription("mic")
                    print(transcribed_text)
            except ValueError:
                continue


if __name__ == "__main__":

    r = recorder("mic.wav")
    p = player("mic.wav")
    listener_class = listener(r, p)

    l = Thread(target=listener_class.record)
    l.start()  # keyboard listener is a thread so we start it here
    l.join()  # wait for the tread to terminate so the program doesn't instantly close
