size(800,800);
background(0,0,0);

int space = 20;
fill(255, 255, 255);
//Center
for (int i = 0;i < 800;i += space) {
    int rad = space / 2;
    strokeWeight(5);
    stroke(0, 191, 255); //stroke color
    ellipse(i, i, space, space);
}
//Left
for (int i = 0;i < 800;i += space) {
    int rad = space / 2;
    strokeWeight(5);
    stroke(51, 248, 202);
    rect(i - 2 * space, i + 2 * space, space, space);
}