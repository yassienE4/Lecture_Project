/*

#include "score.h"

score:: score(QObject *parent)
    : QObject(parent), your_score(0), highscore(0){}
int score:: getscore() const{
    return your_score;
}
int score:: gethighscore() const{
    return highscore;
}
void score:: increase_score(int points){
    your_score += points;

}
void score:: reset_score(){
    your_score =0;
}
void score:: save_score(){
    if (your_score > highscore){
        highscore = your_score;
    }
    your_score =0;
}
*/

// #include "score.h"
// #include <QFont>

// // Constructor
// score::score(QGraphicsItem *parent) : QGraphicsTextItem(parent), the_score(0) {
//     // Initialize the score display
//     setPlainText(QString("Score: ") + QString::number(the_score));
//     setDefaultTextColor(Qt::black);  // Set text color
//     setFont(QFont("Arial", 16));     // Set font and size
// }

// // Method to increase the score
// void score::increase() {
//     the_score++;
//     setPlainText(QString("Score: ") + QString::number(the_score));  // Update the displayed score
// }

// // Method to get the current score
// int score::getScore() const {
//     return the_score;
// }

#include "score.h"
#include <QFont>
#include "diamonds.h"
#include <QGraphicsScene>
#include<steve.h>

// Constructor
score::score(QGraphicsItem *parent) : QGraphicsTextItem(parent), the_score(0) {
    // Initialize the score display
    setPlainText(QString("Score: ") + QString::number(the_score));

    // Set text color to black
    setDefaultTextColor(Qt::black);

    // Set font to bold and size to 16
    QFont font("Arial", 16, QFont::Bold);
    setFont(font);

    // Position the score to the right
    setPos(700, 200);  // Adjust x and y values as needed to position it on the right
}

// Method to increase the score
void score::increase() {
    the_score++;
    setPlainText(QString("Score: ") + QString::number(the_score));  // Update the displayed score
}

// Method to get the current score
int score::getScore() const {
    return the_score;
}
void score::checkCollision(QGraphicsItem *steve, QList<QGraphicsItem *> &diamonds) {
    for (QGraphicsItem *item : diamonds) {
        if (steve->collidesWithItem(item)) {
            // Increase score
            increase();

            // Remove diamond from scene
            item->scene()->removeItem(item);  // Properly access the scene
            diamonds.removeOne(item);        // Remove from list
            delete item;                     // Free memory
            break;                           // Exit loop after handling one collision
        }
    }
}
score::~score() {
    // Clean up if needed
}
