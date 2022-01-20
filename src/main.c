#include <gtk/gtk.h>

static void print_leave_me(GtkWidget *widget, gpointer data)
{
	g_print("Leave me alone\n");
}

static void print_hello(GtkWidget *widget, gpointer data)
{
	g_print("Hello World\n");
}

static void activate(GtkApplication *app, gpointer user_data)
{
	GtkWidget *button;
	GtkWidget *grid;
	GtkWidget *window;

	/* Create a new window */
	window = gtk_application_window_new(app);

	/* Set its title */
	gtk_window_set_title(GTK_WINDOW(window), "Hello World GTK4");

	/* Default Window Size */
	gtk_window_set_default_size(GTK_WINDOW(window), 200, 200);

	/* Create a grid layout container */
	grid = gtk_grid_new();

	/* Make the grid a child of main window */
	gtk_window_set_child(GTK_WINDOW(window), grid);

	/* Create first button */
	button = gtk_button_new_with_label("Button 1");

	/* Clicked callback for first button */
	g_signal_connect(button, "clicked", G_CALLBACK(print_hello), NULL);

	/*
	 * Place the first button in cell (0,0) and make it fill a
	 * single cell horizontally and vertically
	 */
	gtk_grid_attach(GTK_GRID(grid), button, 0, 0, 1, 1);

	/* Create a second button */
	button = gtk_button_new_with_label("Button 2");

	/* Clicked callback for the second button */
	g_signal_connect(button, "clicked", G_CALLBACK(print_leave_me), NULL);

	/* Place the second button in cell (1,0) and make it fill a
	 * single cell horizontally and vertically
	 */
	gtk_grid_attach(GTK_GRID(grid), button, 1, 0, 1, 1);

	/* Create a third button */
	button = gtk_button_new_with_label("Quit");

	/* Clicked callback for the third button */
	g_signal_connect_swapped(button, "clicked",
			G_CALLBACK(gtk_window_destroy), window);

	/* Place the third button in cell (0,1) and make it fill two
	 * cells horizontally and one cell vertically.
	 */
	gtk_grid_attach(GTK_GRID(grid), button, 0, 1, 2, 1);

	/* Show our main window */
	gtk_widget_show(window);
}

int main(int argc, char **argv)
{
	GtkApplication *app;
	int status;

	app = gtk_application_new("org.gtk.example", G_APPLICATION_FLAGS_NONE);
	g_signal_connect(app, "activate", G_CALLBACK(activate), NULL);
	status = g_application_run(G_APPLICATION(app), argc, argv);
	g_object_unref(app);

	return status;
}
