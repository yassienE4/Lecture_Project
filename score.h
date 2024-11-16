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
