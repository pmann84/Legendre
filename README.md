# Overview #
This two classes are meant to provide a lightweight unit tested way of calculating Associated Legendre Polynomial values in C++. This class only has dependencies on the C++ standard library, so should work cross platform. 

# Prerequisites #
* C++11 or later
* Visual C++ 2015 (for building in Windows)
* Googlemock and Google test framework (for running unit tests)

# Setup #
Currently this project is only setup to build for Windows for Visual Studio 2015. You can either build the libraries and link to these or you can copy the code into your own project.

## Windows ##
The solution is setup to build both static (.lib) and dynamic (.dll) windows libraries

### Summary of Setup ###
* Check the solution out and open in Visual Studio
* Select the type of library you want to use (Debug/Release => .lib, Debug/Release DLL => .dll)
* Build the solution and the libraries are ready to use

#### Running the tests ####
* You must have the Google Test and Google Mock frameworks built and installed on your machine
* The Visual Studio solution is currently setup to read these libraries from an install located in C:\Googletest
* You can run these tests by running the TestLegendre.exe executable built with the test project

# Using the code #
* Alternatively you can copy this code straight into your project (should be platform agnostic) as long as your compiler supports C++11 features.
* Include the header into your file and you can calculate the value of the Legendre Polynomial of degree (l, m) with the following code:
~~~~
#include "AssociatedLegendre.h"
AssociatedLegendre legendre(4, 2);
std::cout << "The value of the legendre polynomial at 0.298 = " << legendre(0.298) << std::endl;
~~~~
* Alternatively you can pass in a vector of values
~~~~
#include "AssociatedLegendre.h"
std::vector<double> inputs({ -0.75, -0.5, 0.0, 0.25, 0.5 });
AssociatedLegendre legendre(4, 2);
std::vector<double> results = legendre(inputs);
~~~~

# Contributions #
* Constributions are welcome!

# Who do I talk to? #
* Repo owner!