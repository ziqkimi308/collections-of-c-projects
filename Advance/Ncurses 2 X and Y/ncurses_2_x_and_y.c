#include <ncurses.h>

int main()
{
	int x, y;

	initscr(); // Create a window
	clear();

	getyx(stdscr, y, x); // Track cursor position
	printw("(x, y) = (%d, %d)", x, y);
	refresh();

	x = 5;
	y = 5;
	move(y, x); // Actually move cursor to x, y coordinates

	getyx(stdscr, y, x);
	printw("(x, y) = (%d, %d)", x, y);
	refresh();

	getch();
	endwin(); // Close window

	return 0;
}