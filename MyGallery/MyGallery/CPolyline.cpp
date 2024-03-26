#include "stdafx.h"
#include "CPolyline.h"

void CPolyline::SetStart(double nX_, double nY_)
{
	m_ptStart = DPOINT(nX_, nY_);
}

void CPolyline::AddNode(double nX_, double nY_)
{
	m_vecSegs.emplace_back(DPOINT(nX_, nY_));
}
