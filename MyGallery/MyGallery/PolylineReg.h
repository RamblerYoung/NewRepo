#pragma once

/*CPolyline�Ĺ���������װΪLuaFunction��ʽ */


int lua_create_new_polyline(lua_State* L);

int lua_set_start(lua_State* L);
int lua_add_node(lua_State* L);

//------ע��ȫ�ֺ�����Luaʹ��------
static const luaL_Reg ope_lib[] = {
	{ "create", lua_create_new_polyline },
	{ "set_start", lua_set_start },
	{ "add_node", lua_add_node },
	{ NULL, NULL },
};

int luaopen_polyline_libs(lua_State* L);