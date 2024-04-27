/*
Bride Pattern is used when one module wants to access services of another module 
which are not core part of it.

1. DesktopRecorder class is used for desktop screen recording.
2. MP4VideoPlayer class is used for Playing Video.
3. VideoPlayer: An abstract class which will act as a bridge for getting video playing
functionality in DesktopRecorder class.

*/

#include<iostream>
using namespace std;

//abstract class
class VideoPlayer
{
protected:
string file;
public:
void setFile(string file)
{
this->file=file;
}
string getFile()
{
return this->file;
}
virtual void playVideo()=0;
virtual void pauseVideo()=0;
virtual void stopVideo()=0;
};

class MP4VideoPlayer:public VideoPlayer
{
//Properties related to encoding MP4Video
public:
void playVideo()
{
//Code to play the video
cout<<file<<" is playing"<<endl;
}
void pauseVideo()
{
//Code to pause the video
cout<<file<<" is paused"<<endl;
}
void stopVideo()
{
//Code to stop the video
cout<<file<<" is stopped"<<endl;
}
};

class Recorder
{
protected:
/*
This interface / abstract class acts as a bridge to play video which is the 
functionality of VideoPlayer not a core functionality of Desktop Recorder.
*/
VideoPlayer &videoPlayer; 
Recorder(VideoPlayer &videoPlayer):videoPlayer(videoPlayer)
{
cout<<"Recorder abstract class constructor"<<endl;
}
public:
virtual void startRecording()=0;
virtual void stopRecording()=0;
virtual void exportToVideo(string file)=0;
virtual void saveRecording(string file)=0;
virtual void playVideo()=0;
virtual void pauseVideo()=0;
virtual void stopVideo()=0;
};

class DesktopRecorder:public Recorder
{
public:
//properties / datastructures related to desktop recording
DesktopRecorder(MP4VideoPlayer &videoPlayer):Recorder(videoPlayer)
{
cout<<"DesktopRecorder class constructor"<<endl;
//initialization code
}
void startRecording()
{
//Code to start Desktop Recording
cout<<"Desktop recording started"<<endl;
}
void stopRecording()
{
//Code to stop Desktop Recording
cout<<"Desktop recording stopped"<<endl;
}
void exportToVideo(string file)
{
//Code to Export Desktop Recording To MP4 Video File
cout<<"Export Desktop Recording to MP4 Video file: "<<videoPlayer.getFile()<<endl;
}
void saveRecording(string file)
{
//Code to Save Desktop Recording To MP4 Video File
cout<<"Save Desktop recording to a file: "<<videoPlayer.getFile()<<endl;
}
void playVideo()
{
//Not code Part of DesktopRecorder
//Using VideoPlayer service to start playing video
videoPlayer.playVideo();
}
void pauseVideo()
{
//Not code Part of DesktopRecorder
//Using VideoPlayer service to pause video
videoPlayer.pauseVideo();
}
void stopVideo()
{
//Not code Part of DesktopRecorder
//Using VideoPlayer service to stop video
videoPlayer.stopVideo();
}
};

int main()
{
MP4VideoPlayer mp4VideoPlayer;
mp4VideoPlayer.setFile("C:\\amanw\\video\\Bridge.mp4");
DesktopRecorder desktopRecorder(mp4VideoPlayer);
desktopRecorder.playVideo();
desktopRecorder.pauseVideo();
desktopRecorder.startRecording();
desktopRecorder.stopRecording();
desktopRecorder.exportToVideo("C:\\amanw\\video\\Bridge.mp4");
desktopRecorder.saveRecording("C:\\amanw\\video\\Bridge.mp4");
}