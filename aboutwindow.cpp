#include "aboutwindow.h"
#include "ui_aboutwindow.h"

AboutWindow::AboutWindow(const std::string& name, const std::string& email, const std::string& phone, QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::AboutWindow)
{
    ui->setupUi(this);

    ui->about_name_email_phone_label->setText(QString::fromStdString("Name: " + name +
                                                                     "          Email: " + email +
                                                                     "          Phone: " + phone));
}

AboutWindow::~AboutWindow()
{
    delete ui;
}

void AboutWindow::on_about_close_push_button_clicked()
{
    this->close();
}
