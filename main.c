#include <stdio.h>
#include <stdlib.h>
#include <gtk/gtk.h>

void on_telaP_destroy();
void on_click_clicked(GtkWidget *widget, gpointer data);

void on_click_clicked(GtkWidget *widget, gpointer data){

  on_telaP_destroy();
}

void on_telaP_destroy(){

  gtk_main_quit();
}

int main(int numArgs, char *nomArgs[]){

  GtkBuilder *arquivo;
  GtkWidget *tela;
  
  gtk_init(&numArgs, &nomArgs);

  arquivo = gtk_builder_new_from_file("IU.glade");
  tela = GTK_WIDGET(gtk_builder_get_object(arquivo, "telaP"));

  gtk_builder_add_callback_symbols(arquivo, "on_telaP_destroy", G_CALLBACK(on_telaP_destroy), "on_click_clicked", G_CALLBACK(on_click_clicked), NULL);
  gtk_builder_connect_signals(arquivo, NULL);

  gtk_widget_show(tela);

  gtk_main();
}
