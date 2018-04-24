#include <config.h>
#include <gtk/gtk.h>


#include <glib/gi18n.h>


static GtkWidget *
create_window (void)
{
  GtkWidget *window;
  GtkBuilder *builder;
  GError *error = NULL;

  /* Load UI from file */
  builder = gtk_builder_new ();
  if (!gtk_builder_add_from_file (builder, UI_FILE, &error))
    {
      g_critical ("Couldn't load builder file: %s", error->message);
      g_error_free (error);
    }

  /* Auto-connect signal handlers */
  gtk_builder_connect_signals (builder, NULL);

  /* Get the window object from the ui file */
  window = GTK_WIDGET (gtk_builder_get_object (builder, TOP_WINDOW));
  if (!window)
    {
      g_critical ("Widget \"%s\" is missing in file %s.",
		  TOP_WINDOW, UI_FILE);
    }

  priv = g_malloc (sizeof (struct _Private));
  /* ANJUTA: Widgets initialization for gtk_foobar.ui - DO NOT REMOVE */

  g_object_unref (builder);

  return window;
}
