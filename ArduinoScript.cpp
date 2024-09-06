#define relay_sig 13
#define poll_ID_1 0
#define poll_ID_2 1
#define poll_ID_3 2
#define poll_ID_4 3
#define poll_ID_5 4
#define poll_ID_6 5
#define env_res 7

const int active_sig = 0;
const int thresh_hold = 0; 

int poll_ID_reading_[] = {active_sig , active_sig , active_sig , active_sig , active_sig, active_sig};
int poll_ID_[] = {poll_ID_1, poll_ID_2, poll_ID_3, poll_ID_4, poll_ID_5, poll_ID_6};

void setup() {
  Serial.begin(9600);
  pinMode(env_res, INPUT);
  pinMode(relay_sig, OUTPUT);
  pinMode(poll_ID_1, INPUT);
  pinMode(poll_ID_2, INPUT);
  pinMode(poll_ID_3, INPUT);
  pinMode(poll_ID_4, INPUT);
  pinMode(poll_ID_5, INPUT);
  pinMode(poll_ID_6, INPUT);
}

void loop() {
  double env_value = analogRead(env_res); // environmental light sensing
  // compare to thresh hold 
    poll_ID_reading_[0]= analogRead(poll_ID_1);
    poll_ID_reading_[1]= analogRead(poll_ID_2);
    poll_ID_reading_[2]= analogRead(poll_ID_3);
    poll_ID_reading_[3]= analogRead(poll_ID_4);
    poll_ID_reading_[4]= analogRead(poll_ID_5);
    poll_ID_reading_[5]= analogRead(poll_ID_6);
    for(int i = 0; i < 6; i++)
    {
      //detecting faulty poll and returning poll ID
      if(poll_ID_reading_[i]  > active_sig){
        Serial.println(String(poll_ID_[i]) + ",ACTIVE"); // active
        delay(500);
      }
      if (poll_ID_reading_[i]  == active_sig){
        Serial.println(String(poll_ID_[i]) + ",INACTIVE"); // active
        delay(500);
      }
    }
  delay(500); // checks for fault every seconds
}
