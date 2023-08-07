cmake_minimum_required(VERSION 2.8.11)
project(se)

include_directories(
	src
	include
)

add_executable(se
	src/main.c
	include/lua.h
	include/lauxlib.h
	include/lualib.h
)

target_link_libraries(se lib/lua54)