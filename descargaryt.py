from pytube import YouTube
from moviepy.editor import VideoFileClip
import re

def limpiar_nombre(nombre):
    # Remover caracteres no válidos para nombres de archivo
    return re.sub(r'[<>:"/\\|?*]', '', nombre)

def descargar_video(url, inicio, fin):
    yt = YouTube(url)
    # Filtrar los streams progresivos que son mp4 y tienen vídeo y audio
    streams = yt.streams.filter(progressive=True, file_extension='mp4', subtype='mp4', audio_codec='mp4a.40.2')

    # Obtener el stream con la resolución más alta
    video = streams.order_by('resolution').desc().first()

    # Descargar el video completo
    video_title = limpiar_nombre(yt.title)
    video_path = video.download(output_path=".", filename=video_title)

    # Recortar el video descargado al rango de tiempo especificado
    video_clip = VideoFileClip(video_path).subclip(inicio, fin)
    nuevo_nombre = f'{video_title}_{inicio}-{fin}.mp4'
    video_clip.write_videofile(nuevo_nombre, codec="libx264", audio_codec="aac")
    
def descargar_audio(url):
    audio = YouTube(url).streams.filter(only_audio=True).first()
    audio.download()

descargar_video('https://www.youtube.com/watch?v=OU0H7-zvTL0', 535, 68)
