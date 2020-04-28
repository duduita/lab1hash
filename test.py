import pytube
import pandas as pd
df = pd.read_excel('D:\Poliedro\guia.xlsx')
df2 = df.Links
for i in range(136, len(df2)):
    video_url = df2[i]
    youtube = pytube.YouTube(video_url)
    video = youtube.streams.first()
    video.download('D:/Poliedro') # path, where to video download.