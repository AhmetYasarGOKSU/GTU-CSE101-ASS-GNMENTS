const char* morseCode[] = {
  "....", // H
  ".",    // E
  ".-..", // L
  ".-..", // L
  "---",  // O
  ".--",  // W
  "---",  // O
  ".-.",  // R
  ".-..", // L
  "-.."   // D
};

const char* letters = "HELLOWORLD"; //Letters

const char* message = "HELLO WORLD"; // Message

void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop() {
  for (int i = 0; message[i] != '\0'; i++) {
    char c = message[i];

    if (c == ' ') {
      delay(700); // Waiting Between Hello and World
      continue;
    }

    // Check morse code
    int index = getMorseIndex(c);
    if (index != -1) { // Index Check
      showMorse(morseCode[index]);

      delay(1000);
    } else {
    }
  }
}

int getMorseIndex(char c) {
  // Looks for letter's index in letters 
  for (int i = 0; letters[i] != '\0'; i++) {
    if (letters[i] == c) {
      return i; // Index
    }
  }
  return -1; // Invalid Letter
}

void showMorse(const char* code) {
  for (int i = 0; code[i] != '\0'; i++) {
    if (code[i] == '.') {
      digitalWrite(LED_BUILTIN, HIGH); //Turn on the led
      delay(250); // (.) delay
      digitalWrite(LED_BUILTIN, LOW); //Turn off the led
      delay(250); 
    } else if (code[i] == '-') {
      digitalWrite(LED_BUILTIN, HIGH); //Turn on the led
      delay(750); // (-) delay
      digitalWrite(LED_BUILTIN, LOW); //Turn off the led
      delay(250); 
    }
  }
}
