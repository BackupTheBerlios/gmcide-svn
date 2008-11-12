#include <fltk/Window.h>
#include <fltk/ask.h>
#include <stdlib.h>
#include "control.h"
#include "ced.h"

static control *pcontrol; // global pointer for browser window

ced::ced (int w, int h) : fltk::Window(fltk::USEDEFAULT, fltk::USEDEFAULT, w, h)
{
	callback (window_cb);
	begin (); // draw the window
		// Here starts the menu
		menubar = new fltk::MenuBar (0, 0, w, 30);

		menubar->begin ();
			//menubar->add("File/Exit This", 0, exitthis_cb, (void*)this);

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
	pcontrol = (control*)w; // set the pointer to the control
}

void ced::exitthis_cb(fltk::Widget* w, void* data)
{
	char buffer[30];

	fltk::Window* tmp = w->window ();
	sprintf (buffer, "%d - %d - %d", w, tmp, pcontrol);
	if (fltk::ask (buffer))
	{
		pcontrol->delete_this (w); // tell control that this window is deleted
		tmp->hide ();
	}
}

void ced::window_cb (fltk::Widget* w, void* data)
{
	char buffer[30];
	fltk::Window* tmp = w->window ();
	sprintf (buffer, "%d - %d - %d", w, tmp, pcontrol);
	if (fltk::ask (buffer))
	{
		//pcontrol->delete_this ((fltk::Window*)w);
    	((fltk::Window*)w)->hide();
	}
}
