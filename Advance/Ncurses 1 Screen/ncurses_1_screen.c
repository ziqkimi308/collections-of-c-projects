// NOTES: You need to compile with library flag "-lncurses"

#include <ncurses.h> // Probably means "new cursus"

int main()
{
	char letter;

	// Initialize scree
	initscr();

	// User input
	// "printf" of ncurses
	printw("Press any key");
	refresh();

	// Capture user input
	letter = getch();
	clear();
	printw("You pushed: '%c'", letter);
	refresh();

	// End the window only after user input
	getch();
	endwin();

	return 0;
}