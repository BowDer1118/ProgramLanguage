int num = 50;
int[] x = new int[num];
int[] y = new int[num];
int[] r = new int[num];
int[] g = new int[num];
int[] b = new int[num];

void setup() {
    size(800, 800);
    noStroke();
    smooth();
    fill(255, 102);
}

void draw() {
    background(0);
    // Shift the values to the right
    for (int i = num - 1; i > 0; i--) {
        x[i] = x[i - 1];
        y[i] = y[i - 1];
        r[i] = r[i - 1];
        g[i] = g[i - 1];
        b[i] = b[i - 1];
    } 
    
    // Add the new values to the beginning of the array
    x[0] = mouseX;
    y[0] = mouseY;
    r[0] = (int)random(0, 255);
    g[0] = (int)random(0,255);
    b[0] = (int)random(0,255);
    
    // Drawthe circles
    for (int i = 0; i < num; i++) {
        fill(r[i],g[i],b[i]);
        ellipse(x[i], y[i], i / 2.0, i / 2.0);
    }
} 