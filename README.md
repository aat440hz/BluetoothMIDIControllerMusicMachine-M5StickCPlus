# Bluetooth MIDI Controller Music Machine

The Bluetooth MIDI Controller Music Machine is a versatile tool designed for musicians and music producers to stimulate creativity by generating random MIDI notes within selected key signatures. It's an excellent device for creating distinctive melodies and exploring new musical ideas.

## How It Works

The Bluetooth MIDI Controller Music Machine randomly generates MIDI notes based on the selected key signature. Users can seamlessly switch between key signatures to inspire unique musical creations. It's designed to work as a MIDI controller with various digital audio workstations and music production software.

## Dependencies

To ensure smooth operation, you'll need:

1. **MIDIberry (Windows 10)**: A MIDI loopback driver to route MIDI data between applications. [Download MIDIberry](https://www.manyetas.com/creed/midiberry).
2. **loopMIDI (Windows 10)**: A tool for creating virtual MIDI ports, facilitating communication between MIDI applications. [Download loopMIDI](https://www.tobias-erichsen.de/software/loopmidi.html).

## Compatibility and Setup Instructions

The Bluetooth MIDI Controller Music Machine is confirmed to work well with the following setups:

### For Windows 10 Users:

- **REAPER (or any DAW supporting MIDI):** Tested for reliability and performance.
- **Board Selection:** Use the ESP32 board definition from Espressif (`https://dl.espressif.com/dl/package_esp32_index.json`) when working with Windows. This has been found to resolve connectivity issues specific to Windows.

### For Android Users:

- **MIDI+BTLE and BandLab:** Provides expanded usability for mobile musicians and producers.
- **Board Selection:** Use the M5StickCPlus board definition from M5Stack (`https://m5stack.oss-cn-shenzhen.aliyuncs.com/resource/arduino/package_m5stack_index.json`) when working with Android. This ensures compatibility with Android-specific MIDI features.

### General Installation:

1. **Download and Install MIDIberry and loopMIDI (Windows 10):** Follow the instructions on their respective websites to install these applications.
2. **Clone the Repository:** Obtain the project files from this GitHub repository.
3. **Set Up Arduino Environment:**
    - Open the project in your Arduino development environment.
    - Select the correct board from the Tools menu based on your target OS (Windows or Android).
    - Upload the code to your M5StickC or similar hardware.
4. **Hardware Connection:** Connect your hardware to your computer or mobile device via Bluetooth.
5. **MIDI Configuration:**
    - In your DAW or music production software, configure the MIDI inputs to use MIDIberry (Windows) or the respective MIDI driver for Android.
    - Ensure the software is set to receive MIDI from the correct virtual port if using loopMIDI or a similar tool.
6. **Initialization:** Activate the Bluetooth MIDI Controller Music Machine on your hardware, and you're ready to start creating music!

## Feedback and Contributions

We encourage users to share their experiences, especially regarding compatibility with different systems and setups. Your feedback helps improve this tool for everyone!

- **Reporting Issues:** Please use the issues section of this GitHub repository for any problems or suggestions.
- **Contributions:** Code improvements and feature suggestions are welcome! Feel free to fork this repository and submit pull requests.

## License

This project is open-source and available under the [MIT License](LICENSE.md).

Happy music making with the Bluetooth MIDI Controller Music Machine!
