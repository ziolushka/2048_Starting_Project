#ifndef SECONDWINDOW_H
#define SECONDWINDOW_H

#include <QMainWindow>
#include <QLayout>
#include <QFile>
#include <QDesktopServices>
#include <QUrl>

namespace Ui {
class SecondWindow;
}

class SecondWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit SecondWindow(QWidget *parent = nullptr);
    void applyStyles();
    ~SecondWindow();

private slots:
    void on_try_again_button_clicked();
    void on_link_button_clicked();

signals:
    void closed();

private:
    Ui::SecondWindow *ui;
};

#endif // SECONDWINDOW_H
