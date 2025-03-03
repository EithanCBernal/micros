 int val;
int last=0;
int stat=LOW;
int stat2;
int contar=0;
int sens=75;
int nAspas=2;
int milisegundos=500;

void setup() {
  Serial.begin(9600);
  pinMode(2,OUTPUT);
}
void loop() {
  val=analogRead(0);
  if(val<sens)
  stat=LOW;
  else
  stat=HIGH;
  digitalWrite(2,stat);

  if(stat2!=stat){
    contar++;
    stat2=stat;
  }
  if(millis()-last>=milisegundos){
    double rps=((double)contar/nAspas)/2.0*1000.0/milisegundos;
    Serial.println(rps);
    contar=0;
    last=millis();
  }

}
