#pragma once
#include <stdlib.h>
extern "C" {
#include <lua.h>
#include <lualib.h>
#include <lauxlib.h>
}

using namespace std;

/*
 * #define LUA_TNIL     0
 * #define LUA_TBOOLEAN     1
 * #define LUA_TLIGHTUSERDATA   2
 * #define LUA_TNUMBER      3
 * #define LUA_TSTRING      4
 * #define LUA_TTABLE       5
 * #define LUA_TFUNCTION        6
 * #define LUA_TUSERDATA        7
 * #define LUA_TTHREAD      8
 * */

char* get_val(lua_State* L, int idx);

int print_stack(lua_State* L);