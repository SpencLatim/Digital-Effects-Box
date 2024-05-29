
### Digital Effects Box

The code in this project accomplished the ability to apply digital effects to an audio signal, having been optimized for guitars specifically. This was one part of my 2024 EE capstone project building an all-in-one audio guitar rig. This project required many different components which will be explained later, as well as had a physical structure and is currently marked as complete due to current lack of those components.

Digital effects are very commonly used by musicians to both correct the music that they produce and create interesting sounds that fit their vision. This box allows the user to both the ability to apply audio effects and control that effect via a UI. This requires both ways to input and output audio and communication between the user interface and the audio processing elements. The audio effects actively coded in are tremolo/ring modulation, distortion, downsampling, bass boost, normal playthrough, and mute. The philosophy behind building this project was to absolutely focus on the fundamentals of this project, and to add anything extra like additional audio effects and UI features that wouldn't be classified as a must have. It was also agreed since upon for compartmentalization reasons to have separate processors for the audio effects and the UI, allowing multiple members to work individually. Lastly, the financials of the project were heavily considered, with as much cost-cutting parameters achieved for competition with more modern audio rigs.

### Core Technical Concepts/Inspiration






### Getting Started/Requirements/Prerequisites/Dependencies
The C code requires a TMDX5535EZDSP board and TI-RTOS and was coded on the Code Composer Studio 6.1.1 IDE. There is python code there for the sole purpose of initializing the UART on the Raspberry Pi 4 for UI interface purposes, where the other functionalities of the raspberry pi were written by a fellow group member and are not included. 

- Describe very briefly but clearly what the project does.
- State if it is out-of-the-box user-friendly, so it’s clear to the user.
- List its most useful/innovative/noteworthy features.
- State its goals/what problem(s) it solves.
- Note and briefly describe any key concepts (technical, philosophical, or both) important to the user’s understanding.
- Link to any supplementary blog posts or project main pages.
- Note its development status.
- Include badges.
- If possible, include screenshots and demo videos.



- Why does it exist?
- Frame your project for the potential user. 
- Compare/contrast your project with other, similar projects so the user knows how it is different from those projects.
- Highlight the technical concepts that your project demonstrates or supports. Keep it very brief.
- Keep it useful.


Include any essential instructions for:
- Getting it
- Installing It
- Configuring It
- Running it

### More Specific Topics (+ sample sub-categories)
- Versioning: Services, APIs, Systems
- Common Error Messages/related details
- Tests
- Is it a Swift project? Please take a look at Mattt Thompson & Nate Cook's [Swift documentation](http://nshipster.com/swift-documentation/) guide

### Contributing
- Contributor Guidelines
- Code Style/Requirements
- Format for commit messages
- Thank you (name contributors)

### TODO
- Next steps
- Features planned
- Known bugs (shortlist)

### Contact
- Email address
- Google Group/mailing list (if applicable)
- IRC or Slack (if applicable)

### License
