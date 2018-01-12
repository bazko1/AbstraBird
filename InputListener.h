//
// Created by bazyli on 1/8/18.
//

#ifndef ABSTRABIRD_INPUTLISTENER_H
#define ABSTRABIRD_INPUTLISTENER_H


class InputListener {

private:

    bool jumped= false;

public:
    bool hasJumped() const;

    bool isPause() const;

    bool isGameFinished() const;

    bool isGameStarted() const;

private:

    bool pause= false;

    bool gameFinished= false;

    bool gameStarted = false;

public:
    void checkInput();


};


#endif //ABSTRABIRD_INPUTLISTENER_H
