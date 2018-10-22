#ifndef Rectangle_H
#define Rectangle_H

#include <string>
#include "shape.h"

using namespace std;

class Rectangle: public Shape
{
public:
  Rectangle(double l, double w):_l(l), _w(w)
  {

  }

  double area() const
  {
    return _l * _w;
  }

  double perimeter() const
  {
    return 2 * (_l + _w);
  }
  
  double compactness() const
  {
	if (_l * _w == 0)
		throw string("Division by zero");
	else
		return (2 * (_l + _w) * 2 * (_l + _w)) / (_l * _w);
  }

private:
  double _l;
  double _w;
};

#endif