#include "win_lay.h"
#include <pebble.h>

// BEGIN AUTO-GENERATED UI CODE; DO NOT MODIFY
static Window *s_window;
static TextLayer *s_textlayer_1;
static TextLayer *s_textlayer_2;
static MenuLayer *s_menulayer_1;
static ActionBarLayer *s_actionbarlayer_1;

static void initialise_ui(void) {
  s_window = window_create();
  window_set_background_color(s_window, GColorBlack);
  window_set_fullscreen(s_window, true);
  
  // s_textlayer_1
  s_textlayer_1 = text_layer_create(GRect(20, 20, 100, 20));
  text_layer_set_text(s_textlayer_1, "Text layer");
  layer_add_child(window_get_root_layer(s_window), (Layer *)s_textlayer_1);
  
  // s_textlayer_2
  s_textlayer_2 = text_layer_create(GRect(8, 146, 100, 20));
  text_layer_set_text(s_textlayer_2, "Text layer");
  layer_add_child(window_get_root_layer(s_window), (Layer *)s_textlayer_2);
  
  // s_menulayer_1
  s_menulayer_1 = menu_layer_create(GRect(0, 0, 144, 168));
  menu_layer_set_click_config_onto_window(s_menulayer_1, s_window);
  layer_add_child(window_get_root_layer(s_window), (Layer *)s_menulayer_1);
  
  // s_actionbarlayer_1
  s_actionbarlayer_1 = action_bar_layer_create();
  action_bar_layer_add_to_window(s_actionbarlayer_1, s_window);
  action_bar_layer_set_background_color(s_actionbarlayer_1, GColorBlack);
  layer_add_child(window_get_root_layer(s_window), (Layer *)s_actionbarlayer_1);
}

static void destroy_ui(void) {
  window_destroy(s_window);
  text_layer_destroy(s_textlayer_1);
  text_layer_destroy(s_textlayer_2);
  menu_layer_destroy(s_menulayer_1);
  action_bar_layer_destroy(s_actionbarlayer_1);
}
// END AUTO-GENERATED UI CODE

static void handle_window_unload(Window* window) {
  destroy_ui();
}

void show_win_lay(void) {
  initialise_ui();
  window_set_window_handlers(s_window, (WindowHandlers) {
    .unload = handle_window_unload,
  });
  window_stack_push(s_window, true);
}

void hide_win_lay(void) {
  window_stack_remove(s_window, true);
}
