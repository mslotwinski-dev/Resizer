#include "./index.h"

char* ParseStatus(enum StatusCode Status) {
  printf(RESET);

  switch (Status) {
    case CreatedFiles:  return "Successfully created icons";
    case NoFile:        return "No file! Please specify path to your file.";
    case InvalidFile:   return "Invalid file! Make sure you enter the correct filename and its extension is png.";
    default:            return "Invalid Status - please report an error.";
  }
}

char* ParseMode(enum Mode Mode) {
  switch (Mode) {
    case Info:      return CYAN "Info: ";
    case Success:   return GREEN "Success: ";
    case Warning:   return YELLOW "Warning: ";
    case Error:     return RED "Error: ";
    case Critical:  return MAGENTA "Critical Error: ";
    default: {
      printf("Invalid Mode - please report an error.");
      exit(EXIT_FAILURE);
    }
  }

}

void Print(enum Mode Mode, enum StatusCode Status) {
  printf(ParseMode(Mode));
  printf(ParseStatus(Status));
  ENDL;

  if (Mode == Error || Mode == Critical) exit(EXIT_FAILURE);
}

