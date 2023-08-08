#include <lua.h>
#include <lauxlib.h>
#include <lualib.h>


int main(int argc, char** argv) {
	lua_State* L = luaL_newstate(); //Creates a new Lua State
	luaL_openlibs(L);               //Opens the Lua Standard Libraries

	if (luaL_loadfile(L, "tests/test.lua") != LUA_OK) { //If file does not exist. Close the Lua Library and exit
		printf("%s\n", lua_tostring(L, -1));
		lua_close(L);
		return 0;
	}

	/*
		Register C function into Lua here.

		lua_register(L, <function name as string>, <function name in code>);
	*/

	lua_pcall(L, 0, 0, 0); // Execute lua code loaded from file.

	lua_close(L);
	return 0;
}