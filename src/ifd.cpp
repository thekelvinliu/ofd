/**
 * ifd.cpp
 * improved face detection
 */
#include <iostream>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/objdetect/objdetect.hpp>

using namespace std;
using namespace cv;

CascadeClassifier face_cascade, eyes_cascade;
String window_name = "ifd";

/**
 * detects faces and eyes and draws an ellipse around them
 */
void detectFacesAndEyes(Mat frame) {
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
        Mat face_mat = frame_gray(face);
        // detect eyes
        vector<Rect> eyes;
        eyes_cascade.detectMultiScale(face_mat, eyes, 1.1, 2,
                                      0|CASCADE_SCALE_IMAGE, Size(30, 30));
        if (eyes.size() > 0) {
            // get center of face
            Point center(face.x + face.width/2, face.y + face.height/2);
            // draw ellipse
            ellipse(frame, center, Size(face.width/2, face.height/2), 0, 0, 360,
                    Scalar(255, 0, 255), 4, 8, 0);
        }
    }
    // show the frame
    imshow(window_name, frame);
}

/**
 * main function
 */
int main(int argc, char** argv) {
    if (argc != 3) {
        cout << "usage: " << argv[0] << " <path/to/face/cascade.xml> <path/to/eye/cascade.xml>" << endl;
        exit(1);
    }
    String fc_path = String(argv[1]);
    String ec_path = String(argv[2]);
    // load classifiers
    face_cascade.load(fc_path);
    eyes_cascade.load(ec_path);
    // create frame buffer
    Mat frame;
    // open default camera
    VideoCapture cap(0);
    // continually read camera image to frame and run detectFaces
    while(cap.read(frame)) {
        detectFacesAndEyes(frame);
        if (waitKey(30) >= 0)
            break;
    }
    return 0;
}
