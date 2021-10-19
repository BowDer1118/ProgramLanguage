int numPic = 20;
String[] str = {"Empty","Next","Pre","Random","Next","Pre"};
int top,buttom;

void setup() {
    size(600,800);
    frameRate(1);
    
    background(0,0,0);
    
    fill(255,255,255);
    textSize(15);
    
    
    int x,y;
    for (int i = 1;i <= 5;i ++) {
        x = 510;
        y = i * 100 + 50;
        fill(255,255,255);
        rect(x,y,75,50);
        fill(0,0,0);
        text(str[i],x + 5,y + 30);
        println("LT: " + x + " " + y + " RB: " + (x + 75) + " " + (y + 50));
    }
    
    //Init first top and bottom image file
    top = (int)random(1,numPic);
    buttom = (int)random(1,numPic);
}

void draw() {
    int posX,posY;
    if (mousePressed ==  true &&  mouseButton ==  LEFT) {
        posX = mouseX;
        posY = mouseY;
        if (510 <=  mouseX &&  mouseX <=  585) { //x在範圍內
            if (150 <=  mouseY &&  mouseY <=  200) { //Top::next
                top++; 
            } else if (250 <=  mouseY &&  mouseY <=  300) { //Top::pre
                top--;
            } else if (350 <=  mouseY &&  mouseY <=  400) { //Random
                top = (int)random(1,numPic);
                buttom = (int)random(1,numPic);
            } else if (450 <=  mouseY &&  mouseY <=  550) { //Buttom::next
                buttom++;
            } else if (550 <=  mouseY && mouseY <=  650) { //Buttom::pre
                buttom--;
            } else{
                
            }
        }
    }
}

PImage imgTop = loadImage("hw05_Images\\" + top + "t.jpg");
PImage imgButtom = loadImage("hw05_Images\\" + buttom + "b.jpg");

image(imgTop,0,0);
image(imgButtom, 0,400);
}
