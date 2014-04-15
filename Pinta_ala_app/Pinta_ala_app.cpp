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
void helppari();

int main(int argc, char *argv[])
{	
	if ( argc < 2 || argc > 5 ) {
		helppari();
		return 0;
	}

	callRegistryKey();
	
	string shape;

	char* shape_a = argv[1];
	string radius_s = ""; 
	string sideA_s = "";
	string sideB_s = "";

	double radius = 0;
	double sideA = 0;
	double sideB = 0;
	double result = 0;

	switch ( shape_a[1] ) {
	case 'c':
		shape = circle;
		radius_s = argv[2];
		radius = atof(radius_s.c_str());
		result = Math::circle(radius);
		break;
	case 't':
		shape = triangle;
		sideA_s = argv[2];
		sideB_s = argv[3];
		sideA = atof(sideA_s.c_str());
		sideB = atof(sideB_s.c_str());
		result = Math::triangle(sideA,sideB);
		break;
	case 'q':
		shape = quadrangle;
		sideA_s = argv[2];
		sideB_s = argv[3];
		sideA = atof(sideA_s.c_str());
		sideB = atof(sideB_s.c_str());
		result = Math::quadrangle(sideA,sideB);
		break;
	default:
		break;
	}

	cout << shape << resultText << result << endl;

	return 0;
}


void callRegistryKey() {
	HKEY hKey;
	LPCWSTR sKey = L"SOFTWARE\\Pinta_Ala";
	//RegOpenKeyEx(HKEY_LOCAL_MACHINE,sKey,0,KEY_QUERY_VALUE, &hKey );
	long error = RegOpenKeyEx(HKEY_CURRENT_USER,sKey,0,KEY_ALL_ACCESS, &hKey );

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

void helppari() {
	cout << helpText;
}

//void Triangle