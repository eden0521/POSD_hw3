#ifndef Sort_H
#define Sort_H

#include <algorithm>
#include <vector>

using namespace std;

class Sort{
    public:
      Sort(std::vector<Shape*>* v): _v(v){}

      // The argument ** Accept comparison ** can accept lambda, function, and object]
	  template <typename comparearea>
      void sortArea(comparearea sortA){ //use lambda
		  std::sort(_v->begin(), _v->end(), sortA);
		  
	  }

      void sortPerimeter(bool (&sortP)(Shape *a, Shape *b)){ //use function
		  std::sort(_v->begin(), _v->end(), sortP);
	  }
	  template<class comparecompact>
      void sortCompactness(comparecompact sortC){ //use object
		  std::sort(_v->begin(), _v->end(), sortC);
	  }

    private:
      std::vector<Shape*>* _v;
};

//You should implement area ascending and descending lamda function as parameter for Sort::sortArea()

//You should use those "functions" as parameter for Sort::sortPerimeter()
bool perimeterDescendingComparison(Shape *a, Shape *b) { 
	return a->perimeter() > b->perimeter();
}

bool perimeterAscendingComparison(Shape *a, Shape *b) {
	return a->perimeter() < b->perimeter(); 
}

//You should use those "objects" as parameter for Sort::sortCompactness()
class CompactnessAscendingComparison{
	public:
	  bool operator() (Shape *a, Shape *b){
		return  a->compactness() < b->compactness(); 
	  }
};

class CompactnessDescendingComparison{
	public:
	  bool operator() (Shape *a, Shape *b){
		return  a->compactness() > b->compactness(); 
	  }
};


#endif