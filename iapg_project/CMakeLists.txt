cmake_minimum_required(VERSION 3.14)
project(iapg_project C)

set(CMAKE_C_STANDARD 99)

add_executable(iapg_project main.c funcoes.c funcoes.h menu_pr.c menu_pr.h menu_search.c menu_search.h  menu_add.c menu_add.h menu_edit.c menu_edit.h menu_remove.c menu_remove.h menu_artist.c menu_artist.h menu_music.c menu_music.h)