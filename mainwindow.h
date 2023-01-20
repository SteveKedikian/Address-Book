#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "address.h"

#include <QMainWindow>
#include <vector>
#include <QDialog>
#include <string>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_prog_about_push_button_clicked();
    void on_prog_create_push_button_clicked();
    void on_prog_status_push_button_clicked();
    void on_prog_edit_push_button_clicked();
    void on_prog_logout_push_button_clicked();

private:
    Ui::MainWindow *ui;
    std::vector<Address> m_addresses;
    static const std::string m_name_empty;
    static const std::string m_email_empty;
    static const std::string m_phone_empty;
};

#endif // MAINWINDOW_H
