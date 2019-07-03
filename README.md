Camera Wrapper class

The program streams a video and takes images while pressing any key. for exit press any key twise.

The camera can be started by calling the openCamera function. 
The structure of opencamera function: openCamera(bool isblured=0,int blursize=5,bool isedgedetected=0)
isblured=1 is for blurring the frame and the blursize is the Gaussian blur filter size
isedgedetection = 1 for detecting edges using Canny filter
if the value of the parameter is not set, it uses the default value

the openCamera function calls the read function. while pressing a key the read function calls closeCamera function  for taking images and closing the window.
