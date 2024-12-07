from pynput import keyboard
from recorder import recorder
from player import player
from serial import Serial
from threading import Thread
import sounddevice as sd
from whisper_live import transcription
from sentimental_analysis import analyze_sentiment, score_threshold
import random
import os
from pydub import AudioSegment

arduinoComPort = "/dev/ttyACM0"
baudRate = 9600
serialPort = Serial(arduinoComPort, baudRate, timeout=5)


def convert_m4a_to_wav(input_file, output_file):
    audio = AudioSegment.from_file(input_file, format="m4a")
    audio.export(output_file, format="wav")


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
                    score = analyze_sentiment(transcribed_text)
                    path = f"recordings/{score_threshold(score)}"
                    file = random.choice(os.listdir(path))
                    convert_m4a_to_wav(path + "/" + file, "output.wav")
                    play_music = player("output.wav")
                    play_music.run()

            except ValueError:
                continue


if __name__ == "__main__":

    r = recorder("mic.wav")
    p = player("mic.wav")
    listener_class = listener(r, p)

    l = Thread(target=listener_class.record)
    l.start()  # keyboard listener is a thread so we start it here
    l.join()  # wait for the tread to terminate so the program doesn't instantly close
