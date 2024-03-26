#pragma once

/*CPolyline的公共方法包装为LuaFunction形式 */


int lua_create_new_polyline(lua_State* L);

int lua_set_start(lua_State* L);
int lua_add_node(lua_State* L);

//------注册全局函数供Lua使用------
static const luaL_Reg ope_lib[] = {
	{ "create", lua_create_new_polyline },
	{ "set_start", lua_set_start },
	{ "add_node", lua_add_node },
	{ NULL, NULL },
};

int luaopen_polyline_libs(lua_State* L);