package pers.quiz.complex_number;

import java.util.Scanner;

class Complex {
	private double a;
	private double b;

	public Complex() {

	}

	public Complex(double a, double b) {
		setA(a);
		setB(b);
	}

	public double getA() {
		return a;
	}

	public void setA(double a) {
		this.a = a;
	}

	public double getB() {
		return b;
	}

	public void setB(double b) {
		this.b = b;
	}

	public Complex add(Complex c2) {
		return new Complex(this.getA() + c2.getA(), this.getB() + c2.getB());
	}

	public Complex subtract(Complex c2) {
		return new Complex(this.getA() - c2.getA(), this.getB() - c2.getB());
	}

	public Complex multiply(Complex c2) {
		return new Complex(this.getA() * c2.getA() - this.getB() * c2.getB(),
				this.getB() * c2.getA() + this.getA() * c2.getB());
	}

	public Complex divide(Complex c2) {
		return new Complex(
				(this.getA() * c2.getA() + this.getB() * c2.getB()) / (c2.getA() * c2.getA() + c2.getB() * c2.getB()),
				(this.getB() * c2.getA() - this.getA() * c2.getB()) / (c2.getA() * c2.getA() + c2.getB() * c2.getB()));
	}

	public double abs() {
		return Math.sqrt(this.getA() * this.getA() + this.getB() * this.getB());
	}

	@Override
	public String toString() {
		if (this.getA() == 0.0) {
			return String.format("%.4fi", this.getB());
		} else if (this.getB() == 0.0) {
			return String.format("%.4f", this.getA());
		} else {
			return String.format("%.4f + %.4fi", this.getA(), this.getB());
		}
	}
}

public class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		boolean flag = false;
		while (sc.hasNext()) {
			if (flag) {
				System.out.println();
			}
			Complex c1 = new Complex(sc.nextDouble(), sc.nextDouble());
			Complex c2 = new Complex(sc.nextDouble(), sc.nextDouble());
			System.out.println("(" + c1 + ") + (" + c2 + ") = " + c1.add(c2));
			System.out.println("(" + c1 + ") - (" + c2 + ") = " + c1.subtract(c2));
			System.out.println("(" + c1 + ") * (" + c2 + ") = " + c1.multiply(c2));
			System.out.println("(" + c1 + ") / (" + c2 + ") = " + c1.divide(c2));
			System.out.printf("|" + c1 + "| = %.4f\n", c1.abs());
			flag = true;
		}

		sc.close();
	}

}
