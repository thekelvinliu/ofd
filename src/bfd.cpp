/**
 * bfd.cpp
 * basic face detection
 */
#include <iostream>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/objdetect/objdetect.hpp>

using namespace std;
using namespace cv;

CascadeClassifier face_cascade;
String window_name = "bfd";

/**
 * detects faces and draws an ellipse around them
 */
void detectFaces(Mat frame) {
    // convert frame to grayscale
    Mat frame_gray;
    cvtColor(frame, frame_gray, COLOR_BGR2GRAY);
    equalizeHist(frame_gray, frame_gray);
    // detect faces
    vector<Rect> faces;
    face_cascade.detectMultiScale(frame_gray, faces, 1.1, 3,
                                  0|CASCADE_SCALE_IMAGE, Size(30, 30));
    // iterate over faces and draw ellipses
    for (int i = 0; i < faces.size(); i++) {
        // current face
        Rect face = faces[i];
        // get center of face
        Point center(face.x + face.width/2, face.y + face.height/2);
        // draw ellipse
        ellipse(frame, center, Size(face.width/2, face.height/2), 0, 0, 360,
                Scalar(255, 0, 255), 4, 8, 0);
    }
    // show the frame
    imshow(window_name, frame);
}

/**
 * main function
 */
int main(int argc, char** argv) {
    if (argc != 2) {
        cout << "usage: " << argv[0] << " <path/to/haar/cascade.xml>" << endl;
        exit(1);
    }
    String hc_path = String(argv[1]);
    // load classifier
    face_cascade.load(hc_path);
    // create frame buffer
    Mat frame;
    // open default camera
    VideoCapture cap(0);
    // continually read camera image to frame and run detectFaces
    while(cap.read(frame)) {
        detectFaces(frame);
        if (waitKey(30) >= 0)
            break;
    }
    return 0;
}
