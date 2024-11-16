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
