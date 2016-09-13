# Chainsaw-Sim:   A Chain simulator
Chainsaw-Sim is a cycle accurate simulator that models the host core, the 'Chainsaw' accelerator, and spatial fabrics of parameterizable size.

## Dependencies
* 1- Boost 1.61 (or higher)
* 2- CMake 2.8.8 (or higher)
* 3- C++11 compiler (e.g., clang++, g++-5)


## Build
1- **Download boost:** You can download boost library from [here](http://www.boost.org/users/history/version_1_61_0.html)

'If you already have built boost on your system you can skip first step.'

Compile boost with `regex`, `graph`, `system`, `filesystem`, `iostreams` and `program_option` libraries.

    $ ./bootstrap --show-libraries (showing available boost libraries)
    $ ./bootstrap.sh --prefix=`<PATH_TO_INSTALL>` --with-libraries=filesystem,graph,regex,program_options,system
    $ ./b2 --prefix=`<PATH_TO_INSTALL>` install

2- **Compile:** _Simulator_ with CMake:

    $ mkdir build && cd build
    $ cmake ../ -DBOOST_ROOT=/home/amiralis/Tools/boost_1_61_0/ -DCMAKE_BUILD_TYPE=Release
    $ make && make install

3- **Test** the simulator:

For running __Chainsaw__ you need to add these two paths into your `LD_LIBRARY_PATH`. 

    $ export <BOOST_ROOT_DIR>/lib:${LD_LIBRARY_PATH}
    $ export <CHAINSAW_SRC>/gems-lib/ruby_clean/amd64-linux/generated/MESI_CMP_directory_m/lib:${LD_LIBRARY_PATH}

    $ make test

If you could pass the test case you will the follwoing message:

    Running tests...
        Start 1: Test
        1/1 Test #1: Test .............................   **Passe**    9.27 sec

        100% tests passed, 0 tests failed out of 1

        Total Test time (real) =   9.28 sec

In case you couldn't pass the test case you will get the following message:

    Running tests...
        Start 1: Test
        1/1 Test #1: Test .............................***Failed    0.00 sec

        0% tests passed, 1 tests failed out of 1

        Total Test time (real) =   0.01 sec

        The following tests FAILED:
              1 - Test (Failed)
              Errors while running CTest

The following file contains error message:

    $ cat <BUILD_DIR>/Testing/Temporary/LastTest.log
