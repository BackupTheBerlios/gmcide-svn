#include <fltk/Window.h>
#include <fltk/MenuBar.h>
#include <fltk/Browser.h>
#include "ced.h"

#include <list>

#ifndef CONTROL_H
#define CONTROL_H


class control : public fltk::Window
{
public:
	void static quit_cb (fltk::Widget*, void* data);
	void static new_cb (fltk::Widget*, void* data);
	void redraw_list ();
	void delete_this (fltk::Widget*);

	std::list<ced*> wc;
	std::list<ced*>::iterator wc_iterator;

	fltk::MenuBar *menubar;
	fltk::Browser *browser;

	control (int w, int h, const char*);
}; // end class control

#endif
