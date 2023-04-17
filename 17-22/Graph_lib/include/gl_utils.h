#pragma once
#include "std_lib_facilities.h"
#include "Point.h"
#include "fltk.h"

namespace gl {

// does two lines (p1,p2) and (p3,p4) intersect?
// if se return the distance of the intersect point as distances from p1
inline std::pair<double,double> line_intersect(Point p1, Point p2, Point p3, Point p4, bool& parallel) 
{
    double x1 = p1.x;
    double x2 = p2.x;
	double x3 = p3.x;
	double x4 = p4.x;
	double y1 = p1.y;
	double y2 = p2.y;
	double y3 = p3.y;
	double y4 = p4.y;
	double denom = ((y4-y3)*(x2-x1) - (x4-x3)*(y2-y1));

	if (denom == 0){
		parallel= true;
		return std::pair<double,double>(0,0);
	}

	parallel = false;
	return std::pair<double,double>(((x4-x3)*(y1-y3)-(y4-y3)*(x1-x3))/denom,((x2-x1)*(y1-y3)-(y2-y1)*(x1-x3))/denom);
}


//intersection between two line segments
//Returns true if the two segments intersect,
//in which case intersection is set to the point of intersection
inline bool line_segment_intersect(Point p1, Point p2, Point p3, Point p4, Point& intersection)
{
    bool parallel;
    std::pair<double,double> u = line_intersect(p1,p2,p3,p4,parallel);
    if (parallel || u.first < 0 || u.first > 1 || u.second < 0 || u.second > 1) 
		return false;
    intersection.x = p1.x + u.first*(p2.x - p1.x);
    intersection.y = p1.y + u.first*(p2.y - p1.y);
    return true;
}

inline void draw_mark(Point xy, char c)
{
	static const int dx = 4;
	static const int dy = 4;
	std::string m(1,c);
	fl_draw(m.c_str(),xy.x-dx,xy.y+dy);
}

inline bool can_open(const std::string& s)
            // check if a file named s exists and can be opened for reading
{
	std::ifstream ff(s.c_str());
	return ff.is_open();
}

} 