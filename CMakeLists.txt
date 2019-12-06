cmake_minimum_required(VERSION 3.10.0)

project(mmap_example)

find_package(Boost 1.67 REQUIRED COMPONENTS system)
IF(Boost_FOUND)
  INCLUDE_DIRECTORIES(${Boost_INCLUDE_DIRS})
  LINK_DIRECTORIES(${Boost_LIBRARY_DIRS})
ENDIF(Boost_FOUND)


add_executable(${PROJECT_NAME} main.cpp)
target_link_libraries(${PROJECT_NAME} PUBLIC ${Boost_SYSTEM_LIBRARY})
