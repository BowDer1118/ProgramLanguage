void setup() {
    background(255);
    size(800, 600);
    smooth(); //將線的邊緣柔和
    strokeWeight(4); //畫筆的筆寬
    
    fill(255,255,128);
    rect(0,0,100,100);
    
    fill(255,0,0);
    rect(0,100,100,100);
    
    fill(178,255,102);
    rect(0,200,100,100);
    
    fill(102,255,255);
    rect(0,300,100,100);
    
    fill(255,153,51);
    rect(0,400,100,100);
    
    fill(255);
    rect(700,0,100,100);
    fill(0);
    textSize(15);
    text("Erase",730,55);
    
    fill(255);
    rect(700,100,100,100);
    fill(0);
    textSize(15);
    text("Save",730,155);
    
    fill(255);
    rect(700,200,100,100);
    fill(0);
    ellipse(750, 250, 2, 2);
    
    fill(255);
    rect(700,300,100,100);
    fill(0);
    ellipse(750, 350, 5, 5);
    
    fill(255);
    rect(700,400,100,100);
    fill(0);
    textSize(15);
    text("Clear",730,455);
}

/*
mousePressed 使用true/false 代表是否 按下滑鼠
mouseButton 使用LEFT RIGHT CENTER 代表 按下滑鼠 左 右 中 鍵
*/
void draw() {
    if (mouseButton ==  LEFT) {
        if (0 <  mouseX &&  mouseX <  100 && (0 <  mouseY &&  mouseY <  100)) {
            stroke(255,255,128);
        }
        if (0 <  mouseX &&  mouseX <  100 && (100 <  mouseY &&  mouseY <  200)) {
            stroke(255,0,0);
        }
        if (0 <  mouseX &&  mouseX <  100 && (200 <  mouseY &&  mouseY <  300)) {
            stroke(178,255,102);
        }
        if (0 <  mouseX &&  mouseX <  100 && (300 <  mouseY &&  mouseY < 400)) {
            stroke(102,255,255);
        }
        if (0 <  mouseX &&  mouseX <  100 && (400 <  mouseY &&  mouseY <  500)) {
            stroke(255,153,51);
        }
        
        if (0 <  mouseX &&  mouseX <  100 && (400 <  mouseY &&  mouseY <  500)) {
            stroke(255,153,51);
        }
        
        if (700 <  mouseX &&  mouseX <  800 && (0 <  mouseY &&  mouseY <  100)) {
            stroke(255,255,255);
        }
        
        if (700 <  mouseX &&  mouseX <  800 && (100 <  mouseY &&  mouseY <  200)) {
            save("My_Picture.jpg");
        }
        
        if (700 <  mouseX &&  mouseX <  800 && (200 <  mouseY &&  mouseY <  300)) {
            strokeWeight(2);
        }
        if (700 <  mouseX &&  mouseX <  800 && (300 <  mouseY &&  mouseY <  400)) {
            strokeWeight(6);
        }
        
        if (700 <  mouseX &&  mouseX <  800 && (400 <  mouseY &&  mouseY <  500)) {
            noStroke();
            fill(255);
            rect(100 + 4,4,600 - 4 - 5,800);
            strokeWeight(4);
            stroke(0);
        }
        
        if ((pmouseX > 100 + 4 &&  mouseX > 100 + 4) && (pmouseX<700 - 4 &&  mouseX<700 - 4)) {
            line(mouseX, mouseY, pmouseX, pmouseY);
        }
    }
}
