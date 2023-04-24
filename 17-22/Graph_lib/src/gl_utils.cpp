#include "gl_utils.h"

namespace {
std::map<std::string, gl::Suffix::Encoding> suffix_map;
int init_suffix_map() {
  suffix_map["jpg"] = gl::Suffix::jpg;
  suffix_map["JPG"] = gl::Suffix::jpg;
  suffix_map["jpeg"] = gl::Suffix::jpg;
  suffix_map["JPEG"] = gl::Suffix::jpg;
  suffix_map["gif"] = gl::Suffix::gif;
  suffix_map["GIF"] = gl::Suffix::gif;
  suffix_map["bmp"] = gl::Suffix::bmp;
  suffix_map["BMP"] = gl::Suffix::bmp;
  return 0;
}
int x = init_suffix_map();
} // namespace

gl::Suffix::Encoding get_encoding(const std::string &s)
// try to deduce type from file name using a lookup table
{
  std::string::const_iterator p = find(s.begin(), s.end(), '.');
  if (p == s.end())
    return gl::Suffix::none; // no suffix

  std::string suf(p + 1, s.end());
  return suffix_map[suf];
}

std::pair<double, double> line_intersect(gl::Point p1, gl::Point p2,
                                         gl::Point p3, gl::Point p4,
                                         bool &parallel) {
  double x1 = p1.x;
  double x2 = p2.x;
  double x3 = p3.x;
  double x4 = p4.x;
  double y1 = p1.y;
  double y2 = p2.y;
  double y3 = p3.y;
  double y4 = p4.y;
  double denom = ((y4 - y3) * (x2 - x1) - (x4 - x3) * (y2 - y1));

  if (denom == 0) {
    parallel = true;
    return std::pair<double, double>(0, 0);
  }

  parallel = false;
  return std::pair<double, double>(
      ((x4 - x3) * (y1 - y3) - (y4 - y3) * (x1 - x3)) / denom,
      ((x2 - x1) * (y1 - y3) - (y2 - y1) * (x1 - x3)) / denom);
}

bool can_open(const std::string &s)
// check if a file named s exists and can be opened for reading
{
  std::ifstream ff(s.c_str());
  return ff.is_open();
}

void gl::draw_mark(gl::Point xy, char c) {
  static const int dx = 4;
  static const int dy = 4;
  std::string m(1, c);
  fl_draw(m.c_str(), xy.x - dx, xy.y + dy);
}

bool line_segment_intersect(gl::Point p1, gl::Point p2, gl::Point p3,
                            gl::Point p4, gl::Point &intersection) {
  bool parallel;
  std::pair<double, double> u = line_intersect(p1, p2, p3, p4, parallel);
  if (parallel || u.first < 0 || u.first > 1 || u.second < 0 || u.second > 1)
    return false;
  intersection.x = p1.x + u.first * (p2.x - p1.x);
  intersection.y = p1.y + u.first * (p2.y - p1.y);
  return true;
}