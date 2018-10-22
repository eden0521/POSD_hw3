#include <gtest/gtest.h>
#include <algorithm>
#include "../src/shape.h"
#include "../src/circle.h"
#include "../src/rectangle.h"
#include "../src/triangle.h"
#include "../src/sort.h"



TEST(ShapeTest, Sorting)
{
  vector<Shape*> shapes;
  vector<Shape*> shapesWithPerimeter;

  Shape *c10 = new Circle(10.0);
  Shape *t003004 = new Triangle(0, 0, 3, 0, 0, 4);
  Shape *r48 = new Rectangle(4,8);
  Shape *c5d25 = new Circle(5.25);
  Shape *t000680 = new Triangle(0, 0, 0, 6, 8, 0);

  shapes.push_back(c10);
  shapes.push_back(t003004);
  shapes.push_back(r48);
  shapes.push_back(c5d25);
  shapes.push_back(t000680);
  
  Sort *s = new Sort(&shapes);
  
  s->sortArea([](Shape *a, Shape *b){
    return a->area() < b->area();
  });
  ASSERT_NEAR(314.15, shapes[4]->area(), 0.01);
  ASSERT_NEAR(6, shapes[0]->area(), 0.01);
  ASSERT_NEAR(32, shapes[2]->area(), 0.01);
  ASSERT_NEAR(86.59, shapes[3]->area(), 0.01);
  ASSERT_NEAR(24, shapes[1]->area(), 0.01);

  s->sortPerimeter(perimeterAscendingComparison);
  ASSERT_NEAR(62.83, shapes[4]->perimeter(), 0.01);
  ASSERT_NEAR(12, shapes[0]->perimeter(), 0.01);
  ASSERT_NEAR(24, shapes[1]->perimeter(), 0.01);
  ASSERT_NEAR(32.979, shapes[3]->perimeter(), 0.01);
  ASSERT_NEAR(24, shapes[2]->perimeter(), 0.01);


  s->sortPerimeter(perimeterDescendingComparison);
  ASSERT_NEAR(62.83, shapes[0]->perimeter(), 0.01);
  ASSERT_NEAR(12, shapes[4]->perimeter(), 0.01);
  ASSERT_NEAR(24, shapes[3]->perimeter(), 0.01);
  ASSERT_NEAR(32.979, shapes[1]->perimeter(), 0.01);
  ASSERT_NEAR(24, shapes[2]->perimeter(), 0.01);
  
}