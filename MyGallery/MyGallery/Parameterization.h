#pragma once


struct ParamItem
{
	string strName;
	double nVal;			//先全部用double   
	//Range range;         //取值范围

	bool Valid()const
	{
		return true;
	}

	ParamItem(const char* szName_="",double nVal_=0.0 ) :strName(szName_), nVal(nVal_)
	{

	}
};

struct CDrawing
{
	CDrawing():m_pGroup(nullptr), m_strScriptPathName("")
	{
		//m_pGroup = new CCadGroup();
	}

	void AddItem(const char* szName_, double nVal_);
	bool Valid()const;


	//与该图纸对应的lua脚本路径
	string m_strScriptPathName;

	//几何
	CCadGroup* m_pGroup;

	//参数化
	std::vector<ParamItem> m_vecParamItems;
};

int lua_add(lua_State* L);
int lua_valid(lua_State* L);
int lua_calcshapes(lua_State* L);
int lua_drawpreview(lua_State* L);

static const luaL_Reg open_param_lib[] = {
	{ "add", lua_add },
	{ "valid", lua_valid },
	{ "calc", lua_calcshapes },
	{ "draw", lua_drawpreview },

	{ NULL, NULL },
};
int luaopen_parameterization_libs(lua_State* L);