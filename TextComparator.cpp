#include "TextComparator.h"
#include <QMetaObject>
#include <QString>
#include <QStringList>
#include <QTextCursor>
#include <QTextCharFormat>

TextComparator::TextComparator(QWidget *parent)
    : QMainWindow(parent)
{
    // Create widgets
    leftTextEdit = new QTextEdit(this);
    rightTextEdit = new QTextEdit(this);
    resultTextEdit = new QTextEdit(this);
    compareButton = new QPushButton("Compare", this);
    
    // Set read-only for result
    resultTextEdit->setReadOnly(true);
    
    // Create layouts
    QSplitter *splitter = new QSplitter(Qt::Horizontal);
    splitter->addWidget(leftTextEdit);
    splitter->addWidget(rightTextEdit);
    
    QVBoxLayout *mainLayout = new QVBoxLayout();
    mainLayout->addWidget(splitter);
    mainLayout->addWidget(compareButton);
    mainLayout->addWidget(resultTextEdit);
    
    QWidget *centralWidget = new QWidget(this);
    centralWidget->setLayout(mainLayout);
    setCentralWidget(centralWidget);
    
    // Connect button signal
    connect(compareButton, &QPushButton::clicked, this, &TextComparator::compareTexts);
    
    // Window settings
    setWindowTitle("Text Comparator");
    resize(800, 600);
}

TextComparator::~TextComparator()
{
    // Clean up widgets
    delete leftTextEdit;
    delete rightTextEdit;
    delete resultTextEdit;
    delete compareButton;
}

void TextComparator::compareTexts()
{
    QString leftText = leftTextEdit->toPlainText();
    QString rightText = rightTextEdit->toPlainText();
    
    QStringList leftLines = leftText.split('\n');
    QStringList rightLines = rightText.split('\n');
    
    resultTextEdit->clear();
    
    int maxLines = qMax(leftLines.count(), rightLines.count());
    for (int i = 0; i < maxLines; i++) {
        QString leftLine = i < leftLines.count() ? leftLines[i] : "";
        QString rightLine = i < rightLines.count() ? rightLines[i] : "";
        
        if (leftLine == rightLine) {
            resultTextEdit->append(QString("Line %1: [MATCH] %2").arg(i+1).arg(leftLine));
        } else {
            resultTextEdit->append(QString("Line %1: [DIFF]").arg(i+1));
            resultTextEdit->append(QString("  Left:  %1").arg(leftLine));
            resultTextEdit->append(QString("  Right: %1").arg(rightLine));
            resultTextEdit->append("");
        }
    }
}
