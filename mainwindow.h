#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include <QTimer>
#include <QList>
#include <QMovie>
#include "ghost.h"
#include "normal_ghost.h"
#include "hat_ghost.h"
#include "bucket_ghost.h"
#include "football_ghost.h"
#include "plant.h"
#include "nut.h"
#include "bomb.h"
#include "shooter.h"
#include "ice_shooter.h"
#include "bullet.h"
#include "ice_bullet.h"
#include "brain.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    void movie_start();

    void initial();

    void clear();

    void paintEvent(QPaintEvent *event);

    void if_win();

    void if_lost();

    void if_next();

    void set_ghost_card_back();

    void set_ghost_card_choosed(int i);

    void set_solid(int i,int j,int card_get);

    int judge_money(int i);

    void if_ghost_attack(ghost* ghostc);

    void if_bomb_attack(bomb* bombc);

    void if_shooter_shoot(shooter* shooterc);

    void if_ice_shooter_shoot(ice_shooter* ice_shooterc);

    void if_bullet_attack(bullet* bulletc);

    void if_ice_bullet_attack(ice_bullet* ice_bulletc);

private slots:

    void refresh();

    void on_normal_ghost_card_clicked();

    void on_hat_ghost_card_clicked();

    void on_bucket_ghost_card_clicked();

    void on_football_ghost_card_clicked();

    void on_block_9_1_clicked();

    void on_block_9_2_clicked();

    void on_block_9_3_clicked();

    void on_block_9_4_clicked();

    void on_block_9_5_clicked();

    void on_block_8_1_clicked();

    void on_block_8_2_clicked();

    void on_block_8_3_clicked();

    void on_block_8_4_clicked();

    void on_block_8_5_clicked();

    void on_block_7_1_clicked();

    void on_block_7_2_clicked();

    void on_block_7_3_clicked();

    void on_block_7_4_clicked();

    void on_block_7_5_clicked();

    void on_block_6_1_clicked();

    void on_block_6_2_clicked();

    void on_block_6_3_clicked();

    void on_block_6_4_clicked();

    void on_block_6_5_clicked();

    void get_hide();

    void get_show();

    void get_close();

private:
    QTimer * ptimer;
    QList<bullet*> bullets;
    QList<ice_bullet*> ice_bullets;
    QList<nut*> nuts;
    QList<bomb*> bombs;
    QList<shooter*> shooters;
    QList<ice_shooter*> ice_shooters;
    QList<brain*> brains;
    QList<booming*> boomings;
    QList<bullet_breaking*> bullet_breakings;
    QList<ice_bullet_breaking*> ice_bullet_breakings;
    QList<ghost*> normal_ghosts;
    QList<ghost*> hat_ghosts;
    QList<ghost*> bucket_ghosts;
    QList<ghost*> football_ghosts;
    QList<ghost_die*> ghost_dies;
    QList<ghost_die*> football_ghost_dies;
    QMovie * nut_movie;
    QMovie * nut_cracked2_movie;
    QMovie * nut_cracked1_movie;
    QMovie * bomb_movie;
    QMovie * shooter_movie;
    QMovie * ice_shooter_movie;
    QMovie * bullet_movie;
    QMovie * ice_bullet_movie;
    QMovie * brain_movie;
    QMovie * normal_ghost_move_movie;
    QMovie * normal_ghost_attack_movie;
    QMovie * hat_ghost_move_movie;
    QMovie * hat_ghost_attack_movie;
    QMovie * bucket_ghost_move_movie;
    QMovie * bucket_ghost_attack_movie;
    QMovie * football_ghost_move_movie;
    QMovie * football_ghost_attack_movie;
    QList<QMovie*> ghost_die_movie;
    QList<QMovie*> football_ghost_die_movie;
    int card_get;
    int x;int y;
    int round=0;
    int place[5][25]={{14, 8, 15, 16, 23, 5, 24, 20, 10, 1, 9, 18, 4, 17, 12, 19, 6, 3, 7, 2, 13, 0, 11, 21, 22},
                      {6, 22, 19, 10, 15, 8, 18, 14, 3, 4, 7, 23, 21, 13, 2, 20, 17, 12, 24, 16, 11, 0, 1, 9, 5},
                      {15, 5, 2, 8, 18, 22, 16, 7, 14, 10, 20, 9, 13, 3, 11, 6, 1, 4, 23, 12, 19, 0, 24, 17, 21},
                      {20, 0, 22, 18, 10, 9, 7, 15, 17, 12, 23, 16, 3, 21, 11, 19, 8, 24, 4, 5, 6, 13, 14, 1, 2},
                      {16, 24, 13, 9, 10, 23, 18, 12, 17, 21, 19, 5, 14, 6, 11, 3, 2, 4, 22, 8, 20, 0, 15, 7, 1}};
    Ui::MainWindow * ui;
};

#endif // MAINWINDOW_H
