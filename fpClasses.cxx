/* fpCLasses.cxx */
/* ===========================================================================
 * SOURCE FILE FOR ALL CUSTOM TYPES WITH DEFINITIONS
 *
 * CLASS 1: TEXTURE(IMAGES)
 * CLASS 2: BUTTONS
 * CLASS 3: PIANO KEYS(NOTES)
 *
 */

#include "fpClasses.h"
#include "fpConstants.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_mixer.h>
#include <SDL2/SDL_ttf.h>
#include <stdio.h>
#include <string>
#include <vector>

// TEXTURE CLASS MEMBER DEFINITIONS
// define Texture constructor
Texture::Texture()
{
	texture = NULL;
	width = 0;
	height = 0;
}

// define Texture destructor
Texture::~Texture()
{
	freeTexture();
}

// define the function for deallocating Texture memory
void Texture::freeTexture()
{
	if (texture != NULL)
	{
		SDL_DestroyTexture(texture);
		texture = NULL;
		width = 0;
		height = 0;
	}
}

// define the function for creating new texture from image file
bool Texture::loadTexture(std::string t_path)
{
	freeTexture();

	SDL_Texture* newTexture = NULL;
	SDL_Surface* tempSurface = IMG_Load(t_path.c_str());

	if (tempSurface == NULL)
	{
		printf("%s\n", IMG_GetError());
	}
	else
	{
		newTexture = SDL_CreateTextureFromSurface(fpRenderer, tempSurface);
		if (newTexture == NULL)
		{
			printf("%s\n", SDL_GetError());
		}
		else
		{
			width = tempSurface -> w;
			height = tempSurface -> h;
		}
	SDL_FreeSurface(tempSurface);
	}
	texture = newTexture;

	return texture != NULL;
}

// define the function for creating new texture from string
bool Texture::loadFontString(std::string t_content, TTF_Font* t_font)
{
	freeTexture();

	SDL_Surface* tempSurface = TTF_RenderText_Solid(t_font, t_content.c_str(), fpFontColor);
	if (tempSurface == NULL)
	{
		printf("%s\n", TTF_GetError());
	}
	else
	{
		texture = SDL_CreateTextureFromSurface(fpRenderer, tempSurface);
        if (texture == NULL)
        {
            printf("%s\n", SDL_GetError());
        }
        else
        {
            width = tempSurface -> w;
            height = tempSurface -> h;
        }
        SDL_FreeSurface(tempSurface);
	}

	return texture != NULL;
}


int Texture::getWidth()
{
	return width;
}


int Texture::getHeight()
{
	return height;
}

// define the function for rendering a portion of the texture
void Texture::renderTexture(int t_x, int t_y, SDL_Rect* t_crop=NULL)
{
	SDL_Rect location = {t_x, t_y, width, height};
	if (t_crop != NULL)
	{
		location.w = t_crop -> w;
		location.h = t_crop -> h;
	}
	SDL_RenderCopyEx(fpRenderer, texture, t_crop, &location, 0, NULL, SDL_FLIP_NONE);
}

// BUTTON CLASS MEMBER DEFINITIONS
// define Button constructor
Button::Button()
{
	name = -1;
	rect = NULL;
	clicked = false;
}

// define Button destructor
Button::~Button()
{
	freeButton();
}


void Button::freeButton()
{
	if (name != -1)
	{
		name = -1;
		rect = NULL;
		clicked = false;
	}
}

// define the function for setting up the button
void Button::setButton(int t_name, SDL_Rect* t_rect)
{
	freeButton();

	name = t_name;
	rect = t_rect;
}

// define the function for handling mouse events
void Button::handleMouseEvent(SDL_Event* t_event, std::vector<int>& t_action_queue)
{
	SDL_Point position;

	if (t_event -> type == SDL_MOUSEBUTTONDOWN)
	{
		SDL_GetMouseState(&position.x, &position.y);
		if (SDL_PointInRect(&position, rect))
		{
			clicked = true;
		}
	}
	else if (t_event -> type == SDL_MOUSEBUTTONUP)
	{
		SDL_GetMouseState(&position.x, &position.y);
		if (SDL_PointInRect(&position, rect) && clicked == true)
		{
			t_action_queue.push_back(name);
		}
		clicked = false;
	}
}

// PIANO KEY CLASS MEMBER DEFINITIONS
// define PianoKey constructor
PianoKey::PianoKey()
{
	name = -1;
	rect_1 = NULL;
	rect_2 = NULL;
}

// define PianoKey destructor
PianoKey::~PianoKey()
{
	freePK();
}


void PianoKey::freePK()
{
	if (name != -1)
	{
		name = -1;
		rect_1 = NULL;
		rect_2 = NULL;
	}
}

// define the function for setting up the piano key
void PianoKey::setPK(int t_name, SDL_Rect* t_rect_1, SDL_Rect* t_rect_2)
{
	freePK();

	name = t_name;
	rect_1 = t_rect_1;
	rect_2 = t_rect_2;
}

// define the function for handling mouse events
void PianoKey::handleMouseEvent(SDL_Event* t_event, std::vector<int>& t_play_queue, std::vector<int>& t_fade_queue)
{
	SDL_Point position;

	if (t_event -> type == SDL_MOUSEBUTTONDOWN)
	{
		SDL_GetMouseState(&position.x, &position.y);
		if (SDL_PointInRect(&position, rect_1) || SDL_PointInRect(&position, rect_2))
		{
			t_play_queue.push_back(name);
		}
	}
	else if (t_event -> type == SDL_MOUSEBUTTONUP)
	{
		t_fade_queue.push_back(name);
	}
}

// define the functions for pressing the piano key (with keyboard control)
void PianoKey::pressPK(std::vector<int>& t_play_queue)
{
	t_play_queue.push_back(name);
}


void PianoKey::releasePK(std::vector<int>& t_fade_queue)
{
	t_fade_queue.push_back(name);
}
