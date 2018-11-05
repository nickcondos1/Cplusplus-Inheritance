//Nick Condos
#ifndef PACKAGEEXCEPTION_H_
#define PACKAGEEXCEPTION_H_

#include <exception>
#include <string>
#include <iostream>

using namespace std;

class PackageException : public exception
{
	private:
	string error;

	public:
	PackageException(int trackNumber, int weight);
	~PackageException();

	string getError() const { return error; }
	void setError(string s);

};




#endif /* PACKAGEEXCEPTION_H_ */
