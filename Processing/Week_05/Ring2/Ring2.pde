Ring[] rings; // Declare the array
int numRings = 50;
int currentRing = 0;
float distance;

void setup() {
    size(600, 600);
    smooth();
    rings = new Ring[numRings]; // Create the array
    for (int i = 0; i < numRings; i++) {
        rings[i] = new Ring(); // Create each object
    }
}

void draw() {
    background(0);
    for (int i = 0;i < numRings;i++) {
        for (int j = (i + 1);j<numRings;j++) {
            if (rings[i].on &&  rings[j].on) {
                distance = sqrt(pow(rings[i].x - rings[j].x,2) + pow(rings[i].y - rings[j].y,2));
                if (distance < (rings[i].diameter / 2 + rings[j].diameter / 2)) {
                    if (rings[i].diameter > rings[j].diameter) {
                        rings[i].on = false;
                    } else{
                        rings[j].on = false;
                    }
                }
            }
        }
    }
    
    for (int i = 0; i < numRings; i++) {
        rings[i].grow();
        rings[i].display();
    }
}

// Click to create a new Ring
void mousePressed() {
    rings[currentRing].start(mouseX, mouseY);
    currentRing++;
    if (currentRing >= numRings) {
        currentRing = 0;
    }
}

class Ring {
    float x, y; // X-coordinate, y-coordinate
    float diameter; // Diameter of the ring
    boolean on = false; // Turns the display on and off
    color c;
    
    void start(float xpos, float ypos) {
        x = xpos;
        y = ypos;
        on = true;
        diameter = 1;
        c = color((int)random(0, 255),(int)random(0, 255),(int)random(0, 255));
    }
    
    void grow() {
        if (on == true) {
            diameter += 0.5;
            if (diameter > 400) {
                on = false;
            }
        }
    }
    
    void display() {
        if (on == true) {
            noFill();
            strokeWeight(4);
            stroke(c);
            ellipse(x, y, diameter, diameter);
        }
    }
}
