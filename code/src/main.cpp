#include<iostream>
#include<fstream>
#include<fstream>
#include <cstdlib>

#include "shape.h"
#include "circle.h"
#include "rectangle.h"
#include "triangle.h"
#include "sort.h"

using namespace std;


int main(int argc, char *argv[]){
    
	string C;
	string R1, R2;
	string T1, T2, T3, T4, T5, T6;
	
	double Cir;
	double Rect1, Rect2;
	double Tri1, Tri2, Tri3, Tri4, Tri5, Tri6;
	
	int i=0, j=0;
	char line[500];
	ifstream fin;
	ofstream fout;
    fin.open(argv[1]);
	fout.open(argv[2]);
	
	vector<Shape*> shapes;
	
	
    while(fin.getline(line,sizeof(line),'\n')){
        if (line[0] == 'C'){
			i = 8;
			j = 0;
			while (line[i] != ')'){
				C[j] = line[i];
				i++;
				j++;
			}
			Cir = atof(C.c_str());
			Shape *shape = new Circle(Cir);
			shapes.push_back(shape);
		}
		else if(line[0] == 'R'){
			i = 11;
			j = 0;
			while (line[i] != ','){
				R1[j] = line[i];
				i++;
				j++;
			}
			i ++;
			j = 0;
			while (line[i] != ')'){
				R2[j] = line[i];
				i++;
				j++;
			}
			Rect1 = atof(R1.c_str());
			Rect2 = atof(R2.c_str());
			Shape *shape = new Rectangle(Rect1, Rect2);
			shapes.push_back(shape);
		}
		else if(line[0] == 'T'){
			i = 10;
			j = 0;
			while (line[i] != ','){
				T1[j] = line[i];
				i++;
				j++;
			}
			i ++;
			j = 0;
			while (line[i] != ','){
				T2[j] = line[i];
				i++;
				j++;
			}
			i ++;
			j = 0;
			while (line[i] != ','){
				T3[j] = line[i];
				i++;
				j++;
			}
			i ++;
			j = 0;
			while (line[i] != ','){
				T4[j] = line[i];
				i++;
				j++;
			}
			i ++;
			j = 0;
			while (line[i] != ','){
				T5[j] = line[i];
				i++;
				j++;
			}
			i ++;
			j = 0;
			while (line[i] != ')'){
				T6[j] = line[i];
				i++;
				j++;
			}
			Tri1 = atof(T1.c_str());
			Tri2 = atof(T2.c_str());
			Tri3 = atof(T3.c_str());
			Tri4 = atof(T4.c_str());
			Tri5 = atof(T5.c_str());
			Tri6 = atof(T6.c_str());
			Shape *shape = new Triangle(Tri1, Tri2, Tri3, Tri4, Tri5, Tri6);
			shapes.push_back(shape);
		}
    }
	
	Sort *s = new Sort(&shapes);
	fin.close();
	
	if (argv[3][0] == 'a'){
		if (argv[4][0] == 'i'){
			s->sortArea([](Shape *a, Shape *b){
				return a->area() < b->area();
			});
			fout << "[";
			for (i=0 ; i < shapes.size()-1 ; i++ ){
				fout << shapes[i]->area() << ",";
			}
			fout << shapes[i]->area() << ']' << endl;
		}
		else if (argv[4][0] == 'd'){
			s->sortArea([](Shape *a, Shape *b){
				return a->area() > b->area();
			});
			fout << "[";
			for (i=0 ; i < shapes.size()-1 ; i++ ){
				fout << shapes[i]->area() << ",";
			}
			fout << shapes[i]->area() << ']' << endl;
		}
	}
	else if (argv[3][0] == 'p'){
		if (argv[4][0] == 'i'){
			s->sortPerimeter(perimeterAscendingComparison);
			fout << "[";
			for (i=0 ; i < shapes.size()-1 ; i++ ){
				fout << shapes[i]->perimeter() << ",";
			}
			fout << shapes[i]->perimeter() << ']' << endl;
		
		}
		else if (argv[4][0] == 'd'){
			s->sortPerimeter(perimeterDescendingComparison);
			fout << "[";
			for (i=0 ; i < shapes.size()-1 ; i++ ){
				fout << shapes[i]->perimeter() << ",";
			}
			fout << shapes[i]->perimeter() << ']' << endl;
		}
	}
	
	fout.close();
	return 0;  
}


