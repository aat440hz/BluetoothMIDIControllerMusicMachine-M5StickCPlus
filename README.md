# Bluetooth MIDI Controller Music Machine

The Bluetooth MIDI Controller Music Machine is a versatile tool designed for musicians and music producers to stimulate creativity by generating random MIDI notes within selected key signatures. It's an excellent device for creating distinctive melodies and exploring new musical ideas.

## How It Works

The Bluetooth MIDI Controller Music Machine randomly generates MIDI notes based on the selected key signature. Users can seamlessly switch between key signatures to inspire unique musical creations. It's designed to work as a MIDI controller with various digital audio workstations and music production software.

## Dependencies

To ensure smooth operation, you'll need:

1. **MIDIberry (Windows 10)**: A MIDI loopback driver to route MIDI data between applications. [Download MIDIberry](http://newbodyfresher.linclip.com/).
2. **loopMIDI (Windows 10)**: A tool for creating virtual MIDI ports, facilitating communication between MIDI applications. [Download loopMIDI](https://www.tobias-erichsen.de/software/loopmidi.html).

## Compatibility and Setup Instructions

The Bluetooth MIDI Controller Music Machine has been confirmed to work well with various setups including Windows 10, Android, and now iPhone devices, providing a versatile tool for musicians and producers.

### For Windows 10 Users:

- **REAPER (or any DAW supporting MIDI):** Tested for reliability and performance.
- **Board Selection:** Use the M5StickC ESP32 board definition from Espressif (`https://dl.espressif.com/dl/package_esp32_index.json`) when working with Windows to resolve connectivity issues.

### For Android and iPhone Users:

- **Android: MIDI+BTLE and BandLab.**
- **iPhone: Bluetooth MIDI Connect by KORG and BandLab (available on the Apple Store).**
- **Board Selection for Both Android and iPhone:** Use the M5StickCPlus board definition from M5Stack (`https://m5stack.oss-cn-shenzhen.aliyuncs.com/resource/arduino/package_m5stack_index.json`). This board selection has been tested and works well for both Android and iPhone, facilitating a consistent experience across mobile devices.

### General Installation:

1. **Download and Install Necessary Applications:** MIDIberry and loopMIDI for Windows 10, and respective MIDI applications for mobile devices.
2. **Clone the Repository:** Obtain the project files from the GitHub repository.
3. **Set Up Arduino Environment:**
    - Open the project in your Arduino development environment.
    - Select the correct board from the Tools menu based on your target OS (Windows, Android, or iPhone).
    - Upload the code to your M5StickC or similar hardware.
4. **Hardware Connection:** Connect your hardware to your computer or mobile device via Bluetooth.
5. **MIDI Configuration:**
    - In your DAW or music production software, configure the MIDI inputs to use the appropriate MIDI driver.
    - Ensure the software is set to receive MIDI from the correct virtual port if using tools like loopMIDI.
6. **Initialization:** Activate the Bluetooth MIDI Controller Music Machine on your hardware to start creating music!

## Feedback and Contributions

We encourage users to share their experiences, especially regarding compatibility with different systems and setups. Your feedback helps improve this tool for everyone!

- **Reporting Issues:** Please use the issues section of this GitHub repository for any problems or suggestions.
- **Contributions:** Code improvements and feature suggestions are welcome! Feel free to fork this repository and submit pull requests.

## License

This project is open-source and available under the [MIT License](LICENSE.md).

Enjoy creating music with the Bluetooth MIDI Controller Music Machine, now compatible with Windows, Android, and iPhone!
