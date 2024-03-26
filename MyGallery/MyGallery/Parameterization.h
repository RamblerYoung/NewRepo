#pragma once


struct ParamItem
{
	string strName;
	double nVal;			//��ȫ����double   
	//Range range;         //ȡֵ��Χ

	bool Valid()const
	{
		return true;
	}

	ParamItem(const char* szName_="",double nVal_=0.0 ) :strName(szName_), nVal(nVal_)
	{

	}
};

typedef std::vector<CPolyline*> CadGroup;

struct CDrawing
{
	void AddItem(const char* szName_, double nVal_);
	bool Valid()const;


	//���ͼֽ��Ӧ��lua�ű�·��
	string m_strScriptPathName;

	//����
	CadGroup m_Group;

	//������
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