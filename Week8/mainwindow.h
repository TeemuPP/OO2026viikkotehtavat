#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QTimer>


#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void timeout();

public slots:
    void timeOutHandler();

private:
    Ui::MainWindow *ui;
    short player1Time;
    short player2Time;
    short currentPlayer;
    short gameTime;
    QTimer * pQTimer;
    void updateProgressBar();
    void setGameInfoText(QString,short);

private slots:
    void startGameHandler();
    void stopGameHandler();
    void switchPlayerHandler();
    void gameTimeHandler();
};
#endif // MAINWINDOW_H
