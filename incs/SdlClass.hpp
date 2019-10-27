//
// Created by Hippolyte Einfalt on 26/10/2019.
//

#ifndef SDLCLASS_HPP
#define SDLCLASS_HPP

#include <iostream>
#include <string>
#include <unistd.h>
#include <sys/types.h>
#include <pwd.h>
#include <uuid/uuid.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_main.h>
#include <SDL2/SDL_quit.h>
#include <SDL2/SDL_ttf.h>
#include <cstdio>
#include <algorithm>
#include <list>

class SdlClass {
public:
    SdlClass();
    ~SdlClass();
    SdlClass(SdlClass const &);

    SdlClass &operator=(SdlClass const &);

    SDL_Window *initSdl();
    void exitSdl();
    void update();
    void initScrValue();
    void initSurfaces(unsigned int nbr);
    void printInfo(SDL_Rect);

    class BadSdlInitException : public std::exception {
    public:
        BadSdlInitException();
        BadSdlInitException(BadSdlInitException const &);
        ~BadSdlInitException() throw();
        BadSdlInitException &operator=(BadSdlInitException const &);
        virtual const char *what() const throw();
    };

    class BadWindowCreationException : public std::exception {
    public:
        BadWindowCreationException();
        BadWindowCreationException(BadWindowCreationException const &);
        ~BadWindowCreationException() throw();
        BadWindowCreationException &operator=(BadWindowCreationException const &);
        virtual const char *what() const throw();
    };

    class BadTtfInitException : public std::exception {
    public:
        BadTtfInitException();
        BadTtfInitException(BadTtfInitException const &);
        ~BadTtfInitException() throw();
        BadTtfInitException &operator=(BadTtfInitException const &);
        virtual const char *what() const throw();
    };

    SDL_Window *getScreen() const;
    void setScreen(SDL_Window *screen);
    void setRunning(bool running);
    bool isRunning() const;
    unsigned int getScrWidth() const;
    void setScrWidth(unsigned int scrWidth);
    unsigned int getScrHeight() const;
    void setScrHeight(unsigned int scrHeight);
    const std::list<SDL_Surface *> &getSurfaces() const;

private:
    SDL_Window              *_screen;
    bool                    _running;
    std::list<SDL_Surface*> _surfaces;
    unsigned int            _scrWidth;
    unsigned int            _scrHeight;
    TTF_Font                *_police;
};


#endif //SDLCLASS_HPP
