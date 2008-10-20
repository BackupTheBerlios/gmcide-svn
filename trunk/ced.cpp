#include <fltk/Window.h>
#include <stdlib.h>
#include "control.h"
#include "ced.h"

static control *pcontrol; // global pointer for browser window

ced::ced (int w, int h, const char* t) : fltk::Window(fltk::USEDEFAULT, fltk::USEDEFAULT, w, h, t)
{
	begin (); // draw the window
		// Here starts the menu
		menubar = new fltk::MenuBar (0, 0, w, 30);

		menubar->begin ();
			menubar->add("File/Exit This", 0, exitthis_cb, (void*)this);
		menubar->end (); // here ends the menu

		ed = new fltk::TextEditor (0, 30, w, h); // the editor window
	end (); // end draw the window

	resizable (ed);
	ed->linenumber_width (60);
	ed->wrap_mode (true, 0);
}

void ced::setcontrol (fltk::Window* w)
{
	pcontrol = (control*)w;
}

void ced::exitthis_cb(fltk::Widget* w, void* data)
{
	pcontrol->browser->add ("good");
	fltk::Window* tmp = w->window ();
	tmp->hide ();
}

