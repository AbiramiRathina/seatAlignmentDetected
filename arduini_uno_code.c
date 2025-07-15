const int trig1=11;
const int echo1=12;
const int trig2=9;
const int echo2=8;
long duration, duration1;
int distance, distance1;
String values;
void setup() 
{   
    pinMode(trig1, OUTPUT);
    pinMode(echo1, INPUT);
    pinMode(trig2, OUTPUT);
    pinMode(echo2, INPUT); 
    Serial.begin(9600);  
    delay(2000);    
 } 
void loop() 
{
    values= (getStatus1()+','+getStatus2());
    delay(1000);       
    Serial.flush();
    delay(1000);
       
   Serial.println(values);
   delay(2000);
} 
String getStatus1()
{
    digitalWrite(trig1, LOW);
    delayMicroseconds(2);
    digitalWrite(trig1, HIGH);
    delayMicroseconds(10);
    digitalWrite(trig1, LOW);
    duration = pulseIn(echo1, HIGH);
    distance = duration * 0.034 / 2;   
    if(distance <= 12)
    {
        return "Arranged";    
    }
    return "Not Arranged";
}
String getStatus2()
{
    digitalWrite(trig2, LOW);
    delayMicroseconds(2);
    digitalWrite(trig2, HIGH);
    delayMicroseconds(10);
    digitalWrite(trig2, LOW);
    duration1 = pulseIn(echo2, HIGH);
    distance1 = duration1 * 0.034 / 2; 
    if(distance1 <= 12)
    {
        return "Arranged";    
    } 
       return "Not Arranged";
}
