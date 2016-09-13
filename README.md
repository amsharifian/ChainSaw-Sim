# Chainsaw-Sim:   A Chain simulator
Chainsaw-Sim is a cycle accurate simulator that models the host core, the 'Chainsaw' accelerator, and spatial fabrics of parameterizable size.

## Dependencies
* 1- Boost 1.55 (or higher)
* 2- CMake 2.8.8 (or higher)
* 3- C++11 compiler (e.g., clang++, g++-5)


## Build
1- **Download boost 1.61:** You can download boost library from [here](http://www.boost.org/users/history/version_1_61_0.html)

Compile boost with `regex`, `graph`, `system`, `filesystem`, `iostreams` and `program_option` libraries.

    $ ./bootstrap --show-libraries (showing available boost libraries)
    $ ./bootstrap.sh --prefix=`<PATH_TO_INSTALL>` --with-libraries=filesystem,graph,regex,program_options,system
    $ ./b2 --prefix=`<PATH_TO_INSTALL>` install

2- **Compile** _Simulator_ with CMake:

    $ mkdir build && cd build
    $ cmake ../ -DBOOST_ROOT=/home/amiralis/Tools/boost_1_61_0/ -DCMAKE_BUILD_TYPE=Release
    $ make && make install

3- Test the simulator:

    $ make test
