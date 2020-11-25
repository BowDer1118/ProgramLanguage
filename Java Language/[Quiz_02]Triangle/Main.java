import java.awt.Point;  
import java.awt.geom.Point2D;  
import java.util.Arrays;  
import java.util.Scanner;  
  
public class Main {  
    static class Triangle {  
        Point2D a = new Point();  
        Point2D b = new Point();  
        Point2D c = new Point();  
        double[] side = new double[3];  
  
        public Triangle() {  
  
        }  
  
        public Triangle(int[] data) {  
            a.setLocation(data[0], data[1]);  
            b.setLocation(data[2], data[3]);  
            c.setLocation(data[4], data[5]);  
        }  
  
        public double calculateArea() {  
            double ab = this.a.distance(this.b);  
            double ac = this.a.distance(this.c);  
            double bc = this.b.distance(this.c);  
            this.side[0] = ab;  
            this.side[1] = ac;  
            this.side[2] = bc;  
            double s = (ab + ac + bc) / 2.0;  
            return Math.sqrt(s * (s - ab) * (s - ac) * (s - bc));  
        }  
  
        public double[] getSide() {  
            Arrays.sort(this.side);  
            return this.side;  
        }  
    }  
  
    public static void main(String[] args) {  
        Scanner sc = new Scanner(System.in);  
        int count = sc.nextInt();  
        for (int i = 0; i < count; i++) {  
            int[] data = new int[6];  
            for (int j = 0; j < 6; j++) {  
                data[j] = sc.nextInt();  
            }  
            Triangle t = new Triangle(data);  
  
            if (t.calculateArea() > 0.0) {  
                double[] result = t.getSide();  
                System.out.printf("%.3f %.3f %.3f %.3f\n", result[0], result[1], result[2], t.calculateArea());  
            } else {  
                System.out.println("Just Line!");  
            }  
        }  
        sc.close();  
    }  
}  