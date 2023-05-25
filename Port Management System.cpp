#include <bits/stdc++.h>
using namespace std;

//This class is a class for a ship. It has a name and a type. 
//The type is used to determine which port the ship can be added to.
class Ship
{
public:
    string name, type;
    Ship(string name, string type) : name(name), type(type) {}

    string getType()
    {
        return type;
    }
};

//This class is a class for a port. It has a name and a capacity.
//The capacity is used to determine how many ships can be added to the port.

class Port
{
public:
    string name;
    int capacity;

    Port(string name, int capacity) : name(name), capacity(capacity) {}

    virtual void addShip(Ship* ship) = 0;   //This is a pure virtual function. It is used to add a ship to the port.
    virtual void removeShip(Ship* ship) = 0;    //This is a pure virtual function. It is used to remove a ship from the port.
    virtual void print() const = 0;     //This is a pure virtual function. It is used to print the details of the port.


};


//This class is a class for a container port. It inherits from the port class.
//It has a number of containers. It can add a container ship to the port if the number of containers is less than the capacity.
//It can remove a container ship from the port if the number of containers is greater than 0.
//It can print the details of the port.
class ContainerPort : public Port
{
public:
    int number_of_containers;

    ContainerPort(string name, int capacity, int num) : Port(name, capacity), number_of_containers(num) {}

    void addShip(Ship* ship) override   
    {
        if (ship->getType() == "Container Ship" && number_of_containers < capacity)
        {
            number_of_containers++;
        }
    }

    void removeShip(Ship* ship) override
    {
        if (ship->getType() == "Container Ship" && number_of_containers > 0)
        {
            number_of_containers--;
        }
    }

    void print() const override
    {
        cout << "Name: " << name << endl;
        cout << "Capacity: " << capacity << endl;
        cout << "Number of containers: " << number_of_containers << endl;
    }
};


//This class is a class for a cruise port. It inherits from the port class.
//It has a number of cruise ships. It can add a cruise ship to the port if the number of cruise ships is less than the capacity.
//It can remove a cruise ship from the port if the number of cruise ships is greater than 0.
//It can print the details of the port.

class CruisePort : public Port
{
public:
    int number_of_cruise_ships;

    CruisePort(string name, int capacity, int num) : Port(name, capacity), number_of_cruise_ships(num) {}

    void addShip(Ship* ship) override
    {
        if (ship->getType() == "Cruise Ship" && number_of_cruise_ships < capacity)
        {
            number_of_cruise_ships++;
        }
    }

    void removeShip(Ship* ship) override
    {
        if (ship->getType() == "Cruise Ship" && number_of_cruise_ships > 0)
        {
            number_of_cruise_ships--;
        }
    }

    void print() const override
    {
        cout << "Name: " << name << endl;
        cout << "Capacity: " << capacity << endl;
        cout << "Number of cruise ships: " << number_of_cruise_ships << endl;
    }
};



//This class is a class for a fishing port. It inherits from the port class.
//It has a number of fishing ships. It can add a fishing ship to the port if the number of fishing ships is less than the capacity.
//It can remove a fishing ship from the port if the number of fishing ships is greater than 0.
//It can print the details of the port.

class FishingPort : public Port
{
public:
    int number_of_fishing_ships;

    FishingPort(string name, int capacity, int num) : Port(name, capacity), number_of_fishing_ships(num) {}

    void addShip(Ship* ship) override
    {
        if (ship->getType() == "Fishing Ship" && number_of_fishing_ships < capacity)
        {
            number_of_fishing_ships++;
        }
    }

    void removeShip(Ship* ship) override
    {
        if (ship->getType() == "Fishing Ship" && number_of_fishing_ships > 0)
        {
            number_of_fishing_ships--;
        }
    }

    void print() const override
    {
        cout << "Name: " << name << endl;
        cout << "Capacity: " << capacity << endl;
        cout << "Number of fishing ships: " << number_of_fishing_ships << endl;
    }
};


//This class is a class for a ferry port. It inherits from the port class.
//It has a number of ferry ships. It can add a ferry ship to the port if the number of ferry ships is less than the capacity.
//It can remove a ferry ship from the port if the number of ferry ships is greater than 0.
//It can print the details of the port.

class FerryPort : public Port
{
    public:
    int number_of_ferry_ships;

    FerryPort(string name, int capacity, int num) : Port(name, capacity), number_of_ferry_ships(num) {}

    void addShip(Ship* ship) override
    {
        if (ship->getType() == "Ferry Ship" && number_of_ferry_ships < capacity)
        {
            number_of_ferry_ships++;
        }
    }

    void removeShip(Ship* ship) override
    {
        if (ship->getType() == "Ferry Ship" && number_of_ferry_ships > 0)
        {
            number_of_ferry_ships--;
        }
    }

    void print() const override
    {
        cout << "Name: " << name << endl;
        cout << "Capacity: " << capacity << endl;
        cout << "Number of ferry ships: " << number_of_ferry_ships << endl;
    }
};






int main()
{
    ifstream inFile("ports.txt");       //opening the input file
    if (!inFile)
    {
        cerr << "Error opening input file." << endl;    //if the file is not opened
        return 1;                                       //return 1
    }

    ofstream outFile("port_details.txt");           //opening the output file
    if (!outFile)
    {
        cerr << "Error creating output file." << endl;      //if the file is not opened
        return 1;                                           //return 1
    }

    vector<Port*> ports;        //creating a vector of ports

    string portType, portName;      //variables for the port type and port name
    int capacity, number;           //variables for the capacity and number of ships

    while (inFile >> portType >> portName >> capacity >> number)        //reading the input file
    {
        if (portType == "ContainerPort")        //if the port type is container port
        {
            ports.push_back(new ContainerPort(portName, capacity, number));     //pushing a new container port to the vector
        }
        else if (portType == "CruisePort")      //if the port type is cruise port
        {
            ports.push_back(new CruisePort(portName, capacity, number));        //pushing a new cruise port to the vector
        }
         else if (portType == "FishingPort")    //if the port type is fishing port
         {
            ports.push_back(new FishingPort(portName, capacity, number));       //pushing a new fishing port to the vector
         }
         else if (portType == "FerryPort")      //if the port type is ferry port
         {
             ports.push_back(new FerryPort(portName, capacity, number));        //pushing a new ferry port to the vector
         }

        else                                                            //if the port type is invalid
        {
            cerr << "Invalid port type." << endl;                       //print an error message
            return 1;
        }
    }

    for (const auto& port : ports)      //for each port in the vector
    {
        port->print();                  //print the details of the port
        cout << endl;
    }
    
    for (const auto& port : ports)          //for each port in the vector
    {                               
        outFile << "Port Type: " << typeid(*port).name() << endl;       //print the port type
        outFile << "Port Name: " << port->name << endl;                 //print the port name
        outFile << "Capacity: " << port->capacity << endl;              //print the capacity

        if (typeid(*port) == typeid(ContainerPort))            //if the port type is container port
        {
            ContainerPort* containerPort = dynamic_cast<ContainerPort*>(port);      //cast the port to container port
            outFile << "Number of containers: " << containerPort->number_of_containers << endl;     //print the number of containers
        }
        else if (typeid(*port) == typeid(CruisePort))           //if the port type is cruise port
        {
            CruisePort* cruisePort = dynamic_cast<CruisePort*>(port);       //cast the port to cruise port
            outFile << "Number of cruise ships: " << cruisePort->number_of_cruise_ships << endl;     //print the number of cruise ships
        }

         else if (typeid(*port) == typeid(FishingPort))         //if the port type is fishing port
         {
             FishingPort* fishingPort = dynamic_cast<FishingPort*>(port);   //cast the port to fishing port
             outFile << "Number of fishing boats: " << fishingPort->number_of_fishing_ships << endl;    //print the number of fishing ships
         }
         else if (typeid(*port) == typeid(FerryPort))       //if the port type is ferry port
         {
             FerryPort* ferryPort = dynamic_cast<FerryPort*>(port);     //cast the port to ferry port
             outFile << "Number of ferry ships: " << ferryPort->number_of_ferry_ships << endl;      //print the number of ferry ships
         }
        

        outFile << endl;
    }

    for (const auto& port : ports)
    {
        delete port;        //deleting the ports    
    }

    inFile.close();     //closing the input file
    outFile.close();    //closing the output file

    return 0;
}