import processing.serial.*;
Serial myPort;
PImage player,npc,weapon;
int posX,posY;
int counter;
int X, Y, Button;

class Monster{
    boolean alive;
    int x,y;
    
    void init() {
        x = (int)random(0,700);
        y = 0;
        alive = true;
        // println("Init at " + x + " " + y);
    }
    
    void display() {
        if (alive) {
            if (y > 500) {
              counter--;
              init();  
            }
            image(npc,x,y);
            y += 5;
        } else{
            init();
        }
    }
};
int N = 5;

class Weapon{
    int pX,pY;
    boolean exist;
    
    void init(int x,int y) {
        exist = true;
        pX = x;
        pY = y;
    }
    
    void display() {
        if (exist) {
            image(weapon,pX,pY);
            pY -= 10;
            if (pY < 0) {
                exist = false;
            }
        }
    }
}

Monster[] monsters = new Monster[N];
Weapon[] weapons = new Weapon[50];

int index;

void setup() {
    size(1000, 800);
    background(0, 0, 0);
    player = loadImage("Roket5.jpg");
    npc = loadImage("Roket2.jpg");
    weapon = loadImage("weapon.png");
    posX = 300;
    counter = 0;
    fill(255, 255, 255);
    textSize(15);
    
    for (int i = 0;i < N;i++) {
        monsters[i] = new Monster();
        monsters[i].init();
    }
    
    for (int i = 0;i < 50;i++) {
        weapons[i] = new Weapon();
    }
    index = 0;
    
    String portName = Serial.list()[2];
    myPort = new Serial(this, portName, 9600);
}


void draw() {
    getData();
    background(0, 0, 0);
    text("Score: " + counter,5,20);

    if (Y<500) {
        posX -= 50;
        if (posX < 0) {
            posX = 0;
        }
    } else if(Y>600){
        posX += 50;
        if (posX > 800) {
            posX = 800;
        }
    }
    if(X>550||X<450){
      weapons[index].init(posX + 80,600);
      index++;
      if (index ==  50) {
          index = 0;
      }
    }
    
    image(player,posX, 600);
    
    for (int i = 0;i < 50;i++) {
        if (weapons[i].exist) {
            for (int j = 0;j < 5;j++) {
                if (((weapons[i].pY - monsters[j].y)<100)) {
                    if (weapons[i].pX > monsters[j].x && ((weapons[i].pX - monsters[j].x)<100)) {
                        weapons[i].exist = false;
                        monsters[j].alive = false;
                        counter++;
                    }
                }
            }
        }
        weapons[i].display();
        
    }
    
    for (int i = 0;i < N;i++) {
        monsters[i].display();
    }
    
}

//void mousePressed() {
//    // println("fire at " + posX + " " + posY);
//    weapons[index].init(posX + 80,600);
//    index++;
//    if (index ==  50) {
//        index = 0;
//    }
//}

void getData() {
  String msg;
  if (myPort.available() > 0) {
    msg = myPort.readStringUntil('\n');
    if (msg != null)
    {
          msg = trim(msg);
          println(msg);
          String[] token = msg.split(",");
          try{
            X=int(token[0]);
            Y=int(token[1]);
            Button=int(token[2]);
            println(X, Y, Button);
          }catch(Exception e){
            println("Read failure");
          }
    }
  }
}
