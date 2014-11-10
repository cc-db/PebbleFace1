#include <pebble.h>
  
static Window *s_main_window;
static TextLayer *s_time_layer;
static TextLayer *s_time_layer1;

static void main_window_load(Window *window) {
  //set background
  window_set_background_color(window, GColorBlack);
  
  
  // create the text layer
  s_time_layer = text_layer_create(GRect(0,55, 144, 50));
  text_layer_set_overflow_mode(s_time_layer, GTextOverflowModeWordWrap);
  text_layer_set_background_color(s_time_layer, GColorClear);
  text_layer_set_text_color(s_time_layer, GColorWhite);
  text_layer_set_text(s_time_layer, "00:00");
  
  //improve the layout to be more like a watchface
  text_layer_set_font(s_time_layer, fonts_get_system_font(FONT_KEY_GOTHIC_28_BOLD));
  text_layer_set_text_alignment(s_time_layer, GTextAlignmentCenter);
  
  // create the text layer
  s_time_layer1 = text_layer_create(GRect(0, 85, 144, 50));
  text_layer_set_background_color(s_time_layer1, GColorClear);
  text_layer_set_text_color(s_time_layer1, GColorWhite);
  text_layer_set_text(s_time_layer1, "phooey\non you\nLMP");
  
  //improve the layout to be more like a watchface
  text_layer_set_font(s_time_layer1, fonts_get_system_font(FONT_KEY_GOTHIC_24_BOLD));
  text_layer_set_text_alignment(s_time_layer1, GTextAlignmentCenter);
  // add it as a child to the window's root layer
  layer_add_child(window_get_root_layer(window), text_layer_get_layer(s_time_layer));                      
  //layer_add_child(window_get_root_layer(window), text_layer_get_layer(s_time_layer1));                       

}

static void main_window_unload(Window *window) {
  text_layer_destroy(s_time_layer);
  text_layer_destroy(s_time_layer1);

}
  
static void init() {
  // Create main Window element and assign to pointer
  s_main_window = window_create();

  // Set handlers to manage the elements inside the Window
  window_set_window_handlers(s_main_window, (WindowHandlers) {
    .load = main_window_load,
    .unload = main_window_unload
  });

  // Show the Window on the watch, with animated=true
  window_stack_push(s_main_window, true);
}

static void deinit() {
  // Destroy Window
   window_destroy(s_main_window);
}

int main(void) {
  init();
  app_event_loop();
  deinit();
}
