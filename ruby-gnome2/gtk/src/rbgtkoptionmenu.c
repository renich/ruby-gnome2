/* -*- c-file-style: "ruby" -*- */
/************************************************

  rbgtkoptionmenu.c -

  $Author: mutoh $
  $Date: 2002/05/19 12:29:39 $

  Copyright (C) 1998-2000 Yukihiro Matsumoto,
                          Daisuke Kanda,
                          Hiroshi Igarashi
************************************************/

#include "global.h"

static VALUE
omenu_initialize(self)
    VALUE self;
{
    set_widget(self, gtk_option_menu_new());
    return Qnil;
}

static VALUE
omenu_set_menu(self, child)
    VALUE self, child;
{
    rb_iv_set(self, "option_menu", child);
    gtk_option_menu_set_menu(GTK_OPTION_MENU(get_widget(self)),
			     get_widget(child));
    return self;
}

static VALUE
omenu_get_menu(self)
    VALUE self;
{
    return rb_iv_get(self, "option_menu");
}

static VALUE
omenu_remove_menu(self)
    VALUE self;
{
    gtk_option_menu_remove_menu(GTK_OPTION_MENU(get_widget(self)));
    return self;
}

static VALUE
omenu_set_history(self, index)
    VALUE self, index;
{
    gtk_option_menu_set_history(GTK_OPTION_MENU(get_widget(self)),
				NUM2INT(index));
    return self;
}

void Init_gtk_option_menu()
{
    gOptionMenu = rb_define_class_under(mGtk, "OptionMenu", gButton);

    rb_define_method(gOptionMenu, "initialize", omenu_initialize, 0);
    rb_define_method(gOptionMenu, "get_menu", omenu_get_menu, 0);
    rb_define_method(gOptionMenu, "menu", omenu_get_menu, 0);
    rb_define_method(gOptionMenu, "set_menu", omenu_set_menu, 1);
    rb_define_method(gOptionMenu, "remove_menu", omenu_remove_menu, 0);
    rb_define_method(gOptionMenu, "set_history", omenu_set_history, 1);
}
