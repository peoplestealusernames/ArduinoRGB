int red = 5;
int green = 3;
int blue = 6;

void setup() {
  // put your setup code here, to run once:
  pinMode(LED_BUILTIN, OUTPUT);
  Serial.begin(9600);
}

String MsgTab = "";

void loop() {
  while(Serial.available()>0) {
    char Rec = Serial.read();

    if (Rec == '|'){
      MsgRec(MsgTab);
      MsgTab = "";
    } else {
      MsgTab.concat(Rec);
    }
  }

}

void MsgRec(String Msg) {
  switch (Msg.charAt(0)) {
    case 'r':
      changeColor(red,Msg);
      break;
    case 'g':
      changeColor(green,Msg);
      break;
    case 'b':
      changeColor(blue,Msg);
      break;
  } 
}

void changeColor(int pin, String Msg)
{
  String NStri = "";
  for (int i = 1; i <= Msg.length()-1; i++) {
    NStri.concat(Msg.charAt(i));
  }  
  int Val = NStri.toInt();
  if (Val<300) {
    analogWrite(pin,Val);
  }
}
