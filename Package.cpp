//Nick Condos
#include "Package.h"

using namespace std;

Package::Package()
{
	trackingNum = 0;
	weight = 0.0;
	shipcost = 0.0;
	type = "";
}

Package::Package(int trackNumber, double packWeight)
{
	trackingNum = trackNumber;
	weight = packWeight;

	if (trackNumber % 10 == 0) {
		shipcost = .05 * packWeight;
		type = "Letter";
	}
	else if (trackNumber % 10 == 1) {
		shipcost = 2.0 * packWeight;
		type = "Box";
	}
	else if (trackNumber % 10 == 2) {
		shipcost = 2.5 * packWeight;
		type = "Wooden Crate";
	}
	else if (trackNumber % 10 == 3) {
		shipcost = 3.0 * packWeight;
		type = "Metal Crate";
	}
	else {
		shipcost = 0;
		type = "unknown";
	}
}

Package::~Package()
{
	//cout << "Package Destructor deleting: " << type << endl;
}

void Package::setTrackingNum(int num)
{
	trackingNum = num;
}
void Package::setWeight(double w)
{
	weight = w;
}
void Package::setShipCost(double cost)
{
	shipcost = cost;
}
ostream& operator<<(ostream& out, const Package& p)
{
	out << "Package Type: " << p.getType()
			<< "\nTracking Number: " << p.getTrackingNum() << endl;

	if (p.getType() == "Letter"){
		out << "Package Weight: " << p.getWeight() << " ounces" << endl;
	}
	else {
		out << "Package Weight: " << p.getWeight() << " pounds" << endl;
	}

	return out;
}

void Package::print(ostream& out) const
{
	cout << *this << endl;
}

void Package::print1(fstream& fout) const
{
	fout << *this << endl;
}



