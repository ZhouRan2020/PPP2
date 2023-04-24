#ifndef UTILS
#define UTILS
#include "Point.h"
#include "fltk.h"
#include "std_lib_facilities.h"
typedef double Fct(double);
namespace gl {
struct Suffix {
  enum Encoding { none, jpg, gif, bmp };
};
} // namespace gl
gl::Suffix::Encoding get_encoding(const std::string &s);
// does two lines (p1,p2) and (p3,p4) intersect?
// if se return the distance of the intersect point as distances from p1

// intersection between two line segments
// Returns true if the two segments intersect,
// in which case intersection is set to the point of intersection
bool line_segment_intersect(gl::Point p1, gl::Point p2, gl::Point p3,
                            gl::Point p4, gl::Point &intersection);

std::pair<double, double> line_intersect(gl::Point p1, gl::Point p2,
                                         gl::Point p3, gl::Point p4,
                                         bool &parallel);
namespace gl {
void draw_mark(Point xy, char c);
}

bool can_open(const std::string &s);

//} // namespace gl
#endif