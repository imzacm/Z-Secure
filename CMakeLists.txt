project("Z Secure")

add_executable(ZSecure main.cc crypt.cc)
add_executable(ZEncrypt encrypt.cc crypt.cc)
add_executable(ZDecrypt decrypt.cc crypt.cc)
set( CMAKE_CXX_FLAGS "-Wall -m64 -O3 -std=c++11")
