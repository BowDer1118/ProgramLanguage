

void setup() {
    size(800, 600);
    background(153, 255, 255);    
    smooth();
}

void draw() {
    background(153, 255, 255);    
    for (int i = 100;i < 800;i += 200) {
        for (int j = 100;j < 600;j += 200) {
            fill(255, 51, 51);
            ellipse(i, j, 200, 200);
            fill(153,255,51);
            ellipse(i + (mouseX - 400) / 11, j + (mouseY - 400) / 11, 100, 100);
            fill(178,102,255);
            ellipse(i + (mouseX - 400) / 7, j + (mouseY - 400) / 7, 50, 50);
        }   
    }
}
