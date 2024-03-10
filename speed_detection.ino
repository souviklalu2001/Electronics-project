


int trigPin = 5;

int echoPin = 6;

 



int distance1 = 0;

int distance2 = 0;

int measured_speed = 0;

long duration = 0;

int distance = 0;

 

void setup()

{

    

    pinMode(trigPin, OUTPUT);

 

    

    pinMode(echoPin, INPUT);

 

   

    Serial.begin(9600); 

}

 

void loop()

{

   

    distance1 = ultrasonicRead(); 

    delay(1000);                  

    distance2 = ultrasonicRead(); 

 

    

    measured_speed = abs(distance2 - distance1) / 1.0;

 



    Serial.print("Speed in cm/s :");

    Serial.println(measured_speed);

}

 

 

float ultrasonicRead()

{

    

    digitalWrite(trigPin, HIGH);

    delayMicroseconds(10);

    digitalWrite(trigPin, LOW);

 

    
    duration = pulseIn(echoPin, HIGH);

    

    distance = duration * 0.034 / 2;

 

    

    return distance;

}
