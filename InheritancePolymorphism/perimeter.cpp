class Figure {
  public:
	virtual int Perimeter() const { return 0; }
	virtual ~Figure() {}
};
class Triangle : public Figure {
  private:
	int a, b, c;

  public:
	Triangle(int a_, int b_, int c_) {
		a = a_;
		b = b_;
		c = c_;
	}
	int Perimeter() const { return a + b + c; }
};

class Rectangle : public Figure {
  private:
	int a, b;

  public:
	Rectangle(int a_, int b_) {
		a = a_;
		b = b_;
	}
	int Perimeter() const { return (a + b) * 2; }
};