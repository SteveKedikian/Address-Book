#ifndef CREATEWINDOW_H
#define CREATEWINDOW_H

#include <QDialog>

namespace Ui {
class CreateWindow;
}

class CreateWindow : public QDialog
{
    Q_OBJECT

public:
    explicit CreateWindow(std::string& name, std::string& email, std::string& phone, QWidget *parent = nullptr);
    ~CreateWindow();

private slots:
    void on_create_create_push_button_clicked();
    void on_create_cancel_push_button_clicked();

private:
    Ui::CreateWindow *ui;
    std::string& m_name;
    std::string& m_email;
    std::string& m_phone;
};

#endif // CREATEWINDOW_H
