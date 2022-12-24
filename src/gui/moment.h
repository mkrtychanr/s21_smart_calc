#ifndef MOMENT_H
#define MOMENT_H

struct Moment {
    int bracketCounter = 0;
    int status = 0;
    int characters = 0;
    Moment(int bracketCounter, int status, int characters) {
        this -> bracketCounter = bracketCounter;
        this -> status = status;
        this -> characters = characters;
    }
};


#endif // MOMENT_H