cmake_minimum_required(VERSION 3.14)
project(iapg_project C)

set(CMAKE_C_STANDARD 99)

add_executable(iapg_project main.c menu_pr.c menu_artist.c menu_music.c menu_search.c project.h)