project("Z Secure")

add_executable(main main.cc crypt.cc)
add_executable(encrypt encrypt.cc crypt.cc)
set( CMAKE_CXX_FLAGS "-Wall -m64 -O3 -std=c++11")
