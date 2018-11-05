//Nick Condos
#include "Truck.h"

using namespace std;


Truck::Truck()
{
	driverName = "";
	origCity = "";
	destCity = "";

	pounds = 0;
	ounces = 0;
	unloadWeight = 0;
	shipCost = 0.0;
	packageCount = 0;
	//packages = {};
}

Truck::Truck(string driver, string orig, string dest, int unload)
{
	driverName = driver;
	origCity = orig;
	destCity = dest;
	unloadWeight = unload;

	pounds = 0;
	ounces = 0;
	shipCost = 0.0;
	packageCount = 0;
	//packages = {};
}

/*int Truck::getPackageSize() const
{
	return packages.size();
}*/


void Truck::setPounds(int g)
{
	pounds = pounds + g;
}

void Truck::setOunces(int o)
{
	ounces = ounces + o;
}

void Truck::setPackageCount(int c)
{
	packageCount = packageCount + c;
}

void Truck::setShipCost(double s)
{
	shipCost = shipCost + s;
}

ostream& operator<<(ostream& out, const Truck& t)
{
	out << "Driver name: " << t.getDriver()
			<< "\nUnloaded truck weight: " << t.getUnloaded()
			<< "\nSource city: " << t.getOrigCity()
			<< "\nDestination city: " << t.getDestCity()
			<< "\n"
			<< "PACKAGE LOADING INFORMATION: "
			<< "\n----------------------------" << endl;

	return out;

}

Truck Truck::truckPart1(ifstream &fin, ofstream &fout)
{
	if (!fin.is_open())
		cout << "Input file did not open" << endl;

	string driver;
	string weight;
	int weight1;
	string orig;
	string dest;

	int numbertrack;
	int weightpackage;

	getline(fin, driver);
	getline(fin, weight);
	weight1 = stoi(weight);
	getline(fin, orig);
	getline(fin, dest);

	Truck truckObject(driver, orig, dest, weight1);

	fout << "Driver name: " << truckObject.getDriver()
					<< "\nUnloaded truck weight: " << truckObject.getUnloaded()
					<< "\nSource city: " << truckObject.getOrigCity()
					<< "\nDestination city: " << truckObject.getDestCity()
					<< "\nPACKAGE LOADING INFORMATION: "
					<< "\n----------------------------\n" << endl;

	bool yesNo;
	int i = 0;
	while (!fin.eof())
	{
		fin >> numbertrack;
		fin >> weightpackage;

		yesNo = loadTruck(numbertrack, weightpackage, i, fout);
		if (yesNo == true)
			i++;
	}

	totalWeight(fout, truckObject);
	truckPart2(fout, truckObject);

	return truckObject;
}

void Truck::totalWeight(ofstream &fout, const Truck& t)
{
	int convert = ounces / 16;
	int extra = ounces % 16;
	pounds += convert;

	fout << "LOADED TRUCK WEIGHT: " << pounds + t.getUnloaded() << " pounds, " << extra << " ounces" << endl;

}

void Truck::truckPart2(ofstream &fout, const Truck& t) //Deallocate memory for packages here
{
	fout << "\nDRIVING TRUCK FROM " << t.getOrigCity() << " TO "
			<< t.getDestCity() << "...\n"
			<< "ARRIVED AT " << t.getDestCity()
			<< "\nPACKAGE UNLOADING INFORMATION:"
			<< "\n------------------------------\n" << endl;

	for (int i = 0; i < packageCount; i++)
	{
		fout << *packages[i] << endl;
		//Package* stuff = packages[i];
		//stuff->print(cout);
		//cout << endl;
		delete packages[i];
	}
	delete [] packages;

	fout << "FINAL TRUCK INFORMATION"
		 << "\n-----------------------"
		 << "\nPackages Delivered: " << packageCount
		 << "\nTotal cost: $" << shipCost << endl;



}

bool Truck::loadTruck(int numbertrack, int weightpackage, int i, ofstream &fout)
{


	if (numbertrack % 10 == 0 && weightpackage <= 32) {
		packages[i] = new Letter(numbertrack, weightpackage, .05);
		fout << *packages[i]
			 << "LOADED\n" << endl;
		setShipCost(weightpackage * .05);
		setOunces(weightpackage);
		setPackageCount(1);
		return true;
	}
	else if (numbertrack % 10 == 1 && weightpackage <= 40) {
		packages[i] = new Box(numbertrack, weightpackage, 2.0);
		fout << *packages[i]
			 << "LOADED\n" << endl;
		setShipCost(weightpackage * 2.0);
		setPounds(weightpackage);
		setPackageCount(1);
		return true;
	}
	else if (numbertrack % 10 == 2 && weightpackage <= 80) {
		packages[i] = new WoodenCrate(numbertrack, weightpackage, 2.5);
		fout << *packages[i]
			 << "LOADED\n" << endl;
		setShipCost(weightpackage * 2.5);
		setPounds(weightpackage);
		setPackageCount(1);
		return true;
	}
	else if (numbertrack % 10 == 3 && weightpackage <= 100) {
		packages[i] = new MetalCrate(numbertrack, weightpackage, 3.0);
		fout << *packages[i]
			 << "LOADED\n" << endl;
		setShipCost(weightpackage * 3.0);
		setPounds(weightpackage);
		setPackageCount(1);
		return true;
	}
	else {
		try
		{
			Package *pptr;
			if (numbertrack % 10 == 0) {
				pptr = new Letter(numbertrack, weightpackage, .05);
				fout << *pptr;
			}
			else if (numbertrack % 10 == 1){
				pptr = new Box(numbertrack, weightpackage, 2.0);
				fout << *pptr;
			}
			else if (numbertrack % 10 == 2){
				pptr = new WoodenCrate(numbertrack, weightpackage, 2.5);
				fout << *pptr;
			}
			else if (numbertrack % 10 == 3){
				pptr = new MetalCrate(numbertrack, weightpackage, 3.0);
				fout << *pptr;
			}
			else {
				fout << "Package Type: Unknown"
					<< "\nTracking Number: " << numbertrack
					<< "\nWeight: " << weightpackage << endl;

			}

			throw new PackageException(numbertrack, weightpackage);
			delete pptr;

		}
		catch (PackageException *pe)
		{
			fout << pe->getError() << endl;
			delete pe;
		}
		return false;
	}
	return false;
}









