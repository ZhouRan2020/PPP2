
#include "Simple_window.h"    // get access to our window library
#include "Graph.h"            // get access to our graphics library facilities

int fac(int n) {
	int r = 1;
	while (n > 1) {
		r *= n;
		--n;

	}
	return r;
}

double term(double x, int n) { return pow(x, n) / fac(n); }

double expe(double x ,int n) {
	double sum = 0;
	for (int i = 0; i < n; ++i) sum += term(x, i);
	return sum;
}
//------------------------------------------------------------------------------

int main()
{
	using namespace Graph_lib;   // our graphics facilities are in Graph_lib
	constexpr int xmax = 700;
	constexpr int ymax = 700;
	constexpr int x_orig = xmax / 2;
	constexpr int y_orig = ymax / 2;
	constexpr Point orig{ x_orig,y_orig };
	constexpr int r_min = -10;
	constexpr int r_max = 11;
	constexpr int n_points = 400;
	constexpr int x_scale = 35;
	constexpr int y_scale = 35;
	
	Simple_window win{ Point{100,100},xmax,ymax,"Function graphing" };

	for (int n = 0; n < 20; ++n) {

		ostringstream oss;
		oss << "exponential approximation;n==" << n;
		win.set_label(oss.str());

		
		//Function e( [n](double x) {return expe(x, n);}, r_min, r_max, orig, n_points, x_scale, y_scale);

		Function e_test ( [](double x) {return expe(x, 8); }, r_min, r_max, orig, n_points, x_scale, y_scale);


		win.attach(e_test);
		win.wait_for_button();
		win.detach(e_test);
	}
	


	


}


