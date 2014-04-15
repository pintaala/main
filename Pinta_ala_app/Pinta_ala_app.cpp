#include <stdio.h>
#include <tchar.h>
#include <string>
#include <iostream>
#include <stdlib.h>
#include <Windows.h>
#include <sstream>
#include "../DLLMath/MathDLL.h"
#include <time.h>

using namespace std;
using namespace MyMath;

#define LANG FI

#if LANG == FI
	#include "Lang_fi.h"
#else
	#include "Lang_en.h"
#endif

void callRegistryKey();
double CheckDigit (int param_count, char* height, char* width, string shape);

int main(int argc, char *argv[])
{	
	if ( argc < 2 || argc > 5 ) {
		cout << helpText;
		return 0;
	}

	callRegistryKey();
	
	string shape;

	char* shape_a = argv[1];
	double result = 0;

	switch ( shape_a[1] ) {
	case 'c':
		shape = circle;
		argv[3] = "0";
		result = CheckDigit(argc, argv[2],argv[3],shape);
		break;
	case 't':
		shape = triangle;
		result = CheckDigit(argc, argv[2],argv[3],shape);
		break;
	case 'q':
		shape = quadrangle;
		result = CheckDigit(argc, argv[2],argv[3],shape);
		break;
	default:
		break;
	}

	cout << shape << resultText << result << endl;

	return 0;
}

/**  
* This function opens the registry key and reads and writes the last time the software were opened
*/
void callRegistryKey() {
	HKEY hKey;
	LPCWSTR sKey = L"SOFTWARE\\Pinta_Ala";
	
	long error = RegOpenKeyEx(HKEY_CURRENT_USER,sKey,0,KEY_ALL_ACCESS, &hKey );

	// if registry key is not found, we create it
	if(error = ERROR_FILE_NOT_FOUND) {
		RegCreateKeyEx(HKEY_CURRENT_USER,sKey,0,NULL,REG_OPTION_NON_VOLATILE,KEY_ALL_ACCESS,NULL,&hKey,NULL);
	}

	DWORD lpcbData;
	BYTE Data[sizeof(DWORD)]; 
	DWORD type = REG_DWORD;
	char val[1024] = {0};
	DWORD val1;
	
	char date[30] = {0};
	_strdate_s(date);
	DWORD bufSize = sizeof(date);


	if( RegQueryValueEx(hKey,L"stringValue",0,&type,(LPBYTE)val,&lpcbData) == ERROR_SUCCESS) { // handle error 
		
		cout << endl << lastOpen << val << endl << endl;
	}

	RegSetValueEx(hKey,L"stringValue",0,REG_SZ,(PBYTE)&date,bufSize); 

	RegCloseKey(hKey);
}

/**  
* This function calculates the area of the shape큦
* @param paramCount parameters amount
* @param height shape큦 height
* @param width shape큦 width
* @param shape which kind of shape it is
* @return result the shape큦 calculated area
*/
double CheckDigit (int paramCount, char* height, char* width, string shape) {
	double sideA = 0;
	double sideB = 0;
	double result = 0;

	string sideA_s = "";
	string sideB_s = "";

	sideA_s = height;
	sideB_s = width;

	for(int i = 0; i < sideA_s.length(); i++) {
		if( !isdigit( sideA_s.at(i) ) ) {
			cout << warningText << endl;
			return 1;
		}
	}
	if(paramCount == 4) {
		for(int i = 0; i < sideB_s.length(); i++) {
			if( !isdigit( sideB_s.at(i) ) ) {
				cout << warningText << endl;
				return 1;
			}
		}
	
		sideA = atof(sideA_s.c_str());
		sideB = atof(sideB_s.c_str());

		if(shape == "Triangle" || shape == "Kolmion" ) {
			result = Math::triangle(sideA,sideB);
		}
		else {
			result = Math::quadrangle(sideA,sideB);
		}
	}

	else if(paramCount == 3){
		sideA = atof(sideA_s.c_str());
		result = Math::circle(sideA);
	}
	
	return result;
}