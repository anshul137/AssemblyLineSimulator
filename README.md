# AssemblyLineSimulator
Developed a comprehensive simulation of an assembly line with dynamic workstations, order processing, and inventory management using C++ Object-Oriented Programming. Implemented modules for utilities, station management, customer order processing, and line management, showcasing advanced skills in class design, file handling, and STL usage.


## Project Overview

The **AssemblyLineSimulator** is a C++ application designed to simulate a dynamic assembly line system. It models a production line with multiple workstations, where each workstation handles specific items and processes customer orders. The system manages inventory, processes orders through various stations, and provides detailed reporting on order fulfillment and station status.

## Features

- **Assembly Line Simulation:** Simulates a configurable assembly line with a set of workstations.
- **Order Processing:** Handles customer orders, processes them through the assembly line, and manages inventory.
- **Detailed Reporting:** Provides detailed output on order fulfillment and station statuses.
- **Efficient Design:** Utilizes object-oriented programming principles with C++ for robust and scalable code.

## Modules

1. **Utilities**
   - Parses input files and extracts tokens.
   - Provides functions for setting and retrieving field width and delimiters.

2. **Station**
   - Manages information about individual workstations.
   - Handles item inventory and processes orders.

3. **CustomerOrder**
   - Manages customer orders, including item lists and order statuses.
   - Handles order filling and status reporting.

4. **Workstation**
   - Represents an active workstation on the assembly line.
   - Manages order processing and moves orders between stations.

5. **LineManager**
   - Configures the assembly line and manages order movement through the line.
   - Provides functionality for running the assembly line and displaying its status.

## Installation

1. Clone the repository:
    ```bash
    git clone https://github.com/yourusername/AssemblyLineSimulator.git
    ```
2. Navigate to the project directory:
    ```bash
    cd AssemblyLineSimulator
    ```
3. Build the project using a C++ compiler (e.g., g++):
    ```bash
    g++ -o AssemblyLineSimulator main.cpp Utilities.cpp Station.cpp CustomerOrder.cpp Workstation.cpp LineManager.cpp
    ```

## Usage

1. Prepare your input files for assembly line configuration and customer orders.
2. Run the application:
    ```bash
    ./AssemblyLineSimulator
    ```
3. Follow the prompts and view the output to see the assembly line simulation in action.

## Sample Output

Example output can be found in the `ms_output.txt` files provided in the repository. 

## Contributing

Feel free to fork the repository and submit pull requests with improvements or bug fixes. For major changes, please open an issue first to discuss what you would like to change.

## License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.


