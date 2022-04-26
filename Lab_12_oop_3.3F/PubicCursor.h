// PubicCursor.h
#pragma once
#include "LongLong.h"
#include <iostream>
using namespace std;

class PubicCursor : public LongLong
{
	char size;
	bool view;
public:
	PubicCursor(LongLong pos = LongLong(0,0), char size = 1, bool  view = false);
	PubicCursor(const PubicCursor& c);
	PubicCursor& operator=(const PubicCursor& c);
	
	operator string() const;
	friend ostream& operator<<(ostream& out, const PubicCursor& c);
	friend istream& operator>>(istream& in, PubicCursor& c);

	bool setPosition(LongLong ll);
	char getSize() { return size; }
	bool setSize(char s);
	bool getView() { return view; }
	bool setView(bool v) { view = v; return true; }

	void move(long x, long y);
	void changeView();
	void SizeUp();
	void SizeDown();

	void Show();
	void Hide();
};

