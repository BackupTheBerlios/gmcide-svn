#include <fltk/Window.h>
#include <fltk/run.h>
#include <stdlib.h>
#include <iostream>

#include "control.h"

int main(int argc, char **argv)
{ // start main
	control win (400, 400, "Test Control");
	win.show ();
	return fltk::run ();
} // end main
