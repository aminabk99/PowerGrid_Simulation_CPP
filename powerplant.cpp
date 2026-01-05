#include <iostream>
#include <string>
#include <iomanip> // for std, we do not need to write std before every line
using namespace std;
// PowerPlant class and definition
class PowerPlant {
private:
string plantName;
double capacityMW;
public:
// Constructor with initial values
PowerPlant(string name = "Default Plant", double capacity = 100.0)
: plantName(name), capacityMW(capacity) {}
// Display function
void display() const {
cout << "Plant: " << plantName << ". Capacity: "
<< fixed << setprecision(2) << capacityMW << " MW" << endl;
}
};
int main() {
// Default constructor displaying default values
PowerPlant plant1;
plant1.display();
//Constructor
PowerPlant plant2("HydroDam", 500.0);
plant2.display();
// Dynamically allocated PowerPlant
PowerPlant* pPlant = new PowerPlant("TexasSun", 300.0);
pPlant->display();
// Deallocating memory to avoid memory leak from occuring
delete pPlant;
// Pointer is reassigned to already existing stack object
pPlant = &plant1;
pPlant->display();
return 0;
}
