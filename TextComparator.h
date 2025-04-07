#ifndef TEXTCOMPARATOR_H
#define TEXTCOMPARATOR_H

#include <QMainWindow>
#include <QTextEdit>
#include <QPushButton>
#include <QSplitter>
#include <QVBoxLayout>

class TextComparator : public QMainWindow
{
    Q_OBJECT

public:
    TextComparator(QWidget *parent = nullptr);
    ~TextComparator();

private slots:
    void compareTexts();

private:
    QTextEdit *leftTextEdit;
    QTextEdit *rightTextEdit;
    QTextEdit *resultTextEdit;
    QPushButton *compareButton;
};

#endif // TEXTCOMPARATOR_H
