
//#include "Window.h"    // get access to our window library
//#include "Graph.h"            // get access to our graphics library facilities
#include "GUI.h"

template<class T> class Vector_ref {
	vector<T*> v;
	vector<T*> owned;
public:
	Vector_ref(){}
	Vector_ref(T* a, T* b = 0, T* c = 0, T* d = 0);

	~Vector_ref() { for (int i = 0; i < owned.size(); ++i) delete owned[i]; }


	void push_back(T& s) { v.push_back(&s); }
	void push_back(T* p) { v.push_back(p); owned.push_back(p); }

	T& operator[](int i) { return *v[i]; }
	const T& operator[](int i)const { return *v[i]; }
	int size()const { return v.size(); }

};
//using namespace Graph_lib;
/*
class Button : public Graph_lib::Widget {
public:
	Button(Graph_lib::Point xy,int ww,int hh,const string& s, Graph_lib::Callback cb)
		:Widget{xy,ww,hh,s,cb}{}
};

struct In_box : Graph_lib::Widget {
	In_box(Graph_lib::Point xy,int w,int h,const string& s)
		:Widget{xy,w,h,s,0}{}
	int get_int();
	string get_string();

	void attach(Graph_lib::Window& win);
};

struct Out_box :Graph_lib::Widget {
	Out_box(Graph_lib::Point xy,int w,int h,const string& s)
		:Graph_lib::Widget{xy,w,h,s,0}{}
	void put(int);
	void put(const string&);

	void attach(Graph_lib::Window& win);
};

struct Menu : Graph_lib::Widget {
	enum Kind{horizontal,vertical};
	Menu(Graph_lib::Point xy, int w, int h, Kind kk, const string& label);
	Vector_ref<Button> selection;
	Kind k;
	int offset;
	int attach(Button& b);
	int attach(Button* p);

	void show()
	{
		for (Button& b : selection) b.show();
	}
	void hide();
	void move(int dx, int dy);

	void attach(Graph_lib::Window& win);
};

struct Lines_window : Graph_lib::Window {
	Lines_window(Graph_lib::Point xy, int w, int h, const string& title);
	Graph_lib::Open_polyline lines;
private:
	Button next_button;
	Button quit_button;
	In_box next_x;
	In_box next_y;
	Out_box xy_out;

	void next() {
		int x = next_x.get_int();
		int y = next_y.get_int();
		lines.add(Graph_lib::Point{ x,y });

		ostringstream ss;
		ss << '(' << x << ',' << y << ')';
		xy_out.put(ss.str());

		redraw();
	};

	void quit() {
		hide();
	};
};

*/
//------------------------------------------------------------------------------

int main()
try{/*
	Lines_window win{ Graph_lib::Point{100,100},600,400,"lines" };*/
	return Graph_lib::gui_main();
	return 0;
}
catch (exception& e) {
	cerr << "exception:" << e.what() << '\n';
	return 1;
}
catch (...) {
	cerr << "some exception\n";
	return 2;
}


