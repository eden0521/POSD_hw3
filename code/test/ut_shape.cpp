#include <gtest/gtest.h>
#include "../src/shape.h"
#include "../src/circle.h"
#include "../src/rectangle.h"
#include "../src/triangle.h"

#include <algorithm>

using std::string;


TEST (ShapeTest, first)
{
  ASSERT_TRUE(true);
}

TEST (ShapeTest, Circle)
{
  Circle c(10.0);
  Circle cc(0.0);
  ASSERT_NEAR(314.159, c.area(), 0.001);
  ASSERT_NEAR(62.831, c.perimeter(), 0.001);
  ASSERT_NEAR(12.566, c.compactness(), 0.001);
  ASSERT_THROW(cc.compactness(), string);
}

TEST (ShapeTest, Rectangle)
{
  Rectangle r(3, 4);
  Rectangle rr(3, 0);
  ASSERT_NEAR(12, r.area(), 0.001);
  ASSERT_NEAR(14, r.perimeter(), 0.001);
  ASSERT_NEAR(16.333, r.compactness(), 0.001);
  ASSERT_THROW(rr.compactness(), string);
}

//TEST (ShapeTest, Triangle)
//{
  //Triangle t(1, 1, 4, 1, 1, 5);
  //Triangle tt(1, 1, 1, 1, 1, 5);
  //ASSERT_NEAR(6, t.area(), 0.001);
  //ASSERT_NEAR(12, t.perimeter(), 0.001);
  //ASSERT_NEAR(24, t.compactness(), 0.001);
  //ASSERT_THROW(tt.compactness(), string);
//}