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
   
   public:
   static Camera *getInstance() {
      if (!instance)
      instance = new Camera;
      return instance;
   }
public:
    bool color,blur,edgedetector;

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
        Mat frame, edges;
        namedWindow("frames",1);
        for(;;){
            cap >> frame;
            cvtColor(frame, edges, COLOR_BGR2GRAY);
            //GaussianBlur(edges, edges, Size(7,7), 1.5, 1.5);
            //Canny(edges, edges, 0, 30, 3);
            imshow("frames", frame);
            framei = frame;
            if(waitKey(30) >= 0){
                cap.release();
              closeCamera();
              }
            }
            return 0;
        }
    void openCamera(){
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
