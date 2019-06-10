cmake_minimum_required(VERSION 3.2)

set (CMAKE_CXX_STANDARD 11)

include_directories(
  ${CMAKE_CURRENT_SOURCE_DIR}/asio/asio/include
  )
 
 file(GLOB SRC "*.cpp")
  
 add_executable(server ${SRC})