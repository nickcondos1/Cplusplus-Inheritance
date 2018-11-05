//Nick Condos
#include "PackageException.h"


PackageException::PackageException(int trackNumber, int weight)
{
	if (trackNumber % 10 > 3)
		setError("NOT LOADED: UNKNOWN PACKAGE TYPE\n");
	else
		setError("NOT LOADED: TOO HEAVY\n");

}

void PackageException::setError(string s)
{
	error = s;
}

PackageException::~PackageException()
{
	//cout << "Destroying PackageException..." << endl;
}




