// MyGallery.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "stdafx.h"
#include <iostream>

#include "Common.h"
using namespace std;

#include "CPolyline.h"
#include "PolylineReg.h"
#include "Parameterization.h"

void PrintDrawing(const CDrawing* pDrawing_);

static const luaL_Reg lua_reg_libs[] = {
	{ "base", luaopen_base }, //系统模块
	{ "Geometry", luaopen_polyline_libs}, //几何模块
	{ "Drawing", luaopen_parameterization_libs}, //图库参数化

	{ NULL, NULL }
};

int main()
{
	if (lua_State* L = luaL_newstate()) {
		//0.注册让lua使用的库
		const luaL_Reg* lua_reg = lua_reg_libs;
		for (; lua_reg->func; ++lua_reg) {
			luaL_requiref(L, lua_reg->name, lua_reg->func, 1);
			lua_pop(L, 1);
		}

		//加载脚本
		//if (luaL_dofile(L, "Triangle.lua"))
		if (luaL_dofile(L, "hole_rect.lua"))
		//if (luaL_dofile(L, "Rect.lua")) 
		{
			cout << lua_tostring(L, -1) << endl;
		}

		CDrawing* _pDrawing = new CDrawing();

		//1.初始化
		lua_getglobal(L, "init");
		lua_pushlightuserdata(L, &_pDrawing);
		int nRet = lua_pcall(L, 1, 1, 0);
		if (nRet)
		{
			const char* pErrorMsg = lua_tostring(L, -1);
			cout << pErrorMsg << endl;
			lua_close(L);
			return 0;
		}

		//2.计算shape
		lua_getglobal(L, "clac");		// 获取函数，压入栈中
		// 栈过程：参数出栈->保存参数->参数出栈->保存参数->函数出栈->调用函数->返回结果入栈
		// 调用函数，调用完成以后，会将返回值压入栈中，0表示参数个数，1表示返回结果个数。
		int iRet = lua_pcall(L, 0, 1, 0);

		if (iRet)
		{
			print_stack(L);
			// 调用出错
			const char* pErrorMsg = lua_tostring(L, -1);
			cout << pErrorMsg << endl;
			lua_close(L);
			return 0;
		}

		if (lua_isuserdata(L, -1))
		{
			CCadGroup** _ppgroup = (CCadGroup**)lua_touserdata(L, -1);
			_pDrawing->m_pGroup = *_ppgroup;
		}

		//3.绘制缩略图
		//todo ...

		//4.print
		PrintDrawing(_pDrawing);

		//cout << "\nCurrent lua stack:" << endl;
		//print_stack(L);

		lua_close(L);
	}
	else {
		cout << "luaL_newstate error !" << endl;
	}

	system("pause");

	return 0;
}

void PrintDrawing(const CDrawing* pDrawing_)
{
	cout << "============Drawing information=============" << endl;
	cout << "\tParameter:" << endl;
	for (auto _it = pDrawing_->m_vecParamItems.begin(); _it != pDrawing_->m_vecParamItems.end(); ++_it)
	{
		cout <<"\t\t"<< _it->strName << ":" << _it->nVal << endl;
	}

	cout << "\tGeometry:" << endl;
	cout << "\t\tcad count:" << pDrawing_->m_pGroup->m_vecCad.size()<< endl;
	for (int nIdx(0); nIdx < pDrawing_->m_pGroup->m_vecCad.size(); ++nIdx)
	{
		cout << "\t\t\tPolyline_" << nIdx << endl;
		CPolyline* _polyline = pDrawing_->m_pGroup->m_vecCad[nIdx];
		cout << "\t\t\t\tStart: (" << _polyline->GetStart().nX << "," << _polyline->GetStart().nY << ")" << endl;
		cout << "\t\t\t\tSegs:" << endl;
		const std::vector<DPOINT>& _vecSeg = _polyline->GetSegments();
		for (auto _it = _vecSeg.cbegin(); _vecSeg.cend() != _it; ++_it)
		{
			cout << "\t\t\t\t\t(" << _it->nX << "," << _it->nY << ")" << endl;
		}
	}


	cout << "============================================" << endl;
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
