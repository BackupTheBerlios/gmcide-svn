#include <fltk/Window.h>
#include <fltk/MenuBar.h>
#include <fltk/TextEditor.h>
#include <fltk/TextBuffer.h>

#ifndef CED_H
#define CED_H

class ced : public fltk::Window
{
private:
	static void exitthis_cb(fltk::Widget* w, void* data);
public:
	fltk::MenuBar *menubar;
	fltk::TextEditor *ed;
	fltk::TextBuffer *textbuf;

	ced (int w, int h, const char* t);
}; // end class ced

#endif