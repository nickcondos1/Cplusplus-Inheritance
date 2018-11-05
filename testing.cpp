//Nick Condos
//Compiled with g++ and visual studios 2017


#include <iostream>
#include "Truck.h"

using namespace std;

int main()
{
	ifstream fin("manifest.txt");
	ofstream fout("log.txt", fstream::app);

	Truck ok;

	ok = ok.truckPart1(fin, fout); //Calling this function will call all other necessary functions
	fin.close();
	fout.close();
	//cout << ok << endl;

	return 0;
}




