//Nick Condos
#include "Crate.h"

using namespace std;

Crate::Crate(int trackNumber, double cWeight, double cCost):Package(trackNumber,
		cWeight)
{
	trackingNum = trackNumber;
	crateWeight = cWeight;

		if (trackNumber % 10 == 2) {
			crateCost = 2.5 * cWeight;
			type = "Wooden Crate";
		}
		else if (trackNumber % 10 == 3) {
			crateCost = 3.0 * cWeight;
			type = "Metal Crate";
		}
		else
			type = "unknown";

}

void Crate::print(ostream& out) const
{
	out << "Tracking Number: " << trackingNum
			<< "\nCrate Weight: " << crateWeight
			<< "\nCrate Cost: " << crateCost
			<< "\nCrate Type: " << type << "\n" << endl;
}

ostream& operator<<(ostream& out, const Crate& c)
{
	out << "Tracking Number: " << c.getTrackNum()
			<< "\nCrate Weight: " << c.getWeight()
			<< "\nCrate Cost: " << c.getCost()
			<< "\nCrate Type: "<< c.getType() << endl;

	return out;
}

Crate::~Crate()
{
	//cout << "Destructing Crate" << endl;
}




