//Nick Condos
#include "Letter.h"

using namespace std;

Letter::Letter(int trackNumber, double lWeight, double lCost):Package(trackNumber,
		lWeight)
{
	trackingNum = trackNumber;
	letterWeight = lWeight;
	letterCost = lCost * letterWeight;

}

void Letter::print(ostream& out) const
{
	out << "Package Type: Letter"
				<< "\nTracking Number: " << trackingNum
				<< "\nWeight: " << letterWeight << endl;

}

ostream& operator<<(ostream& out, const Letter& l)
{
	out << "Package Type: Letter"
					<< "\nTracking Number: " << l.getTrackNum()
					<< "\nWeight: " << l.getWeight() << endl;
	return out;
}

Letter::~Letter()
{
	//cout << "Destructing letter" << endl;
}



