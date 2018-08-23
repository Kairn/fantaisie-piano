/* fpClasses.h */
/* ===========================================================================
 * HEADER FILE FOR ALL CUSTOM TYPES
 *
 */

#ifndef FPCLASSES_H
#define FPCLASSES_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_mixer.h>
#include <SDL2/SDL_ttf.h>
#include <string>
#include <vector>

extern SDL_Renderer* fpRenderer;

// declare Texture class
class Texture
{
	private:
		SDL_Texture* texture;
		int width;
		int height;

	public:
		Texture();
		~Texture();
		void freeTexture();
		bool loadTexture(std::string);
		bool loadFontString(std::string, TTF_Font*);
		int getWidth();
		int getHeight();
		void renderTexture(int, int, SDL_Rect*);
};

// declare Button class
class Button
{
	private:
		int name;
		SDL_Rect* rect;
		bool clicked;

	public:
		Button();
		~Button();
		void freeButton();
		void setButton(int, SDL_Rect*);
		void handleMouseEvent(SDL_Event*, std::vector<int>&);
};

// declare Piano Key class
class PianoKey
{
	private:
		// add code
		int name;
		SDL_Rect* rect_1;
		SDL_Rect* rect_2;

	public:
		PianoKey();
		~PianoKey();
		void freePK();
		void setPK(int, SDL_Rect*, SDL_Rect*);
		void handleMouseEvent(SDL_Event*, std::vector<int>&, std::vector<int>&);
		void pressPK(std::vector<int>&);
		void releasePK(std::vector<int>&);
};

#endif
