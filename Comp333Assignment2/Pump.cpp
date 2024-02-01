#include"Pump.h"

// Sara McHattie
// Assignment 2 - Implenentation file

// Non-default constructors
Pump::Pump(int initAmtGas, int initTankCapacity)
{
	amtGas = (initAmtGas > 0) ? initAmtGas : 0;
	tankCapacity = (initTankCapacity > 0) ? initTankCapacity : 0;
}

GasPump::GasPump(int newAmtGas, int newTankCapacity, string newTypeGas, double newGasPrice)
	: Pump(newAmtGas, newTankCapacity)
{

	typeGas = new string(
		(newTypeGas.length() == 0) ? "No gas type provided" : newTypeGas);

	assert(typeGas != 0);

	gasPrice = (newGasPrice > 0) ? newGasPrice : 0;
}

FillTank::FillTank(int newAmtGas, int newTankCapacity) 
	: Pump(newAmtGas, newTankCapacity)
{
	// no additional members were declared for the fill take class,
	// the Pump constructor will take care of the 2 ints
}

// default constructors
Pump::Pump() 
{
	amtGas = 30;
	tankCapacity = 120;
}

GasPump::GasPump() 
{
	typeGas = new string("Premium");
	gasPrice = 1.98;
}

FillTank::FillTank()
{
	// empty since there are no added members in this class
}


// Remaining functions 
// Pump 

void Pump::showPump(ostream& out) const
{
	out << amtGas << endl;
	out << tankCapacity << endl;
}

/*
	1. declare newAmtGas
	2. subtract newAmtGas from tank capacity
	3. ensure newAmtGas is available in the tank 
	4. display amount pumped and amount remaining 
*/
void Pump::pumpGas(int newAmtGas)
{
	// ensureing that a non negative number was entered that is less than tankCapacity
	amtGas = (newAmtGas > 0 && newAmtGas <= tankCapacity) ? newAmtGas : 0;
	// subtract amtGas from what is in the tank
	tankCapacity -= amtGas;

	cout << "Amount of gas pumped:   " << amtGas << endl
		<< "Amount remaining in tank:   " << tankCapacity << endl;
}

Pump::~Pump()
{
	// deal with any alloccated memory used in showPumpPoly function
}



// Gaspump 
void GasPump::showPump(ostream& out) const
{
	Pump:: showPump(out);
	out << "\nGas type is " << *typeGas << " and the price is " << gasPrice << endl;
}

GasPump::~GasPump()
{
	delete typeGas;
}

/*
	1. validate the amount passed into the function - the amount must be available
	2. subtract amount bought from tank capacity
	3. if user requires more gas than in tank, only give remaining tank capacity, with message
	4. multiply amount pumped by gasPrice for totalCost
	5. display amount pumped, amount remaining in tank, and total price
*/
void GasPump::buyGas(int clientAmt)
{
	clientAmt = (clientAmt > 0) ? clientAmt : 0;
	int tankCapacity = getCapacity();
	
	// step 2 - 3
	if (clientAmt <= tankCapacity)
		tankCapacity -= clientAmt;
	else
	{
		clientAmt = tankCapacity;
		tankCapacity = 0;
		cout << "There is only " << clientAmt << " left in tank" << endl;
	}

	// step 4
	double totalCost = clientAmt * gasPrice;

	// step 5
	cout << "Amount of purchased gas: " << clientAmt << endl
		<< "Amount remaining in tank: " << tankCapacity
		<< "Total price of gas: " << totalCost << endl << endl;

}

// FillTank 
/*
	1. call getCapacity and user added gas
	2. have user enter gas amount to be added to tank
	3. have the gas amt added to the tank to capacity use if else
*/
void FillTank::addGas()
{
	// step 1
	int tankCapacity, addedGas;
	tankCapacity = getCapacity();

	// step 2
	cout << "Enter amount of gas to be added to the tank or hit ctr z to exit: ";
	cin >> addedGas;
	// error handleing
	if (cin.eof()) {
		cout << "Exiting the program. Goodbye!" << endl;
		exit(-1);
	}
	else if (cin.fail()) {
		cerr << "Invalid input. Exiting the program." << endl;
		cin.clear(); 
		cin.ignore(80, '\n');
		exit(-1);
	}

	// step 3
	if (addedGas <= tankCapacity)  
		tankCapacity += addedGas;
	else
	{
		// validating input 
		cout << "Not enough space in the tank, please enter a number equal to or less than " 
			<< tankCapacity;
		cin >> addedGas;
		if (cin.eof())
			exit(-1);
		tankCapacity += addedGas;
		if (addedGas > tankCapacity)
		{
			cout << "Invalid entry, exiting the program" << endl;
			exit(-1);
		}
	}
}

void FillTank::showPump(ostream& out) const
{
	Pump::showPump(out);
}