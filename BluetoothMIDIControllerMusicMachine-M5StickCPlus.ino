#include <M5StickCPlus.h>
#include <Arduino.h>
#include <BLEMIDI_Transport.h>
#include <hardware/BLEMIDI_ESP32_NimBLE.h>

BLEMIDI_CREATE_DEFAULT_INSTANCE()

bool isConnected = false;
bool notePlaying = false;
int currentNote = -1; // Initial note set to -1 to indicate no note is playing
const int maxNotes = 12; // Maximum number of notes that can play simultaneously
int playingNotes[maxNotes]; // Array to store the currently playing notes
int numPlayingNotes = 0; // Number of currently playing notes

int currentKeyIndex = 0; // Index for cycling through the keys
const int numKeys = 13; // Number of possible keys (including "Chromatic")
int currentKey = 0; // Default key (C Chromatic)

const int twoOctaveRange = 24; // Two octaves range (24 semitones)
const int middleC = 60; // Middle C

// Define the scales for each key signature
int cMinorScale[] = {48, 50, 51, 53, 55, 56, 58, 60, 62, 63, 65, 67};
int cSharpMinorScale[] = {49, 51, 52, 54, 56, 57, 59, 61, 63, 64, 66, 68};
int dMinorScale[] = {50, 52, 53, 55, 57, 58, 60, 62, 64, 65, 67, 69};
int dSharpMinorScale[] = {51, 53, 54, 56, 58, 59, 61, 63, 65, 66, 68, 70};
int eMinorScale[] = {52, 54, 55, 57, 59, 60, 62, 64, 66, 67, 69, 71};
int fMinorScale[] = {53, 55, 56, 58, 60, 61, 63, 65, 67, 68, 70, 72};
int fSharpMinorScale[] = {54, 56, 57, 59, 61, 62, 64, 66, 68, 69, 71, 73};
int gMinorScale[] = {55, 57, 58, 60, 62, 63, 65, 67, 69, 70, 72, 74};
int gSharpMinorScale[] = {56, 58, 59, 61, 63, 64, 66, 68, 70, 71, 73, 75};
int aMinorScale[] = {57, 59, 60, 62, 64, 65, 67, 69, 71, 72, 74, 76};
int aSharpMinorScale[] = {58, 60, 61, 63, 65, 66, 68, 70, 72, 73, 75, 77};
int bMinorScale[] = {59, 61, 62, 64, 66, 67, 69, 71, 73, 74, 76, 78};
int chromaticScale[] = {48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59};

int bButtonPressCount = 0; // Count of button B presses

unsigned long lastBButtonPressTime = 0; // Timestamp of the last button B press
const unsigned long debounceDelay = 200; // Debounce time in milliseconds

void setup() {
  M5.begin();
  M5.Lcd.setRotation(3); // Rotate the display 90 degrees clockwise
  MIDI.begin();

  BLEMIDI.setHandleConnected([]() {
    isConnected = true;
  });

  BLEMIDI.setHandleDisconnected([]() {
    isConnected = false;
  });

  updateDisplay(); // Initial display of the key
}

void loop() {
  M5.update();
  MIDI.read();

  if (isConnected) {
    // Check if button A is pressed to play another random note
    if (M5.BtnA.isPressed()) {
      if (!notePlaying) {
        changeNote();
        notePlaying = true;
      }
    } else {
      // Button A is released, stop the note
      if (notePlaying) {
        for (int i = 0; i < numPlayingNotes; i++) {
          MIDI.sendNoteOff(playingNotes[i], 0, 1);
        }
        numPlayingNotes = 0;
        notePlaying = false;
      }
    }

    // Check if button B is pressed to release the note or change key
    if (M5.BtnB.wasReleased()) {
      if (notePlaying) {
        for (int i = 0; i < numPlayingNotes; i++) {
          MIDI.sendNoteOff(playingNotes[i], 0, 1);
        }
        numPlayingNotes = 0;
        notePlaying = false;
      } else {
        // Increment the B button press counter and change key after three presses
        unsigned long currentMillis = millis();
        if (currentMillis - lastBButtonPressTime > debounceDelay) {
          lastBButtonPressTime = currentMillis;
          bButtonPressCount++;
          if (bButtonPressCount >= 3) {
            currentKeyIndex = (currentKeyIndex + 1) % numKeys; // Cycle through keys
            updateDisplay(); // Update the display with the new key
            bButtonPressCount = 0; // Reset the counter
          }
        }
      }
    }
  }
}

void changeNote() {
  // Choose a random note within the selected key signature and transpose based on the key
  int randomIndex = random(12); // There are 12 notes in each key signature
  currentNote = getScaleForCurrentKey()[randomIndex];
  MIDI.sendNoteOn(currentNote, 100, 1);

  // Store the currently playing note
  if (numPlayingNotes < maxNotes) {
    playingNotes[numPlayingNotes] = currentNote;
    numPlayingNotes++;
  }
}

void updateDisplay() {
  M5.Lcd.fillScreen(TFT_BLACK);
  M5.Lcd.setTextSize(2); // Increase text size
  M5.Lcd.setTextColor(TFT_WHITE);
  M5.Lcd.setCursor(10, 10); // Adjust the cursor position
  M5.Lcd.println("Current Key:");
  M5.Lcd.setCursor(20, 60);
  M5.Lcd.println(getKeyString(currentKeyIndex));
}

int* getScaleForCurrentKey() {
  switch (currentKeyIndex) {
    case 0: return cMinorScale;
    case 1: return cSharpMinorScale;
    case 2: return dMinorScale;
    case 3: return dSharpMinorScale;
    case 4: return eMinorScale;
    case 5: return fMinorScale;
    case 6: return fSharpMinorScale;
    case 7: return gMinorScale;
    case 8: return gSharpMinorScale;
    case 9: return aMinorScale;
    case 10: return aSharpMinorScale;
    case 11: return bMinorScale;
    case 12: return chromaticScale;
    default: return cMinorScale; // Default to C Minor/Eb Major
  }
}

String getKeyString(int keyIndex) {
  switch (keyIndex) {
    case 0: return "C Minor/Eb Major";
    case 1: return "C# Minor/E Major";
    case 2: return "D Minor/F Major";
    case 3: return "D# Minor/F# Major";
    case 4: return "E Minor/G Major";
    case 5: return "F Minor/Ab Major";
    case 6: return "F# Minor/A Major";
    case 7: return "G Minor/Bb Major";
    case 8: return "G# Minor/B Major";
    case 9: return "A Minor/C Major";
    case 10: return "A# Minor/C# Major";
    case 11: return "B Minor/D Major";
    case 12: return "Chromatic";
  }
}
