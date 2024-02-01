#include"Pump.h"

// Sara McHattie 
// Assignment 2 - client code

// polymorphic function
void showPumpPoly(const Pump* pumpPtr)
{
	pumpPtr->showPump(cout);
}


int main()
{
	cout << fixed << setprecision(2);

	cout << endl << endl << "For slcTank (non default Pump) " << endl;
	Pump* slcTank = new Pump(100, 90); // non-default constructor
	assert(slcTank);
	cout << "Amt= " << slcTank->getAmtGas() << endl;
	cout << "Capacity=" << slcTank->getCapacity() << endl << endl;
	slcTank->pumpGas(10);  //remove gas from tank
	slcTank->pumpGas(200);  //attempt to remove more gas than in tank
	cout << "Call polymorphic function:\n ";
	showPumpPoly(slcTank);

	cout << endl << endl;
	delete slcTank;

	Pump* slcPump = new Pump; // default constructor
	assert(slcPump != NULL);
	cout << "For slcPump (default Pump): " << endl;
	slcPump->showPump(cout);
	cout << "Call polymorphic function:\n ";
	showPumpPoly(slcPump);

	cout << endl << endl;
	delete slcPump;


	cout << endl << endl << "For slcGas (non default GasPump) " << endl;
	GasPump* slcGas = new GasPump(100, 90, "unleaded", 1.50); // non=default constructor
	assert(slcGas);
	slcGas->showPump(cout);
	slcGas->buyGas(10);  //customer buys gas 
	slcGas->buyGas(200);  //customer tries to buy more gas than in tank
	cout << "Call polymorphic function:\n ";
	showPumpPoly(slcGas);

	cout << endl << endl;

	delete slcGas;

	cout << endl << endl << "For slcFuel (default GasPump) " << endl;
	GasPump* slcFuel = new GasPump; // default constructor
	assert(slcFuel);
	cout << "Amt= " << slcFuel->getAmtGas() << endl;
	cout << "Capacity=" << slcFuel->getCapacity() << endl;
	cout << "type=" << slcFuel->getGasType() << endl;
	cout << "Price= $" << slcFuel->getPrice() << endl << endl;
	cout << "Call polymorphic function:\n ";
	showPumpPoly(slcFuel);

	cout << endl << endl;


	delete slcFuel;

	cout << endl << endl << "For slcStore (non default FillTank) " << endl;
	FillTank* slcStore = new FillTank(-1, -1); // non-default constructor
	assert(slcStore);
	cout << "Amt= " << slcStore->getAmtGas() << endl;
	cout << "Capacity=" << slcStore->getCapacity() << endl << endl;
	cout << "Call polymorphic function:\n ";
	showPumpPoly(slcStore);

	cout << endl << endl;
	delete slcStore;

	cout << endl << endl << "For slcStore (default FillTank) " << endl;
	FillTank* slcTanker = new FillTank; // default constructor
	assert(slcTanker != NULL);
	cout << "Amt= " << slcTanker->getAmtGas() << endl;
	cout << "Capacity=" << slcTanker->getCapacity() << endl;
	cout << "add 10 litres of gas (when asked) ";
	slcTanker->addGas();				//add gas to the station's holding tank
	cout << "Amt of gas remaining= " << slcTanker->getAmtGas() << endl;
	cout << "add more than the capacity, when asked ";
	slcTanker->addGas();                //try to add more gas than capacity
	cout << "Amt of gas (should be full) = " << slcTanker->getAmtGas() << endl;
	cout << "Call polymorphic function:\n ";
	showPumpPoly(slcTanker);

	cout << endl << endl;
	delete slcTanker;

	system("pause");

}


/*
	console output



	For slcTank (non default Pump)
	Amt= 100
	Capacity=90

	Amount of gas pumped:   10
	Amount remaining in tank:   80
	Amount of gas pumped:   0
	Amount remaining in tank:   80
	Call polymorphic function:
	 0
	80


	For slcPump (default Pump):
	30
	120
	Call polymorphic function:
	 30
	120




	For slcGas (non default GasPump)
	100
	90
	Gas type is unleaded and the price is 1.50
	Amount of purchased gas: 10
	Amount remaining in tank: 80Total price of gas: 15.00

	There is only 90 left in tank
	Amount of purchased gas: 90
	Amount remaining in tank: 0Total price of gas: 135.00

	Call polymorphic function:
	 100
	90
	Gas type is unleaded and the price is 1.50




	For slcFuel (default GasPump)
	Amt= 30
	Capacity=120
	type=Premium
	Price= $1.98

	Call polymorphic function:
	 30
	120
	Gas type is Premium and the price is 1.98




	For slcStore (non default FillTank)
	Amt= 0
	Capacity=0

	Call polymorphic function:
	 0
	0




	For slcStore (default FillTank)
	Amt= 30
	Capacity=120
	add 10 litres of gas (when asked) Enter amount of gas to be added to the tank or hit ctr z to exit: 10
	Amt of gas remaining= 30
	add more than the capacity, when asked Enter amount of gas to be added to the tank or hit ctr z to exit: 40
	Amt of gas (should be full) = 30
	Call polymorphic function:
	 30
	120


	Press any key to continue . . .

*/
