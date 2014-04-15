#include "MathDLL.h"

namespace MyMath {

	double Math::circle(double r) {
		
		return M_PI * r * r;
	}

	double Math::triangle(double a, double b) {
	
		return a * b / 2;
	}

	double Math::quadrangle(double a, double b) {
	
		return a * b;
	}
}
