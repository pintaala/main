#ifndef M_PI
	#define M_PI 3.1415926535897932384626433832795028841971693993751058209749445923078164062862089986280348253421170679
#endif

/**
	Math class for mathematic functions
*/
class Math {

	public:
		/**  
		* This function calculates the area of circle
		* @param r is radius of circle and it's double
		* @return area of circle which is double
		*/
		static __declspec(dllexport) double circle(double r);

		/**  
		* This function calculates the area of triangle
		* @param a is height and it's double
		* @param b is width and it's double
		* @return area of triangle which is double
		*/
		static __declspec(dllexport) double triangle(double a, double b);

		/**  
		* This function calculates the area of quadrangle
		* @param a is height and it's double
		* @param b is width and it's double
		* @return area of quadrangle which is double
		*/
		static __declspec(dllexport) double quadrangle(double a, double b);
};
