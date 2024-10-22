const char* morseCode[] = {
  ".-",   // A
  "-...", // B
  "-.-.", // C
  "-..",  // D
  ".",    // E
  "..-.", // F
  "--.",  // G
  "....", // H
  "..",   // I
  ".---", // J
  "-.-",  // K
  ".-..", // L
  "--",   // M
  "-.",   // N
  "---",  // O
  ".--.", // P
  "--.-", // Q
  ".-.",  // R
  "...",  // S
  "-",    // T
  "..-",  // U
  "...-", // V
  ".--",  // W
  "-..-", // X
  "-.--", // Y
  "--.."  // Z
};

void setup() {
  Serial.begin(9600);
  pinMode(LED_BUILTIN, OUTPUT); // OUTPUT LED 13
}

void loop() {
  if (Serial.available() > 0) {
    String input = Serial.readStringUntil('\n'); // take an input
    input.toUpperCase(); // Upper case to all letters

    for (char letter : input) {
      if (letter >= 'A' && letter <= 'Z') { //Between A and Z letters
        int index = letter - 'A';
        const char* morse = morseCode[index];

        // Morse kodunu göster
        for (int j = 0; morse[j] != '\0'; j++) {
          if (morse[j] == '.') {
            digitalWrite(LED_BUILTIN, HIGH); // LED is open
            delay(250); // (.) time
            digitalWrite(LED_BUILTIN, LOW); // LED is close
            delay(250); // waiting after (.)
          } else if (morse[j] == '-') {
            digitalWrite(LED_BUILTIN, HIGH); // LED is open
            delay(750); // (-) time
            digitalWrite(LED_BUILTIN, LOW); // LED is close
            delay(250); // waiting after (-)
          }
        }
        delay(500); // Waiting between letters
      }
    }
  }
}
