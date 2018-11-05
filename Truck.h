//Nick Condos
#ifndef TRUCK_H_
#define TRUCK_H_

#include <iostream>
#include <string>
#include <fstream>
#include "Package.h"
#include "WoodenCrate.h"
#include "MetalCrate.h"
#include "Box.h"
#include "Letter.h"
#include "PackageException.h"

using namespace std;

class Truck
{


	private:

	Package** packages = new Package*[500];
	string driverName;
	string origCity;
	string destCity;
	int pounds;
	int ounces;
	int unloadWeight;
	double shipCost;
	int packageCount;


	public:

	Truck();
	Truck(string driver, string orig, string dest, int unload);

	//Getters
	int getPackageSize() const;
	string getDriver() const { return driverName; }
	string getOrigCity() const { return origCity; }
	string getDestCity() const { return destCity; }
	int getPounds() const { return pounds; }
	int getUnloaded() const { return unloadWeight; }
	double getShipCost() const { return shipCost; }

	//Setters
	void setDriver(string d);
	void setOrigCity(string orig);
	void setDestCity(string dest);
	void setPounds(int g);
	void setUnloaded(int u);
	void setShipCost(double s);
	void setOunces(int o);
	void setPackageCount(int c);


	Truck truckPart1(ifstream &fin, ofstream &fout);
	bool loadTruck(int numbertrack, int weightpackage, int i, ofstream& fout);
	void truckPart2(ofstream &fout, const Truck& t);
	void totalWeight(ofstream &fout, const Truck& t);



};

ostream& operator<<(ostream& out, const Truck& t);

#endif
