#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "fileload.h"
#include "aboutwindow.h"
#include "createwindow.h"
#include "editwindow.h"
#include "filesave.h"

// Random symbols for name, email, phone to be used for CREATE function
const std::string MainWindow::m_name_empty = "#_)!!)*%";
const std::string MainWindow::m_email_empty = "^&))@#";
const std::string MainWindow::m_phone_empty = "^*)J#U";

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    FileLoad loader;

    m_addresses = loader.load_addresses_data_txt(parent);

    for (unsigned int i = 0; i < m_addresses.size(); ++i) {
        ui->prog_list_widget->addItem(QString::fromStdString(std::to_string(i + 1) +
                                                             "   " + m_addresses[i].get_name() +
                                                             "          " + m_addresses[i].get_email() +
                                                             "          " + m_addresses[i].get_phone()));
    }
}

MainWindow::~MainWindow()
{
    FileSave saver;
    saver.save_addresses_data_txt(m_addresses);
    delete ui;
}


void MainWindow::on_prog_about_push_button_clicked()
{
    int row_index = ui->prog_list_widget->currentRow();
    std::string name = m_addresses[row_index].get_name();
    std::string email = m_addresses[row_index].get_email();
    std::string phone = m_addresses[row_index].get_phone();

    AboutWindow about_window(name, email, phone);
    about_window.setModal(true);
    about_window.exec();
}


void MainWindow::on_prog_create_push_button_clicked()
{
    std::string name = m_name_empty;
    std::string email = m_email_empty;
    std::string phone = m_phone_empty;

    CreateWindow create_window(name, email, phone);
    create_window.setModal(true);
    create_window.exec();

    if (name == m_name_empty || email == m_email_empty || phone == m_phone_empty) {
        return;
    }

    m_addresses.push_back(Address(name, email, phone));
    ui->prog_list_widget->addItem(QString::fromStdString(std::to_string(m_addresses.size()) +
                                                         "   " + m_addresses[m_addresses.size() - 1].get_name() +
                                                         "          " + m_addresses[m_addresses.size() - 1].get_email() +
                                                         "          " + m_addresses[m_addresses.size() - 1].get_phone()));
}

void MainWindow::on_prog_status_push_button_clicked()
{
    int row_index = ui->prog_list_widget->currentRow();
    m_addresses[row_index] = m_addresses[m_addresses.size() - 1]; // changing with last one

    ui->prog_list_widget->currentItem()->setText(QString::fromStdString(std::to_string(row_index + 1) +
                                                                        "   " + m_addresses[row_index].get_name() +
                                                                        "          " + m_addresses[row_index].get_email() +
                                                                        "          " + m_addresses[row_index].get_phone()));

    QListWidgetItem  *it = ui->prog_list_widget->takeItem(m_addresses.size() - 1);
    m_addresses.pop_back();
    delete it;
}

void MainWindow::on_prog_edit_push_button_clicked()
{
    int row_index = ui->prog_list_widget->currentRow();
    std::string name = m_name_empty;
    std::string email = m_email_empty;
    std::string phone = m_phone_empty;



    EditWindow edit_window(name, email, phone);
    edit_window.setModal(true);
    edit_window.exec();

    if (name == m_name_empty || email == m_email_empty || phone == m_phone_empty) {
        return;
    }

    m_addresses[row_index].set_name(name);
    m_addresses[row_index].set_email(email);
    m_addresses[row_index].set_phone(phone);
    ui->prog_list_widget->currentItem()->setText(QString::fromStdString(std::to_string(row_index + 1) +
                                                                        "   " + m_addresses[row_index].get_name() +
                                                                        "          " + m_addresses[row_index].get_email() +
                                                                        "          " + m_addresses[row_index].get_phone()));
}


void MainWindow::on_prog_logout_push_button_clicked()
{
    this->close();
}

