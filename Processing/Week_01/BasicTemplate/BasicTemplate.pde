//Global variable area
int y = 0;

//Program enter (only do once time)
void setup() {
    size(300, 300);
    int n = 10;
    frameRate(n); //draw() will do n times per second
    background(255);
}

//Infinite Loop
void draw() {
    println(y); 
    line(0, y, 300, y);
    if (y > 300) {
        background(255);
        y = 0;
    } else{
        y += 10;
    }
}