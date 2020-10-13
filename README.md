# VideoCompare

1. Build "Debug, x86"

2. Copy below files to Debug folder:
* ffmpeg\lib-shared\x86\*.dll
* SDL2\lib\x86\*.dll
* SDL2_ttf\lib\x86\*.dll
* SourceCodePro-Regular.ttf

3. Run
* VideoCompare.exe 1.mp4 2.mp4
* VideoCompare.exe --loop 1.mp4 2.mp4
* VideoCompare.exe 1.jpg 2.jpg

4. Controls
* Space: Toggle play/pause
* Escape: Quit
* Down arrow: Seek 15 seconds backward
* Left arrow: Seek 1 second backward
* Page down: Seek 600 seconds backward
* Up arrow: Seek 15 seconds forward
* Right arrow: Seek 1 second forward
* Page up: Seek 600 seconds forward
* S: Swap left and right video
* A: Previous frame
* D: Next frame
* Z: Zoom area around cursor (result shown in lower left corner)
* C: Zoom area around cursor (result shown in lower right corner)
* 1: Toggle hide/show left video
* 2: Toggle hide/show right video
* 3: Toggle hide/show HUD
* 0: Toggle video/subtraction mode

