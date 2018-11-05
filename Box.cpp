//Nick Condos
#include "Box.h"

using namespace std;

Box::Box(int trackNumber, double bWeight, double bCost):Package(trackNumber,
		bWeight)
{
	trackingNum = trackNumber;
	boxWeight = bWeight;
	boxCost = bCost * boxWeight;

}

void Box::print(ostream& out) const
{
	out << "Package Type: Box"
			<< "\nTracking Number: " << trackingNum
			<< "\nWeight: " << boxWeight << endl;

}

ostream& operator<<(ostream& out, const Box& b)
{
	out << "Package Type: Box"
				<< "\nTracking Number: " << b.getTrackNum()
				<< "\nWeight: " << b.getWeight() << endl;
	return out;
}

Box::~Box()
{
	//cout << "Destructing Box" << endl;
}





