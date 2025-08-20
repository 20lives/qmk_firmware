#pragma once

// ========================================
// HOMEROW MOD FINE-TUNING OPTIONS
// ========================================
// Try these different configurations to find what feels best:

// === OPTION 1: CONSERVATIVE (Current) ===
// #define TAPPING_TERM 200
// #define PERMISSIVE_HOLD
// #define TAPPING_FORCE_HOLD
// #define HOLD_ON_OTHER_KEY_PRESS

// === OPTION 2: FASTER & MORE RESPONSIVE ===
// Uncomment these and comment out Option 1 to try:
// #define TAPPING_TERM 175
// #define PERMISSIVE_HOLD
// #define HOLD_ON_OTHER_KEY_PRESS
// // Remove TAPPING_FORCE_HOLD for quicker tap detection

// === OPTION 3: SLOWER & MORE FORGIVING ===
// Uncomment these and comment out Option 1 to try:
// #define TAPPING_TERM 250
// #define PERMISSIVE_HOLD
// #define TAPPING_FORCE_HOLD

// === OPTION 4: ZMK-LIKE BALANCED ===
// Uncomment these and comment out Option 1 to try:
#define TAPPING_TERM 200
#define PERMISSIVE_HOLD
#define TAPPING_FORCE_HOLD
// This is closer to ZMK "balanced" flavor (IGNORE_MOD_TAP_INTERRUPT is now default)

// === OPTION 5: CUSTOM PER-KEY TIMING ===
// Uses the get_tapping_term() function in keymap.c
// #define TAPPING_TERM 180  // Base timing
// #define PERMISSIVE_HOLD

// Additional fine-tuning options:
// #define QUICK_TAP_TERM 100     // Quick tap-tap detection
// #define RETRO_TAPPING          // Tap on release if no other key pressed

// Combo settings
#define COMBO_COUNT 4
#define COMBO_TERM 50

// Debounce settings
#define DEBOUNCE 5

// Enable more layers
#define DYNAMIC_KEYMAP_LAYER_COUNT 4