
### Digital Effects Box

Digital effects are very commonly used by musicians to both correct the music that they produce and create interesting sounds that fit their vision. Often, musicians have to bring many different devices like speakers, digital effects units, and amplifiers when showing up to a gig. This requires spending all of their hard earned cash on their set-up. The digital effects unit was one specific part of an all-in-one audio guitar rig project built by my capstone team to solve this issue. This device and uploaded code allows a musician both the ability to apply real-time audio effects to their music and control that effect via an user interface. This project required many different components as well as had a physical structure and is currently marked as complete due to a current lack of those components. 

The audio effects currently coded in are tremolo/ring modulation, distortion, downsampling, bass boost, normal playthrough, and mute. The philosophy behind building this project was to absolutely focus and complete on the fundamentals of this project, and after that to add anything extra like additional audio effects and UI features that wouldn't be classified as a must have. It was also agreed since upon for compartmentalization reasons to have separate processors for the audio effects and the UI, allowing multiple members to work individually. Lastly, the financials of the project were heavily considered, with as much cost-cutting parameters achieved for competition with more modern audio rigs, achieving an end result under 416$ for the entire project, which is much cheaper than the alternatives.

### Getting Started/Requirements

The audio processing for this project requires a TMDX5535EZDSP board and TI-RTOS and was coded on the Code Composer Studio 6.1.1 IDE. There are also many CSL functions created by TI and ezdsp5535 libraries that need to be included in the program to run, which can be found on the TI website here: https://www.ti.com/tool/TMDX5535EZDSP . Simply plug in the USB-A port of the DSP board to the computer, and build/debug the program. Once up and running, the input and output stereo jacks can be connected to an audio source and speaker, and the applied effects can be controlled via UART at an 115400 baud rate in the terminal in CCS. 

The Python Code document shows how me and one of my capstone teammates shared code. The Python code included in the PDF was for the sole purpose of initializing the UART on the Raspberry Pi 4 for UI interface purposes, where the other UI functionalities of the raspberry pi were written by a fellow group member and are included. It also includes the method used to convert characters to discrete values to better transmit data over. 






