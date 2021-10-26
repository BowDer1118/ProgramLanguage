PImage img;
int i;
boolean direct;
void setup()
{
    size(1000, 1000);
    i = 0;
    direct = true;
    img = loadImage("Rat.png");
    frameRate(20);
}

void draw()
{
    background(255);
    image(img, i, 0);
    if (direct ==  true) {
        i += 20;
    } else{
        i -= 20;
    }
    
    if (i + 700 > 1000) {
        direct = false;
    }
    
    if (i < 0) {
        direct = true;
    }
}
