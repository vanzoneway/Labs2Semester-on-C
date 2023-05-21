cmake_minimum_required(VERSION 3.23)
project(Gronsfeld C)

set(CMAKE_C_STANDARD 11)

add_executable(Gronsfeld main.c menu.c menu.h gronsfeld.c gronsfeld.h goodinputs.c goodinputs.h)
