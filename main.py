import cv2
import mediapipe as mp
import firebase_admin
from firebase_admin import credentials,db

if not firebase_admin._apps:
    cred = credentials.Certificate("credentials.json")
    firebase_admin.initialize_app(cred, {
        'databaseURL': 'https://project-nsic-default-rtdb.asia-southeast1.firebasedatabase.app/'
    })
ref = db.reference("/gesture")

mp_hands = mp.solutions.hands
mp_drawing = mp.solutions.drawing_utils
hands = mp_hands.Hands(min_detection_confidence=0.5, min_tracking_confidence=0.5)


cap = cv2.VideoCapture(0)


finger_tips = [8, 12, 16, 20] 
thumb_tip = 4 

while True:
    success, img = cap.read()
    if not success:
        break

   
    img_rgb = cv2.cvtColor(img, cv2.COLOR_BGR2RGB)


    result = hands.process(img_rgb)

    
    if result.multi_hand_landmarks:
        for hand_landmark in result.multi_hand_landmarks:
            
            mp_drawing.draw_landmarks(img, hand_landmark, mp_hands.HAND_CONNECTIONS)

        
            landmarks = hand_landmark.landmark
            fingers_count = 0

            
            for tip in finger_tips:
                if landmarks[tip].y < landmarks[tip - 2].y:  
                    fingers_count += 1

        
            if landmarks[thumb_tip].x > landmarks[thumb_tip - 2].x:  
                fingers_count += 1

            
            print(f"Fingers Raised: {fingers_count}")
            if fingers_count==5:
                ref.update({"Load1":1})
            elif fingers_count==0:
                ref.update({"Load1":0})
            elif fingers_count==1:
                ref.update({"Load2":1})
            elif fingers_count==2:
                ref.update({"Load2":0})
            elif fingers_count==3:
                ref.update({"Load3":1})
            elif fingers_count==4:
                ref.update({"Load3":0})
            

 
    cv2.imshow("Hand Gesture Detection", img)

   
    if cv2.waitKey(1) & 0xFF == ord('q'):
        break

cap.release()
cv2.destroyAllWindows()
