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
