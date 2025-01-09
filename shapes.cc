#include <iostream>
#include <vector>
#include <algorithm>

const double kPi = 3.1415926535897932;

class Shape {
  public:
    Shape(double area, const std::string& graphic) 
      : area_{area}, graphic_{graphic} {}
    double GetArea() const { return area_; }
    const std::string& GetGraphic() const { return graphic_; }
  private:
    double area_;
    std::string graphic_;
};

class Square : public Shape {
  public:
    Square (double side) : Shape{side * side, "[]"} {}
};

class Circle : public Shape {
  public:
    Circle (double radius) 
      : Shape{kPi * radius * radius, "()"} {}
};

class Triangle : public Shape {
  public:
    Triangle (double base, double height)
      : Shape{base * height / 2, "/\\"} {}
};

std::ostream& operator<<(std::ostream& output, const Shape& shape);
bool operator<(const Shape& shape1, const Shape& shape2);

int main(int argc, char const** argv) {
  std::vector<Shape> shapes{Square{1.0}, Circle{0.5}, Triangle{1, 1}, Triangle{2, 2}};
  std::sort(shapes.begin(), shapes.end());
  for (const auto& shape : shapes) {
    std::cout << shape << ", ";
  }
  std::cout << std::endl;
  return 0;
}

std::ostream& operator<<(std::ostream& output, const Shape& shape) {
  output << shape.GetGraphic() << shape.GetArea();
  return output;
}

bool operator<(const Shape& shape1, const Shape& shape2) {
  return shape1.GetArea() < shape2.GetArea();
}