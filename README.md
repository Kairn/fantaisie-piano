# Fantaisie Piano :heart::musical_note:
[![Open Source Love](https://badges.frapsoft.com/os/v1/open-source.png?v=103)](https://github.com/ellerbrock/open-source-badges/)
[![made-with-cpp](https://img.shields.io/badge/made%20with-C%2B%2B-yellowgreen.svg)](https://isocpp.org)
[![MIT Licence](https://img.shields.io/apm/l/vim-mode.svg)](https://opensource.org/licenses/mit-license.php)

Fantaisie Piano is a virtual piano program that simulates the functions of a real piano by playing prerecorded sounds in response to the user's keyboard or mouse inputs. The program features all 88 keys of a standard piano with a sustain pedal function. Moreover, it comes with a Music Box that can digitally perform piano pieces that are coded into the file. At the time of this writing, only two pieces are ready to be played, but I will continuously add more pieces in the future. The program is written in **C++** language (not C) with Simple DirectMedia Layer and some of its supportive libraries.

## Getting Started
### Prerequisites
* [GNU Compiler Collection](https://gcc.gnu.org/) or an alternative C++ compiler
* [Ogg Vorbis](https://xiph.org/downloads/)
* [Simple DirectMedia Layer](https://www.libsdl.org/download-2.0.php) (SDL2)
* [SDL_mixer 2.0](https://www.libsdl.org/projects/SDL_mixer/), [SDL_ttf 2.0](https://www.libsdl.org/projects/SDL_ttf/), [SDL_image 2.0](https://www.libsdl.org/projects/SDL_image/)

### Compatibility
Fantaisie Piano supports all **Unix** based operating systems. The program might fail to compile on a **Windows** platform if SDL_mixer cannot be configured to load .ogg sound files. This can be resolved by using .wav sound files instead, but it will take up more disk space.

### Compile and Run
1. Download the repository as a .zip file or using git clone.
2. Extract the .zip file.
3. Open a terminal and navigate to the directory that contains the program files.
4. Run the following command to build the executable from source code:

	`make all`
5. Double click on the executable or run the following command to launch the program:

	`./fantaisie_piano`

## Play the Piano
### About the Interface
You can access the virtual piano interface by clicking on the **"Play Piano"** button on the start screen. The interface is fairly simple and self-explanatory. An interactive piano keyboard is placed at the center of the program UI with a button for toggling the sustain pedal function right below it. On the top left, there are twelve buttons for switching between different scales.

### Mouse Control
To play a note with the mouse, simply **left click** on the corresponding key on the keyboard, and the note will continue to sound if the mouse button is held down until the sound eventually dissipates. If you toggle the sustain function by clicking on the **"Sustain"** button, all notes played will sound for as long as they last even if you release the mouse button sooner. This is very similar to how a real piano works (the same applies for the keyboard control). Using the mouse is easy and direct, but it is difficult to play different notes in rapid succession.

### Keyboard Control
***TLDR. Version***
1. Choose a scale by clicking on one of the buttons above the keyboard.
2. Play the C-B notes (with key signatures) in each octave by pressing **Z-M** keys.
3. Hold down **Num1-Num7** keys to access the first to the seventh octave (default octave is 4).
4. Hold down the **Left Shift** key to raise the note by one semitone (or **Left Ctrl** to lower by one semitone).

***Detailed Explanation***

Fantaisie Piano is very unique when it comes to how to play with a computer keyboard. Instead of mapping every note onto a separate key which will make it really hard to use without key assists (hints), it only uses seven keys with a few modifiers to reach almost the entire range of the piano. These seven keys are simply **Z, X, C, V, B, N, M** (lower letter row on the standard keyboard) which corresponds to the C, D, E, F, G, A, B notes in each scale within an octave (any sharps and flats will be applied based on the key signature of the chosen scale). The fourth octave (one that includes the middle C) is the default octave, and you can switch to a different octave by holding down the corresponding number key on the **Numpad**. For example, if you are playing in C major, and you wish to play the E5 (mediant of the fifth octave) note, it can be done by holding down the **Num5** key while pressing the **C** key on the keyboard. You can choose any of the twelve major (or its relative natural minor) scales within the standard diatonic scales. Accidentals are applied by holding down the **Left Shift** key which will raise any note you play by one semitone or the **Left Ctrl** key which will lower any note you play by one semitone. For example, in C major scale, to play the C8 (rightmost note) note, you can use the combination of **Num7 + Left Shift + M** (leading tone of the seventh octave raised by one semitone). By the way, Num0 is not an octave recognized by the program (nor is Num8), and therefore the two leftmost notes are unreachable with the keyboard, but given how rarely they are used in notable compositions, it shouldn't be a serious issue (though I might implement them later). Using the keyboard allows you to play notes faster (harmonic chords are still hard to play because the program interface struggles to process simultaneous key inputs), but it is less user friendly to people who are not familiar with scales. For those who have not studied basic music theory, you can use sources like Wikipedia to see what notes are in each scale.

**If any key is stuck, press the **Tab** key to reset the keyboard and silence all sounds.*

## Music Box
### Introduction
The Music Box in Fantaisie Piano is essentially a digital performance system. In order for it to play music, the programmer needs to give full instructions on which note(s) is played at a given time by writing data into one of the header files. Translating sheet music into formatted data that the program understands can be a difficult process, and it requires a lot of dedication and patience to get it right (debugging is a nightmare unless you have remarkable ears). I am not an expert on music literature, so it might take days before I can update a new piece. For now, I only have plans to include some of the most iconic Classical masterpieces in Fantaisie Piano, but I could change direction in the future such as to add video game music.

### Play Music
You can access the Music Box by clicking on the **"Music Box"** button on the start screen which will direct you to a screen with a list of piano pieces. Clicking on a piece title will direct you to the playing screen of the piece you selected. The piece is not played automatically until you click on the **"Play/Pause"** button on the button right corner, and you can pause/resume the playing by clicking on the same button. Clicking on the **"Stop"** button will halt the playing entirely, and the piece will be played from the beginning when you start the playing again.

### List of Available Pieces
* ***Liebestraum No. 3*** (Liszt) **NEW!!**
* ***Fantaisie-Impromptu*** (Chopin)
* ***Für Elise*** (Beethoven)
* ***Clair de Lune*** (Debussy)

**You will see a **red music note** next to the piece title on the selection screen if the piece is available.*  
**Other titles on the selection screen are the ones I have planned to add in the future.*

### :musical_score: *Progress Updates* :notes:
*Liebestraum* No.3 is now in the playable collection! I will start working on Bach's *Prelude in C* and *Brahms' Lullaby* in the next a few days. Both pieces are fairly short and are likely to come out soon.

## Acknowledgments
The sound files used in Fantaisie Piano are provided by **Ivy Audio** in their publicly available *Piano in 162* library.
