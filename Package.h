//Nick Condos
#ifndef PACKAGE_H_
#define PACKAGE_H_

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

class Package
{
	friend ostream& operator<<(ostream& out, const Package& p);

	private:

	int trackingNum;
	double weight;
	double shipcost;
	string type;

	public:

	Package();
	Package(int trackNumber, double packWeight);

	virtual ~Package();
	virtual void print(ostream& out=cout) const = 0;
	void print1(fstream& fout) const;

	int getTrackingNum() const { return trackingNum; }
	double getWeight() const { return weight; }
	double getShipCost() const { return shipcost; }
	string getType() const { return type; }

	void setTrackingNum(int num);
	void setWeight(double w);
	void setShipCost(double cost);

	string typeofPackage(int trackingNumber);


};



#endif /* PACKAGE_H_ */
