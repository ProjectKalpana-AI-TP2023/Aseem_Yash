import cv2 as cv
import numpy as np

#INPUT VIDEO INIT
cap = cv.VideoCapture('Vid.mp4')
prevCircle = None
dist = lambda x1,y1,x2,y2: (x1-x2)**2 + (y1-y2)**2

#OUTPUT VIDEO INIT
fourcc = cv.VideoWriter_fourcc(*'mp4v')
out = cv.VideoWriter('Out.mp4', fourcc, 30.0, (int(cap.get(3)), int(cap.get(4))))
frame_count = 0



while True:
    ret, frame = cap.read()
    if not ret: break
    width  = cap.get(3)
    height = cap.get(4)

    bwFrame = cv.cvtColor(frame, cv.COLOR_BGR2GRAY)
    gaussFrame = cv.GaussianBlur(bwFrame, (15,15), 0)

    distBetweenTwo = ((width+height)/2)/5
    minRad = 5
    maxRad = 30
    sensitivity = 150
    accuracy = 5
    
    halfCircles = cv.HoughCircles(gaussFrame, cv.HOUGH_GRADIENT, 2, distBetweenTwo, param1=sensitivity, param2=accuracy, minRadius = minRad, maxRadius = maxRad )

    if halfCircles is not None:
        halfCircles = np.uint16(np.around(halfCircles))
        chosen = None

        for i in halfCircles[0,:]:
            if chosen is None:  chosen = i
            if prevCircle is not None:
                if ( dist(chosen[0],chosen[1],prevCircle[0],prevCircle[1]) <= dist(i[0],i[1],prevCircle[0],prevCircle[1])): chosen = i
                   
        cv.circle(frame, (chosen[0], chosen[1]), 1, (0,100,100),3)
        cv.circle(frame, (chosen[0], chosen[1]), chosen[2], (0,100,100),3)
        prevCircle = chosen

        
    cv.imshow("Raw Frame",frame)
    cv.imshow("B/W", bwFrame)
    cv.imshow("Blurred", gaussFrame)
    if cv.waitKey(0) & 0xFF == ord("1"):   break
    out.write(frame)


out.release()    
cap.release()
cv.destroyAllWindows()    
