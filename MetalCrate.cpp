//Nick Condos
#include "MetalCrate.h"

MetalCrate::MetalCrate(int trackNumber, double cWeight, double cCost):Crate(trackNumber,
		cWeight, crateCost)
{
	trackingNum = trackNumber;
	crateWeight = cWeight;
	crateCost = 3.0 * crateWeight;

}

void MetalCrate::print(ostream& out) const
{
	out << "Package Type: Metal Crate"
				<< "\nTracking Number: " << trackingNum
				<< "\nWeight: " << crateWeight << endl;
}

ostream& operator<<(ostream& out, const MetalCrate& mc)
{
	out << "Package Type: Metal Crate"
				<< "\nTracking Number: " << mc.getTrackNum()
				<< "\nWeight: " << mc.getWeight() << endl;
	return out;
}

MetalCrate::~MetalCrate()
{
	//cout << "Destructing metal crate" << endl;
}




