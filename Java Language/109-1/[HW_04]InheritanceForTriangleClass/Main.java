import java.util.Scanner;  
  
public class Main {  
    // 靜態型抽象父類  
    public static abstract class GeometricObject {  
        private String color;  
        private boolean filled;  
  
        // 無參構造方法  
        public GeometricObject() {  
  
        }  
  
        // 帶參構造方法  
        public GeometricObject(String color, boolean filled) {  
            setColor(color);  
            setFilled(filled);  
        }  
  
        // Getter Setter  
        public String getColor() {  
            return color;  
        }  
  
        public void setColor(String color) {  
            this.color = color;  
        }  
  
        public boolean isFilled() {  
            return filled;  
        }  
  
        public void setFilled(boolean filled) {  
            this.filled = filled;  
        }  
  
        // 抽象方法  
        public abstract double getArea();  
  
        public abstract double getPerimeter();  
    }  
  
    // 實現抽象類的靜態型實現類  
    public static class Triangle extends GeometricObject {  
        // 實現類屬性  
        private double side1;  
        private double side2;  
        private double side3;  
  
        // 無參構造方法  
        public Triangle() {  
            super();  
        }  
  
        // 帶參構造方法  
        public Triangle(double side1, double side2, double side3, String color, boolean filled) {  
            setSide1(side1);  
            setSide2(side2);  
            setSide3(side3);  
            setColor(color);  
            setFilled(filled);  
        }  
  
        // Getter Setter  
        public double getSide1() {  
            return side1;  
        }  
  
        public void setSide1(double side1) {  
            this.side1 = side1;  
        }  
  
        public double getSide2() {  
            return side2;  
        }  
  
        public void setSide2(double side2) {  
            this.side2 = side2;  
        }  
  
        public double getSide3() {  
            return side3;  
        }  
  
        public void setSide3(double side3) {  
            this.side3 = side3;  
        }  
  
        // 實現抽象方法  
        @Override  
        public double getArea() {  
            double s = (getSide1() + getSide2() + getSide3()) / 2;  
            return Math.sqrt(s * (s - getSide1()) * (s - getSide2()) * (s - getSide3()));  
        }  
  
        @Override  
        public double getPerimeter() {  
            return getSide1() + getSide2() + getSide3();  
        }  
  
        // 重寫toString方法  
        @Override  
        public String toString() {  
            // return super.toString();  
            return "Triangle: side1 = " + getSide1() + " side2 = " + getSide2() + " side3 = " + getSide3() + "\n"  
                    + "The area is " + getArea() + "\n" + "The perimeter is " + getPerimeter() + "\n" + getColor()  
                    + "\n" + isFilled();  
        }  
    }  
  
    public static void main(String[] args) {  
        Scanner sc = new Scanner(System.in);  
        Triangle t = new Triangle(sc.nextDouble(), sc.nextDouble(), sc.nextDouble(), sc.next(), sc.nextBoolean());  
        System.out.println(t);  
        sc.close();  
    }  
  
}  