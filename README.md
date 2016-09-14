# Chainsaw-Sim:   A Chain simulator
Chainsaw-Sim is a cycle accurate simulator that models the host core, the 'Chainsaw' accelerator, and spatial fabrics of parameterizable size.

## Dependencies
* 1- Boost 1.61 (or higher)
* 2- CMake 2.8.8 (or higher)
* 3- C++11 compiler (e.g., clang++, g++-5)


## Build
1- **Download boost:** You can download boost library from [here](http://www.boost.org/users/history/version_1_61_0.html)
_Note: If you already have built boost on your system you can skip first step_

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

## Usage
In `def` folder there are three config file which set the simulator's variables:

 1. **Graph.def**:

  Graph.def contains configurations for input graph.
  
   - `<MAX_ILP>`: Breaking each chain at every live-in and live-out so that we can get highest available ILP from the chains.
   - `<MERGE>`: Running `mergeq` algorithm on input graph.
   - `<FUSE>`: Running memory fusion mode.
   - `<MAX_NUM_CHAIN>`: Maximum nubmer chains.
   - `<MAX_LIVE_OUT>`: Maximum number of live-out for each chain.
   - `<MAX_LIVE_IN>`: Maximum number of live-in for each chain.
   - `<BLOCK_LIMIT>`: Number of bypass registers.

 2. **Core.def**:
    
 Core.def contains Core's config variables. By setting these vriables you can control the Core's fabric parameters:
 
  - `<MEMORY_MODE>`: Choosing core's memory system.
  - `<LANE_SIZE>`: Set how many instructions each lane can support.
  - `<SCHEDULER>`: _Chainsaw_ supports two different scheduling strategeies (LEVEL SCHEDULING | BLOCK SCHEDULING)
  - `<NUM_LANE>`: Set number of lanes.


 3. **Lane.def**

  - `<L1_MISS_LATENCY>`: L1 cache miss latency. 
  - `<L2_MISS_LATENCY>`: L2 cache miss latency. 
  - `<L3_MISS_LATENCY>`: L3 cache miss latency. 
  - `<FETCH_DELAY>`: Fetch stage's delay.
  - `<DECODE_DELAY>`: Decode stage's delay.


## Getting Started
_Chainsaw_ in general runs in two different modes:

1. **Memory Trace Driven:** In this mode _Chainsaw_ directly reads memory from a file, and simulate the Memory subsystem while it's simulating the instructions.
 There two different memory files which should feed to _Chainsaw_ simulator.
 In the first file each line contains only memory requests whithin the hotpath and also node id inside the data flow graph and iteration id (Format: `<ITER_ID>,<Load|Store>,<NODE_ID>,<ADDRESS>`).

    - .
    - .
    - 2,Load,10,140683921899632
    - 2,Store,14,140683921899608
 
 The second contains program memory requests and also markers indicating begining of the _HotPath_ trace:
    
    - 140721745227768,Store,8
    - 140721745227736,Store,8
    - 2,__chunk_begin_
    - 140721745227736,Load,8
    - 140721745227776,Load,8
    - 140721745227784,Load,8

 The addresses have been saved in decimal format and each node ID **should** match with the node ID inside original dot graph file.

 Running _Chainsaw_ in Memory trace driven mode:

    $ cd build
    $ make -j install
    $ ./bin/chainSaw -i <DOT_GRAPH> -a <HOTPATH_TRACE> -m <MEMORY_TRACE>
    $ Simulation is done.
    # NOTE: Statics they are written in ouput/ folder.

2. **Constant memory mode** In this mode the user has three options to put constant miss-latency delay for all the memory requests:
 
 Running _Chainsaw_ in Memory trace driven mode:

    $ cd build
    $ make -j install
    $ ./bin/chainSaw -i <DOT_GRAPH> 
    $ Simulation is done.
    # NOTE: Statics they are written in ouput/ folder.

_These modes can be set in the config files._

