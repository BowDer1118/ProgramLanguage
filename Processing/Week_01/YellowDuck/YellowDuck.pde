size(800, 600); //Window size:width height
background(100, 255, 155); // r g b
noStroke(); //No outer radius
fill(255, 255, 0);
ellipse(400, 200, 350, 300); //Draw ellipse
ellipse(400, 400, 600, 300);


int n = 10; 
for (int i = n;i > 0;i--) {
    fill((int)random(255.0),(int)random(255.0),(int)random(255.0));
    int radius = 10 * (i + 10);
    ellipse(400,400,200,radius);
}

fill(100, 0, 255);
ellipse(300, 180, 50, 100);
ellipse(500, 180, 50, 100);
fill(255, 255, 255);
ellipse(300, 180, 20, 20);
ellipse(500, 180, 20, 20);
fill(255, 0, 0);
ellipse(400, 250, 150, 50);

