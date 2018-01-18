//
// Created by bazyli on 1/8/18.
//

#ifndef ABSTRABIRD_INPUTLISTENER_H
#define ABSTRABIRD_INPUTLISTENER_H


class InputListener {

private:


    bool pause = false;

    bool gameFinished = false;

    bool gameStarted = false;

    bool jumped= false;

public:
    bool JumpButtonClicked() const;

    bool isPause() const;

    bool isGameFinished() const;

    bool isGameStarted() const;

    void checkInput();

    void setJumped(bool jumped);

    void reset();

};


#endif //ABSTRABIRD_INPUTLISTENER_H
