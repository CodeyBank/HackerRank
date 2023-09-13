#include <iostream>

using namespace std;
/*
 * Create classes Rectangle and RectangleArea
 */

class Rectangle
{

public:
    int width;
    int height;

    Rectangle()
    {
    }
    Rectangle(int w, int h) : width(w), height(h)
    {
    }

    void display()
    {
        cout << width << " " << height << endl;
    }
};

class RectangleArea : public Rectangle
{
public:
    RectangleArea()
    {
    }
    void read_input(void)
    {
        cin >> Rectangle::width >> Rectangle::height;
    }
    void display()
    {
        cout << Rectangle::width * Rectangle::height;
    }
};


int main()
{
    /*
     * Declare a RectangleArea object
     */
    RectangleArea r_area;

    /*
     * Read the width and height
     */
    r_area.read_input();

    /*
     * Print the width and height
     */
    r_area.Rectangle::display();

    /*
     * Print the area
     */
    r_area.display();

    return 0;
}
