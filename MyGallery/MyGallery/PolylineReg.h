#pragma once



/*CPolyline�Ĺ���������װΪLuaFunction��ʽ */


int lua_create_new_polyline(lua_State* L);
int lua_create_new_group(lua_State* L);

int lua_set_start(lua_State* L);
int lua_insert_node(lua_State* L);
int lua_emplace_cad(lua_State* L);

//------ע��ȫ�ֺ�����Luaʹ��------
static const luaL_Reg ope_lib[] = {
	{ "create_polyline", lua_create_new_polyline },
	{ "create_cadgroup", lua_create_new_group },
	{ "set_start", lua_set_start },
	{ "insert_node", lua_insert_node },
	{ "emplace", lua_emplace_cad },
	{ NULL, NULL },
};

int luaopen_polyline_libs(lua_State* L);