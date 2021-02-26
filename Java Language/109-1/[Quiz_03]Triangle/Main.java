package pers.quiz.triangle;

import java.awt.Point;
import java.awt.geom.Point2D;
import java.util.Arrays;
import java.util.Scanner;

class Triangle {
	private Point2D pA;
	private Point2D pB;
	private Point2D pC;

	public Triangle() {

	}

	public Triangle(Point2D pA, Point2D pB, Point2D pC) {
		this.pA = pA;
		this.pB = pB;
		this.pC = pC;
	}

	public double Area() {
		double[] sides = this.getSides();
		double s = (sides[0] + sides[1] + sides[2]) / 2;
		return Math.sqrt(s * (s - sides[0]) * (s - sides[1]) * (s - sides[2]));
	}

	public double[] getSides() {
		double[] sides = { this.pA.distance(this.pB), this.pB.distance(this.pC), this.pA.distance(this.pC) };
		return sides;
	}
}

public class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int count = sc.nextInt();
		for (int i = 0; i < count; i++) {
			Point2D pA = new Point();
			Point2D pB = new Point();
			Point2D pC = new Point();
			pA.setLocation(sc.nextDouble(), sc.nextDouble());
			pB.setLocation(sc.nextDouble(), sc.nextDouble());
			pC.setLocation(sc.nextDouble(), sc.nextDouble());

			Triangle t = new Triangle(pA, pB, pC);
			double area = t.Area();
			double[] sides = t.getSides();
			Arrays.sort(sides);
			if (area > 0) {
				System.out.printf("%.3f %.3f %.3f %.3f\n", sides[0], sides[1], sides[2], area);
			} else {
				System.out.print("Just Line!\n");
			}
		}
		sc.close();

	}

}
