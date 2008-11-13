#include <fltk/Window.h>
#include <fltk/MenuBar.h>
#include <fltk/TextEditor.h>
#include <fltk/TextBuffer.h>
#include <fltk/file_chooser.h>

#ifndef CED_H
#define CED_H

class ced : public fltk::Window
{
private:
	static void exitthis_cb (fltk::Widget* w, void* data);
	static void window_cb (fltk::Widget* w, void* data);
	static void open_cb (fltk::Widget* w, void* data);
	void load_file (const char*, int);

public:
	fltk::MenuBar *menubar;
	fltk::TextEditor *ed;
	fltk::TextBuffer *textbuf;
	char filename[256];

	ced (int w, int h);
	void setcontrol (fltk::Window* w);
}; // end class ced

#endif
