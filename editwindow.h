#ifndef EDITWINDOW_H
#define EDITWINDOW_H

#include <QDialog>

namespace Ui {
class EditWindow;
}

class EditWindow : public QDialog
{
    Q_OBJECT

public:
    explicit EditWindow(std::string& name, std::string& email, std::string& phone, QWidget *parent = nullptr);
    ~EditWindow();

private slots:
    void on_edit_save_push_button_clicked();
    void on_edit_cancel_push_button_clicked();

private:
    Ui::EditWindow *ui;
    std::string& m_name;
    std::string& m_email;
    std::string& m_phone;
};

#endif // EDITWINDOW_H
