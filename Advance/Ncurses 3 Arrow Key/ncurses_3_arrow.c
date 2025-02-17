#include <ncurses.h>

int main()
{
	int x, y, key;

	initscr();
	keypad(stdscr, TRUE); // Activate the arrow key (and the rest of keypad)
	noecho();

	x = y = 10;

	while (key != 'q')
	{
		clear(); // This erases everything on screen and move cursor back to (0,0)
		
		// Print instruction on top left
		printw("Press left or right arrow - exit by pressing q");

		// Move the cursor
		move(y, x);
		printw("O");
		refresh();

		key = getch();
		if (key == KEY_LEFT)
		{
			x--;
			if (x < 0) x = 0;
		}
		else if (key == KEY_RIGHT)
		{
			x++;
			if (x > 30) x = 30;
		}
		else if (key == KEY_UP)
		{
			y--; // y is inverted in ncurses
			if (y < 5) y = 5;
		}
		else if (key == KEY_DOWN)
		{
			y++;
			if (y > 35) y = 35;
		}
	}

	// End
	endwin();
	return 0;
}