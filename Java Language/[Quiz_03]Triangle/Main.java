package pers.quiz.triangle;

import java.awt.Point;
import java.awt.geom.Point2D;
import java.util.Arrays;
import java.util.Scanner;

class Triangle {
	Point2D pA;
	Point2D pB;
	Point2D pC;

	public Triangle() {

	}

	public Triangle(Point2D pA, Point2D pB, Point2D pC) {
		this.pA = pA;
		this.pB = pB;
		this.pC = pC;
	}

	public double Area(double dAB, double dBC, double dAC) {
		double S = (dAB + dBC + dAC) / 2;
		return Math.sqrt(S * (S - dAB) * (S - dBC) * (S - dAC));
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
			double dAB = pA.distance(pB);
			double dBC = pB.distance(pC);
			double dAC = pA.distance(pC);

			Triangle t = new Triangle(pA, pB, pC);
			double area = t.Area(dAB, dBC, dAC);
			double[] sides = { dAB, dBC, dAC };
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
