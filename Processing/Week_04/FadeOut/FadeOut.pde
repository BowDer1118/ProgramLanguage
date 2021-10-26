PImage img;
int i;
boolean direct;

void setup()
{
    size(1000, 1000);
    i = 255;
    direct = true;
    img = loadImage("Rat.png");
    frameRate(4);
}

void draw()
{
    tint(i); // Tint gray
    image(img, 0, 0);
    if (i >= 255) {
        direct = false;
    }
    
    if (i <= 0) {
        direct = true;
    }
    
    if (direct) {
        i += 20;
    } else{
        i -= 20;
    }
    if (i < 0) {
        i = 0;
    }
}
