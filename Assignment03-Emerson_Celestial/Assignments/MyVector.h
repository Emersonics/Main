#ifndef MYVECTOR
#define MYVECTOR
#include <iostream>
#include <math.h>
using namespace std;

namespace sample //containier
{
	class MyVector
	{
	public:  //vector's components
		float x;
		float y;
		float z;

	public:
		MyVector(float x, float y, float z); //only called once, when an object is created
		float getMagnitude();
		MyVector getDirection(float magnitude);

		//HW03
		sample::MyVector operator+(sample::MyVector& vec); //this is for vector addition
		sample::MyVector operator-(sample::MyVector& vec); //this is for vector subtraction
		sample::MyVector operator*(const float scalar); //this is for scalar multiple
		sample::MyVector getComponentProduct(sample::MyVector& vec1, sample::MyVector& vec2); //this is for ComponentProduct
		float getScalarProduct(sample::MyVector& vec1, sample::MyVector& vec2); //this is for ScalarProduct
		sample::MyVector getVectorProduct(sample::MyVector& vec1, sample::MyVector& vec2); //this is for VectorProduct
	};

}

#endif //MYVECTOR
