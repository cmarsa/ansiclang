// points.c
#include <stdlib.h>
#include <stdio.h>
#define XMAX 50
#define YMAX 50
/**
 * - struct -
 * a structure for storing x and y components
 * of a point in two dimensions.
 */
struct point
{
    int x;
    int y;
};



/**
 * - function -
 * makepoint: make a point from x and y components
 */
struct point makepoint(int x, int y)
{
    struct point temp;

    temp.x = x;
    temp.y = y;
    return temp;
};


/**
 * - struct -
 * a structure for storing the two necessary
 * points to define a rectangle.
 */
struct rect {
    struct point pt1;
    struct point pt2;
};


/*
 * next step is a set of functions to do arithmetic on points.
 * for instance
 */

/**
 * - function -
 * addpoints: add two points */
struct point addpoint(struct point p1, struct point p2) {
    p1.x += p2.x;
    p1.y += p2.y;
    return p1;
}

/**
 * - function -
 * ptinrect: return 1 if p in r, 0 if not
 */
int ptinrect(struct point p, struct rect r) {
    return p.x >= r.pt1.x && p.x < r.pt2.x &&
           p.y >= r.pt1.y && p.y < r.pt2.y;
}

/**
 * this assumes that the rectangle is presented in a standard form where the pt1
 * coordinates are less than the pt2 coordinates. The following function retuns
 * a rectangle guaranteed to be in canonical form
 */
#define min(a, b) ((a) < (b) ? (a) : (b))
#define max(a, b) ((a) > (b) ? (a) : (b))
/**
 * - function -
 * canonrect: canonicalize coordinates of rectangle
 */
struct rect canonrect(struct rect r) {
    struct rect temp;

    temp.pt1.x = min(r.pt1.x, r.pt2.x);
    temp.pt1.y = min(r.pt1.y, r.pt2.y);
    temp.pt2.x = max(r.pt1.x, r.pt2.x);
    temp.pt2.y = max(r.pt1.y, r.pt2.y);
    return temp;
}

int main() {
    /**
     * makepoint can now be used to initialize any structure dynamically, or to provide structure
     * arguments to a function:
     */
    struct rect screen;
    struct point middle;
    struct point makepoint(int, int);

    screen.pt1 = makepoint(0, 0);
    screen.pt2 = makepoint(XMAX, YMAX);
    middle = makepoint((screen.pt1.x + screen.pt2.x) / 2,
                    (screen.pt1.y + screen.pt2.y) / 2);


    /**
     * pp is a pointer to a structure of type struct point . If pp points to a point structure,
     * *pp is the structure, and (*pp).x and (*pp).y are the members.
     */
    struct point origin, *pp;
    pp = &origin;
    printf("origin is (%d,%d)\n", (*pp).x, (*pp).y);

    printf("origin is (%d,%d)\n", pp->x, pp->y);

}
