project(Chain-Scheduler)
cmake_minimum_required(VERSION 2.8)

set(PACKAGE_NAME ChainSaw)
set(PACKAGE_VERSION 0.81)
set(PACKAGE_STRING "${PACKAGE_NAME} ${PACKAGE_VERSION}")
set(PACKAGE_BUGREPORT "amiralis@sfu.ca")

#TODO UPDATE PRJECT_PATH
set(PROJECT_PATH /home/amiralis/git/ChainSaw-Sim)
set(MACASIM_PATH /home/amiralis/git/mem-axc-64/macsim-mem-axc-64/)
set(RUBY_PATH ${CMAKE_SOURCE_DIR}/gems-lib/ruby_clean/amd64-linux/generated/MESI_CMP_directory_m/)

#set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

set(CMAKE_CXX_FLAGS "-std=c++11 -O0 -fpermissive -Wno-write-strings -Wno-unused-label")
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -Wall")
set(CMAKE_CXX_COMPILER g++)
#set(CMAKE_BUILD_TYPE Release)


# Find and include boost 
set(Boost_USE_STATIC_LIBS OFF) 
set(Boost_USE_MULTITHREADED ON)  
set(Boost_USE_STATIC_RUNTIME OFF) 
find_package(Boost 1.55.0 COMPONENTS graph regex system filesystem program_options iostreams) 

if(Boost_FOUND)
    include_directories(${Boost_INCLUDE_DIRS}) 
else()
    message( FATAL_ERROR "ChainSaw needs Boost 1.55 or higher, CMake will exit.")
endif()

# 3rdparty Libraries
include(CMakeLists-ExternalProjects.txt)

#ExternalProject_Add(ruby_sim
    #BUILD_COMMAND make -C gems-lib/ruby_clean PROTOCOL=MESI_CMP_directory_m  NOTESTER=1 DEBUG=0 -j 8 )

#add_custom_command(OUTPUT make-knob  COMMAND make -C knobs/  WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}  )
#Adding macsim
#include_directories(${MACASIM_PATH}/include)
#link_directories(${MACASIM_PATH}/lib)

#Adding ruby
include_directories(../gems-lib/ruby_clean/O3sim_ruby)
#include_directories(/home/amiralis/git/mem-axc-64/macsim.r.d.b.s/macsim-mem-axc-64/gems-lib-ooo/ruby_clean/O3sim_ruby)
link_directories(${RUBY_PATH}/lib)

# Add the project header and library paths
include_directories(${CMAKE_SOURCE_DIR}/include)

# Add subdirectories
add_subdirectory(src)

