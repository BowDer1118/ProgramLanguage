void setup() {
    size(800,600);
    background(255,255,255);
    frameRate(1);
}

void draw() {
    background(255,255,255);
    int shape = (int)random(1, 4);
    
    fill((int)random(0,255),(int)random(0,255),(int)random(0,255));
    
    switch(shape) {
        case 1:
            for (int x = 0;x < 800;x += 20) {
                for (int y = 0;y < 600;y += 20) {
                    rect(x, y, 10, 10);
                }
                
            }
            break;
        case 2:
            for (int x = 0;x < 800;x += 20) {
                for (int y = 0;y < 600;y += 20) {
                    ellipse(x + 5, y + 5, 10, 10);
                }
                
            }
            break;
        case 3:
            for (int x = 0;x < 800;x += 20) {
                for (int y = 0;y < 600;y += 20) {
                    line(x, y, x + 10, y + 10);
                }
            }
            break;
    }
}
