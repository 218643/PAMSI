cmake_minimum_required(VERSION 2.8)

# Name the application
SET( PROJ_NAME      "hash_table" )

project( $(PROJ_NAME) )

# Compiler Settings
add_definitions( -std=c++11 -O2 )

add_subdirectory( src )
