#include <lua.h>
#include <lauxlib.h>
#include <lualib.h>


int main(int argc, char** argv) {
	if (argc == 2) {
		lua_State* L = luaL_newstate(); //Creates a new Lua State
		luaL_openlibs(L);               //Opens the Lua Standard Libraries

		if (luaL_loadfile(L, argv[1]) != LUA_OK) {
			printf("%s\n", lua_tostring(L, -1));
			lua_close(L);
			return 0;
		}

		lua_pcall(L, 0, 0, 0);
		lua_getglobal(L, "update");

		while (lua_pcall(L, 0, 0, 0) == LUA_OK) {
			lua_getglobal(L, "update");
		}

		lua_close(L);
		return 0;
	}

}