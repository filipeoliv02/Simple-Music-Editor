cmake_minimum_required(VERSION 3.14)
project(iapg_project C)

set(CMAKE_C_STANDARD 99)

add_executable(iapg_project main.c funcoes.c funcoes.h menu_pr.c menu_pr.h menu_search.c menu_search.h)