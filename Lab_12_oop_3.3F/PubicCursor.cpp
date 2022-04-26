// PubicCursor.cpp
#include "PubicCursor.h"
#include <sstream>
#include <iostream>

using namespace std;

PubicCursor::PubicCursor(LongLong pos, char s, bool v)
{
    if (!(setPosition(pos) && setSize(s) && setView(v)))
        *this = PubicCursor();
}

PubicCursor::PubicCursor(const PubicCursor& c)
{
    *this = c;
}

PubicCursor& PubicCursor::operator=(const PubicCursor& c)
{
    size = c.size;
    view = c.view;
    *this = LongLong::operator=(c);
    return *this;
}

istream& operator>>(istream& in, PubicCursor& c) 
{
    long x, y;
    int s;
    bool v;
    do
    {
        cout << "¬вед≥ть позиц≥ю x: "; in >> x;
        cout << "¬вед≥ть позиц≥ю y: "; in >> y;
        cout << "¬вед≥ть розм≥р: "; in >> s;
        cout << "¬ед≥ть вид курсору(1 - horizontal, 0 - vertical): "; in >> v;
    } while (!(c.setPosition(LongLong(x, y)) && c.setSize(s) && c.setView(v)));
    return in;
}

PubicCursor::operator string() const
{
    stringstream ss;
    ss << '(' << getHigh() << ", " << getLow() << ") size: " << (int)size << (view ? " horizontal" : " vertical");
    return ss.str();
}

ostream& operator<<(ostream& out, const PubicCursor& c)
{
    out << string(c);
    return out;
}

bool PubicCursor::setPosition(LongLong ll)
{
    if (ll.getHigh() >= 0)
    {
        LongLong::operator=(ll);
        return true;
    }
    else
        return false;
}

bool PubicCursor::setSize(char s)
{
    if (s > 0 && s < 16)
    {
        size = s;
        return true;
    }
    else
        return false;
}

void PubicCursor::move(long x, long y)
{
    Hide();

    LongLong ll(y, x);
    LongLong::operator=(*this + ll);

    Show();
}

void PubicCursor::changeView()
{
    view = !view;
}

void PubicCursor::SizeUp()
{
    setSize(size + 1);
}

void PubicCursor::SizeDown()
{
    setSize(size - 1);
}

void PubicCursor::Show()
{
    cout << "PubicCursor shows" << endl;
}

void PubicCursor::Hide()
{
    cout << "PubicCursor hides" << endl;
}
