#define _GLIBCXX_USE_CXX11_ABI 0
#include <iostream>
#include <gtkmm.h>
#include "GameWindow.h"

GameWindow* pWindow = nullptr;

int main (int argc, char **argv)
{
  auto app = Gtk::Application::create(argc, argv, "org.gtkmm.example");

  //Load the GtkBuilder file and instantiate its widgets:
  auto refBuilder = Gtk::Builder::create();
  try
  {
    refBuilder->add_from_file("game.glade");
  }
  catch(const Glib::FileError& ex)
  {
    std::cerr << "FileError: " << ex.what() << std::endl;
    return 1;
  }
  catch(const Glib::MarkupError& ex)
  {
    std::cerr << "MarkupError: " << ex.what() << std::endl;
    return 1;
  }
  catch(const Gtk::BuilderError& ex)
  {
    std::cerr << "BuilderError: " << ex.what() << std::endl;
    return 1;
  }

  //Get the GtkBuilder-instantiated Dialog:
  refBuilder->get_widget_derived("main_window", pWindow);
  if(pWindow)
  {

    //Get the GtkBuilder-instantiated Button, and connect a signal handler:
    // Gtk::Button* pButton = nullptr;
    // refBuilder->get_widget("quit_button", pButton);
    // if(pButton)
    // {
    //   pButton->signal_clicked().connect( sigc::ptr_fun(on_button_clicked) );
    // }

    app->run(*pWindow);
  }

  delete pWindow;

  return 0;
}
