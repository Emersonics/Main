#ifndef MYVECTOR
#define MYVECTOR

namespace sample
{
	class MyVector
	{
	public:
		float x;
		float y;

		MyVector(float x, float y);
		float getMagnitude();
		MyVector getDirection(float magnitude);
	};
}

#endif //MYVECTOR
