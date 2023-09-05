import pyttsx3

engine = pyttsx3.init()
engine.setProperty('rate',10)
engine.save_to_file('Hello World' , 'test.mp3')


engine.runAndWait()