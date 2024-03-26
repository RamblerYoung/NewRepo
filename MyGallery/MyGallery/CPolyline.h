#pragma once

template<typename T>
struct PointT
{
	T nX;
	T nY;

	PointT() = default;
	PointT(T nX_, T nY_)
	{
		nX = nX_;
		nY = nY_;
	}
};

typedef PointT<double> DPOINT;

class CPolyline
{
public:
	CPolyline():m_ptStart(0.,0.) {};

	const DPOINT GetStart()const { return m_ptStart; };
	const std::vector<DPOINT>& GetSegments()const { return m_vecSegs; };

	void SetStart(double nX_, double nY_);
	void InsertNode(double nX_, double nY_);

protected:
	DPOINT m_ptStart;

	//先只支持直线
	std::vector<DPOINT> m_vecSegs;
};

struct CCadGroup
{
	CCadGroup(){ m_vecCad.clear(); }

	void Emplace(CPolyline* pPolyline_) { m_vecCad.emplace_back(pPolyline_); };

	std::vector<CPolyline*> m_vecCad;
};