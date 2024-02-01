# Gas Pump Simulation Project

## Overview

This C++ project simulates a gas pump system, featuring three classes: `Pump`, `GasPump`, and `FillTank`. The program allows pumping gas, buying gas, and filling a tank.

## Project Structure

- `Pump.h`, `Pump.cpp`: Base class for the gas pump system.
- `GasPump.cpp`: Derived class with additional features for gas purchasing.
- `FillTank.cpp`: Derived class for filling the tank.

## How to Use

1. **Compile the Source Code:**
bash
   g++ Pump.cpp GasPump.cpp FillTank.cpp main.cpp -o GasPumpSimulation
   
Run the Executable:

bash
./GasPumpSimulation

Key Features

Polymorphic Function:

C++
void showPumpPoly(const Pump* pumpPtr)
{
    pumpPtr->showPump(cout);
}


Programming Guidelines:

Implement constructors and getters as specified.
Validate numeric data within a reasonable range.
Use loops for input validation.
Ensure proper dynamic memory management.
Focus on Inheritance
This project prominently utilizes inheritance to create a hierarchy of classes. The GasPump and FillTank classes inherit from the base class Pump. This inheritance relationship allows for code reuse and enables the specialization of functionality in the derived classes. The use of polymorphism is demonstrated through the showPumpPoly function, which can display information for objects of the base class or its derived classes. Inheritance enhances code organization, promotes code extensibility, and supports the creation of specialized classes with shared functionality.

Note: The detailed coding content is available in the source files.
