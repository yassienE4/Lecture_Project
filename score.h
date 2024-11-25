/*
#ifndef SCORE_H
#define SCORE_H

#include <QObject>
#include <QGraphicsTextItem>

class score: public QObject, public QGraphicsTextItem

{
private:
    Q_OBJECT
public:
    score(QObject *parent = nullptr);
    int getscore()const;
    int gethighscore() const;

    // to increase the score
    void increase_score(int points);

    // when the level is sussesfully passed, the score will be save
    void save_score();

    //if you failed the level, reset score
    void reset_score();

private:
    int your_score;
    int highscore;
};

#endif // SCORE_H
*/

// #ifndef sCORE_H
// #define sCORE_H

// #include <QObject>
// #include <QGraphicsTextItem>

// class score : public QGraphicsTextItem {
//     Q_OBJECT
// public:
//     // Constructor
//     score(QGraphicsItem *parent = nullptr);

//     // Public method to increase score
//     void increase();

//     // Public method to get the current score
//     int getScore() const;

// private:
//     int the_score;
// };

// #endif // SCORE_H

#ifndef SCORE_H
#define SCORE_H

#include <QObject>
#include <QGraphicsTextItem>
#include <QGraphicsItem>
#include <QList>

class score : public QGraphicsTextItem {
    Q_OBJECT
public:
    // Constructor
    explicit score(QGraphicsItem *parent = nullptr);

    // Public methods
    void increase();            // Increments the score
    int getScore() const;       // Returns the current score
    void checkCollision(QGraphicsItem *steve, QList<QGraphicsItem *> &diamonds); // Collision checker
    virtual ~score();

private:
    int the_score;                  // Holds the score value
};

#endif // SCORE_H
