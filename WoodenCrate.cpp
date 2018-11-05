//Nick Condos
#include "WoodenCrate.h"

WoodenCrate::WoodenCrate(int trackNumber, double cWeight, double cCost):Crate(trackNumber,
		cWeight, crateCost)
{
	trackingNum = trackNumber;
	crateWeight = cWeight;
	crateCost = 2.5 * crateWeight;

}

void WoodenCrate::print(ostream& out) const
{
	out << "Package Type: Box"
			<< "\nTracking Number: " << trackingNum
			<< "\nWeight: " << crateWeight << endl;
}

ostream& operator<<(ostream& out, const WoodenCrate& wc)
{
	out << "Package Type: Wooden Crate"
				<< "\nTracking Number: " << wc.getTrackNum()
				<< "\nWeight: " << wc.getWeight() << endl;
	return out;
}

WoodenCrate::~WoodenCrate()
{
	//cout << "Destructing wooden crate" << endl;
}




