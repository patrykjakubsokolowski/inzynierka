import processing.serial.*;

Serial myPort;
String s;
int[] val;
boolean arrived;

void setup () {
  size(900, 550);
  myPort = new Serial(this, Serial.list()[0], 115200);
  myPort.bufferUntil('\n');
  background(0);
  fill(80, 20, 5);
  grid();
}

void grid() {
  strokeWeight(1);
  stroke(130,130,0,150);
  line(10, 10, 874, 10); //1000
  line(10, 110, 874, 110); //800
  line(10, 210, 874, 210); //600
  line(10, 310, 874, 310); //400
  line(10, 410, 874, 410); //200
  line(10, 510, 874, 510); //0
  
  line(10, 10, 10, 510); //340
  line(180, 10, 180, 510); //440
  line(350, 10, 350, 510); //540
  line(520, 10, 520, 510); //640
  line(690, 10, 690, 510); //740
  line(860, 10, 860, 510); //840
  tekst();
}

void tekst() {
  textSize(10);
  fill(250,250,200);
  text("308",2, 530);
  text("457",172, 530);
  text("589",342, 530);
  text("704",512, 530);
  text("797",682, 530);
  text("873",852, 530);
  
  text("0",1, 510);
  text("200",1, 410);
  text("400",1, 310);
  text("600",1, 210);
  text("800",1, 110);
  text("1000",1, 10);
}

void draw () {
  if(arrived) {
  arrived = false;
  background(0);
  grid();
  noFill();
  stroke(255,230,160);
  //translate(900,600);
  //rotate(PI);
  beginShape();
  for (int i = 0; i < 288; i++) {
    vertex(i*3+10, 510-val[i]/2);
  }
  endShape();
  }
}

void serialEvent(Serial myPort) {
  val = int(splitTokens(myPort.readString(), ","));
  arrived = true;
 }
 
 //306,072+2,6963*i-0,00106*i^2-0,00000849*i^3+0,0000000122*i^4
