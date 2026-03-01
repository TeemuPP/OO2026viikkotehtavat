#include "mainwindow.h"
#include "./ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    pQTimer = new QTimer(this);

    connect(pQTimer, &QTimer::timeout,
            this, &MainWindow::timeOutHandler);

    connect(ui->startGame, &QPushButton::clicked,
            this, &MainWindow::startGameHandler);
    connect(ui->stopGame, &QPushButton::clicked,
            this, &MainWindow::stopGameHandler);

    connect(ui->p1, &QPushButton::clicked,
            this, &MainWindow::switchPlayerHandler);
    connect(ui->p2, &QPushButton::clicked,
            this, &MainWindow::switchPlayerHandler);

    connect(ui->gameTime120, &QPushButton::clicked,
            this, &MainWindow::gameTimeHandler);
    connect(ui->gameTime5, &QPushButton::clicked,
            this, &MainWindow::gameTimeHandler);
    setGameInfoText("Select playtime and press start game!",12);

    player1Time = 0;
    player2Time = 0;
    gameTime = 0;
    currentPlayer = 1;
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::timeOutHandler()
{
    if(currentPlayer == 1 && player1Time > 0)
    {
        player1Time--;
        gameTime--;
        ui->p1time->setValue(player1Time);
    }
    else if (currentPlayer == 2 && player2Time > 0)
    {
        player2Time--;
        gameTime--;
        ui->p2time->setValue(player2Time);
    }
    if (player1Time == 0)
    {
        setGameInfoText("Player 2 WON!!",25);
        pQTimer->stop();
    }
    if (player2Time == 0)
    {
        setGameInfoText("Player 1 WON!!",25);
        pQTimer->stop();
    }

}

void MainWindow::setGameInfoText(QString txt, short font)
{
    ui->label->setText(txt);
    ui->label->setFrameStyle(QFrame::Panel | QFrame::Sunken);
    ui->label->setFixedHeight(35);
    ui->label->QLabel::setStyleSheet
    (QString("font-size: %1px; font-weight: bold; color: black;").arg(font));
}

void MainWindow::startGameHandler()
{
    if (player1Time == 0 || player2Time == 0)
    {
        setGameInfoText("Select playtime first!",12);
        return;
    }

    setGameInfoText("Game started",12);
    currentPlayer = 1;
    pQTimer->start(1000);
}
void MainWindow::stopGameHandler()
{
    pQTimer->stop();
    ui->p1time->reset();
    ui->p2time->reset();
    setGameInfoText("Select playtime and press start game!",12);
}

void MainWindow::switchPlayerHandler()

{
    QPushButton *button = qobject_cast<QPushButton *>(sender());
    QString toBeSwitched = button->objectName();
    if (toBeSwitched == "p1"){
        currentPlayer = 2;
        setGameInfoText("Player 2 turn!",12);
    }
    if (toBeSwitched == "p2"){
        currentPlayer = 1;
        setGameInfoText("Player 1 turn!",12);
    }

}

void MainWindow::gameTimeHandler()
{
    QPushButton *button = qobject_cast<QPushButton *>(sender());
    QString gameLength = button->objectName();

    if (gameLength == "gameTime120"){
        gameTime = 120;
        player1Time = 120;
        player2Time = 120;
        ui->p1time->setRange(0,player1Time);
        ui->p1time->setValue(player1Time);
        ui->p2time->setRange(0,player2Time);
        ui->p2time->setValue(player2Time);
        setGameInfoText("120 sec selected",12);
    }
    else if (gameLength == "gameTime5"){
        gameTime = 300;
        player1Time = 300;
        player2Time = 300;
        ui->p1time->setRange(0,player1Time);
        ui->p1time->setValue(player1Time);
        ui->p2time->setRange(0,player2Time);
        ui->p2time->setValue(player2Time);
        setGameInfoText("5 min selected",12);
    }
}



