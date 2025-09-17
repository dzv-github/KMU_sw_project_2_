#define mossTime 250
#define LedPin 7
String s="Hello World 1234";


int AlphaMossLength[37]={
  2,4,4,3,1,4,3,4,2,4,3,4,2,2,3,4,4,3,3,1,3,4,3,4,4,4,5,5,5,5,5,5,5,5,5,5
};

bool AlphaTranslator[37][10]=
{
  {1,0}, //a
  {1,0,0,0}, //b
  {1,0,1,0}, //c
  {1,0,0}, //d
  {1}, //e
  {0,0,1,0}, //f
  {1,1,0}, //g
  {0,0,0,0}, //h
  {0,0}, //i
  {0,1,1,1}, //j
  {1,0,1}, //k
  {0,1,0,0}, //l
  {1,1}, //m
  {1,0}, //n
  {1,1,1}, //o
  {0,1,1,0}, //p
  {1,1,0,1}, //q
  {0,1,0}, //r
  {0,0,0}, //s
  {1}, //t
  {0,0,1}, //u
  {0,0,0,1}, //v
  {0,1,1}, //w
  {1,0,0,1}, //x
  {1,0,1,1}, //y
  {1,1,0,0},//z
  {1,1,1,1,1}, //0
  {0,1,1,1,1}, //1
  {0,0,1,1,1}, //2
  {0,0,0,1,1}, //3
  {0,0,0,0,1}, //4
  {0,0,0,0,0}, //5
  {1,0,0,0,0}, //6
  {1,1,0,0,0}, //7
  {1,1,1,0,0}, //8
  {1,1,1,1,0} //9
};

void mossTrue(){
  digitalWrite(LedPin,1);
  delay(mossTime*3);
  digitalWrite(LedPin,0);
  delay(mossTime);
}
void mossFalse(){
  digitalWrite(LedPin,1);
  delay(mossTime*1);
  digitalWrite(LedPin,0);
  delay(mossTime);
}

int stchar(int now_char){
  if('A'<=now_char&&now_char<='Z')return 'A';
  else if('a'<=now_char&&now_char<='z')return 'a';
  else if('0'<=now_char&&now_char<='9')return '0'-26;
}

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(LedPin,OUTPUT);
  delay(mossTime*21);
}

void loop() {

    Serial.println(' ');
    for(int j=0;j<s.length();j++){
      Serial.print(String(s[j]));
      if(s[j]==' ')delay(mossTime*7);

      else{
        int schar=stchar(s[j]);
        for(int i=0;i<AlphaMossLength[s[j]-schar];i++){

          if(AlphaTranslator[s[j]-schar][i]==1)mossTrue();
          else mossFalse();
          
        }
        delay(mossTime*3);
      }
    }
  delay(mossTime*21);
}
