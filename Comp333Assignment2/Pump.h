#include<iostream>
#include<cassert>
#include<iomanip>


// Sara McHattie 
// Assignment 2 - specification file

using namespace std;

class Pump // base class
{
private:
	int amtGas;
	int tankCapacity;
public:
	Pump();//default constructor 
	virtual ~Pump(); // virtual destructor deal with memory from virtual showPump data
	Pump(int /*amtGas*/, int /*tankCapacity*/); // non-default constructor 
	virtual void showPump(ostream& /*output file or console*/) const;
	void pumpGas(int /*antGas*/);
	int getCapacity() const { return tankCapacity; }
	int getAmtGas() const { return amtGas; }
};

class GasPump : public Pump
{
private:
	string* typeGas;
	double gasPrice;
public:
	GasPump(); // default constructor 
	GasPump(int /*amtGas*/, int /*tankCapacity*/, string /*typeGas*/, double /*gasPrice*/);
	~GasPump(); // destructor
	void showPump(ostream& /*file or console output*/) const;
	void buyGas(int /*amtGas*/);
	double getPrice() const { return gasPrice; }
	string getGasType() const { return *typeGas; }
};

class FillTank : public Pump
{
private:
public:
	FillTank(); // default constructor 
	FillTank(int /*amtGas*/, int /*tankCapacity*/);
	void addGas();
	void showPump(ostream& /*file or console output*/) const;
};
