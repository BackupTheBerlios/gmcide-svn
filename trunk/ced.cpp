#include <fltk/Window.h>
#include <fltk/ask.h>
#include <stdlib.h>
#include "control.h"
#include "ced.h"

static control *pcontrol; // global pointer for browser window

ced::ced (int w, int h) : fltk::Window(fltk::USEDEFAULT, fltk::USEDEFAULT, w, h)
{
	char buffer[30];
	callback (window_cb);
	begin (); // draw the window
		// Here starts the menu
		menubar = new fltk::MenuBar (0, 0, w, 30);

		menubar->begin ();
			menubar->add ("File/Open", 0, open_cb, (void*)this);
			menubar->add ("File/Exit", 0, exitthis_cb, (void*)this);
		menubar->end (); // here ends the menu

		ed = new fltk::TextEditor (0, 30, w, h); // the editor window
	end (); // end draw the window

	resizable (ed);
	ed->linenumber_width (60);
	ed->wrap_mode (true, 0);
	textbuf = new fltk::TextBuffer(0);
	ed->buffer (textbuf);
    ed->textfont(fltk::COURIER);

	sprintf (buffer, "%d", this);
	textbuf->text (buffer);
}

void ced::setcontrol (fltk::Window* w)
{
	pcontrol = (control*)w; // set the pointer to the control
}

void ced::open_cb (fltk::Widget* w, void* data)
{
	ced* tmp = (ced*)w->window ();
	/*const char *newfile = fltk::file_chooser("Open File?", "*", tmp->filename);
	if (newfile != NULL)
		tmp->load_file(newfile, -1);*/
    tmp->textbuf->text("line 0\nline 1\nline 2\n"
                "line 3\nline 4\nline 5\n"
                "line 6\nline 7\nline 8\n"
                "line 9\nline 10\nline 11\n"
                "line 12\nline 13\nline 14\n"
                "line 15\nline 16\nline 17\n"
                "line 18\nline 19\nline 20\n"
                "line 21\nline 22\nline 23\n");
}

void ced::load_file(const char *newfile, int ipos)
{
	char buffer[30];
	sprintf (buffer, "%s", newfile);
	fltk::ask (buffer);
	//textbuf->loadfile(newfile);
	//textbuf->insertfile(newfile, ipos);
}

void ced::exitthis_cb (fltk::Widget* w, void* data)
{
	fltk::Window* tmp = w->window ();
	pcontrol->delete_this (tmp); // tell control that this window is deleted
	tmp->hide ();
}

void ced::window_cb (fltk::Widget* w, void* data)
{
	pcontrol->delete_this ((fltk::Window*)w);
	((fltk::Window*)w)->hide();
}
