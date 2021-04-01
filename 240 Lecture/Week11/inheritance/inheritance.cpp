//Single level inheritance Vehicle, Car
//Multi-level Vehicle, Car, Tesla
//Multiple inheritance Vehicle, FourWheels, Car
//Multi-Path Graphic, Barchart (graphic), LineChart (graphic), HybridChart (bar,line)
//    class scope resolution LineChart::res
//    virtual base class (variables shared between base classes) : virtual public Graphic
//Revisit function overriding... now with polymorphism
#include <cstdlib> 
#include <iostream> 

using namespace std;

class Vehicle {
	public: 
		Vehicle() {
			numberWheels = 0;
		}
		void print(){
			cout << "Number of Wheels: " << numberWheels << endl;
		}
		
	protected: 
		void setNumberWheels(int nw){
			numberWheels = nw;
		} 
		int getNumberWheels(){
			return numberWheels;
		}
	//private:
	//protected: 
		int numberWheels;
};
class electricPowered {
	public : 
		electricPowered(){
			kiloHrs = 0.0;
		}
	protected : 
		float kiloHrs;
};
class Car : public Vehicle, public electricPowered {
	public : 
		Car() {
			setNumberWheels(4); 
			mpg = 20.0;
		}
		void print(){
			cout << "Number of Wheels: " << getNumberWheels() << endl;
			cout << "MPG: " << mpg << endl;
			cout << "Kilowatt Hours: " << kiloHrs << endl;
		}
		//override the setNumberWheels to error check?
	protected:
		void setNumberWheels(int nw) {
			numberWheels = 4;
		}
	private : 
		float mpg;
};

int main(int argc, char** argv) 
{
	Car tesla; 
	tesla.print();
	return 0;
}
