/**
 * webcam.cpp
 * simple webcam live-feed
 */
 #include <opencv2/highgui/highgui.hpp>

using namespace cv;

int main(int argc, char** argv) {
    String windowName = "webcam";
    VideoCapture cap(0);
    Mat frame;
    while(true) {
        cap >> frame;
        imshow(windowName, frame);
        if (waitKey(30) >= 0)
            break;
    }
    return 0;
}
