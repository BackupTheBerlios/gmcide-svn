#include <fltk/Window.h>
#include <fltk/MenuBar.h>
#include <fltk/Browser.h>
#include "ced.h"

#include <list>

#ifndef CONTROL_H
#define CONTROL_H


class control : public fltk::Window
{
private:
	void static quit_cb (fltk::Widget*, void* data);
	void static new_cb (fltk::Widget*, void* data);

	std::list<ced*> wc;

public:
	fltk::MenuBar *menubar;
	fltk::Browser *browser;

	control (int w, int h, const char* t);
}; // end class control

#endif
