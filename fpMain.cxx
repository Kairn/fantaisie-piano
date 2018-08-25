/* fpMain.cxx */
/* ===========================================================================
 * SOURCE FILE FOR THE MAIN PROGRAM
 *
 */

#include "fpClasses.h"
#include "fpSheets.h"
#include "fpConstants.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_mixer.h>
#include <SDL2/SDL_ttf.h>
#include <stdio.h>
#include <string>
#include <vector>

// declare system window and renderer
SDL_Window* fpWindow = NULL;
SDL_Renderer* fpRenderer = NULL;

// declare fonts
TTF_Font* fpFontTitle = NULL;
TTF_Font* fpFontAuthor = NULL;

// allocate memory for texture objects
Texture fpTextures[TEXTURE_TOTAL];

// define rectangle objects for all buttons
SDL_Rect buttonRects[BUTTON_TOTAL] =
{
	{1000, 800, 300, 75},
	{1000, 500, 300, 75},
	{1000, 600, 300, 75},
	{1500, 20, 200, 50},
	{730, 750, 300, 100},
	{1500, 830, 250, 60},
	{1500, 910, 250, 60},
	// scales
	{50, 50, 200, 60},
	{50, 150, 200, 60},
	{50, 250, 200, 60},
	{300, 250, 200, 60},
	{300, 150, 200, 60},
	{300, 50, 200, 60},
	{550, 50, 200, 60},
	{550, 150, 200, 60},
	{550, 250, 200, 60},
	{800, 250, 200, 60},
	{800, 150, 200, 60},
	{800, 50, 200, 60},
	// pieces
	{50, 150, 350, 60},
	{50, 250, 350, 60},
	{50, 350, 350, 60},
	{50, 450, 350, 60},
	{50, 550, 350, 60},
	{50, 650, 350, 60},
	{50, 750, 350, 60},
	{50, 850, 350, 60},
	{600, 150, 350, 60},
};

// allocate memory for button objects
Button fpButtons[BUTTON_TOTAL];

// define the notes on the fourth octave for each scale
int fpScaleNotes[SCALE_TOTAL][DEGREE_TOTAL] =
{
	{39, 41, 43, 44, 46, 48, 50},
	{39, 41, 43, 45, 46, 48, 50},
	{40, 41, 43, 45, 46, 48, 50},
	{40, 41, 43, 45, 47, 48, 50},
	{40, 42, 43, 45, 47, 48, 50},
	{40, 42, 43, 45, 47, 49, 50},
	{40, 42, 44, 45, 47, 49, 50},
	{39, 40, 42, 44, 45, 47, 49},
	{39, 40, 42, 44, 46, 47, 49},
	{39, 41, 42, 44, 46, 47, 49},
	{39, 41, 42, 44, 46, 48, 49},
	{39, 41, 43, 44, 46, 48, 49},
};

// define rectangle objects for all piano keys
SDL_Rect keyRect_1[PK_TOTAL] =
{
	{50, 568, 28, 84},
	{74, 400, 16, 168},
	{82, 568, 28, 84},
	{114, 568, 28, 84},
	{134, 400, 16, 168},
	{146, 568, 28, 84},
	{170, 400, 16, 168},
	{178, 568, 28, 84},
	{210, 568, 28, 84},
	{230, 400, 16, 168},
	{242, 568, 28, 84},
	{264, 400, 16, 168},
	{274, 568, 28, 84},
	{298, 400, 16, 168},
	{306, 568, 28, 84},
	{338, 568, 28, 84},
	{358, 400, 16, 168},
	{370, 568, 28, 84},
	{394, 400, 16, 168},
	{402, 568, 28, 84},
	{434, 568, 28, 84},
	{454, 400, 16, 168},
	{466, 568, 28, 84},
	{488, 400, 16, 168},
	{498, 568, 28, 84},
	{522, 400, 16, 168},
	{530, 568, 28, 84},
	{562, 568, 28, 84},
	{582, 400, 16, 168},
	{594, 568, 28, 84},
	{618, 400, 16, 168},
	{626, 568, 28, 84},
	{658, 568, 28, 84},
	{678, 400, 16, 168},
	{690, 568, 28, 84},
	{712, 400, 16, 168},
	{722, 568, 28, 84},
	{746, 400, 16, 168},
	{754, 568, 28, 84},
	{786, 568, 28, 84},
	{806, 400, 16, 168},
	{818, 568, 28, 84},
	{842, 400, 16, 168},
	{850, 568, 28, 84},
	{882, 568, 28, 84},
	{902, 400, 16, 168},
	{914, 568, 28, 84},
	{936, 400, 16, 168},
	{946, 568, 28, 84},
	{970, 400, 16, 168},
	{978, 568, 28, 84},
	{1010, 568, 28, 84},
	{1030, 400, 16, 168},
	{1042, 568, 28, 84},
	{1066, 400, 16, 168},
	{1074, 568, 28, 84},
	{1106, 568, 28, 84},
	{1126, 400, 16, 168},
	{1138, 568, 28, 84},
	{1160, 400, 16, 168},
	{1170, 568, 28, 84},
	{1194, 400, 16, 168},
	{1202, 568, 28, 84},
	{1234, 568, 28, 84},
	{1254, 400, 16, 168},
	{1266, 568, 28, 84},
	{1290, 400, 16, 168},
	{1298, 568, 28, 84},
	{1330, 568, 28, 84},
	{1350, 400, 16, 168},
	{1362, 568, 28, 84},
	{1384, 400, 16, 168},
	{1394, 568, 28, 84},
	{1418, 400, 16, 168},
	{1426, 568, 28, 84},
	{1458, 568, 28, 84},
	{1478, 400, 16, 168},
	{1490, 568, 28, 84},
	{1514, 400, 16, 168},
	{1522, 568, 28, 84},
	{1554, 568, 28, 84},
	{1574, 400, 16, 168},
	{1586, 568, 28, 84},
	{1608, 400, 16, 168},
	{1618, 568, 28, 84},
	{1642, 400, 16, 168},
	{1650, 568, 28, 84},
	{1682, 568, 28, 84},
};

SDL_Rect keyRect_2[PK_TOTAL] =
{
	{50, 400, 24, 168},
	{0, 0, 0, 0},
	{90, 400, 20, 168},
	{114, 400, 20, 168},
	{0, 0, 0, 0},
	{150, 400, 20, 168},
	{0, 0, 0, 0},
	{186, 400, 20, 168},
	{210, 400, 20, 168},
	{0, 0, 0, 0},
	{246, 400, 18, 168},
	{0, 0, 0, 0},
	{280, 400, 18, 168},
	{0, 0, 0, 0},
	{314, 400, 20, 168},
	{338, 400, 20, 168},
	{0, 0, 0, 0},
	{374, 400, 20, 168},
	{0, 0, 0, 0},
	{410, 400, 20, 168},
	{434, 400, 20, 168},
	{0, 0, 0, 0},
	{470, 400, 18, 168},
	{0, 0, 0, 0},
	{504, 400, 18, 168},
	{0, 0, 0, 0},
	{538, 400, 20, 168},
	{562, 400, 20, 168},
	{0, 0, 0, 0},
	{598, 400, 20, 168},
	{0, 0, 0, 0},
	{634, 400, 20, 168},
	{658, 400, 20, 168},
	{0, 0, 0, 0},
	{694, 400, 18, 168},
	{0, 0, 0, 0},
	{728, 400, 18, 168},
	{0, 0, 0, 0},
	{762, 400, 20, 168},
	{786, 400, 20, 168},
	{0, 0, 0, 0},
	{822, 400, 20, 168},
	{0, 0, 0, 0},
	{858, 400, 20, 168},
	{882, 400, 20, 168},
	{0, 0, 0, 0},
	{918, 400, 18, 168},
	{0, 0, 0, 0},
	{952, 400, 18, 168},
	{0, 0, 0, 0},
	{986, 400, 20, 168},
	{1010, 400, 20, 168},
	{0, 0, 0, 0},
	{1046, 400, 20, 168},
	{0, 0, 0, 0},
	{1082, 400, 20, 168},
	{1106, 400, 20, 168},
	{0, 0, 0, 0},
	{1142, 400, 18, 168},
	{0, 0, 0, 0},
	{1176, 400, 18, 168},
	{0, 0, 0, 0},
	{1210, 400, 20, 168},
	{1234, 400, 20, 168},
	{0, 0, 0, 0},
	{1270, 400, 20, 168},
	{0, 0, 0, 0},
	{1306, 400, 20, 168},
	{1330, 400, 20, 168},
	{0, 0, 0, 0},
	{1366, 400, 18, 168},
	{0, 0, 0, 0},
	{1400, 400, 18, 168},
	{0, 0, 0, 0},
	{1434, 400, 20, 168},
	{1458, 400, 20, 168},
	{0, 0, 0, 0},
	{1494, 400, 20, 168},
	{0, 0, 0, 0},
	{1530, 400, 20, 168},
	{1554, 400, 20, 168},
	{0, 0, 0, 0},
	{1590, 400, 18, 168},
	{0, 0, 0, 0},
	{1624, 400, 18, 168},
	{0, 0, 0, 0},
	{1658, 400, 20, 168},
	{1682, 400, 28, 168},
};

// allocate memory for piano key objects
PianoKey fpPKs[PK_TOTAL];

// allocate memory for sound chunks
Mix_Chunk* fpNoteSounds[PK_TOTAL];

// allocate memory for piece and author textures
Texture fpPieces[PIECE_TOTAL];
Texture fpAuthorSource[AUTHOR_TOTAL];
Texture* fpAuthors[PIECE_TOTAL];

// set up control variables (default)
bool fpSuccess = false;
bool fpActive = true;
bool fpSustain = false;
bool fpPaused = true;
bool fpHalted = true;
int fpMusic = -1;
int fpState = STATE_WELCOME;
int fpScale = C_MAJOR;		// C major is the default scale
int fpAccidental = 0;
int fpOctave = 4;		// default octave contains middle C or C4
int fpNextNote = 0;		// next note to be played
int fpTempo = 100;		// relative speed of the piece
double fpTime1 = 0;
double fpTime2 = 0;
double fpPlaytime = 0;		// time into the piece

// set up event structure
SDL_Event fpEvent;

// set up the music sheet pointer
Note* fpSheet;

// set up action queue
std::vector<int> fpActionQueue;

// set up piano key queues
std::vector<int> fpPlayQueue;
std::vector<int> fpFadeQueue;
std::vector<Note> fpChordQueue;

// define the function for initializing SDL
bool initSDL()
{
	bool success = true;

	if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO) < 0)
	{
		printf("%s\n", SDL_GetError());
		success = false;
	}
	else
	{
		fpWindow = SDL_CreateWindow(
			"Fantaisie Piano",
			SDL_WINDOWPOS_UNDEFINED,
			SDL_WINDOWPOS_UNDEFINED,
			SCREEN_WIDTH,
			SCREEN_HEIGHT,
			SDL_WINDOW_SHOWN
		);
		if (fpWindow == NULL)
		{
			printf("%s\n", SDL_GetError());
			success = false;
		}
		else
		{
			fpRenderer = SDL_CreateRenderer(fpWindow, -1, SDL_RENDERER_ACCELERATED);
			if (fpRenderer == NULL)
			{
				printf("%s\n", SDL_GetError());
				success = false;
			}
			else
			{
				SDL_SetRenderDrawColor(fpRenderer, 0x00, 0x00, 0x00, 0xFF);

				int imgFlags = IMG_INIT_PNG;
				if (!(IMG_Init(imgFlags) & imgFlags))
				{
					printf("%s\n", IMG_GetError());
					success = false;
				}
				else
				{
					if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 1024) < 0)
					{
						printf("%s\n", Mix_GetError());
						success = false;
					}
					else
					{
						Mix_AllocateChannels(88);
						if (Mix_AllocateChannels(-1) != 88)
						{
							printf("%s\n", "unable to allocate channels");
							success = false;
						}
						else
						{
							if (TTF_Init() == -1)
							{
								printf("%s\n", TTF_GetError());
								success = false;
							}
							else
							{
								fpFontTitle = TTF_OpenFont("fonts/cac_champagne.ttf", 104);
								fpFontAuthor = TTF_OpenFont("fonts/CaviarDreams.ttf", 60);
								if (fpFontTitle == NULL || fpFontAuthor == NULL)
								{
									printf("%s\n", TTF_GetError());
									success = false;
								}
							}
						}
					}
				}
			}
		}
	}

	return success;
}

// define the function for quitting SDL
void quitSDL()
{
	// free window and renderer
	SDL_DestroyRenderer(fpRenderer);
	SDL_DestroyWindow(fpWindow);
	fpRenderer = NULL;
	fpWindow = NULL;

	// free fonts
	TTF_CloseFont(fpFontTitle);
	TTF_CloseFont(fpFontAuthor);
	fpFontTitle = NULL;
	fpFontAuthor = NULL;

	// shutdown SDL
	TTF_Quit();
	Mix_Quit();
	IMG_Quit();
	SDL_Quit();
}

// define the function for setting up button and piano key objects
void objSetup()
{
	// set up button objects
	for (int i = 0; i < BUTTON_TOTAL; ++i)
	{
		fpButtons[i].setButton(i, &buttonRects[i]);
	}

	// set up piano key objects
	for (int i = 0; i < PK_TOTAL; ++i)
	{
		fpPKs[i].setPK(i, &keyRect_1[i], &keyRect_2[i]);
	}
}

// define the function for loading all images and sounds
bool loadMedia()
{
	bool success = true;

	// load textures from PNG files
	if
	(
		!fpTextures[TEXTURE_WELCOME].loadTexture("images/welcome.png") ||
		!fpTextures[TEXTURE_KEYBOARD_UP].loadTexture("images/keyboard_up.png") ||
		!fpTextures[TEXTURE_KEYBOARD_DOWN].loadTexture("images/keyboard_down.png") ||
		!fpTextures[TEXTURE_MUSIC_SELECT].loadTexture("images/music_selection.png") ||
		!fpTextures[TEXTURE_MUSIC_PLAYER].loadTexture("images/music_player.png") ||
		!fpPieces[FANTAISIE_IMPROMPTU].loadFontString("Fantaisie-Impromptu", fpFontTitle) ||
		!fpPieces[LIEBESTRAUME].loadFontString("Liebestraum No. 3", fpFontTitle) ||
		!fpPieces[FUR_ELISE].loadFontString("Fur Elise", fpFontTitle) ||
		!fpPieces[CLAIR_DE_LUNE].loadFontString("Clair de Lune", fpFontTitle) ||
		!fpPieces[SONATA_PATHETIQUE].loadFontString("Piano Sonata No. 8 \"Pathetique\"", fpFontTitle) ||
		!fpPieces[NOCTURNE_9].loadFontString("Nocturne Op. 9 No. 2", fpFontTitle) ||
		!fpPieces[PRELUDE_FUGUE_C].loadFontString("Prelude and Fugue in C Major", fpFontTitle) ||
		!fpPieces[BRAHMS_LULLABY].loadFontString("Wiegenlied: Guten Abend, gute Nacht", fpFontTitle) ||
		!fpPieces[MOONLIGHT_SONATA].loadFontString("Piano Sonata No. 14 \"Moonlight\"", fpFontTitle) ||
		!fpAuthorSource[CHOPIN].loadFontString("By Frederic Chopin", fpFontAuthor) ||
		!fpAuthorSource[LISZT].loadFontString("By Franz Liszt", fpFontAuthor) ||
		!fpAuthorSource[BEETHOVEN].loadFontString("By Ludwig van Beethoven", fpFontAuthor) ||
		!fpAuthorSource[DEBUSSY].loadFontString("By Claude Debussy", fpFontAuthor) ||
		!fpAuthorSource[BACH].loadFontString("By Johann Sebastian Bach", fpFontAuthor) ||
		!fpAuthorSource[BRAHMS].loadFontString("By Johannes Brahms", fpFontAuthor)
	)
	{
		printf("%s\n", IMG_GetError());
		printf("%s\n", "or unable to generate TTF textures");
		success = false;
	}
	else
	{
		// match author pointers to their sources
		fpAuthors[FANTAISIE_IMPROMPTU] = &fpAuthorSource[CHOPIN];
		fpAuthors[LIEBESTRAUME] = &fpAuthorSource[LISZT];
		fpAuthors[FUR_ELISE] = &fpAuthorSource[BEETHOVEN];
		fpAuthors[CLAIR_DE_LUNE] = &fpAuthorSource[DEBUSSY];
		fpAuthors[SONATA_PATHETIQUE] = &fpAuthorSource[BEETHOVEN];
		fpAuthors[NOCTURNE_9] = &fpAuthorSource[CHOPIN];
		fpAuthors[PRELUDE_FUGUE_C] = &fpAuthorSource[BACH];
		fpAuthors[BRAHMS_LULLABY] = &fpAuthorSource[BRAHMS];
		fpAuthors[MOONLIGHT_SONATA] = &fpAuthorSource[BEETHOVEN];

		// load sounds from OGG files
		fpNoteSounds[PK_A0] = Mix_LoadWAV("sounds/notes_ogg/A0.ogg");
		fpNoteSounds[PK_Bb0] = Mix_LoadWAV("sounds/notes_ogg/Bb0.ogg");
		fpNoteSounds[PK_B0] = Mix_LoadWAV("sounds/notes_ogg/B0.ogg");
		fpNoteSounds[PK_C1] = Mix_LoadWAV("sounds/notes_ogg/C1.ogg");
		fpNoteSounds[PK_Db1] = Mix_LoadWAV("sounds/notes_ogg/Db1.ogg");
		fpNoteSounds[PK_D1] = Mix_LoadWAV("sounds/notes_ogg/D1.ogg");
		fpNoteSounds[PK_Eb1] = Mix_LoadWAV("sounds/notes_ogg/Eb1.ogg");
		fpNoteSounds[PK_E1] = Mix_LoadWAV("sounds/notes_ogg/E1.ogg");
		fpNoteSounds[PK_F1] = Mix_LoadWAV("sounds/notes_ogg/F1.ogg");
		fpNoteSounds[PK_Gb1] = Mix_LoadWAV("sounds/notes_ogg/Gb1.ogg");
		fpNoteSounds[PK_G1] = Mix_LoadWAV("sounds/notes_ogg/G1.ogg");
		fpNoteSounds[PK_Ab1] = Mix_LoadWAV("sounds/notes_ogg/Ab1.ogg");
		fpNoteSounds[PK_A1] = Mix_LoadWAV("sounds/notes_ogg/A1.ogg");
		fpNoteSounds[PK_Bb1] = Mix_LoadWAV("sounds/notes_ogg/Bb1.ogg");
		fpNoteSounds[PK_B1] = Mix_LoadWAV("sounds/notes_ogg/B1.ogg");
		fpNoteSounds[PK_C2] = Mix_LoadWAV("sounds/notes_ogg/C2.ogg");
		fpNoteSounds[PK_Db2] = Mix_LoadWAV("sounds/notes_ogg/Db2.ogg");
		fpNoteSounds[PK_D2] = Mix_LoadWAV("sounds/notes_ogg/D2.ogg");
		fpNoteSounds[PK_Eb2] = Mix_LoadWAV("sounds/notes_ogg/Eb2.ogg");
		fpNoteSounds[PK_E2] = Mix_LoadWAV("sounds/notes_ogg/E2.ogg");
		fpNoteSounds[PK_F2] = Mix_LoadWAV("sounds/notes_ogg/F2.ogg");
		fpNoteSounds[PK_Gb2] = Mix_LoadWAV("sounds/notes_ogg/Gb2.ogg");
		fpNoteSounds[PK_G2] = Mix_LoadWAV("sounds/notes_ogg/G2.ogg");
		fpNoteSounds[PK_Ab2] = Mix_LoadWAV("sounds/notes_ogg/Ab2.ogg");
		fpNoteSounds[PK_A2] = Mix_LoadWAV("sounds/notes_ogg/A2.ogg");
		fpNoteSounds[PK_Bb2] = Mix_LoadWAV("sounds/notes_ogg/Bb2.ogg");
		fpNoteSounds[PK_B2] = Mix_LoadWAV("sounds/notes_ogg/B2.ogg");
		fpNoteSounds[PK_C3] = Mix_LoadWAV("sounds/notes_ogg/C3.ogg");
		fpNoteSounds[PK_Db3] = Mix_LoadWAV("sounds/notes_ogg/Db3.ogg");
		fpNoteSounds[PK_D3] = Mix_LoadWAV("sounds/notes_ogg/D3.ogg");
		fpNoteSounds[PK_Eb3] = Mix_LoadWAV("sounds/notes_ogg/Eb3.ogg");
		fpNoteSounds[PK_E3] = Mix_LoadWAV("sounds/notes_ogg/E3.ogg");
		fpNoteSounds[PK_F3] = Mix_LoadWAV("sounds/notes_ogg/F3.ogg");
		fpNoteSounds[PK_Gb3] = Mix_LoadWAV("sounds/notes_ogg/Gb3.ogg");
		fpNoteSounds[PK_G3] = Mix_LoadWAV("sounds/notes_ogg/G3.ogg");
		fpNoteSounds[PK_Ab3] = Mix_LoadWAV("sounds/notes_ogg/Ab3.ogg");
		fpNoteSounds[PK_A3] = Mix_LoadWAV("sounds/notes_ogg/A3.ogg");
		fpNoteSounds[PK_Bb3] = Mix_LoadWAV("sounds/notes_ogg/Bb3.ogg");
		fpNoteSounds[PK_B3] = Mix_LoadWAV("sounds/notes_ogg/B3.ogg");
		fpNoteSounds[PK_C4] = Mix_LoadWAV("sounds/notes_ogg/C4.ogg");
		fpNoteSounds[PK_Db4] = Mix_LoadWAV("sounds/notes_ogg/Db4.ogg");
		fpNoteSounds[PK_D4] = Mix_LoadWAV("sounds/notes_ogg/D4.ogg");
		fpNoteSounds[PK_Eb4] = Mix_LoadWAV("sounds/notes_ogg/Eb4.ogg");
		fpNoteSounds[PK_E4] = Mix_LoadWAV("sounds/notes_ogg/E4.ogg");
		fpNoteSounds[PK_F4] = Mix_LoadWAV("sounds/notes_ogg/F4.ogg");
		fpNoteSounds[PK_Gb4] = Mix_LoadWAV("sounds/notes_ogg/Gb4.ogg");
		fpNoteSounds[PK_G4] = Mix_LoadWAV("sounds/notes_ogg/G4.ogg");
		fpNoteSounds[PK_Ab4] = Mix_LoadWAV("sounds/notes_ogg/Ab4.ogg");
		fpNoteSounds[PK_A4] = Mix_LoadWAV("sounds/notes_ogg/A4.ogg");
		fpNoteSounds[PK_Bb4] = Mix_LoadWAV("sounds/notes_ogg/Bb4.ogg");
		fpNoteSounds[PK_B4] = Mix_LoadWAV("sounds/notes_ogg/B4.ogg");
		fpNoteSounds[PK_C5] = Mix_LoadWAV("sounds/notes_ogg/C5.ogg");
		fpNoteSounds[PK_Db5] = Mix_LoadWAV("sounds/notes_ogg/Db5.ogg");
		fpNoteSounds[PK_D5] = Mix_LoadWAV("sounds/notes_ogg/D5.ogg");
		fpNoteSounds[PK_Eb5] = Mix_LoadWAV("sounds/notes_ogg/Eb5.ogg");
		fpNoteSounds[PK_E5] = Mix_LoadWAV("sounds/notes_ogg/E5.ogg");
		fpNoteSounds[PK_F5] = Mix_LoadWAV("sounds/notes_ogg/F5.ogg");
		fpNoteSounds[PK_Gb5] = Mix_LoadWAV("sounds/notes_ogg/Gb5.ogg");
		fpNoteSounds[PK_G5] = Mix_LoadWAV("sounds/notes_ogg/G5.ogg");
		fpNoteSounds[PK_Ab5] = Mix_LoadWAV("sounds/notes_ogg/Ab5.ogg");
		fpNoteSounds[PK_A5] = Mix_LoadWAV("sounds/notes_ogg/A5.ogg");
		fpNoteSounds[PK_Bb5] = Mix_LoadWAV("sounds/notes_ogg/Bb5.ogg");
		fpNoteSounds[PK_B5] = Mix_LoadWAV("sounds/notes_ogg/B5.ogg");
		fpNoteSounds[PK_C6] = Mix_LoadWAV("sounds/notes_ogg/C6.ogg");
		fpNoteSounds[PK_Db6] = Mix_LoadWAV("sounds/notes_ogg/Db6.ogg");
		fpNoteSounds[PK_D6] = Mix_LoadWAV("sounds/notes_ogg/D6.ogg");
		fpNoteSounds[PK_Eb6] = Mix_LoadWAV("sounds/notes_ogg/Eb6.ogg");
		fpNoteSounds[PK_E6] = Mix_LoadWAV("sounds/notes_ogg/E6.ogg");
		fpNoteSounds[PK_F6] = Mix_LoadWAV("sounds/notes_ogg/F6.ogg");
		fpNoteSounds[PK_Gb6] = Mix_LoadWAV("sounds/notes_ogg/Gb6.ogg");
		fpNoteSounds[PK_G6] = Mix_LoadWAV("sounds/notes_ogg/G6.ogg");
		fpNoteSounds[PK_Ab6] = Mix_LoadWAV("sounds/notes_ogg/Ab6.ogg");
		fpNoteSounds[PK_A6] = Mix_LoadWAV("sounds/notes_ogg/A6.ogg");
		fpNoteSounds[PK_Bb6] = Mix_LoadWAV("sounds/notes_ogg/Bb6.ogg");
		fpNoteSounds[PK_B6] = Mix_LoadWAV("sounds/notes_ogg/B6.ogg");
		fpNoteSounds[PK_C7] = Mix_LoadWAV("sounds/notes_ogg/C7.ogg");
		fpNoteSounds[PK_Db7] = Mix_LoadWAV("sounds/notes_ogg/Db7.ogg");
		fpNoteSounds[PK_D7] = Mix_LoadWAV("sounds/notes_ogg/D7.ogg");
		fpNoteSounds[PK_Eb7] = Mix_LoadWAV("sounds/notes_ogg/Eb7.ogg");
		fpNoteSounds[PK_E7] = Mix_LoadWAV("sounds/notes_ogg/E7.ogg");
		fpNoteSounds[PK_F7] = Mix_LoadWAV("sounds/notes_ogg/F7.ogg");
		fpNoteSounds[PK_Gb7] = Mix_LoadWAV("sounds/notes_ogg/Gb7.ogg");
		fpNoteSounds[PK_G7] = Mix_LoadWAV("sounds/notes_ogg/G7.ogg");
		fpNoteSounds[PK_Ab7] = Mix_LoadWAV("sounds/notes_ogg/Ab7.ogg");
		fpNoteSounds[PK_A7] = Mix_LoadWAV("sounds/notes_ogg/A7.ogg");
		fpNoteSounds[PK_Bb7] = Mix_LoadWAV("sounds/notes_ogg/Bb7.ogg");
		fpNoteSounds[PK_B7] = Mix_LoadWAV("sounds/notes_ogg/B7.ogg");
		fpNoteSounds[PK_C8] = Mix_LoadWAV("sounds/notes_ogg/C8.ogg");
	}

	for (int i = 0; i < PK_TOTAL; ++i)
	{
		if (fpNoteSounds[i] == NULL)
		{
			printf("%s\n", Mix_GetError());
			success = false;
		}
	}

	return success;
}

// define the function for executing button actions
void actionProcessor()
{
	for (size_t i = 0; i < fpActionQueue.size(); ++i)
	{
		if (fpActionQueue[i] == BUTTON_QUIT)
		{
			fpActive = false;
			fpState = -1;
			fpSuccess = true;
			break;
		}
		else if (fpActionQueue[i] <= BUTTON_MUSIC_BOX)
		{
			fpState = fpActionQueue[i];
			fpSustain = false;
			fpScale = C_MAJOR;
			fpAccidental = 0;
			fpOctave = 4;
		}
		else if (fpActionQueue[i] == BUTTON_GO_BACK)
		{
			if (fpState == STATE_MUSIC_PLAYER)
			{
				fpState = STATE_MUSIC_SELECT;
				fpMusic = -1;
				fpHalted = true;
				fpPaused = true;
				fpSheet = NULL;
				Mix_HaltChannel(-1);
			}
			else
			{
				fpState = STATE_WELCOME;
			}
		}
		else if (fpActionQueue[i] == BUTTON_SUSTAIN)
		{
			fpSustain = !fpSustain;
		}
		else if (fpActionQueue[i] == BUTTON_PAUSE)
		{
			if (fpHalted)
			{
				fpTime1 = SDL_GetTicks();
				fpPlaytime = 0;
				fpTime2 = 0;
				fpNextNote = 0;
				fpHalted = false;
				fpPaused = false;
			}
			else if (!fpHalted && !fpPaused)
			{
				fpPaused = true;
				Mix_Pause(-1);
			}
			else if (!fpHalted && fpPaused)
			{
				fpPaused = false;
				Mix_Resume(-1);
			}
		}
		else if (fpActionQueue[i] == BUTTON_STOP)
		{
			fpHalted = true;
			fpTempo = 100;
			Mix_HaltChannel(-1);
		}
		else if (BUTTON_C_MAJOR <= fpActionQueue[i] && fpActionQueue[i] <= BUTTON_D_MINOR)
		{
			fpScale = fpActionQueue[i] - 7;
		}
		else if (fpActionQueue[i] < BUTTON_TOTAL)
		{
			fpState = STATE_MUSIC_PLAYER;
			fpMusic = fpActionQueue[i] - 19;
			fpHalted = true;
			fpPaused = true;
			fpTempo = 100;

			// load the programmed sheet music
			switch (fpMusic)
			{
				case FANTAISIE_IMPROMPTU:
					fpSheet = musicFantaisieImpromptu;
					break;
				case LIEBESTRAUME:
					fpSheet = musicLiebestraum;
					break;
				case FUR_ELISE:
					fpSheet = musicFurElise;
					break;
				case CLAIR_DE_LUNE:
					fpSheet = musicClairdeLune;
					break;
				case SONATA_PATHETIQUE:
					fpSheet = musicSonataPathetique;
					break;
				case NOCTURNE_9:
					fpSheet = musicNocturnes9;
					break;
				case PRELUDE_FUGUE_C:
					fpSheet = musicPreludeC;
					break;
				case BRAHMS_LULLABY:
					fpSheet = musicBrahmsLullaby;
					break;
				case MOONLIGHT_SONATA:
					fpSheet = musicMoonlightSonata;
					break;
			}
		}
	}

	// clear action queue
	fpActionQueue.clear();
}

// define the function for executing piano key actions
void keyProcessor()
{
	// handle key presses
	if (!fpPlayQueue.empty())
	{
		for (size_t i = 0; i < fpPlayQueue.size(); ++i)
		{
			if (Mix_FadingChannel(fpPlayQueue[i]) == MIX_FADING_OUT)
			{
				Mix_HaltChannel(fpPlayQueue[i]);
				Mix_PlayChannel(fpPlayQueue[i], fpNoteSounds[fpPlayQueue[i]], 0);
			}
			else
			{
				Mix_PlayChannel(fpPlayQueue[i], fpNoteSounds[fpPlayQueue[i]], 0);
			}
		}
	}

	// handle key releases
	if (!fpFadeQueue.empty())
	{
		for (size_t i = 0; i < fpFadeQueue.size(); ++i)
		{
			if (!fpSustain)
			{
				if (Mix_Playing(fpFadeQueue[i]))
				{
					Mix_FadeOutChannel(fpFadeQueue[i], 1000);
				}
			}
		}
	}

	// clear piano key queues
	fpPlayQueue.clear();
	fpFadeQueue.clear();
}

// define the function for updating the play time
int updatePlayTime()
{
	fpTime2 = SDL_GetTicks();
	if (!fpPaused)
	{
		fpPlaytime += ((fpTime2 - fpTime1) * fpTempo) / 100;
	}
	fpTime1 = fpTime2;
}

// define the function for rendering and updating the screen
void updateScreen()
{
	// render buttons
	if (fpState == STATE_PIANO)
	{
		// sustain buttion
		if (fpSustain)
		{
			fpTextures[TEXTURE_KEYBOARD_DOWN].renderTexture(buttonRects[BUTTON_SUSTAIN].x, buttonRects[BUTTON_SUSTAIN].y, &buttonRects[BUTTON_SUSTAIN]);
		}
		// scale buttons
		fpTextures[TEXTURE_KEYBOARD_DOWN].renderTexture(buttonRects[fpScale + 7].x, buttonRects[fpScale + 7].y, &buttonRects[fpScale + 7]);

		// render piano keys
		for (int i = 0; i < PK_TOTAL; ++i)
		{
			if (Mix_Playing(i))
			{
				// white keys
				if (keyRect_1[i].y == 568)
				{
					fpTextures[TEXTURE_KEYBOARD_DOWN].renderTexture(keyRect_1[i].x, keyRect_1[i].y, &keyRect_1[i]);
					fpTextures[TEXTURE_KEYBOARD_DOWN].renderTexture(keyRect_2[i].x, keyRect_2[i].y, &keyRect_2[i]);
				}
				// black keys
				else if (keyRect_1[i].y == 400)
				{
					fpTextures[TEXTURE_KEYBOARD_DOWN].renderTexture(keyRect_1[i].x, keyRect_1[i].y, &keyRect_1[i]);
				}
			}
		}
	}

	// render piece title and author
	if (fpState == STATE_MUSIC_PLAYER)
	{
		fpPieces[fpMusic].renderTexture((SCREEN_WIDTH - fpPieces[fpMusic].getWidth()) / 2, 400, NULL);
		fpAuthors[fpMusic] -> renderTexture(SCREEN_WIDTH / 2, 550, NULL);
	}

	// update screen
	SDL_RenderPresent(fpRenderer);
}

// define the function for handling the main loop while the program is active
bool startLoop()
{
	// keyboard management booleans
	bool acc_good = 1;		// for accidentals
	bool oct_good = 1;		// for octaves
	bool z_good = 1;		// Z key
	bool x_good = 1;		// X key
	bool c_good = 1;		// C key
	bool v_good = 1;		// V key
	bool b_good = 1;		// B key
	bool n_good = 1;		// N key
	bool m_good = 1;		// M key

	// system loop
	while (fpActive)
	{
		// loop on the welcome screen
		while (fpState == STATE_WELCOME)
		{
			SDL_RenderClear(fpRenderer);
			fpTextures[TEXTURE_WELCOME].renderTexture(0, 0, NULL);

			// detect events
			while (SDL_PollEvent(&fpEvent))
			{
				// mouse events
				if (fpEvent.type == SDL_QUIT)
				{
					fpActive = false;
					fpState = -1;
					fpSuccess = true;
					break;
				}
				for (int i = BUTTON_QUIT; i <= BUTTON_MUSIC_BOX; ++i)
				{
					fpButtons[i].handleMouseEvent(&fpEvent, fpActionQueue);
				}
			}

			// process actions
			actionProcessor();

			// update screen
			updateScreen();
		}

		// loop on the piano mode
		while (fpState == STATE_PIANO)
		{
			SDL_RenderClear(fpRenderer);
			fpTextures[TEXTURE_KEYBOARD_UP].renderTexture(0, 0, NULL);

			// detect events
			while (SDL_PollEvent(&fpEvent))
			{
				// mouse events
				if (fpEvent.type == SDL_QUIT)
				{
					fpActive = false;
					fpState = -1;
					fpSuccess = true;
					break;
				}
				for (int i = BUTTON_GO_BACK; i <= BUTTON_D_MINOR; ++i)
				{
					if (i != BUTTON_PAUSE && i != BUTTON_STOP)
					{
						fpButtons[i].handleMouseEvent(&fpEvent, fpActionQueue);
					}
				}
				for (int i = 0; i < PK_TOTAL; ++i)
				{
					fpPKs[i].handleMouseEvent(&fpEvent, fpPlayQueue, fpFadeQueue);
				}

				// keyboard events
				if (fpEvent.type == SDL_KEYDOWN)
				{
					switch (fpEvent.key.keysym.sym)
					{
						case SDLK_LSHIFT:
							if (acc_good)
							{
								fpAccidental = 1;
								acc_good = false;
							}
							break;
						case SDLK_LCTRL:
							if (acc_good)
							{
								fpAccidental = -1;
								acc_good = false;
							}
							break;
						case SDLK_KP_1:
							if (oct_good)
							{
								fpOctave = 1;
								oct_good = false;
							}
							break;
						case SDLK_KP_2:
							if (oct_good)
							{
								fpOctave = 2;
								oct_good = false;
							}
							break;
						case SDLK_KP_3:
							if (oct_good)
							{
								fpOctave = 3;
								oct_good = false;
							}
							break;
						case SDLK_KP_5:
							if (oct_good)
							{
								fpOctave = 5;
								oct_good = false;
							}
							break;
						case SDLK_KP_6:
							if (oct_good)
							{
								fpOctave = 6;
								oct_good = false;
							}
							break;
						case SDLK_KP_7:
							if (oct_good)
							{
								fpOctave = 7;
								oct_good = false;
							}
							break;
						case SDLK_z:
							if (z_good)
							{
								fpPKs[fpScaleNotes[fpScale][CNote] + (fpOctave - 4) * 12 + fpAccidental].pressPK(fpPlayQueue);
								z_good = false;
							}
							break;
						case SDLK_x:
							if (x_good)
							{
								fpPKs[fpScaleNotes[fpScale][DNote] + (fpOctave - 4) * 12 + fpAccidental].pressPK(fpPlayQueue);
								x_good = false;
							}
							break;
						case SDLK_c:
							if (c_good)
							{
								fpPKs[fpScaleNotes[fpScale][ENote] + (fpOctave - 4) * 12 + fpAccidental].pressPK(fpPlayQueue);
								c_good = false;
							}
							break;
						case SDLK_v:
							if (v_good)
							{
								fpPKs[fpScaleNotes[fpScale][FNote] + (fpOctave - 4) * 12 + fpAccidental].pressPK(fpPlayQueue);
								v_good = false;
							}
							break;
						case SDLK_b:
							if (b_good)
							{
								fpPKs[fpScaleNotes[fpScale][GNote] + (fpOctave - 4) * 12 + fpAccidental].pressPK(fpPlayQueue);
								b_good = false;
							}
							break;
						case SDLK_n:
							if (n_good)
							{
								fpPKs[fpScaleNotes[fpScale][ANote] + (fpOctave - 4) * 12 + fpAccidental].pressPK(fpPlayQueue);
								n_good = false;
							}
							break;
						case SDLK_m:
							if (m_good)
							{
								fpPKs[fpScaleNotes[fpScale][BNote] + (fpOctave - 4) * 12 + fpAccidental].pressPK(fpPlayQueue);
								m_good = false;
							}
					}
				}
				else if (fpEvent.type == SDL_KEYUP)
				{
					switch (fpEvent.key.keysym.sym)
					{
						case SDLK_LSHIFT:
							fpAccidental = 0;
							acc_good = true;
							break;
						case SDLK_LCTRL:
							fpAccidental = 0;
							acc_good = true;
							break;
						case SDLK_KP_1:
							fpOctave = 4;
							oct_good = true;
							break;
						case SDLK_KP_2:
							fpOctave = 4;
							oct_good = true;
							break;
						case SDLK_KP_3:
							fpOctave = 4;
							oct_good = true;
							break;
						case SDLK_KP_5:
							fpOctave = 4;
							oct_good = true;
							break;
						case SDLK_KP_6:
							fpOctave = 4;
							oct_good = true;
							break;
						case SDLK_KP_7:
							fpOctave = 4;
							oct_good = true;
							break;
						case SDLK_z:
							fpPKs[fpScaleNotes[fpScale][CNote] + (fpOctave - 4) * 12 + fpAccidental].releasePK(fpFadeQueue);
							z_good = true;
							break;
						case SDLK_x:
							fpPKs[fpScaleNotes[fpScale][DNote] + (fpOctave - 4) * 12 + fpAccidental].releasePK(fpFadeQueue);
							x_good = true;
							break;
						case SDLK_c:
							fpPKs[fpScaleNotes[fpScale][ENote] + (fpOctave - 4) * 12 + fpAccidental].releasePK(fpFadeQueue);
							c_good = true;
							break;
						case SDLK_v:
							fpPKs[fpScaleNotes[fpScale][FNote] + (fpOctave - 4) * 12 + fpAccidental].releasePK(fpFadeQueue);
							v_good = true;
							break;
						case SDLK_b:
							fpPKs[fpScaleNotes[fpScale][GNote] + (fpOctave - 4) * 12 + fpAccidental].releasePK(fpFadeQueue);
							b_good = true;
							break;
						case SDLK_n:
							fpPKs[fpScaleNotes[fpScale][ANote] + (fpOctave - 4) * 12 + fpAccidental].releasePK(fpFadeQueue);
							n_good = true;
							break;
						case SDLK_m:
							fpPKs[fpScaleNotes[fpScale][BNote] + (fpOctave - 4) * 12 + fpAccidental].releasePK(fpFadeQueue);
							m_good = true;
							break;
						case SDLK_TAB:
							Mix_HaltChannel(-1);
					}
				}
			}

			// process actions
			actionProcessor();
			keyProcessor();

			// update screen
			updateScreen();
		}

		// loop on the piece selection mode
		while (fpState == STATE_MUSIC_SELECT)
		{
			SDL_RenderClear(fpRenderer);
			fpTextures[TEXTURE_MUSIC_SELECT].renderTexture(0, 0, NULL);

			// detect events
			while (SDL_PollEvent(&fpEvent))
			{
				// mouse events
				if (fpEvent.type == SDL_QUIT)
				{
					fpActive = false;
					fpState = -1;
					fpSuccess = true;
					break;
				}
				fpButtons[BUTTON_GO_BACK].handleMouseEvent(&fpEvent, fpActionQueue);
				for (int i = BUTTON_FANTAISIE_IMPROMPTU; i < BUTTON_TOTAL; ++i)
				{
					fpButtons[i].handleMouseEvent(&fpEvent, fpActionQueue);
				}
			}

			// process actions
			actionProcessor();

			// update screen
			updateScreen();
		}

		// loop on the music player mode
		while (fpState == STATE_MUSIC_PLAYER)
		{
			SDL_RenderClear(fpRenderer);
			fpTextures[TEXTURE_MUSIC_PLAYER].renderTexture(0, 0, NULL);

			// detect events
			while (SDL_PollEvent(&fpEvent))
			{
				if (fpEvent.type == SDL_QUIT)
				{
					fpActive = false;
					fpState = -1;
					fpSuccess = true;
					break;
				}
				fpButtons[BUTTON_GO_BACK].handleMouseEvent(&fpEvent, fpActionQueue);
				fpButtons[BUTTON_PAUSE].handleMouseEvent(&fpEvent, fpActionQueue);
			}

			// loop for playing the programmed notes
			while (!fpHalted)
			{
				// play or fade a note based on play time
				if (fpSheet[fpNextNote].name != -1 && fpSheet[fpNextNote].name != -2 && fpSheet[fpNextNote].name != -3 && fpSheet[fpNextNote].name != -4)
				{
					if (fpPlaytime >= fpSheet[fpNextNote].time)
					{
						if (fpSheet[fpNextNote].toplay)
						{
							int chord_time = fpSheet[fpNextNote].time;
							bool chord_continue = true;
							// build chord notes before playing them
							while (chord_continue)
							{
								fpChordQueue.push_back(fpSheet[fpNextNote]);
								if (fpSheet[fpNextNote + 1].toplay && fpSheet[fpNextNote + 1].time == chord_time)
								{
									fpNextNote += 1;
								}
								else
								{
									for (Note ni : fpChordQueue)
									{
										if (Mix_FadingChannel(ni.name) == MIX_FADING_OUT)
										{
											Mix_HaltChannel(ni.name);
										}
										Mix_Volume(ni.name, ni.volume);
									}
									for (Note ni : fpChordQueue)
									{
										Mix_PlayChannel(ni.name, fpNoteSounds[ni.name], 0);
									}
									fpChordQueue.clear();
									chord_continue = false;
									fpNextNote += 1;
								}
							}
						}
						else
						{
							if (Mix_Playing(fpSheet[fpNextNote].name))
							{
								Mix_FadeOutChannel(fpSheet[fpNextNote].name, 600);
							}
							fpNextNote += 1;
						}
					}
				}
				// time change
				else if (fpSheet[fpNextNote].name == -4)
				{
					fpPlaytime = fpSheet[fpNextNote].time;
					fpNextNote += 1;
				}
				// tempo change
				else if (fpSheet[fpNextNote].name == -3)
				{
					if (fpSheet[fpNextNote].time == 0)
					{
						fpTempo = 100;
					}
					else if (fpSheet[fpNextNote].time > 0)
					{
						fpTempo = fpSheet[fpNextNote].time;
					}
					fpNextNote += 1;
				}
				// release pedal
				else if (fpSheet[fpNextNote].name == -2)
				{
					Mix_FadeOutChannel(-1, 600);
					fpNextNote += 1;
				}
				// end piece
				else
				{
					SDL_Delay(2000);
					fpHalted = true;
					Mix_HaltChannel(-1);
				}

				// check events
				while (SDL_PollEvent(&fpEvent))
				{
					if (fpEvent.type == SDL_QUIT)
					{
						fpHalted = true;
						fpActive = false;
						fpState = -1;
						fpSuccess = true;
						break;
					}
					fpButtons[BUTTON_GO_BACK].handleMouseEvent(&fpEvent, fpActionQueue);
					fpButtons[BUTTON_PAUSE].handleMouseEvent(&fpEvent, fpActionQueue);
					fpButtons[BUTTON_STOP].handleMouseEvent(&fpEvent, fpActionQueue);
				}

				actionProcessor();

				updateScreen();

				// update play time
				updatePlayTime();
			}

			// process actions
			actionProcessor();

			// update screen
			updateScreen();
		}
	}

	return fpSuccess;
}

// main program launcher
int main(int argc, char** argv)
{
	// initialize SDL
	if (!initSDL())
	{
		printf("\n%s\n", "unable to initialize SDL");
	}
	else
	{
		// set up objects
		objSetup();

		// load media
		if (!loadMedia())
		{
			printf("\n%s\n", "unable to load media files");
		}
		else
		{
			// run the main program loop
			if (!startLoop())
			{
				printf("\n%s\n", "process ended unexpectedly");
			}
		}

		// quit SDL
		quitSDL();
	}

	return 0;
}
