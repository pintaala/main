#include "MathDLL.h"
#include "windows.h"

double Math::circle(double r) {
	
	return M_PI * r * r;
}

double Math::triangle(double a, double b) {

	return a * b / 2;
}

double Math::quadrangle(double a, double b) {

	return a * b;
}

// DLL entry function (called on load, unload, ...)
BOOL APIENTRY DllMain(HANDLE hModule, DWORD dwReason, LPVOID lpReserved)
{
    return TRUE;
}
