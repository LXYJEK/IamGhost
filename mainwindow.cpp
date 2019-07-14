#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QString"
#include <math.h>
#include <QPainter>
#include <QPixmap>
#include <QMovie>
#include <QPaintEvent>
#include "startdialog.h"
#include "middledialog.h"
#include "losedialog.h"
#include "windialog.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowFlags(Qt::FramelessWindowHint);
    ptimer=new QTimer;
    ptimer->start(50);
    connect(ptimer,SIGNAL(timeout()),this,SLOT(refresh()));
    StartDialog* s_dialog=new StartDialog;
    s_dialog->show();
    connect(s_dialog,SIGNAL(start_signal()),this,SLOT(get_show()));
    movie_start();
    initial();
}

MainWindow::~MainWindow()
{
    delete ui;
}

//GIF播放
void MainWindow::movie_start()
{
    nut_movie=new QMovie(":/new/prefix1/images/Plants/WallNut.gif");
    nut_movie->start();
    nut_cracked2_movie=new QMovie(":/new/prefix1/images/Plants/WallNutCracked2.gif");
    nut_cracked2_movie->start();
    nut_cracked1_movie=new QMovie(":/new/prefix1/images/Plants/WallNutCracked1.gif");
    nut_cracked1_movie->start();
    bomb_movie=new QMovie(":/new/prefix1/images/Plants/Bomb.gif");
    bomb_movie->start();
    shooter_movie=new QMovie(":/new/prefix1/images/Plants/Shooter.gif");
    shooter_movie->start();
    ice_shooter_movie=new QMovie(":/new/prefix1/images/Plants/IceShooter.gif");
    ice_shooter_movie->start();
    ice_bullet_movie=new QMovie(":/new/prefix1/images/Plants/IceBullet.gif");
    ice_bullet_movie->start();
    bullet_movie=new QMovie(":/new/prefix1/images/Plants/Bullet.gif");
    bullet_movie->start();
    normal_ghost_move_movie=new QMovie(":/new/prefix1/images/Zombies/NormalZombie.gif");
    normal_ghost_move_movie->start();
    hat_ghost_move_movie=new QMovie(":/new/prefix1/images/Zombies/HatZombie.gif");
    hat_ghost_move_movie->start();
    bucket_ghost_move_movie=new QMovie(":/new/prefix1/images/Zombies/BucketZombie.gif");
    bucket_ghost_move_movie->start();
    football_ghost_move_movie=new QMovie(":/new/prefix1/images/Zombies/FootballZombie.gif");
    football_ghost_move_movie->start();
    normal_ghost_attack_movie=new QMovie(":/new/prefix1/images/Zombies/NormalZombieAttack.gif");
    normal_ghost_attack_movie->start();
    hat_ghost_attack_movie=new QMovie(":/new/prefix1/images/Zombies/HatZombieAttack.gif");
    hat_ghost_attack_movie->start();
    bucket_ghost_attack_movie=new QMovie(":/new/prefix1/images/Zombies/BucketZombieAttack.gif");
    bucket_ghost_attack_movie->start();
    football_ghost_attack_movie=new QMovie(":/new/prefix1/images/Zombies/FootballZombieAttack.gif");
    football_ghost_attack_movie->start();
}

//关卡初始化
void MainWindow::initial()
{
    card_get=0;
    set_ghost_card_back();
    ui->money_num->setValue(500);
    nut *nutc[10];
    bomb *bombc[10];
    shooter *shooterc[10];
    ice_shooter *ice_shooterc[10];
    brain *brainc[10];
    for(int i=0;i<7-round/2;i++){
        nutc[i]=new nut(place[round][i]/5+1,place[round][i]%5+1);
        nuts<<nutc[i];
    }
    for(int i=0;i<8+round/2;i++){
        bombc[i]=new bomb(place[round][i+7-round/2]/5+1,place[round][i+7-round/2]%5+1);
        bombs<<bombc[i];
    }
    for(int i=0;i<6+round/2;i++){
        shooterc[i]=new shooter(place[round][i+15]/5+1,place[round][i+15]%5+1);
        shooters<<shooterc[i];
    }
    for(int i=0;i<4-round/2;i++){
        ice_shooterc[i]=new ice_shooter(place[round][i+21+round/2]/5+1,place[round][i+21+round/2]%5+1);
        ice_shooters<<ice_shooterc[i];
    }
    for(int i=0;i<5;i++){
        brainc[i]=new brain(i+1);
        brains<<brainc[i];
    }
}

//清理僵尸和植物
void MainWindow::clear()
{
    for(int i=0;i<normal_ghosts.size();i++){
        normal_ghosts[i]->hp=0;
        delete normal_ghosts[i];
        normal_ghosts.clear();
    }
    for(int i=0;i<hat_ghosts.size();i++){
        hat_ghosts[i]->hp=0;
        delete hat_ghosts[i];
        hat_ghosts.clear();
    }
    for(int i=0;i<bucket_ghosts.size();i++){
        bucket_ghosts[i]->hp=0;
        delete bucket_ghosts[i];
        bucket_ghosts.clear();
    }
    for(int i=0;i<football_ghosts.size();i++){
        football_ghosts[i]->hp=0;
        delete football_ghosts[i];
        football_ghosts.clear();
    }
    for(int i=0;i<nuts.size();i++){
        nuts[i]->hp=0;
        delete nuts[i];
        nuts.clear();
    }
    for(int i=0;i<bombs.size();i++){
        bombs[i]->hp=0;
        delete bombs[i];
        bombs.clear();
    }
    for(int i=0;i<shooters.size();i++){
        shooters[i]->hp=0;
        delete shooters[i];
        shooters.clear();
    }
    for(int i=0;i<ice_shooters.size();i++){
        ice_shooters[i]->hp=0;
        delete ice_shooters[i];
        ice_shooters.clear();
    }
    for(int i=0;i<brains.size();i++){
        brains[i]->hp=0;
        delete brains[i];
        brains.clear();
    }
}

//游戏界面刷新(根据ptimer->start(int)决定帧数)
void MainWindow::refresh(){
    if_win();
    if_lost();
    if_next();
    for(int i=0;i<nuts.size();i++){
        if(nuts[i]->hp<=0){
            delete nuts[i];
            nuts.removeAt(i);
            i--;
        }
    }
    for(int i=0;i<bombs.size();i++){
        if_bomb_attack(bombs[i]);
        if(bombs[i]->hp<=0){
            delete bombs[i];
            bombs.removeAt(i);
            i--;
        }
    }
    for(int i=0;i<shooters.size();i++){
        if_shooter_shoot(shooters[i]);
        if(shooters[i]->hp<=0){
            delete shooters[i];
            shooters.removeAt(i);
            i--;
        }
    }
    for(int i=0;i<ice_shooters.size();i++){
        if_ice_shooter_shoot(ice_shooters[i]);
        if(ice_shooters[i]->hp<=0){
            delete ice_shooters[i];
            ice_shooters.removeAt(i);
            i--;
        }
    }
    for(int i=0;i<bullets.size();i++){
        if_bullet_attack(bullets[i]);
        bullets[i]->move();
        if(bullets[i]->hp<=0){
            delete bullets[i];
            bullets.removeAt(i);
            i--;
        }
    }
    for(int i=0;i<ice_bullets.size();i++){
        if_ice_bullet_attack(ice_bullets[i]);
        ice_bullets[i]->move();
        if(ice_bullets[i]->hp<=0){
            delete ice_bullets[i];
            ice_bullets.removeAt(i);
            i--;
        }
    }
    for(int i=0;i<brains.size();i++){
        if(brains[i]->hp<=0){
            delete brains[i];
            brains.removeAt(i);
            i--;
        }
    }
    for(int i=0;i<boomings.size();i++){
        boomings[i]->reduce();
        if(boomings[i]->hp<=0){
            delete boomings[i];
            boomings.removeAt(i);
            i--;
        }
    }
    for(int i=0;i<bullet_breakings.size();i++){
        bullet_breakings[i]->reduce();
        if(bullet_breakings[i]->hp<=0){
            delete bullet_breakings[i];
            bullet_breakings.removeAt(i);
            i--;
        }
    }
    for(int i=0;i<ice_bullet_breakings.size();i++){
        ice_bullet_breakings[i]->reduce();
        if(ice_bullet_breakings[i]->hp<=0){
            delete ice_bullet_breakings[i];
            ice_bullet_breakings.removeAt(i);
            i--;
        }
    }
    for(int i=0;i<normal_ghosts.size();i++){
        if_ghost_attack(normal_ghosts[i]);
        if(!normal_ghosts[i]->attack_judge)
            normal_ghosts[i]->move();
        if(normal_ghosts[i]->hp<=0){
            ghost_dies<<normal_ghosts[i]->die();
            QMovie* ghost_die_moviec=new QMovie(":/new/prefix1/images/Zombies/ZombieDie.gif");
            ghost_die_moviec->start();
            ghost_die_movie<<ghost_die_moviec;
            delete normal_ghosts[i];
            normal_ghosts.removeAt(i);
            i--;
        }
    }
    for(int i=0;i<hat_ghosts.size();i++){
        if_ghost_attack(hat_ghosts[i]);
        if(!hat_ghosts[i]->attack_judge)
            hat_ghosts[i]->move();
        if(hat_ghosts[i]->hp<=0){
            ghost_dies<<hat_ghosts[i]->die();
            QMovie* ghost_die_moviec=new QMovie(":/new/prefix1/images/Zombies/ZombieDie.gif");
            ghost_die_moviec->start();
            ghost_die_movie<<ghost_die_moviec;
            delete hat_ghosts[i];
            hat_ghosts.removeAt(i);
            i--;
        }
    }
    for(int i=0;i<bucket_ghosts.size();i++){
        if_ghost_attack(bucket_ghosts[i]);
        if(!bucket_ghosts[i]->attack_judge)
            bucket_ghosts[i]->move();
        if(bucket_ghosts[i]->hp<=0){
            ghost_dies<<bucket_ghosts[i]->die();
            QMovie* ghost_die_moviec=new QMovie(":/new/prefix1/images/Zombies/ZombieDie.gif");
            ghost_die_moviec->start();
            ghost_die_movie<<ghost_die_moviec;
            delete bucket_ghosts[i];
            bucket_ghosts.removeAt(i);
            i--;
        }
    }
    for(int i=0;i<football_ghosts.size();i++){
        if_ghost_attack(football_ghosts[i]);
        if(!football_ghosts[i]->attack_judge)
            football_ghosts[i]->move();
        if(football_ghosts[i]->hp<=0){
            football_ghost_dies<<football_ghosts[i]->die();
            QMovie* football_ghost_die_moviec=new QMovie(":/new/prefix1/images/Zombies/FootallZombieDie.gif");
            football_ghost_die_moviec->start();
            football_ghost_die_movie<<football_ghost_die_moviec;
            delete football_ghosts[i];
            football_ghosts.removeAt(i);
            i--;
        }
    }
    for(int i=0;i<ghost_dies.size();i++){
        ghost_dies[i]->reduce();
        if(ghost_dies[i]->hp<=0){
            delete ghost_dies[i];
            ghost_dies.removeAt(i);
            delete ghost_die_movie[i];
            ghost_die_movie.removeAt(i);
            i--;
        }
    }
    for(int i=0;i<football_ghost_dies.size();i++){
        football_ghost_dies[i]->reduce();
        if(football_ghost_dies[i]->hp<=0){
            delete football_ghost_dies[i];
            football_ghost_dies.removeAt(i);
            delete football_ghost_die_movie[i];
            football_ghost_die_movie.removeAt(i);
            i--;
        }
    }
    update();
}

//判定游戏获胜
void MainWindow::if_win()
{
    if(brains.size()==0){
        if(round==4){
            this->hide();
            round=0;
            clear();
            initial();
            WinDialog* w_dialog=new WinDialog();
            w_dialog->show();
            connect(w_dialog,SIGNAL(continue_signal()),this,SLOT(get_show()));
            connect(w_dialog,SIGNAL(quit_signal()),this,SLOT(get_close()));
        }
    }
}

//判定游戏失败
void MainWindow::if_lost()
{
    if(brains.size()!=0&&ui->money_num->value()==0){
        if(normal_ghosts.size()==0&&hat_ghosts.size()==0&&bucket_ghosts.size()==0&&football_ghosts.size()==0){
            this->hide();
            round=0;
            clear();
            initial();
            LoseDialog* l_dialog=new LoseDialog();
            l_dialog->show();
            connect(l_dialog,SIGNAL(continue_signal()),this,SLOT(get_show()));
            connect(l_dialog,SIGNAL(quit_signal()),this,SLOT(get_close()));
        }
    }
}

//判定进入下一关
void MainWindow::if_next()
{
    if(brains.size()==0){
        if(round<4){
            this->hide();
            round++;
            clear();
            initial();
            MiddleDialog* m_dialog=new MiddleDialog;
            m_dialog->show();
            connect(m_dialog,SIGNAL(continue_signal()),this,SLOT(get_show()));
            connect(m_dialog,SIGNAL(quit_signal()),this,SLOT(get_close()));
        }
    }
}

//游戏画面调整(由refresh()控制)
void MainWindow::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    painter.drawPixmap(0,0,QPixmap(":/new/prefix1/images/interface/background.jpg"));
    for(int i=0;i<nuts.size();i++){
        if(nuts[i]->hp>3500)
            painter.drawPixmap(nuts[i]->x+30,nuts[i]->y+30,this->nut_movie->currentPixmap());
        if(nuts[i]->hp<=3500&&nuts[i]->hp>1500)
            painter.drawPixmap(nuts[i]->x+30,nuts[i]->y+30,this->nut_cracked2_movie->currentPixmap());
        if(nuts[i]->hp<=1500)
            painter.drawPixmap(nuts[i]->x+30,nuts[i]->y+30,this->nut_cracked1_movie->currentPixmap());
    }
    for(int i=0;i<bombs.size();i++){
        painter.drawPixmap(bombs[i]->x+30,bombs[i]->y+30,this->bomb_movie->currentPixmap());
    }
    for(int i=0;i<shooters.size();i++){
        painter.drawPixmap(shooters[i]->x+30,shooters[i]->y+30,this->shooter_movie->currentPixmap());
    }
    for(int i=0;i<ice_shooters.size();i++){
        painter.drawPixmap(ice_shooters[i]->x+30,ice_shooters[i]->y+30,this->ice_shooter_movie->currentPixmap());
    }
    for(int i=0;i<bullets.size();i++){
        painter.drawPixmap(bullets[i]->x+30,bullets[i]->y+30,this->bullet_movie->currentPixmap());
    }
    for(int i=0;i<ice_bullets.size();i++){
        painter.drawPixmap(ice_bullets[i]->x+30,ice_bullets[i]->y+30,this->ice_bullet_movie->currentPixmap());
    }
    for(int i=0;i<brains.size();i++){
        painter.drawPixmap(brains[i]->x+50,brains[i]->y+50,QPixmap(":/new/prefix1/images/Plants/Brain.png"));
    }
    for(int i=0;i<boomings.size();i++){
        painter.drawPixmap(boomings[i]->x+30,boomings[i]->y+30,QPixmap(":/new/prefix1/images/Plants/Booming.gif"));
    }
    for(int i=0;i<bullet_breakings.size();i++){
        painter.drawPixmap(bullet_breakings[i]->x+30,bullet_breakings[i]->y+30,QPixmap(":/new/prefix1/images/Plants/BulletBreaking.gif"));
    }
    for(int i=0;i<ice_bullet_breakings.size();i++){
        painter.drawPixmap(ice_bullet_breakings[i]->x+30,ice_bullet_breakings[i]->y+30,QPixmap(":/new/prefix1/images/Plants/IceBulletBreaking.png"));
    }
    for(int i=0;i<normal_ghosts.size();i++){
        if(normal_ghosts[i]->attack_judge)
            painter.drawPixmap(normal_ghosts[i]->x,normal_ghosts[i]->y-30,this->normal_ghost_attack_movie->currentPixmap());
        else
            painter.drawPixmap(normal_ghosts[i]->x,normal_ghosts[i]->y-30,this->normal_ghost_move_movie->currentPixmap());
    }
    for(int i=0;i<hat_ghosts.size();i++){
        if(hat_ghosts[i]->attack_judge)
            painter.drawPixmap(hat_ghosts[i]->x,hat_ghosts[i]->y-30,this->hat_ghost_attack_movie->currentPixmap());
        else
            painter.drawPixmap(hat_ghosts[i]->x,hat_ghosts[i]->y-30,this->hat_ghost_move_movie->currentPixmap());
    }
    for(int i=0;i<bucket_ghosts.size();i++){
        if(bucket_ghosts[i]->attack_judge)
            painter.drawPixmap(bucket_ghosts[i]->x,bucket_ghosts[i]->y-30,this->bucket_ghost_attack_movie->currentPixmap());
        else
            painter.drawPixmap(bucket_ghosts[i]->x,bucket_ghosts[i]->y-30,this->bucket_ghost_move_movie->currentPixmap());
    }
    for(int i=0;i<football_ghosts.size();i++){
        if(football_ghosts[i]->attack_judge)
            painter.drawPixmap(football_ghosts[i]->x+50,football_ghosts[i]->y-40,this->football_ghost_attack_movie->currentPixmap());
        else
            painter.drawPixmap(football_ghosts[i]->x+50,football_ghosts[i]->y-40,this->football_ghost_move_movie->currentPixmap());
    }
    for(int i=0;i<ghost_dies.size();i++){
        painter.drawPixmap(ghost_dies[i]->x,ghost_dies[i]->y,ghost_die_movie[i]->currentPixmap());
    }
    for(int i=0;i<football_ghost_dies.size();i++){
        painter.drawPixmap(football_ghost_dies[i]->x+10,football_ghost_dies[i]->y-20,football_ghost_die_movie[i]->currentPixmap());
    }
}

//卡片放回或卡片槽刷新(在卡片按钮的槽函数和僵尸放置时使用)
void MainWindow::set_ghost_card_back()
{
   card_get=0;
   ui->normal_ghost_card->setStyleSheet("border-image: url(:/new/prefix1/images/interface/10.png);");
   ui->hat_ghost_card->setStyleSheet("border-image: url(:/new/prefix1/images/interface/20.png);");
   ui->bucket_ghost_card->setStyleSheet("border-image: url(:/new/prefix1/images/interface/40.png);");
   ui->football_ghost_card->setStyleSheet("border-image: url(:/new/prefix1/images/interface/80.png);");
}

//卡片选取(在卡片按钮的槽函数中使用)
void MainWindow::set_ghost_card_choosed(int card_get)
{
    if(card_get==1)
        ui->normal_ghost_card->setStyleSheet("border-image: url(:/new/prefix1/images/interface/10_choosed.png);");
    if(card_get==2)
        ui->hat_ghost_card->setStyleSheet("border-image: url(:/new/prefix1/images/interface/20_choosed.png);");
    if(card_get==3)
        ui->bucket_ghost_card->setStyleSheet("border-image: url(:/new/prefix1/images/interface/40_choosed.png);");
    if(card_get==4)
        ui->football_ghost_card->setStyleSheet("border-image: url(:/new/prefix1/images/interface/80_choosed.png);");
}

//放置僵尸
void MainWindow::set_solid(int i, int j, int card_get)
{
    if(card_get==1&&judge_money(1)){
        ghost* ghostc=new normal_ghost(i,j);
        normal_ghosts<<ghostc;
    }
    if(card_get==2&&judge_money(2)){
        ghost* ghostc=new hat_ghost(i,j);
        hat_ghosts<<ghostc;
    }
    if(card_get==3&&judge_money(3)){
        ghost* ghostc=new bucket_ghost(i,j);
        bucket_ghosts<<ghostc;
    }
    if(card_get==4&&judge_money(4)){
        ghost* ghostc=new football_ghost(i,j);
        football_ghosts<<ghostc;
    }
    set_ghost_card_back();
}

//判断钱数(在放置僵尸函数中使用)
int MainWindow::judge_money(int card_get)
{
    if(card_get==1){
        if(ui->money_num->value()>=10){
            ui->money_num->setValue(ui->money_num->value()-10);
            return 1;
        }
        else {
            return 0;
        }
    }
    if(card_get==2){
        if(ui->money_num->value()>=20){
            ui->money_num->setValue(ui->money_num->value()-20);
            return 1;
        }
        else {
            return 0;
        }
    }
    if(card_get==3){
        if(ui->money_num->value()>=40){
            ui->money_num->setValue(ui->money_num->value()-40);
            return 1;
        }
        else {
            return 0;
        }
    }
    if(card_get==4){
        if(ui->money_num->value()>=80){
            ui->money_num->setValue(ui->money_num->value()-80);
            return 1;
        }
        else {
            return 0;
        }
    }
    return 0;
}

//ghost判断需不需要攻击
void MainWindow::if_ghost_attack(ghost *ghostc){
    ghostc->attack_judge=0;
    for(int i=0;i<nuts.size();i++){
        if(ghostc->line==nuts[i]->line&&ghostc->col==nuts[i]->col){
            ghostc->attack(nuts[i]);
        }
    }
    for(int i=0;i<bombs.size();i++){
        if(ghostc->line==bombs[i]->line&&ghostc->col==bombs[i]->col){
            ghostc->attack(bombs[i]);
        }
    }
    for(int i=0;i<shooters.size();i++){
        if(ghostc->line==shooters[i]->line&&ghostc->col==shooters[i]->col){
            ghostc->attack(shooters[i]);
        }
    }
    for(int i=0;i<ice_shooters.size();i++){
        if(ghostc->line==ice_shooters[i]->line&&ghostc->col==ice_shooters[i]->col){
            ghostc->attack(ice_shooters[i]);
        }
    }
    for(int i=0;i<brains.size();i++){
        if(ghostc->x/20==brains[i]->x/20&&ghostc->col==brains[i]->col){
            ghostc->attack(brains[i]);
        }
    }
}

//bomb判断需不需要攻击
void MainWindow::if_bomb_attack(bomb *bombc){
    int flag=0;
    for(int i=0;i<normal_ghosts.size();i++){
        if(bombc->line==normal_ghosts[i]->line&&bombc->col==normal_ghosts[i]->col){
            boomings<<bombc->attack(normal_ghosts[i]);
            flag=1;
        }
    }
    for(int i=0;i<hat_ghosts.size();i++){
        if(bombc->line==hat_ghosts[i]->line&&bombc->col==hat_ghosts[i]->col){
            boomings<<bombc->attack(hat_ghosts[i]);
            flag=1;
        }
    }
    for(int i=0;i<bucket_ghosts.size();i++){
        if(bombc->line==bucket_ghosts[i]->line&&bombc->col==bucket_ghosts[i]->col){
            boomings<<bombc->attack(bucket_ghosts[i]);
            flag=1;
        }
    }
    for(int i=0;i<football_ghosts.size();i++){
        if(bombc->line==football_ghosts[i]->line&&bombc->col==football_ghosts[i]->col){
            boomings<<bombc->attack(football_ghosts[i]);
            flag=1;
        }
    }
    if(flag==1)
        bombc->hp-=bombc->power;
}

//shooter判断需不需要发射bullet
void MainWindow::if_shooter_shoot(shooter *shooterc){
    int flag=0;
    for(int i=0;i<normal_ghosts.size();i++){
        if(shooterc->col==normal_ghosts[i]->col){
            flag=1;
        }
    }
    for(int i=0;i<hat_ghosts.size();i++){
        if(shooterc->col==hat_ghosts[i]->col){
            flag=1;
        }
    }
    for(int i=0;i<bucket_ghosts.size();i++){
        if(shooterc->col==bucket_ghosts[i]->col){
            flag=1;
        }
    }
    for(int i=0;i<football_ghosts.size();i++){
        if(shooterc->col==football_ghosts[i]->col){
            flag=1;
        }
    }
    if(flag==1){
        if(shooterc->timer())
            bullets<<shooterc->shoot_bullet();
    }
}

//ice_shooter判断需不需要发射bullet
void MainWindow::if_ice_shooter_shoot(ice_shooter *ice_shooterc){
    int flag=0;
    for(int i=0;i<normal_ghosts.size();i++){
        if(ice_shooterc->col==normal_ghosts[i]->col){
            flag=1;
        }
    }
    for(int i=0;i<hat_ghosts.size();i++){
        if(ice_shooterc->col==hat_ghosts[i]->col){
            flag=1;
        }
    }
    for(int i=0;i<bucket_ghosts.size();i++){
        if(ice_shooterc->col==bucket_ghosts[i]->col){
            flag=1;
        }
    }
    for(int i=0;i<football_ghosts.size();i++){
        if(ice_shooterc->col==football_ghosts[i]->col){
            flag=1;
        }
    }
    if(flag==1){
        if(ice_shooterc->timer())
            ice_bullets<<ice_shooterc->shoot_ice_bullet();
    }
}

//bullet判断需不需要攻击
void MainWindow::if_bullet_attack(bullet *bulletc){
    int flag=0;
    for(int i=0;i<normal_ghosts.size();i++){
        if((bulletc->x/16==normal_ghosts[i]->x/16||bulletc->x/16==(normal_ghosts[i]->x/16)+1)&&bulletc->col==normal_ghosts[i]->col&&flag==0){
            bullet_breakings<<bulletc->attack(normal_ghosts[i]);
            flag=1;
        }
    }
    for(int i=0;i<hat_ghosts.size();i++){
        if((bulletc->x/16==hat_ghosts[i]->x/16||bulletc->x/16==(hat_ghosts[i]->x/16)+1)&&bulletc->col==hat_ghosts[i]->col&&flag==0){
            bullet_breakings<<bulletc->attack(hat_ghosts[i]);
            flag=1;
        }
    }
    for(int i=0;i<bucket_ghosts.size();i++){
        if((bulletc->x/16==bucket_ghosts[i]->x/16||bulletc->x/16==(bucket_ghosts[i]->x/16)+1)&&bulletc->col==bucket_ghosts[i]->col&&flag==0){
            bullet_breakings<<bulletc->attack(bucket_ghosts[i]);
            flag=1;
        }
    }
    for(int i=0;i<football_ghosts.size();i++){
        if((bulletc->x/16==football_ghosts[i]->x/16||bulletc->x/16==(football_ghosts[i]->x/16)+1)&&bulletc->col==football_ghosts[i]->col&&flag==0){
            bullet_breakings<<bulletc->attack(football_ghosts[i]);
            flag=1;
        }
    }
}

//ice_bullet判断需不需要攻击
void MainWindow::if_ice_bullet_attack(ice_bullet *ice_bulletc){
    int flag=0;
    for(int i=0;i<normal_ghosts.size();i++){
        if((ice_bulletc->x/16==normal_ghosts[i]->x/16||ice_bulletc->x/16==(normal_ghosts[i]->x/16)+1)&&ice_bulletc->col==normal_ghosts[i]->col&&flag==0){
            ice_bullet_breakings<<ice_bulletc->attack(normal_ghosts[i]);
            flag=1;
        }
    }
    for(int i=0;i<hat_ghosts.size();i++){
        if((ice_bulletc->x/16==hat_ghosts[i]->x/16||ice_bulletc->x/16==(hat_ghosts[i]->x/16)+1)&&ice_bulletc->col==hat_ghosts[i]->col&&flag==0){
            ice_bullet_breakings<<ice_bulletc->attack(hat_ghosts[i]);
            flag=1;
        }
    }
    for(int i=0;i<bucket_ghosts.size();i++){
        if((ice_bulletc->x/16==bucket_ghosts[i]->x/16||ice_bulletc->x/16==(bucket_ghosts[i]->x/16)+1)&&ice_bulletc->col==bucket_ghosts[i]->col&&flag==0){
            ice_bullet_breakings<<ice_bulletc->attack(bucket_ghosts[i]);
            flag=1;
        }
    }
    for(int i=0;i<football_ghosts.size();i++){
        if((ice_bulletc->x/16==football_ghosts[i]->x/16||ice_bulletc->x/16==(football_ghosts[i]->x/16)+1)&&ice_bulletc->col==football_ghosts[i]->col&&flag==0){
            ice_bullet_breakings<<ice_bulletc->attack(football_ghosts[i]);
            flag=1;
        }
    }
}

//卡片按钮槽函数

//1
void MainWindow::on_normal_ghost_card_clicked()
{
    if(card_get==1){
        set_ghost_card_back();
    }
    else{
        set_ghost_card_back();
        card_get=1;
        set_ghost_card_choosed(card_get);
    }
}

//2
void MainWindow::on_hat_ghost_card_clicked()
{
    if(card_get==2){
        set_ghost_card_back();
    }
    else{
        set_ghost_card_back();
        card_get=2;
        set_ghost_card_choosed(card_get);
    }
}

//3
void MainWindow::on_bucket_ghost_card_clicked()
{
    if(card_get==3){
        set_ghost_card_back();
    }
    else{
        set_ghost_card_back();
        card_get=3;
        set_ghost_card_choosed(card_get);
    }
}

//4
void MainWindow::on_football_ghost_card_clicked()
{
    if(card_get==4){
        set_ghost_card_back();
    }
    else{
        set_ghost_card_back();
        card_get=4;
        set_ghost_card_choosed(card_get);
    }
}

//放置格子槽函数

//9,1
void MainWindow::on_block_9_1_clicked()
{
    if(card_get&&ui->money_num){
        set_solid(9,1,card_get);
    }
}

//9,2
void MainWindow::on_block_9_2_clicked()
{
    if(card_get){
        set_solid(9,2,card_get);
    }
}

//9,3
void MainWindow::on_block_9_3_clicked()
{
    if(card_get){
        set_solid(9,3,card_get);
    }
}

//9,4
void MainWindow::on_block_9_4_clicked()
{
    if(card_get){
        set_solid(9,4,card_get);
    }
}

//9,5
void MainWindow::on_block_9_5_clicked()
{
    if(card_get){
        set_solid(9,5,card_get);
    }
}

//8,1
void MainWindow::on_block_8_1_clicked()
{
    if(card_get){
        set_solid(8,1,card_get);
    }
}

//8,2
void MainWindow::on_block_8_2_clicked()
{
    if(card_get){
        set_solid(8,2,card_get);
    }
}

//8,3
void MainWindow::on_block_8_3_clicked()
{
    if(card_get){
        set_solid(8,3,card_get);
    }
}

//8,4
void MainWindow::on_block_8_4_clicked()
{
    if(card_get){
        set_solid(8,4,card_get);
    }
}

//8,5
void MainWindow::on_block_8_5_clicked()
{
    if(card_get){
        set_solid(8,5,card_get);
    }
}

//7,1
void MainWindow::on_block_7_1_clicked()
{
    if(card_get){
        set_solid(7,1,card_get);
    }
}

//7,2
void MainWindow::on_block_7_2_clicked()
{
    if(card_get){
        set_solid(7,2,card_get);
    }
}

//7,3
void MainWindow::on_block_7_3_clicked()
{
    if(card_get){
        set_solid(7,3,card_get);
    }
}

//7,4
void MainWindow::on_block_7_4_clicked()
{
    if(card_get){
        set_solid(7,4,card_get);
    }
}

//7,5
void MainWindow::on_block_7_5_clicked()
{
    if(card_get){
        set_solid(7,5,card_get);
    }
}

//6,1
void MainWindow::on_block_6_1_clicked()
{
    if(card_get){
        set_solid(6,1,card_get);
    }
}

//6,2
void MainWindow::on_block_6_2_clicked()
{
    if(card_get){
        set_solid(6,2,card_get);
    }
}

//6,3
void MainWindow::on_block_6_3_clicked()
{
    if(card_get){
        set_solid(6,3,card_get);
    }
}

//6,4
void MainWindow::on_block_6_4_clicked()
{
    if(card_get){
        set_solid(6,4,card_get);
    }
}

//6,5
void MainWindow::on_block_6_5_clicked()
{
    if(card_get){
        set_solid(6,5,card_get);
    }
}

void MainWindow::get_hide()
{
    this->hide();
}

void MainWindow::get_show()
{
    this->show();
}

void MainWindow::get_close()
{
    this->close();
}
