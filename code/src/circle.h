#ifndef Circle_H
#define Circle_H

#include <math.h>
#include <string>
#include "shape.h"

using namespace std;

class Circle: public Shape
{
public:
  Circle(double r):_r(r)
  {

  }

  double area() const
  {
    return M_PI * _r * _r;
  }

  double perimeter() const
  {
    return 2 * M_PI * _r;
  }
  
  double compactness() const
  {
	if (M_PI * _r * _r == 0)
		throw std::string("Division by zero");
	else
		return (2 * M_PI * _r * 2 * M_PI * _r) / (M_PI * _r * _r);
  }
  
private:
  double _r;
};

#endif