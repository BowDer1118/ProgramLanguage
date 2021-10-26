int posX,posY;
PImage cat;
PImage rat;
int counter;//分數
int N = 50; //Rat數量
//老鼠座標與生命
boolean[] lifes = new boolean[N];
int[] rPosX = new int[N];
int[] rPosY = new int[N];

void setup() {
    size(1000,1000);
    background(255);
    textSize(25);
    cat = loadImage("Cat.jpg"); //300*300
    rat = loadImage("Rat.png"); //250*300
    
    
    posX = (int)random(0,700);
    posY = (int)random(0,700);
    counter = 0;
    
    for (int i = 0;i < N;i++) {
        rPosX[i] = (int)random(0,750);
        rPosY[i] = (int)random(0,700);
        lifes[i] = true;
    }
}

void draw() {
    background(255);
    textSize(25);
    fill(252,43,43);
    text("Score: " + counter,50,50);
    if (counter < 50) {
        for (int i = 0;i < N;i++) {    //更新老鼠圖片
            if (lifes[i]) {            //當前老鼠存活
                image(rat,rPosX[i],rPosY[i]);
            }
        }
    } else{
        textSize(60);
        fill(255,255,0);
        text("Victory!",400,450);
        
    }
    
    image(cat,posX,posY);
    
    if (keyPressed ==  true) {
        if (key ==  'd') {
            posX += 10;
        }
        if (key ==  'a') {
            posX -= 10;
        }
        if (key ==  'w') {
            posY -= 10;
        }
        if (key ==  's') {
            posY += 10;
        }
        
        if (posX < 0) {
            posX = 0;
        }
        if (posY < 0) {
            posY = 0;
        }
        
        if (posX + 300 > 1000) {
            posX = 700;
        }
        if (posY + 300 > 1000) {
            posY = 700;
        }
    }
    
    if (counter < 50) {
        for (int i = 0;i < N;i++) {
            if (lifes[i]) {
                if (abs(posX - rPosX[i])<100 &&  abs(posY - rPosY[i])<100) {
                    lifes[i] = false;
                    counter++;
                }
            }
        }
    }
    
}
