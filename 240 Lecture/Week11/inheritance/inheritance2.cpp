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

class Graphics{
	
	public : 
		Graphics(){
			resolution = new int;
			*resolution = 0;
		}
		//~ Graphics(int res)
		//~ {
			//~ resolution = res;
		//~ }
		virtual void print() = 0; 
		
		void operator=(Graphics& _obj2) 
		{
			*resolution = *(_obj2.resolution);
		}
		~Graphics()
		{
			cout << "Graphics destructor" << endl;
			delete resolution;
		}
		int* resolution;
};
class BarChart : virtual public Graphics {
	public : 
		BarChart() {
			numBars = 10;
		}
		void operator=(BarChart& _obj2) 
		{
			Graphics::operator =(_obj2);
			numBars = _obj2.numBars;
		}
		void print() override {
			cout << "Barchart" << endl; 
		}
		int numBars; 
};

class LineChart : virtual public Graphics {
	public : 
		LineChart() {
			numPoints = 50;
		}
		void print(){
			cout << "LineChart" << endl;
		}
		~LineChart()
		{
		}
		int numPoints; 
};

class BarLineChart : public LineChart, public BarChart{
	public: 
		BarLineChart() {
		}
		void print(){
			cout << "LineBar" << endl;
		}
};

//~ void fun(Graphics * g){
	
//~ }

int main(int argc, char** argv) 
{
	//~ BarLineChart b; 
	//~ //cout << b.LineChart::resolution << endl;
	//~ cout << b.resolution << endl; 
	//~ cout << b.numPoints << endl; 
	//~ cout << b.numBars << endl;
	
	//~ Graphics * g = new LineChart; 
	//~ g->print();
	
	Graphics* g; 
	BarChart b;
	
	g = &b; 
	g->numBars;
	
	
	//delete g;
	return 0;
}
