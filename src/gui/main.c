#include <gtk/gtk.h>
#include <stdio.h>
#define nullptr NULL

// GtkWidget *togglebutton;
// GtkWidget *checkbutton;
// GtkWidget *radiobutton1, *radiobutton2;

void closeApp(GtkWidget *window, gpointer data)
{
    gtk_main_quit();
}

void add_widget_with_label(GtkContainer *box, gchar *caption, GtkWidget *widget)
{
    GtkWidget *label = gtk_label_new(caption);
    GtkWidget *hbox = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 1);

    gtk_label_set_width_chars(GTK_LABEL(label), 0);

    gtk_container_add(GTK_CONTAINER(hbox), label);
    gtk_container_add(GTK_CONTAINER(hbox), widget);

    gtk_container_add(box, hbox);
}

// void print_active(char *button_name, GtkToggleButton *button)
// {
//     gboolean active = gtk_toggle_button_get_active(button);

//     printf("%s is %s\n", button_name, active ? "active" : "not active");
// }

// void button_clicked(GtkWidget *button, gpointer data)
// {
//     print_active("Check button  ", GTK_TOGGLE_BUTTON(checkbutton));
//     print_active("Toggle button ", GTK_TOGGLE_BUTTON(togglebutton));
//     print_active("Radio button 1", GTK_TOGGLE_BUTTON(radiobutton1));
//     print_active("Radio button 2", GTK_TOGGLE_BUTTON(radiobutton2));
//     printf("\n");
// }

// int main(int argc, char *argv[])
// {
//     GtkWidget *window;
//     GtkWidget *button;
//     GtkWidget *button2;
//     GtkWidget *vbox;
//     GtkWidget *vbox2;

//     gtk_init(&argc, &argv);
//     GtkWidget *fix = gtk_fixed_new();
//     window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
//     gtk_window_set_title(GTK_WINDOW(window), "Buttons");
//     gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER);
//     gtk_window_set_default_size(GTK_WINDOW(window), 300, 200);
//     gtk_container_set_border_width(GTK_CONTAINER(window), 10);

//     g_signal_connect(G_OBJECT(window), "destroy", G_CALLBACK(closeApp), NULL);

//     button = gtk_button_new_with_label("OK");
//     button2 = gtk_button_new_with_label("NOT OK");
//     togglebutton = gtk_toggle_button_new_with_label("Toggle");
//     checkbutton = gtk_check_button_new();
//     radiobutton1 = gtk_radio_button_new(NULL);
//     radiobutton2 = gtk_radio_button_new_from_widget(GTK_RADIO_BUTTON(radiobutton1));

//     vbox = gtk_box_new(GTK_ORIENTATION_VERTICAL, 10);
//     vbox2 = gtk_box_new(GTK_ORIENTATION_VERTICAL, 10);

//     add_widget_with_label(GTK_CONTAINER(vbox), "Toggle Button:", togglebutton);
//     add_widget_with_label(GTK_CONTAINER(vbox), "Check Button:", checkbutton);
//     add_widget_with_label(GTK_CONTAINER(vbox), "Radio 1:", radiobutton1);
//     add_widget_with_label(GTK_CONTAINER(vbox), "Radio 2:", radiobutton2);
//     add_widget_with_label(GTK_CONTAINER(vbox), "Button:", button);
//     add_widget_with_label(GTK_CONTAINER(vbox2), "Toggle Button:", button2);

//     g_signal_connect(G_OBJECT(button), "clicked", G_CALLBACK(button_clicked), NULL);

//     gtk_container_add(GTK_CONTAINER(fix), vbox);
//     gtk_container_add(GTK_CONTAINER(fix), vbox2);
//     gtk_fixed_move(GTK_FIXED(fix), vbox2, 300, 0);
//     gtk_container_add(GTK_CONTAINER(window), fix);
//     gtk_widget_show_all(window);
//     // gtk_widget_show_all(window);

//     gtk_main();

//     return 0;
// }

int main(int argc, char *argv[]) {
    GtkWidget *window = nullptr;
    GtkWidget *calc = nullptr;
    GtkWidget *numeric = nullptr;
    GtkWidget *base_operations = nullptr;
    GtkWidget *math_functions = nullptr;
    GtkWidget *num1 = nullptr;
    GtkWidget *num2 = nullptr;
    GtkWidget *num3 = nullptr;
    GtkWidget *digit0 = nullptr;
    GtkWidget *digit1 = nullptr;
    GtkWidget *digit2 = nullptr;
    GtkWidget *digit3 = nullptr;
    GtkWidget *digit4 = nullptr;
    GtkWidget *digit5 = nullptr;
    GtkWidget *digit6 = nullptr;
    GtkWidget *digit7 = nullptr;
    GtkWidget *digit8 = nullptr;
    GtkWidget *digit9 = nullptr;
    GtkWidget *base_operations1 = nullptr;
    GtkWidget *base_operations2 = nullptr;
    GtkWidget *base_operations3 = nullptr;
    GtkWidget *plus = nullptr;
    GtkWidget *minus = nullptr;
    GtkWidget *mul = nullptr;
    GtkWidget *div = nullptr;
    GtkWidget *power = nullptr;
    GtkWidget *mod = nullptr;

    gtk_init(&argc, &argv);
    window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(window), "Buttons");
    gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER);
    gtk_window_set_default_size(GTK_WINDOW(window), 300, 200);
    gtk_container_set_border_width(GTK_CONTAINER(window), 10);
    g_signal_connect(G_OBJECT(window), "destroy", G_CALLBACK(closeApp), NULL);


    digit0 = gtk_button_new_with_label("0");
    digit1 = gtk_button_new_with_label("1");
    digit2 = gtk_button_new_with_label("2");
    digit3 = gtk_button_new_with_label("3");
    digit4 = gtk_button_new_with_label("4");
    digit5 = gtk_button_new_with_label("5");
    digit6 = gtk_button_new_with_label("6");
    digit7 = gtk_button_new_with_label("7");
    digit8 = gtk_button_new_with_label("8");
    digit9 = gtk_button_new_with_label("9");

    num1 = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 4);
    num2 = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 4);
    num3 = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 4);

    add_widget_with_label(GTK_CONTAINER(num1), "", digit1);
    add_widget_with_label(GTK_CONTAINER(num1), "", digit2);
    add_widget_with_label(GTK_CONTAINER(num1), "", digit3);
    add_widget_with_label(GTK_CONTAINER(num1), "", digit0);
    add_widget_with_label(GTK_CONTAINER(num2), "", digit4);
    add_widget_with_label(GTK_CONTAINER(num2), "", digit5);
    add_widget_with_label(GTK_CONTAINER(num2), "", digit6);
    add_widget_with_label(GTK_CONTAINER(num3), "", digit7);
    add_widget_with_label(GTK_CONTAINER(num3), "", digit8);
    add_widget_with_label(GTK_CONTAINER(num3), "", digit9);

    numeric = gtk_fixed_new();

    gtk_container_add(GTK_CONTAINER(numeric), num1);
    gtk_container_add(GTK_CONTAINER(numeric), num2);
    gtk_container_add(GTK_CONTAINER(numeric), num3);
    gtk_fixed_move(GTK_FIXED(numeric), num1, 0, 120);
    gtk_fixed_move(GTK_FIXED(numeric), num2, 0, 80);
    gtk_fixed_move(GTK_FIXED(numeric), num3, 0, 40);


    plus = gtk_button_new_with_label("+");
    minus = gtk_button_new_with_label("-");
    mul = gtk_button_new_with_label("*");
    div = gtk_button_new_with_label("/");
    power = gtk_button_new_with_label("^");
    mod = gtk_button_new_with_label("%");

    base_operations1 = gtk_box_new(GTK_ORIENTATION_VERTICAL, 2);
    base_operations2 = gtk_box_new(GTK_ORIENTATION_VERTICAL, 2);
    base_operations3 = gtk_box_new(GTK_ORIENTATION_VERTICAL, 2);

    add_widget_with_label(GTK_CONTAINER(base_operations1), "", plus);
    add_widget_with_label(GTK_CONTAINER(base_operations1), "", minus);
    add_widget_with_label(GTK_CONTAINER(base_operations2), "", mul);
    add_widget_with_label(GTK_CONTAINER(base_operations2), "", div);
    add_widget_with_label(GTK_CONTAINER(base_operations3), "", power);
    add_widget_with_label(GTK_CONTAINER(base_operations3), "", mod);

    base_operations = gtk_fixed_new();

    gtk_container_add(GTK_CONTAINER(base_operations), base_operations1);
    gtk_container_add(GTK_CONTAINER(base_operations), base_operations2);
    gtk_container_add(GTK_CONTAINER(base_operations), base_operations3);
    gtk_fixed_move(GTK_FIXED(base_operations), base_operations1, 0, 0);
    gtk_fixed_move(GTK_FIXED(base_operations), base_operations2, 55, 0);
    gtk_fixed_move(GTK_FIXED(base_operations), base_operations3, 110, 0);



    calc = gtk_fixed_new();

    gtk_container_add(GTK_CONTAINER(calc), numeric);
    gtk_container_add(GTK_CONTAINER(calc), base_operations);
    gtk_fixed_move(GTK_FIXED(calc), base_operations, 250, 84);

    gtk_container_add(GTK_CONTAINER(window), calc);
    

    gtk_widget_show_all(window);

    gtk_main();
}