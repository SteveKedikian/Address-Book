#ifndef ABOUTWINDOW_H
#define ABOUTWINDOW_H

#include <QDialog>

namespace Ui {
class AboutWindow;
}

class AboutWindow : public QDialog
{
    Q_OBJECT

public:
    explicit AboutWindow(const std::string& name, const std::string& email, const std::string& phone, QWidget *parent = nullptr);
    ~AboutWindow();

private slots:
    void on_about_close_push_button_clicked();

private:
    Ui::AboutWindow *ui;
};

#endif // ABOUTWINDOW_H
