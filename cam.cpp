#include "opencv2/imgproc.hpp"
#include "opencv2/highgui.hpp"
using namespace cv;

class Camera {
   private:
   static Camera *instance;
   // Private constructor so that no objects can be created.
   private:
      Camera() {}
   public:
     Mat framei;
     bool blur;
     bool edge;
     int isblursize;
   public:
   static Camera *getInstance() {
      if (!instance)
      instance = new Camera;
      return instance;
   }


   void closeCamera(){
    for(;;){
      imshow("frames", framei);
      if(waitKey(30) >= 0){
        break;
       }
     }
        exit(1);
    }
   int read()
    {
        VideoCapture cap(0);
        if(!cap.isOpened()) return -1;
        Mat frame, frames;
        namedWindow("frames",1);
        for(;;){
            cap >> frame;
            cvtColor(frame, frames,  COLOR_BGR2GRAY);
            if(blur==1){
            GaussianBlur(frames, frames, Size(isblursize,isblursize), 1.5, 1.5);
           }
           if(edge==1){
            Canny(frames, frames, 0, 30, 3);
           }
            
            //
            imshow("frames", frames);
            framei = frames;
            if(waitKey(30) >= 0){
                cap.release();
              closeCamera();
              }
            }
            return 0;
        }
    void openCamera(bool isblured=0,int blursize=5,bool isedgedetected=0){
        blur = isblured;
        edge = isedgedetected;
        isblursize = blursize;

        read();
   }
        
    
};

//Initialize pointer to zero so that it can be initialized in first call to getInstance
Camera *Camera::instance = 0;

int main(){
   Camera *recorder = recorder->getInstance();
    recorder->openCamera();
   
 
   return 0;
}
