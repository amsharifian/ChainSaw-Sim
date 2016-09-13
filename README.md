# Chainsaw-Sim:   A Chain simulator
Chainsaw-Sim is a cycle accurate simulator that models the host core, the 'Chainsaw' accelerator, and spatial fabrics of parameterizable size.

## Dependencies
* 1- Boost 1.61 (or higher)
* 2- CMake 2.8.8 (or higher)
* 3- C++11 compiler (e.g., clang++, g++-5)


## Build
1- **Download boost: ** You can download boost library from [here](http://www.boost.org/users/history/version_1_61_0.html)

__If you already have built boost on your system you can skip first step__.

Compile boost with `regex`, `graph`, `system`, `filesystem`, `iostreams` and `program_option` libraries.

    $ ./bootstrap --show-libraries (showing available boost libraries)
    $ ./bootstrap.sh --prefix=`<PATH_TO_INSTALL>` --with-libraries=filesystem,graph,regex,program_options,system
    $ ./b2 --prefix=`<PATH_TO_INSTALL>` install

2- **Compile: ** _Simulator_ with CMake:

    $ mkdir build && cd build
    $ cmake ../ -DBOOST_ROOT=/home/amiralis/Tools/boost_1_61_0/ -DCMAKE_BUILD_TYPE=Release
    $ make && make install

3- **Test ** the simulator:

For running __Chainsaw__ you need to add these two paths into your `LD_LIBRARY_PATH`. 

    $ export <BOOST_ROOT_DIR>/lib:${LD_LIBRARY_PATH}
    $ export <CHAINSAW_SRC>/gems-lib/ruby_clean/amd64-linux/generated/MESI_CMP_directory_m/lib:${LD_LIBRARY_PATH}

    $ make test

    Debuging the code
