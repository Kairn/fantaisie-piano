/* fpConstants.h */
/* ===========================================================================
 * HEADER FILE THAT CONTAINS ALL SYMBOLIC CONSTANTS
 *
 */

#ifndef FPCONSTANTS_H
#define FPCONSTANTS_H

// declare constants for system settings
const int SCREEN_WIDTH = 1760;
const int SCREEN_HEIGHT = 990;
const SDL_Color fpFontColor = {255, 255, 255, 220};

// declare symbolic constants for all states of the program
enum fpStateConsts
{
	STATE_WELCOME,
	STATE_PIANO,
	STATE_MUSIC_SELECT,
	STATE_MUSIC_PLAYER,
	// add states here
	STATE_TOTAL
};

// declare symbolic constants for all textures
enum fpTextureConsts
{
	TEXTURE_WELCOME,
	TEXTURE_KEYBOARD_UP,
	TEXTURE_KEYBOARD_DOWN,
	TEXTURE_MUSIC_SELECT,
	TEXTURE_MUSIC_PLAYER,
	// add textures here
	TEXTURE_TOTAL
};

// declare symbolic constants for all buttons
// 0-2: mode selection
// 3-6: interface control
// 7-18: keyboard scale selection
// 19-(-2): piece selection
enum fpButtonConsts
{
	BUTTON_QUIT,
	BUTTON_PLAY_PIANO,
	BUTTON_MUSIC_BOX,
	BUTTON_GO_BACK,
	BUTTON_SUSTAIN,
	BUTTON_PAUSE,
	BUTTON_STOP,
	BUTTON_C_MAJOR,
	BUTTON_G_MAJOR,
	BUTTON_D_MAJOR,
	BUTTON_A_MAJOR,
	BUTTON_E_MAJOR,
	BUTTON_B_MAJOR,
	BUTTON_FS_MAJOR,
	BUTTON_CS_MAJOR,
	BUTTON_F_MINOR,
	BUTTON_C_MINOR,
	BUTTON_G_MINOR,
	BUTTON_D_MINOR,
	BUTTON_FANTAISIE_IMPROMPTU,
	BUTTON_LIEBESTRAUME,
	BUTTON_FUR_ELISE,
	BUTTON_CLAIR_DE_LUNE,
	BUTTON_SONATA_PATHETIQUE,
	BUTTON_NOCTURNE_9,
	BUTTON_PRELUDE_FUGUE_C,
	BUTTON_BRAHMS_LULLABY,
	BUTTON_MOONLIGHT_SONATA,
	// add buttons here
	BUTTON_TOTAL
};

// declare symbolic constants for all scales
enum fpScaleConsts
{
	C_MAJOR,
	G_MAJOR,
	D_MAJOR,
	A_MAJOR,
	E_MAJOR,
	B_MAJOR,
	FS_MAJOR,
	CS_MAJOR,
	F_MINOR,
	C_MINOR,
	G_MINOR,
	D_MINOR,
	SCALE_TOTAL
};

// declare symbolic constants for all scale degrees
enum fpDegreeConsts
{
	CNote,
	DNote,
	ENote,
	FNote,
	GNote,
	ANote,
	BNote,
	DEGREE_TOTAL
};

// declare symbolic constants for all piano keys
enum fpPianoKeyConsts
{
	PK_A0,
	PK_Bb0,
	PK_B0,
	PK_C1,
	PK_Db1,
	PK_D1,
	PK_Eb1,
	PK_E1,
	PK_F1,
	PK_Gb1,
	PK_G1,
	PK_Ab1,
	PK_A1,
	PK_Bb1,
	PK_B1,
	PK_C2,
	PK_Db2,
	PK_D2,
	PK_Eb2,
	PK_E2,
	PK_F2,
	PK_Gb2,
	PK_G2,
	PK_Ab2,
	PK_A2,
	PK_Bb2,
	PK_B2,
	PK_C3,
	PK_Db3,
	PK_D3,
	PK_Eb3,
	PK_E3,
	PK_F3,
	PK_Gb3,
	PK_G3,
	PK_Ab3,
	PK_A3,
	PK_Bb3,
	PK_B3,
	PK_C4,
	PK_Db4,
	PK_D4,
	PK_Eb4,
	PK_E4,
	PK_F4,
	PK_Gb4,
	PK_G4,
	PK_Ab4,
	PK_A4,
	PK_Bb4,
	PK_B4,
	PK_C5,
	PK_Db5,
	PK_D5,
	PK_Eb5,
	PK_E5,
	PK_F5,
	PK_Gb5,
	PK_G5,
	PK_Ab5,
	PK_A5,
	PK_Bb5,
	PK_B5,
	PK_C6,
	PK_Db6,
	PK_D6,
	PK_Eb6,
	PK_E6,
	PK_F6,
	PK_Gb6,
	PK_G6,
	PK_Ab6,
	PK_A6,
	PK_Bb6,
	PK_B6,
	PK_C7,
	PK_Db7,
	PK_D7,
	PK_Eb7,
	PK_E7,
	PK_F7,
	PK_Gb7,
	PK_G7,
	PK_Ab7,
	PK_A7,
	PK_Bb7,
	PK_B7,
	PK_C8,
	PK_TOTAL,
};

// declare symbolic constants for all pieces
enum fpPieceConsts
{
	FANTAISIE_IMPROMPTU,
	LIEBESTRAUME,
	FUR_ELISE,
	CLAIR_DE_LUNE,
	SONATA_PATHETIQUE,
	NOCTURNE_9,
	PRELUDE_FUGUE_C,
	BRAHMS_LULLABY,
	MOONLIGHT_SONATA,
	// add pieces
	PIECE_TOTAL
};

// declare symbolic constants for all authors
enum fpAuthorConsts
{
	CHOPIN,
	LISZT,
	BEETHOVEN,
	DEBUSSY,
	BACH,
	BRAHMS,
	// add authors
	AUTHOR_TOTAL
};

#endif
