cmake_minimum_required(VERSION 3.19)
project(steganografia C)

set(CMAKE_C_STANDARD 11)

add_executable(steganografia main.c steganography.c steganography.h help.c help.h)