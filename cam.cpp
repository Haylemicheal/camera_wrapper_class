#include "opencv2/imgproc.hpp"
#include "opencv2/highgui.hpp"
using namespace cv;

class Camera {
   static Camera *instance;
 
   // Private constructor so that no objects can be created.
   private:
      Camera() {}

   public:
   static Camera *getInstance() {
      if (!instance)
      instance = new Camera;
      return instance;
   }

   int record()
    {
        VideoCapture cap(0);
        if(!cap.isOpened()) return -1;
        Mat frame, edges;
        namedWindow("edges",1);
        for(;;)
        {
            cap >> frame;
            cvtColor(frame, edges, COLOR_BGR2GRAY);
            //GaussianBlur(edges, edges, Size(7,7), 1.5, 1.5);
            //Canny(edges, edges, 0, 30, 3);
            imshow("edges", edges);
            if(waitKey(30) >= 0) break;
        }
       return 0;
    }
};

//Initialize pointer to zero so that it can be initialized in first call to getInstance
Camera *Camera::instance = 0;

int main(){
   Camera *recorder = recorder->getInstance();
   recorder->record();
   return 0;
}