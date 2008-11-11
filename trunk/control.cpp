#include <fltk/Window.h>
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include "control.h"
#include "ced.h"

control::control (int w, int h, const char* t) : fltk::Window(fltk::USEDEFAULT, fltk::USEDEFAULT, w, h, t)
{
	begin (); // draw the window
		// Here starts the menu
		menubar = new fltk::MenuBar (0, 0, w, 30);


		menubar->begin ();
			menubar->add("File/New File", 0, new_cb, (void *)this);
			menubar->add("File/Quit", 0, quit_cb);
		menubar->end (); // here ends the menu

		const char *labels[] = {"Opened files", 0};
		int widths[]   = {-1, 0};

		browser = new fltk::Browser (0, 40, w, 200);
		browser->column_widths (widths);
		browser->column_labels (labels);
	end (); // end draw the window
}


void control::quit_cb (fltk::Widget*, void* data)
{
	exit (0);
}

void control::redraw_list ()
{

	char static buffer2[20];
	int static ic;

	browser->clear ();

	for(wc_iterator=wc.begin(); wc_iterator != wc.end(); wc_iterator++)
	{
		ic = wc.size ();
		sprintf (buffer2, "Anzahl Datensätze %d, %s", ic,(*wc_iterator)->label ());
		browser->add (buffer2);
	}
}

void control::delete_this (fltk::Widget* w)
{
	ced* cw = (ced*) w->window ();
	wc.remove (cw);
	redraw_list ();
}

void control::new_cb (fltk::Widget* w, void* data)
{
	int static ic;
	char buffer[20];
	control* tmp = (control*) w->window ();
	ic = tmp->wc.size ();
	sprintf (buffer, "No Name %d", ic+1);
	ced* cedwin = new ced (200, 200);
	cedwin->copy_label (buffer); // Important for own copy - else garbage displays
	cedwin->setcontrol (tmp); // send a pointer from control to ced
	cedwin->show ();
	tmp->wc.push_back (cedwin); // wright it into the list
	tmp->redraw_list (); // redraw the list
}
