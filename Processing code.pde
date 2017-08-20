import processing.serial.*;

Serial comPort;
int delta;
String[] notepad;
String comPortString;
int counter=0;
float coord[],coord1[],d[];
void setup()
{
  comPort = new Serial(this,"COM4",9600);
  comPort.bufferUntil('\n');
  
  background(0);
}
void draw(){
}
void mousePressed(){
  delay(1000);
  comPort.write("E");
  background(0,255,0);
}

void serialEvent(Serial cPort)
{
 comPortString = cPort.readStringUntil('\n');
if(comPortString != null) {
 comPortString=trim(comPortString);
if(comPortString.equals("A")){
notepad=loadStrings("note.txt");
background(0,0,255);  
sendLineNum(counter);

}
 }
}
void sendLineNum(int lineNumber){
 
coord=float(splitTokens(notepad[lineNumber]," NGXYZ"));
int rx=round(coord[2]);
int ry=round(coord[3]);
int rz=round(coord[4]);
 comPort.write(rx);
 println(rx);
 
 comPort.write(ry);
 println(ry);
 comPort.write(rz); 
 println(rz);
counter++;
delay(100);
 
}





 