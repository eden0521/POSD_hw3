#ifndef Triangle_H
#define Triangle_H

#include<math.h>
#include<string>
#include "shape.h"

using namespace std;


class Triangle: public Shape
{
public:
  Triangle(double x1, double y1, double x2, double y2, double x3, double y3):_x1(x1), _x2(x2), _x3(x3), _y1(y1), _y2(y2), _y3(y3)
  {
	if (line1 > 0 && line2 > 0 && line3 > 0 ){
		if (line1+line2>line3 && line2+line3>line1 && line2+line3>line1){
		}
		else
			throw std::string("Not a triangle.");
	}
	else	
		throw std::string("Not a triangle.");
  }
  
  double area() const
  { 
    
    return sqrt(s * (s - line1) * (s - line2) * (s - line3));
  }

  double perimeter() const
  { 
    return line1 + line2 + line3;
  }
  
  double compactness() const
  {
	if (sqrt(s * (s - line1) * (s - line2) * (s - line3)) == 0)
		throw string("Division by zero");
	else
		return ((line1 + line2 + line3) * (line1 + line2 + line3)) / (sqrt(s * (s - line1) * (s - line2) * (s - line3)));
  }

private:
  double _x1;
  double _x2;
  double _x3;
  double _y1;
  double _y2;
  double _y3;
  double line1 = sqrt((_x1-_x2)*(_x1-_x2) + (_y1-_y2)*(_y1-_y2));
  double line2 = sqrt((_x2-_x3)*(_x2-_x3) + (_y2-_y3)*(_y2-_y3));
  double line3 = sqrt((_x3-_x1)*(_x3-_x1) + (_y3-_y1)*(_y3-_y1)); 
  double s = (line1 + line2 + line3) / 2;
};

#endif