#ifndef __COLORED_INPUT
#define __COLORED_INPUT

#include "boolean.h"

/*
 * Nutze Farbdarstellung
 * Quelle: http://stackoverflow.com/questions/3219393/stdlib-and-colored-output-in-c
 */
#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_GREEN   "\x1b[32m"
#define ANSI_COLOR_RESET   "\x1b[0m"

/**
 *  Gib farbig kodierte Interpretation des
 *  uebergebenen "Wahrheits"werts aus.
 */
void print_test_result(int tests_ok) {

  if (tests_ok == FALSE) {
    printf(ANSI_COLOR_RED   "FAILED\n" ANSI_COLOR_RESET);
  }
  else {
    printf(ANSI_COLOR_GREEN "PASSED\n" ANSI_COLOR_RESET);
  }
  
}

/*
 *  Gib farbig kodierte Interpretation des
 *  uebergebenen "Wahrheits"werts aus.
 */
void show_progress(int tests_ok) {

  if (tests_ok == FALSE) {
    printf(ANSI_COLOR_RED   "-" ANSI_COLOR_RESET);
  }
  else {
    printf(ANSI_COLOR_GREEN "." ANSI_COLOR_RESET);
  }
  
}

#endif
