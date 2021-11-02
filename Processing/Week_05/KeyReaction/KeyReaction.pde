Character[] chars; // Declare the array
int numChar = 50;
int currentChar = 0;

void setup() {
    size(600, 600);
    smooth();
    chars = new Character[numChar]; // Create the array
    for (int i = 0; i < numChar; i++) {
        chars[i] = new Character(); // Create each object
    }
    strokeWeight(4);
}

void draw() {
    background(0);
    for (int i = 0; i < numChar; i++) {
        chars[i].grow();
        chars[i].display();
    }
}

void keyPressed() {
    chars[currentChar].start();
    currentChar++;
    if (currentChar >= numChar) {
        currentChar = 0;
    }
}

class Character {
    float x,y; 
    float diameter; 
    boolean on = false; 
    color c;
    char character;
    
    void start() {
        character = key;
        x = random(0,600);
        y = random(0,600);
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
            fill(c);
            textSize(diameter);
            text(character,x, y);
        }
    }
}
