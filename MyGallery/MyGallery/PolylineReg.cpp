#include "stdafx.h"
#include "CPolyline.h"
extern "C" {
#include "lua.h"
#include "lualib.h"
#include "lauxlib.h"
}
#include "PolylineReg.h"

int lua_create_new_polyline(lua_State* L)
{
	CPolyline** _ppPoly = (CPolyline**)lua_newuserdata(L, sizeof(CPolyline*));
	*_ppPoly = new CPolyline();
	return 1;
}

int lua_create_new_group(lua_State* L)
{
	CCadGroup** _ppGroup = (CCadGroup**)lua_newuserdata(L, sizeof(CCadGroup*));
	*_ppGroup = new CCadGroup();
	return 1;
}

int lua_set_start(lua_State* L)
{
	//取栈底参数
	CPolyline** _ppPoly = (CPolyline**)lua_touserdata(L, 1);
	luaL_argcheck(L, _ppPoly != NULL, 1, "invalid user data!");

	//取第二个入参
	luaL_checknumber(L, -2);
	lua_Number _nX = lua_tonumber(L, -2);

	//取第三个入参
	luaL_checknumber(L, -1);
	lua_Number _nY = lua_tonumber(L, -1);

	(*_ppPoly)->SetStart(_nX, _nY);
	
	return 0;
}

int lua_insert_node(lua_State* L)
{
	//取栈底参数
	CPolyline** _ppPoly = (CPolyline**)lua_touserdata(L, 1);
	luaL_argcheck(L, _ppPoly != NULL, 1, "invalid user data!");

	//取第二个入参
	lua_Number _nX = lua_tonumber(L, -2);

	//取第三个入参
	lua_Number _nY = lua_tonumber(L, -1);

	(*_ppPoly)->InsertNode(_nX, _nY);

	return 0;
}

int lua_emplace_cad(lua_State* L)
{
	//取栈底参数
	CCadGroup** _ppGroup = (CCadGroup**)lua_touserdata(L, 1);
	luaL_argcheck(L, _ppGroup != NULL, 1, "invalid user data!");

	//取第二个入参
	CPolyline** _ppCad = (CPolyline**)lua_touserdata(L, -1);
	
	(*_ppGroup)->Emplace(*_ppCad);
	return 0;
}

int luaopen_polyline_libs(lua_State* L)
{
	//创建新表,注册函数
	luaL_newlib(L, ope_lib);
	return 1;
}
