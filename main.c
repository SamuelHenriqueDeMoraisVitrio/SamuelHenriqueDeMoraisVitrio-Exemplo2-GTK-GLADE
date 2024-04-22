#include <stdio.h>
#include <stdlib.h>
#include <gtk/gtk.h>


void on_telaP_destroy();
void on_click_clicked(GtkWidget *widget, gpointer data);

GtkEntry *peso;
GtkEntry *altura;
GtkLabel *resultados;

void on_click_clicked(GtkWidget *widget, gpointer data){

  const char *str_peso = gtk_entry_get_text(peso);//Pode usar char ou gchar, tanto faz.

  float float_p = atof(str_peso);

  printf("\n\t%d\n\n", float_p);
}

void on_telaP_destroy(){

  system("clear");
  gtk_main_quit();
}

int main(int numArgs, char *nomArgs[]){
  system("clear");

  GtkBuilder *arquivo;
  GtkWidget *tela;
  
  gtk_init(&numArgs, &nomArgs);

  arquivo =    gtk_builder_new_from_file("IU.glade");
  tela =       GTK_WIDGET(gtk_builder_get_object(arquivo, "telaP"));
  peso =       GTK_ENTRY(gtk_builder_get_object(arquivo,  "pesoIN"));
  altura =     GTK_ENTRY(gtk_builder_get_object(arquivo,  "alturaIN"));
  resultados = GTK_LABEL(gtk_builder_get_object(arquivo, "resultado"));

  gtk_builder_add_callback_symbols(arquivo, "on_telaP_destroy", G_CALLBACK(on_telaP_destroy), "on_click_clicked", G_CALLBACK(on_click_clicked), NULL);
  gtk_builder_connect_signals(arquivo, NULL);

  gtk_widget_show_all(tela);

  gtk_main();
}
