#include<opencv2/imgproc.hpp>
#include<opencv2/videoio.hpp>
#include<opencv2/highgui.hpp>
#include<iostream>
#include<string>

using namespace std;
using namespace cv;

int main(){
    //open webcam
    VideoCapture videoCapture(0);

    //Check if webcam is opened successfully
    if(!videoCapture.isOpened()){
        cout<<"Unable to open camea"<<endl;
        return 0;
    }

    int k=0;

    //Create window show webcam feed
    namedWindow("webcam", WINDOW_NORMAL);

    Mat frame;
    while (1){
        videoCapture >> frame;
        
        //Check if esc is pressed
        if(k == 27){
            break;
        }

        //Check if any alphabet is pressed and then display it
        char c = k;
        cout<<c<<endl;
        string str2 = " is pressed";
        string str = c + str2;
        cout<<str<<endl;
        if(k >=65 && k <= 90){
            putText(frame, str, Point(100, 100), FONT_HERSHEY_SIMPLEX, 1, Scalar(0, 0, 255), 5);
        }
        if(k >=97 && k <= 122){
            putText(frame, str, Point(100, 100), FONT_HERSHEY_SIMPLEX, 1, Scalar(0, 0, 255), 5);
        }

        //Display the alphabet which is presses from keyboard
        imshow("webcam", frame);

        //Waitkey time is increased so that we can see the text otherwise it will dissapear very soon
        k = waitKey(4000);
    }
    
    return 0;
}