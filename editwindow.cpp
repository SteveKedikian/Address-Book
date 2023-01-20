#include "editwindow.h"
#include "ui_editwindow.h"

#include <QMessageBox>

EditWindow::EditWindow(std::string& name, std::string& email, std::string& phone, QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::EditWindow)
    , m_name{name}
    , m_email{email}
    , m_phone{phone}
{
    ui->setupUi(this);
}

EditWindow::~EditWindow()
{
    delete ui;
}

void EditWindow::on_edit_save_push_button_clicked()
{
    std::string name = ui->edit_name_line_label->text().toStdString();
    std::string email = ui->edit_email_line_label->text().toStdString();
    std::string phone = ui->edit_phone_line_label->text().toStdString();

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

void EditWindow::on_edit_cancel_push_button_clicked()
{
    this->close();
}

