#include <bits/stdc++.h>
using namespace std;

//This is a ship class. It has a name, type, shipID, and capacity.
class Ship {
public:
    string name;
    string type;
    int shipID;
    int capacity;

    Ship(string name, string type, int shipID, int capacity)    //The ship class has a constructor that takes in the name, type, shipID, and capacity.
        : name(name), type(type), shipID(shipID), capacity(capacity) {}

    string getType() { //The ship class has a getType function that returns the type of the ship.
        return type;
    }

    int getID() {   //The ship class has a getID function that returns the shipID of the ship.
        return shipID;
    }

    int getCapacity() {     //The ship class has a getCapacity function that returns the capacity of the ship.
        return capacity;
    }
};


//This is a port class. It has a name, capacity, location, and a vector of ships.
class Port {
public:
    string name;        //The port class has a name, capacity, location, and a vector of ships.
    int capacity;
    string location;
    vector<Ship*> ships;

    Port(string name, int capacity, string location)    //The port class has a constructor that takes in the name, capacity, and location.
        : name(name), capacity(capacity), location(location) {}

    virtual void addShip(Ship* ship) = 0;       //The port class has a virtual addShip function that takes in a ship pointer and adds it to the vector of ships.
    virtual void removeShip(Ship* ship) = 0;    //The port class has a virtual removeShip function that takes in a ship pointer and removes it from the vector of ships.
    virtual void print() const = 0;         //The port class has a virtual print function that prints the name, capacity, location, and number of ships in the port.
};

class ContainerPort : public Port {     //The container port class is a child of the port class.
public:
    ContainerPort(string name, int capacity, string location)   //The container port class has a constructor that takes in the name, capacity, and location.
        : Port(name, capacity, location) {}

    void addShip(Ship* ship) override {     //The container port class has an addShip function that takes in a ship pointer and adds it to the vector of ships if the ship type is a container ship.
        if (ship->getType() == "Container Ship" && ships.size() < capacity) {
            ships.push_back(ship);    
        }
    }

    void removeShip(Ship* ship) override {  //The container port class has a removeShip function that takes in a ship pointer and removes it from the vector of ships if the ship type is a container ship.
        if (ship->getType() == "Container Ship") {
            auto it = find(ships.begin(), ships.end(), ship);
            if (it != ships.end()) {
                ships.erase(it);
            }
        }
    }

    void print() const override {       
        cout << "Name: " << name << endl;
        cout << "Capacity: " << capacity << endl;
        cout << "Location: " << location << endl;
        cout << "Number of container ships: " << ships.size() << endl;
        cout << "Container ships:" << endl;
        for (auto ship : ships) {
            cout << "Ship Name: " << ship->name << endl;
            cout << "Ship ID: " << ship->getID() << endl;
            cout << "Ship Capacity: " << ship->getCapacity() << endl;
            cout << "-------------------------" << endl;
        }
    }
};

class CruisePort : public Port {        //The cruise port class is a child of the port class.
public:
    CruisePort(string name, int capacity, string location)  //The cruise port class has a constructor that takes in the name, capacity, and location.
        : Port(name, capacity, location) {}

    void addShip(Ship* ship) override {     //The cruise port class has an addShip function that takes in a ship pointer and adds it to the vector of ships if the ship type is a cruise ship.
        if (ship->getType() == "Cruise Ship" && ships.size() < capacity) {
            ships.push_back(ship);
        }
    }

    void removeShip(Ship* ship) override {      //The cruise port class has a removeShip function that takes in a ship pointer and removes it from the vector of ships if the ship type is a cruise ship.
        if (ship->getType() == "Cruise Ship") {
            auto it = find(ships.begin(), ships.end(), ship);
            if (it != ships.end()) {
                ships.erase(it);
            }
        }
    }

    void print() const override {
        cout << "Name: " << name << endl;
        cout << "Capacity: " << capacity << endl;
        cout << "Location: " << location << endl;
        cout << "Number of cruise ships: " << ships.size() << endl;
        cout << "Cruise ships:" << endl;
        for (auto ship : ships) {
            cout << "Ship Name: " << ship->name << endl;
            cout << "Ship ID: " << ship->getID() << endl;
            cout << "Ship Capacity: " << ship->getCapacity() << endl;
            cout << "-------------------------" << endl;
        }
    }
};

class FishingPort : public Port {       //The fishing port class is a child of the port class.
public:
    FishingPort (string name, int capacity, string location)        //The fishing port class has a constructor that takes in the name, capacity, and location.
        : Port(name, capacity, location) {}

    void addShip(Ship* ship) override {     //The fishing port class has an addShip function that takes in a ship pointer and adds it to the vector of ships if the ship type is a fishing ship.
        if (ship->getType() == "Fishing Ship" && ships.size() < capacity) {    
            ships.push_back(ship);
        }
    }

    void removeShip(Ship* ship) override {      //The fishing port class has a removeShip function that takes in a ship pointer and removes it from the vector of ships if the ship type is a fishing ship.
        if (ship->getType() == "Fishing Ship") {
            auto it = find(ships.begin(), ships.end(), ship);
            if (it != ships.end()) {
                ships.erase(it);
            }
        }
    }

    void print() const override {
        cout << "Name: " << name << endl;
        cout << "Capacity: " << capacity << endl;
        cout << "Location: " << location << endl;
        cout << "Number of fishing ships: " << ships.size() << endl;
        cout << "Fishing ships:" << endl;
        for (auto ship : ships) {
            cout << "Ship Name: " << ship->name << endl;
            cout << "Ship ID: " << ship->getID() << endl;
            cout << "Ship Capacity: " << ship->getCapacity() << endl;
            cout << "-------------------------" << endl;
        }
    }
};


class FerryPort : public Port {     //The ferry port class is a child of the port class.
public:
    FerryPort (string name, int capacity, string location)  //The ferry port class has a constructor that takes in the name, capacity, and location.
        : Port(name, capacity, location) {}
    
    void addShip(Ship* ship) override {     //The ferry port class has an addShip function that takes in a ship pointer and adds it to the vector of ships if the ship type is a ferry ship.
        if (ship->getType() == "Ferry Ship" && ships.size() < capacity) {
            ships.push_back(ship);
        }
    }

    void removeShip(Ship* ship) override {      //The ferry port class has a removeShip function that takes in a ship pointer and removes it from the vector of ships if the ship type is a ferry ship.
        if (ship->getType() == "Ferry Ship") {
            auto it = find(ships.begin(), ships.end(), ship);
            if (it != ships.end()) {
                ships.erase(it);
            }
        }
    }

    void print() const override {
        cout << "Name: " << name << endl;
        cout << "Capacity: " << capacity << endl;
        cout << "Location: " << location << endl;
        cout << "Number of ferry ships: " << ships.size() << endl;
        cout << "Ferry ships:" << endl;
        for (auto ship : ships) {
            cout << "Ship Name: " << ship->name << endl;
            cout << "Ship ID: " << ship->getID() << endl;
            cout << "Ship Capacity: " << ship->getCapacity() << endl;
            cout << "-------------------------" << endl;
        }
    }

};

class TankerPort : public Port {        //The tanker port class is a child of the port class.
public:
    TankerPort (string name, int capacity, string location)     //The tanker port class has a constructor that takes in the name, capacity, and location.
        : Port(name, capacity, location) {}

    void addShip(Ship* ship) override {     //The tanker port class has an addShip function that takes in a ship pointer and adds it to the vector of ships if the ship type is a tanker ship.
        if (ship->getType() == "Tanker Ship" && ships.size() < capacity) {
            ships.push_back(ship);
        }
    }

    void removeShip(Ship* ship) override {      //The tanker port class has a removeShip function that takes in a ship pointer and removes it from the vector of ships if the ship type is a tanker ship.
        if (ship->getType() == "Tanker Ship") {
            auto it = find(ships.begin(), ships.end(), ship);
            if (it != ships.end()) {
                ships.erase(it);
            }
        }
    }

    void print() const override{
        cout << "Name: " << name << endl;
        cout << "Capacity: " << capacity << endl;
        cout << "Location: " << location << endl;
        cout << "Number of tanker ships: " << ships.size() << endl;
        cout << "Tanker ships:" << endl;
        for (auto ship : ships) {
            cout << "Ship Name: " << ship->name << endl;
            cout << "Ship ID: " << ship->getID() << endl;
            cout << "Ship Capacity: " << ship->getCapacity() << endl;
            cout << "-------------------------" << endl;
        }
    }
};

class MilitaryPort : public Port {      //The military port class is a child of the port class.
    public: 

    MilitaryPort(string name, int capacity, string location)    //The military port class has a constructor that takes in the name, capacity, and location.
        : Port(name, capacity, location) {}

    void addShip(Ship* ship) override {     //The military port class has an addShip function that takes in a ship pointer and adds it to the vector of ships if the ship type is a military ship.
        if (ship->getType() == "Military Ship" && ships.size() < capacity) {
            ships.push_back(ship);
        }
    }

    void removeShip(Ship* ship) override {      //The military port class has a removeShip function that takes in a ship pointer and removes it from the vector of ships if the ship type is a military ship.
        if (ship->getType() == "Military Ship") {
            auto it = find(ships.begin(), ships.end(), ship);
            if (it != ships.end()) {
                ships.erase(it);
            }
        }
    }

    void print() const override{
        cout << "Name: " << name << endl;
        cout << "Capacity: " << capacity << endl;
        cout << "Location: " << location << endl;
        cout << "Number of military ships: " << ships.size() << endl;
        cout << "Military ships:" << endl;
        for (auto ship : ships) {
            cout << "Ship Name: " << ship->name << endl;
            cout << "Ship ID: " << ship->getID() << endl;
            cout << "Ship Capacity: " << ship->getCapacity() << endl;
            cout << "-------------------------" << endl;
        }
    }
};

class cargoPort : public Port{      //The cargo port class is a child of the port class.
    public:
    cargoPort(string name, int capacity, string location)   //The cargo port class has a constructor that takes in the name, capacity, and location.
        : Port(name, capacity, location) {}

    void addShip(Ship* ship) override {     //The cargo port class has an addShip function that takes in a ship pointer and adds it to the vector of ships if the ship type is a cargo ship.
        if (ship->getType() == "Cargo Ship" && ships.size() < capacity) {
            ships.push_back(ship);
        }
    }

    void removeShip(Ship* ship) override {      //The cargo port class has a removeShip function that takes in a ship pointer and removes it from the vector of ships if the ship type is a cargo ship.
        if (ship->getType() == "Cargo Ship") {
            auto it = find(ships.begin(), ships.end(), ship);
            if (it != ships.end()) {
                ships.erase(it);
            }
        }
    }

    void print() const override{
        cout << "Name: " << name << endl;
        cout << "Capacity: " << capacity << endl;
        cout << "Location: " << location << endl;
        cout << "Number of cargo ships: " << ships.size() << endl;
        cout << "Cargo ships:" << endl;
        for (auto ship : ships) {
            cout << "Ship Name: " << ship->name << endl;
            cout << "Ship ID: " << ship->getID() << endl;
            cout << "Ship Capacity: " << ship->getCapacity() << endl;
            cout << "-------------------------" << endl;
        }
    }
};




void savePortData(const vector<Port*>& ports) {     //The savePortData function takes in a vector of port pointers and saves the data to a file.
    ofstream out("port_data.txt");  //The savePortData function creates a file called port_data.txt and writes the port data to it.
    if (out.is_open()) {        //The savePortData function checks if the file is open.
        for (const auto port : ports) {         //The savePortData function loops through the vector of port pointers and writes the port data to the file.
            out << "Name: " << port->name << endl;
            out << "Capacity: " << port->capacity << endl;
            out << "Location: " << port->location << endl;
            out<< "-------------------------" << endl;
        }
        out.close();        //The savePortData function closes the file.
        cout << "Port data saved to port_data.txt" << endl;
    }
    else {      //The savePortData function prints an error message if the file is not open.
        cout << "Error: Unable to open file for writing." << endl;
    }
}

int main() {
    vector<Port*> ports;    //The main function has a vector of port pointers.

    int option;    //The main function has an option variable that is used to select the port type.
    do {    //The main function has a do while loop that runs until the user selects the exit option.

        //The main function prints the port types and asks the user to select one.
        cout << "Select the port type: " << endl;   
        cout << "1. Container Port" << endl;
        cout << "2. Cruise Port" << endl;
        cout << "3. Fishing Port" << endl;
        cout << "4. Ferry Port" << endl;
        cout << "5. Tanker Port" << endl;
        cout << "6. Military Port" << endl;
        cout << "7. Cargo Port" << endl;
        cout << "8. Exit" << endl;
        cin >> option;

        if (option == 1 || option == 2 || option == 3 || option == 4 || option == 5 || option == 6 || option == 7) {
            //The main function asks the user to enter the port name, capacity, location, and number of ships.

            string name, location;
            int capacity, shipCount;

            cout << "Enter port name: ";
            cin.ignore();       //The main function ignores the newline character.
            getline(cin, name); //The main function gets the port name.

            cout << "Enter port capacity: ";
            cin >> capacity;    //The main function gets the port capacity.

            cout << "Enter port location: ";
            cin.ignore();       //The main function ignores the newline character.
            getline(cin, location); //The main function gets the port location.

            cout << "Enter the number of ships: ";
            cin >> shipCount;       //The main function gets the number of ships.

            Port* port;
            //The main function creates a port pointer based on the option selected by the user.

            if (option == 1) {
                port = new ContainerPort(name, capacity, location);    
            }
            else if(option == 2) {
                port = new CruisePort(name, capacity, location);
            }

            else if(option == 3) {
                port = new FishingPort(name, capacity, location);
            }

            else if(option == 4) {
                port = new FerryPort(name, capacity, location);
            }

            else if(option == 5) {
                port = new TankerPort(name, capacity, location);
            }

            else if(option == 6) {
                port = new MilitaryPort(name, capacity, location);
            }

            else if(option == 7) {
                port = new cargoPort(name, capacity, location);
            }

            //The main function loops through the number of ships and asks the user to enter the ship name, type, and capacity.
            for (int i = 1; i <= shipCount; i++) {
                //The main function creates a ship pointer based on the option selected by the user.

                string shipName, shipType;
                int shipCapacity;
                cout << "Enter ship " << i << " name: ";
                cin.ignore();
                getline(cin, shipName);

                cout << "Enter ship " << i << " type : ";
                getline(cin, shipType);

                cout << "Enter ship " << i << " capacity: ";
                cin >> shipCapacity;

                Ship* ship = new Ship(shipName, shipType, i, shipCapacity);
                port->addShip(ship);
            }

            //The main function adds the port pointer to the vector of port pointers.
            ports.push_back(port);

            //The main function prints the port data.
            cout << "Port ID: " << ports.size() << endl;
            port->print();  //The main function calls the print function of the port pointer.
            cout << "-------------------------" << endl;
        }
        else if (option != 8) {      //The main function prints an error message if the option is invalid.
            cout << "Invalid option. Please try again." << endl;    //The main function prints an error message if the option is invalid.
        }
    } while (option != 8);      //The main function runs until the user selects the exit option.

    savePortData(ports);        //The main function calls the savePortData function and passes the vector of port pointers to it.

    return 0;
}
