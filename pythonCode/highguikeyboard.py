import cv2
import sys

#open webcam
videoCapture = cv2.VideoCapture(0)

k = 0

#create window to display webcam feed
cv2.namedWindow("webcam", cv2.WINDOW_NORMAL)

while(True):
    #Read frame from webcam 
    ret, frame = videoCapture.read()

    #If esc is pressed then exit
    if (k == 27):
        break
    
    #Identify which alphabet is pressed from keyboard and display it
    if(k >= 65 and k <= 90):
        charKey = chr(k)
        cv2.putText(frame, charKey + " is pressed", (100, 100), cv2.FONT_HERSHEY_SIMPLEX, 1, (0, 0, 255), 5)

    if(k >= 97 and k <= 122):
        charKey = chr(k)
        cv2.putText(frame, charKey + " is pressed", (100, 100), cv2.FONT_HERSHEY_SIMPLEX, 1, (0, 0, 255), 5)

    #display webcam feed
    cv2.imshow("webcam", frame)

    #Waitkey time is increased so that we can see the text otherwise it will dissapear very soon
    k = cv2.waitKey(4000)


#after completion release the VideoCapture object
videoCapture.release()

cv2.destroyAllWindows()