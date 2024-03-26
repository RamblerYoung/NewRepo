#include "stdafx.h"
#include <functional>
#include <algorithm>
#include "CPolyline.h"
#include "Common.h"
#include "Parameterization.h"

int lua_add(lua_State* L)
{
	//取栈底参数
	CDrawing** _ppDraw = (CDrawing**)lua_touserdata(L, 1);
	luaL_argcheck(L, _ppDraw != NULL, 1, "invalid user data!");

	//取第一个入参
	const char* _szName = lua_tostring(L, -2);

	//取第二个入参
	const lua_Number _nVal = lua_tonumber(L, -1);

	(*_ppDraw)->AddItem(_szName, _nVal);
	
	return 0;
}

int lua_valid(lua_State* L)
{
	return 0;
}

int lua_calcshapes(lua_State* L)
{
	return 0;
}

int lua_drawpreview(lua_State* L)
{
	return 0;
}

int luaopen_parameterization_libs(lua_State* L)
{
	luaL_newlib(L, open_param_lib);
	return 1;
}

void CDrawing::AddItem(const char* szName_, double nVal_)
{
	m_vecParamItems.emplace_back(ParamItem(szName_, nVal_));
}

bool CDrawing::Valid() const
{
	return std::all_of(m_vecParamItems.begin(), m_vecParamItems.end(), std::bind(&ParamItem::Valid, placeholders::_1));
}
