int n = 100;

void setup() {
    size(800, 800);
    background(255);
    //Set 1 frame per second
    frameRate(1); 
}

void draw() {
    //Clear canvas
    background(255);
    //Each frame generate 100 ractangle
    for (int i = 0;i < n;i++) {
        //random color
        fill(int(random(0,255)), int(random(0,255)), int(random(0,255))); 
        //random position,width,and height
        rect(int(random(0,800)), int(random(0,800)), int(random(0,150)), int(random(0,150))); 
    }
}
