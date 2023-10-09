import cv2 as cv
import numpy as np

#INPUT VIDEO INIT
cap = cv.VideoCapture('Vid.mp4')
prevCircle = None
dist = lambda x1,y1,x2,y2: (x1-x2)**2 + (y1-y2)**2


# #OUTPUT VIDEO INIT
fourcc = cv.VideoWriter_fourcc(*'mp4v')
out = cv.VideoWriter('Out.mp4', fourcc, 30.0, (int(cap.get(3)), int(cap.get(4))))
frame_count = 0

#TENNIS BALL COLOR INIT
ballColorRange = [(0, 100, 100), (100, 200, 200)] 


while True:
    ret, frame = cap.read()
    if not ret: break
    width  = cap.get(3)
    height = cap.get(4)

    bwFrame = cv.cvtColor(frame, cv.COLOR_BGR2GRAY)
    gaussFrame = cv.GaussianBlur(bwFrame, (15,15), 0)


    edges = cv.Canny(gaussFrame, 10, 200)
    kernel = np.ones((5, 5), np.uint8)

    edges = cv.dilate(edges, kernel, iterations=2)
    edges = cv.erode(edges, kernel, iterations=1)


    distBetweenTwo = ((width+height)/2)/5
    minRad = 5
    maxRad = 30
    sensitivity = 150
    accuracy = 5
    
    halfCircles = cv.HoughCircles(edges, cv.HOUGH_GRADIENT, 2, distBetweenTwo, param1=sensitivity, param2=accuracy, minRadius = minRad, maxRadius = maxRad )

    if halfCircles is not None:
        halfCircles = np.uint16(np.around(halfCircles))
        chosen = None

        circFrame = frame.copy()
        outFrame = frame.copy()
        for i in halfCircles[0,:]:

            cv.circle(circFrame, (i[0], i[1]), 1, (255,255,255),3)
            cv.circle(circFrame, (i[0], i[1]), i[2], (0,100,100),3)

            if chosen is None:  chosen = i
            if prevCircle is not None:
                if ( dist(chosen[0],chosen[1],prevCircle[0],prevCircle[1]) <= dist(i[0],i[1],prevCircle[0],prevCircle[1])): chosen = i

        #Most apt circle is inside chosen variable right now, so we will attempt to see if it matches tennis ball colours
        ballRegion = frame[chosen[1] - chosen[2]:chosen[1] + chosen[2], chosen[0] - chosen[2]:chosen[0] + chosen[2]]     
        ballRegionColor = np.mean(ballRegion, axis=(0, 1))    

        ballColor = np.zeros((300, 300, 3), np.uint8)
        ballColor[:] = ballRegionColor

        A =  ballColorRange[0] <= ballRegionColor
        B =  ballRegionColor <= ballColorRange[1]
        print(A,B)

        if (A == B).all():    
            cv.circle(outFrame, (chosen[0], chosen[1]), 1, (0,100,100),3)
            cv.circle(outFrame, (chosen[0], chosen[1]), chosen[2], (0,100,100),3)
            prevCircle = chosen
        else:
            continue
        


    cv.imshow("Color Frame",ballColor)
    cv.imshow("Raw Frame",frame)
    cv.imshow("Out Frame",outFrame)
    cv.imshow("B/W", edges)
    cv.imshow("All Circles Found", circFrame)
    if cv.waitKey(0) & 0xFF == ord("1"):   break
    out.write(frame)


out.release()    
cap.release()
cv.destroyAllWindows()    
