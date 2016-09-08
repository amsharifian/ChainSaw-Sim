#CMakelist file for src directory

file(GLOB SOURCES *.cpp)                
add_executable(chainSaw ${SOURCES})
target_link_libraries(chainSaw ${Boost_LIBRARIES} z ruby)

#Create shared library
add_library(chainS SHARED ${SOURCES})

#install(TARGETS chainSaw 
install(TARGETS chainSaw chainS
    RUNTIME DESTINATION ${CMAKE_BINARY_DIR}/bin
    LIBRARY DESTINATION ${CMAKE_BINARY_DIR}/lib)

