import processing.serial.*;

String portName = "/dev/cu.usbmodemFA131";

PFont raleway;
Serial port;

color txtCol = #dddddd;

void setup() {
  port = new Serial(this, portName, 9600);
  println("Connected to " + portName);
  raleway = createFont("Raleway-Bold", 80, true);
  size(1000, 400);
  println("Starting visual indicator...");
}

void draw() {

  if (port.available() > 0) {
    String in = port.readStringUntil('\n');
    println("in: " + in);
    if (in != null && in.contains("OFF")) {
      txtCol = #ff2e2e;
    } else {
      txtCol = #dddddd;
    }
  }

  background(255);

  // outer
  fill(153, 153, 153);
  stroke(77, 77, 77);
  strokeWeight(22);
  rect(20, 20, width-40, height-40, 50);

  // text
  textFont(raleway);
  textAlign(CENTER, CENTER);
  fill(txtCol);
  textSize(220);
  text("UNSAFE", width/2, height/2-15);
}
