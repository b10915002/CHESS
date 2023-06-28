#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
#include <qpixmap.h>
#include <QMouseEvent>
#include <QDebug>
#include <QDialog>
#include <QMessageBox>
#include <vector>
//#include "pawnpro.h"
gameManager *gamemanager;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //設定按鈕相關事件
    setWindowIcon(QPixmap("king.png"));
    ui->pushButton->setText("Game Start");
    started = 0;
    QGraphicsScene *scene = new QGraphicsScene(this);
    scene->setSceneRect(QRect(0,0,617,623));
    item = new QGraphicsPixmapItem();
    item->setPixmap(QPixmap("board.png"));
    scene->addItem(item);
    ui->graphicsView->setScene(scene);
    ui->graphicsView->setMouseTracking(true);
    //
    QGraphicsScene *menuScene = new QGraphicsScene();
    QGraphicsPixmapItem *back = new QGraphicsPixmapItem();
    back->setPixmap(QPixmap("back.png"));
    menuScene->addItem(back);
    ui->graphicsView_2->setScene(menuScene);
    ui->label_2->setText("Press Button");
    //
    gamemanager = new gameManager();
    gamemanager->board = Board();
    SetChess();
    //
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::mousePressEvent(QMouseEvent *event){
    if (started) {
        qDebug() << event->position();
        if ((event->position().x() >= 21 && event->position().x() <= 610)&&
                (event->position().y() >= 8 && event->position().y() <= 600)) {
            Position pos;
            pos.x = (event->position().x()-20)/74;
            pos.y = (event->position().y()-6)/74;
            qDebug() << pos.x << " " << pos.y;
            gamemanager->gameInput(pos);
            SetChess();
            SetHighlight();
            if (gamemanager->GameOver){
                if (gamemanager->stalemate){    //draw
                    GameLose("Game Draw");
                }else{
                    GameLose("Game Over");
                }
            }
            //
            qDebug() << gamemanager->current_player;
            if (!gamemanager->current_player){
                ui->label_2->setText("White's Turn");
            }else if (gamemanager->current_player){
                ui->label_2->setText("Black's Turn");
            }
        }
    }
}

void MainWindow::GameTime()
{
    if(timelimit != 0 && timelimit1 != 0)
    {
        if (!gamemanager->current_player){
            timelimit -= 1;
            QString num = QString::number(timelimit);
            qDebug() << num;
            ui->label->setText("Time:  "+ num +" s");
        }else{
            timelimit1 -= 1;
            QString num = QString::number(timelimit1);
            qDebug() << num;
            ui->label_3->setText("Time:  "+ num +" s");
        }
    }
    else
    {
        timer->stop();
        timer1->stop();
        GameLose("TIME's UP");
    }
}

void MainWindow::on_pushButton_clicked()
{
    if (!started){
        //
        ui->pushButton->setText("Game Over"); started = 1;
        gamemanager = new gameManager();
        gamemanager->board = Board();
        SetChess();
        GameFirst();
        if (!gamemanager->current_player){
            ui->label_2->setText("White's Turn");
        }else if (gamemanager->current_player){
            ui->label_2->setText("Black's Turn");
        }
        //
        timelimit = 601;
        timer = new QTimer(this);
        connect(timer, SIGNAL(timeout()), this, SLOT(GameTime()));
        timer->start( 1000 );
        timelimit1 = 601;
        timer1 = new QTimer(this);
        connect(timer1, SIGNAL(timeout()), this, SLOT(GameTime()));
        timer->start( 1000 );
    }else{
        //
        GameLose("GAME OVER");
        //
    }
}
//vector<vector<ChessPiece *>> test = gamemanager->board.getCurrentBoard();
//test[1][0]->team 0:W 1:B      //typeid(*test[1][0]).name()
void MainWindow::SetChess(){
    vector<vector<ChessPiece *>> chessboard = gamemanager->board.getCurrentBoard();
    //
    gameScene = new QGraphicsScene(this);
    gameScene->setSceneRect(QRect(0,0,617,623));
    gameScene->addItem(item);
    //
    int team = 0, x = 0, y = 0; string name = "";
    for(int m = 0; m < 8; m++){
        for(int n = 0; n < 8; n++){
            QGraphicsPixmapItem *chess = new QGraphicsPixmapItem();
            team = chessboard[m][n]->team;
            name = typeid(*chessboard[m][n]).name();
            x = 36 + (n * 74); y = 22 + (m * 74);
            //
            switch (team) {
            case 0: //White
                if (name == "class king"){             //king
                    chess->setPixmap(QPixmap("king.png"));
                    chess->setPos(x,y);
                    if (!gamemanager->current_player){
                        kingPos.x = x; kingPos.y = y;
                    }
                }else if (name == "class queen"){       //queen
                    chess->setPixmap(QPixmap("queen.png"));
                    chess->setPos(x,y);
                }else if (name == "class bishop"){       //bishop
                    chess->setPixmap(QPixmap("bishop.png"));
                    chess->setPos(x,y);
                }else if (name == "class knight"){       //knight
                    chess->setPixmap(QPixmap("knight.png"));
                    chess->setPos(x,y);
                }else if (name == "class rook"){       //rook
                    chess->setPixmap(QPixmap("rook.png"));
                    chess->setPos(x,y);
                }else if (name == "class pawn"){       //pawn
                    chess->setPixmap(QPixmap("pawn.png"));
                    chess->setPos(x,y);
                }
                gameScene->addItem(chess);
                break;
            case 1: //Black
                if (name == "class king"){             //king
                    chess->setPixmap(QPixmap("king1.png"));
                    chess->setPos(x,y);
                    if (gamemanager->current_player){
                        kingPos.x = x; kingPos.y = y;
                    }
                }else if (name == "class queen"){       //queen
                    chess->setPixmap(QPixmap("queen1.png"));
                    chess->setPos(x,y);
                }else if (name == "class bishop"){       //bishop
                    chess->setPixmap(QPixmap("bishop1.png"));
                    chess->setPos(x,y);
                }else if (name == "class knight"){       //knight
                    chess->setPixmap(QPixmap("knight1.png"));
                    chess->setPos(x,y);
                }else if (name == "class rook"){       //rook
                    chess->setPixmap(QPixmap("rook1.png"));
                    chess->setPos(x,y);
                }else if (name == "class pawn"){       //pawn
                    chess->setPixmap(QPixmap("pawn1.png"));
                    chess->setPos(x,y);
                }
                gameScene->addItem(chess);
                break;
            default:
                break;
            }
        }
    }
    //
    ui->graphicsView->setScene(gameScene);
}

//std::vector<Position>
void MainWindow::SetHighlight(){
    //if (gamemanager->currentLegalMoves.empty()) { return; }
    vector<Position> LegalMoves = gamemanager->currentLegalMoves;
    if (gamemanager->isCheckmated(gamemanager->board.getCurrentBoard())){
        QGraphicsPixmapItem *die = new QGraphicsPixmapItem();
        die->setPixmap(QPixmap("die.png"));
        die->setPos(kingPos.x - 16, kingPos.y - 16);
        //qDebug() << "king:"<< kingPos.x << kingPos.y;
        gameScene->addItem(die);
    }
    for (Position i:LegalMoves){
        QGraphicsPixmapItem *move = new QGraphicsPixmapItem();
        if (gamemanager->board.getCurrentBoard()[i.y][i.x]->isEmpty()){
            move->setPixmap(QPixmap("high.png"));
        }else{
            move->setPixmap(QPixmap("diee.png"));
        }
        move->setPos(19 + (i.x * 74), 6 + (i.y * 74));
        gameScene->addItem(move);
    }
    ui->graphicsView->setScene(gameScene);
}

void MainWindow::GameLose(const QString _title){
    timer->stop();
    ui->pushButton->setText("Game Start"); started = 0;
    QString teamTurn = "";
    if (_title == "Game Draw"){
        teamTurn = "\n\nDraw";
    }else{
        if (gamemanager->current_player){
            teamTurn = "\n\nWHITE WIN";
        }else{
            teamTurn = "\n\nBLACK WIN";
        }
    }
    QMessageBox *msgBox = new QMessageBox(_title,teamTurn,
    QMessageBox::NoIcon, QMessageBox::Ok | QMessageBox::Default, QMessageBox::Close | QMessageBox::Escape,0);//make again or end
    msgBox->setIconPixmap(QPixmap("lose.png"));
    msgBox->setWindowIcon(QPixmap("overicon.png"));
    msgBox->setButtonText(QMessageBox::Ok,"Try again");
    msgBox->setButtonText(QMessageBox::Close,"Exit");
    msgBox->show();
    if(msgBox->exec() == QMessageBox::Close){
        close();
    }
}

void MainWindow::GameFirst(){
    QMessageBox *msgBox = new QMessageBox("Menu","Choose one",
    QMessageBox::NoIcon, QMessageBox::Ok | QMessageBox::Default, QMessageBox::Close | QMessageBox::Escape,0);//make again or end
    msgBox->setWindowIcon(QPixmap("overicon.png"));
    msgBox->setButtonText(QMessageBox::Ok,"White");
    msgBox->setButtonText(QMessageBox::Close,"Black");
    msgBox->show();
    if(msgBox->exec() == QMessageBox::Close){
        gamemanager->current_player = 1;
    }
}
