#include "createwindow.h"
#include "ui_createwindow.h"

#include <QMessageBox>

CreateWindow::CreateWindow(std::string& name, std::string& email, std::string& phone, QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::CreateWindow)
    , m_name{name}
    , m_email{email}
    , m_phone{phone}
{
    ui->setupUi(this);
}

CreateWindow::~CreateWindow()
{
    delete ui;
}

void CreateWindow::on_create_create_push_button_clicked()
{
    std::string name = ui->create_name_line_label->text().toStdString();
    std::string email = ui->create_email_line_label->text().toStdString();
    std::string phone = ui->create_phone_line_label->text().toStdString();

    // NAME CHECKER
    // EMAIL CHECKER
    // PHONE CHECKER

    if (name.empty()) {
        QMessageBox::information(this, "User Message !", "Address name can't be empty !");
        return;
    }

    if (email.empty()) {
        QMessageBox::information(this, "User Message !", "Address email can't be empty !");
        return;
    }

    if (phone.empty()) {
        QMessageBox::information(this, "User Message !", "Address phone can't be empty !");
        return;
    }

    m_name = name;
    m_email = email;
    m_phone = phone;
    this->close();
}

void CreateWindow::on_create_cancel_push_button_clicked()
{
    this->close();
}

