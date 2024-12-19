import sounddevice as sd
import pydub
from scipy.io.wavfile import write
from groq import Groq
import os
from dotenv import load_dotenv

load_dotenv()

os.environ["GROQ_API_KEY"]


def record_audio(seconds: int, filename: str):
    fs = 44100  # Sample rate

    myrecording = sd.rec(int(seconds * fs), samplerate=fs, channels=2)
    sd.wait()  # Wait until recording is finished
    write(f"{filename}.wav", fs, myrecording)  # Save as WAV file

    sound = pydub.AudioSegment.from_wav(f"{filename}.wav")
    sound.export(f"{filename}.mp3", format="mp3")


def transcription(file: str):
    # Initialize the Groq client
    client = Groq()

    # Specify the path to the audio file
    filename = f"{file}.wav"  # Replace with your audio file!

    # Open the audio file
    with open(filename, "rb") as file:
        # Create a transcription of the audio file
        transcription = client.audio.transcriptions.create(
            file=(filename, file.read()),  # Required audio file
            model="whisper-large-v3-turbo",  # Required model to use for transcription
            prompt="Specify context or spelling",  # Optional
            response_format="json",  # Optional
            language="en",  # Optional
            temperature=0.0,  # Optional
        )
        # Print the transcription text
        return transcription.text
