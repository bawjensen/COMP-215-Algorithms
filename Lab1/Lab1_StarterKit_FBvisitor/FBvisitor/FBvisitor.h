#ifndef FB
#define FB

#include <string>

using namespace std;

class FBvisitor {
public:
	// CTORs - Constructors
	FBvisitor();
	FBvisitor(string, string);
	FBvisitor(string, string, string, string, short, float);
	
	// DTOR - Destructors
	~FBvisitor();
	
	string getFullName() const;
	string getFirstName() const;
	string getLastName() const;
	string getPoliticalView() const;
	string getGender() const;
	short getAge() const;
	float getGPA() const;

	void setFirstName(string);
	void setLastName(string);
	void setPoliticalView(string);
	void setGender(string);
	void setAge(short);
	void setGPA(float);
	
	// overloaded operators, here defined if hold same data (see .cpp)
	bool operator==(const FBvisitor& F);
	
	friend ostream& operator<<(ostream& fout, const FBvisitor& who);

	void makeMeRandom();

private:
		string     firstName;
		string     lastName;
		string     politicalView;
		string     gender;
		short      age;
		float      GPA;
		
}; // FBvisitor

#endif