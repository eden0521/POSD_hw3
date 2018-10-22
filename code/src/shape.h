#ifndef Shape_H
#define Shape_H

class Shape
{
public:
  virtual double area() const = 0;
  virtual double perimeter() const = 0;
  virtual double compactness() const = 0;
};


#endif