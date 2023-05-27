# Port-Management-System
The project in C++ is about a system which manages different types of ports and ships associated with them such as
"Container Port", "Cruise Port", "Fishing Port", "Ferry Port".

The project consists of the following classes:

**Ship

The Ship class represents a ship and has the following attributes:
1. name: A string representing the name of the ship.
2. type: A string representing the type of the ship.

**Port

This is an abstract class which represents a port. It has the following attributes:
1. name: A string representing the name of the port.
2. capacity: An integer representing the maximum capacity of the port.

The Port class defines the following pure virtual functions:

1. addShip(Ship* ship): Adds a ship to the port.
2. removeShip(Ship* ship): Removes a ship from the port.
3. print() const: Prints the details of the port.

**ContainerPort

The ContainerPort class is a subclass of Port and represents a container port. It has an additional attribute:

1. number_of_containers: An integer representing the current number of containers in the port.
The ContainerPort class overrides the virtual functions of the Port class to provide specific functionality for container ports.

**CruisePort

The CruisePort class is a subclass of Port and represents a cruise port. It has an additional attribute:

1. number_of_cruise_ships: An integer representing the current number of cruise ships in the port.
The CruisePort class overrides the virtual functions of the Port class to provide specific functionality for cruise ports.

**FishingPort

The FishingPort class is a subclass of Port and represents a fishing port. It has an additional attribute:

1. number_of_fishing_ships: An integer representing the current number of fishing ships in the port.
The FishingPort class overrides the virtual functions of the Port class to provide specific functionality for fishing ports.

**FerryPort

The FerryPort class is a subclass of Port and represents a ferry port. It has an additional attribute:

1. number_of_ferry_ships: An integer representing the current number of ferry ships in the port.
The FerryPort class overrides the virtual functions of the Port class to provide specific functionality for ferry ports.

**File Input and Output

The project reads port details from an input file and outputs the port details to an output file.
The input file format is as follows:

1. <portType> <portName> <capacity> <number>
2. <portType>: The type of the port (ContainerPort, CruisePort, FishingPort, or FerryPort).
3. <portName>: The name of the port.
4. <capacity>: The maximum capacity of the port.
5. <number>: The initial number of ships in the port.
  
**OOP features used for implementation:

1. Classes and Objects: The code defines multiple classes (Ship, Port, ContainerPort, CruisePort, FishingPort, FerryPort) that encapsulate data and behavior. Objects of these classes are created and used throughout the code.

2. Inheritance: The code utilizes inheritance to create specialized classes (ContainerPort, CruisePort, FishingPort, FerryPort) that inherit from a common base class (Port). This allows for code reuse and specialization.

3. Polymorphism: The code demonstrates polymorphism through the use of virtual functions and function overriding. The Port class declares pure virtual functions (addShip, removeShip, print), and the derived classes (ContainerPort, CruisePort, FishingPort, FerryPort) override these functions with their specific implementations.

4. Encapsulation: The code utilizes encapsulation by encapsulating data and functionality within classes. Class member variables (name, capacity, number_of_containers, etc.) are declared as private, and access to them is provided through public member functions.

5. Abstraction: The code demonstrates abstraction by providing a simplified interface to interact with port objects. The Port class defines pure virtual functions that provide an abstract interface for adding ships, removing ships, and printing port details. The concrete classes implement these functions according to their specific requirements.

6. Constructors: The classes (Ship, Port, ContainerPort, CruisePort, FishingPort, FerryPort) define constructors to initialize object instances. The constructors accept arguments to set the initial values of member variables.

7. File Handling: The code uses file handling operations (ifstream, ofstream) to read input from a file (ports.txt) and write output to a file (port_details.txt). This allows for data persistence and external data source interaction.
 
8.Static Casting: The code uses static casting in the following instances:

  a. In the addShip and removeShip member functions of the derived port classes (ContainerPort, CruisePort, FishingPort, FerryPort), static casting is performed to check the type of the ship passed as an argument and determine if it matches the specific ship type allowed in that port. For example, dynamic_cast<ContainerPort*>(port) is used to cast the Port pointer port to a ContainerPort pointer to perform the type check.
  b. In the main function, when printing the port type to the output file, typeid(*port).name() returns a const char* containing the type name. A static cast is performed to convert it to a std::string for writing to the output file: static_cast<std::string>(typeid(*port).name()).

9.Standard Template Library (STL): The code utilizes the STL in the following ways:
  a. vector<Port*> is used to store and manage a collection of Port pointers. This dynamic container allows for easy addition and iteration over the port objects.
  b. ifstream and std::ofstream are used for file input and output operations. They provide convenient ways to read from and write to files.
  
10. And many more.
  
**Usage
  
To use the port management system, follow these steps:

1. Prepare an input file (ports.txt) with the port details in the specified format.
2. Compile and run the program.
3. The program will generate an output file (port_details.txt) containing the port details.
4. Read the port details from the output file and also at the terminal for further analysis.
  
  
  
  
  


