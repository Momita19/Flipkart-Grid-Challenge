import cv2
import numpy as np
import cv2.aruco as aruco


# Load the predefined dictionary
dictionary = cv2.aruco.Dictionary_get(cv2.aruco.DICT_4X4_50) #size is 4 by 4 and number is 50 - faster


def aruco_create():
   for i in range(50):
       # Generate the markers
       outputMarker = np.zeros((200, 200), dtype=np.uint8)
       markerImage = cv2.aruco.drawMarker(dictionary, i, 500, outputMarker, 1) #500 is the number of pixels
       image_path = r'/home/pi/project/aruco/4X4Marker%i.jpg' %i
       cv2.imwrite(image_path , markerImage)


aruco_create()

#Aruco detection
cap = cv2.VideoCapture(0)

while True:
   ret, frame = cap.read()
   gray = cv2.cvtColor(frame, cv2.COLOR_BGR2GRAY)

   aruco_dict = aruco.Dictionary_get(aruco.DICT_4X4_50)
   arucoParameters = aruco.DetectorParameters_create()
   corners, ids, rejectedImgPoints = aruco.detectMarkers(
       gray, aruco_dict, parameters=arucoParameters)
   print(ids)
   if np.all(ids):
     image = aruco.drawDetectedMarkers(frame,corners,ids)         
     cv2.imshow('Display', image)
   else:
       display = frame
       cv2.imshow('Display', display)
      
   if cv2.waitKey(1) & 0xFF == ord('q'):
       break

cap.release()
cv2.destroyAllWindows()