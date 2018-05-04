//
// Created by sandra on 29.04.18.
//

#ifndef JIMP_EXERCISES_MOVIESUBTITLES_H
#define JIMP_EXERCISES_MOVIESUBTITLES_H

#include <string>
#include <sstream>
#include <regex>
#include <iostream>

using namespace std;

namespace moviesubs {

    class MovieSubtitles {
    public:
        virtual void ShiftAllSubtitlesBy(int ms, int fps, stringstream* in, stringstream* out)=0;
    };
    

    class MicroDvdSubtitles: public MovieSubtitles {
    public:
        void ShiftAllSubtitlesBy(int ms, int fps, stringstream* in, stringstream* out) override ;
    };

    class SubRipSubtitles : public MovieSubtitles {
    public:
        void ShiftAllSubtitlesBy(int ms, int fps, stringstream* in, stringstream* out) override ;
    };
    

    class NegativeFrameAfterShift : public invalid_argument {
    public:
        NegativeFrameAfterShift():invalid_argument(""){};
    };

    class SubtitleEndBeforeStart : public exception {
    public:
        SubtitleEndBeforeStart(int line, string line_text) {
                                                line_ = line;
                                                error_ = "At line " + to_string(line) + ": " + line_text;};
        int LineAt() const;
        const char* what() const throw() ;
    private:
        int line_;
        string error_;
    };

    class InvalidSubtitleLineFormat : public invalid_argument {
    public:
        InvalidSubtitleLineFormat():invalid_argument(""){};
    };

    class MissingTimeSpecification : public invalid_argument {
    public:
        MissingTimeSpecification():invalid_argument(""){};
    };

    class OutOfOrderFrames : public NegativeFrameAfterShift {
    public:
        OutOfOrderFrames():NegativeFrameAfterShift(){};
    };
}

#endif //JIMP_EXERCISES_MOVIESUBTITLES_H
