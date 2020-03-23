int freq[6][10]={
  {329,349,370,392,415,440,466,494,523,659},
  {247,262,277,294,311,329,349,370,392,494},
  {196,208,220,233,247,262,277,294,311,392},
  {147,156,165,175,185,196,208,156,233,294},
  {110,117,123,131,139,147,156,165,175,220},
  {82,87,92,98,104,110,117,123,131,165}
};//line- string
// column-fret
//frets from 0 to 7

#define E0 0
#define B 1
#define G 2
#define D 3
#define A 4
#define E1 5
#define Fret12 9
#define Freq15 784
#define Freq19 988

#define buzzer 2
#define diod 3
#define num 10

void setup() {
  pinMode(buzzer,OUTPUT);
  for(int i=0;i<num;i++)
  {
    pinMode(diod+i,OUTPUT);
  }    
}

void loop() {
  
  int dur=64;
  PlayNote(E0,2,dur);
  PlayNote(E0,0,dur);
  PlayNote(B,4,dur);
  PlayNote(E0,2,dur);
  PlayNote(E0,5,dur);
  PlayNote(E0,3,dur);
  PlayNote(E0,2,dur);
  PlayNote(B,4,dur);
  PlayNote(E0,2,dur);
  PlayNote(E0,3,dur);
  PlayNote(E0,5,dur);
  PlayNote(E0,7,dur);
  PlayNote(E0,5,dur);
  PlayNote(E0,3,dur);
  PlayNote(E0,2,dur);
  PlayNote(B,4,dur);
  
  dur=128;
  Chor(dur,E1);
  PlayNote(E1,0,dur*2);
  PlayNote(A,2,dur);
  PlayNote(E1,3,dur);
  
  Chor(dur,E1);
  PlayNote(E1,0,dur*2);
  
  Chor(dur,E1);
  PlayNote(E1,0,dur*2);
  PlayNote(A,2,dur);
  PlayNote(A,3,dur);

  PlayNote(E1,0,dur*2);
  PlayNote(A,7,dur);
  PlayNote(E1,0,dur*2);
  PlayNote(A,5,dur);
  PlayNote(E1,0,dur*2);

  dur=64;
  PlayNote(E0,7,dur);
  PlayNote(B,8,dur);
  PlayNote(B,5,dur);
  PlayNote(B,8,dur);
  PlayNote(E0,7,dur);
  PlayNote(B,8,dur);
  PlayNote(E0,7,dur);
  PlayNote(E0,Fret12,dur);
  PlayNote(B,Fret12,dur);
  PlayNote(G,Fret12,dur);
  PlayNote(B,Fret12,dur);
  PlayNote(G,Fret12,dur);
  PlayNote(B,Fret12,dur);
  PlayNote(E0,Fret12,dur);
  tone(buzzer,Freq15,dur);
  Diodes(Freq15);
  delay(dur);
  tone(buzzer,Freq19,dur);
  Diodes(Freq19);
  delay(dur);
  Diodes(0);
  delay(4000);
}

inline void PlayNote(int string,int fret,int dur)
{
  int frequency=freq[string][fret];
  Diodes(frequency); 
  tone(buzzer,frequency,dur);
  delay(dur);
  noTone(buzzer);
}
inline void Diodes(int frequency)
{
  for(int i=0;i<num;i++)
  {
    if(frequency>50*i)
      digitalWrite(diod+i,HIGH);
      else digitalWrite(diod+i,LOW);
  }
}

inline void Chor(int dur,int string)
{
    PlayNote(string,0,dur*2);
    PlayNote(string-1,7,dur);
    PlayNote(string,0,dur*2);
    PlayNote(string-1,5,dur);
    PlayNote(string,0,dur*2);
    PlayNote(string-1,3,dur);
    PlayNote(string,0,dur*2);
    PlayNote(string-1,1,dur);
}
