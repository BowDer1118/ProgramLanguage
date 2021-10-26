PImage img;
int i;
boolean direct;
void setup()
{
    size(500, 500);
    i = 10;
    direct = true;
    img = loadImage("Rat.png");
    frameRate(20);
}

void draw()
    {
    background(255);
    image(img, 50, 50, i, i);
    println(i); 
    if (i + 50 > 500) {
        direct = false;
    }
    
    if (i < 0) {
        direct = true;
    }
    
    
    if (direct) {
        i += 20;
    } else{
        i -= 20;
    }
}
