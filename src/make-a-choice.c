#include <gtk/gtk.h>



static void print_yes(GtkWidget *widget, gpointer data) {
    g_print("YES\n");
}

static void print_no(GtkWidget *widget, gpointer data) {
    g_print("NO\n");
}

static void activate(GtkApplication *app, gpointer user_data) {
    GtkWidget *window;
    GtkWidget *grid;
    GtkWidget *button; // use one pointer to create multiple button, function gtk_button_new_with_label return new pointer each time
    
  /* create a new window, and set its title */
    window = gtk_application_window_new(app);
    gtk_window_set_title(GTK_WINDOW(window), "Make a choice");

  /* Here we construct the container that is going pack our buttons */
    grid = gtk_grid_new ();

  /* Pack the container in the window */
    gtk_window_set_child(GTK_WINDOW (window), grid);

    button = gtk_button_new_with_label ("Yes");
    g_signal_connect (button, "clicked", G_CALLBACK (print_yes), NULL);

  /* Place the first button in the grid cell (0, 0), and make it fill
   * just 1 cell horizontally and vertically (ie no spanning)
   */
    gtk_grid_attach (GTK_GRID (grid), button, 0, 0, 1, 1);

    button = gtk_button_new_with_label ("No");
    g_signal_connect (button, "clicked", G_CALLBACK (print_no), NULL);

  /* Place the second button in the grid cell (1, 0), and make it fill
   * just 1 cell horizontally and vertically (ie no spanning)
   */
    gtk_grid_attach (GTK_GRID (grid), button, 1, 0, 1, 1);


    button = gtk_button_new_with_label ("Give up");
    g_signal_connect_swapped (button, "clicked", G_CALLBACK (gtk_window_destroy), window);

  /* Place the Quit button in the grid cell (0, 1), and make it
   * span 2 columns.
   */
    gtk_grid_attach (GTK_GRID (grid), button, 0, 1, 2, 1);


    gtk_grid_set_row_spacing(GTK_GRID (grid), 10);
    gtk_grid_set_column_spacing(GTK_GRID (grid), 10);


    gtk_window_present (GTK_WINDOW (window));
}

int main(int argc, char **argv) {
    GtkApplication *app;
    int status;

    app = gtk_application_new("fr.fishcorp.postfish", 0);
    g_signal_connect(app, "activate", G_CALLBACK(activate), NULL);
    status = g_application_run(G_APPLICATION(app), argc, argv);
    g_object_unref(app);

    return status;
}