#include "field.hpp"
#include <iostream>

/* class Field : public QPushButton
{
    Q_OBJECT
    public:
        

    public slots:
        

    private:
        char m_currentChar;
} */

Field::Field(QWidget *parent, int spacing, int fieldWidth, int fieldHeight, int row, int col)
{
    QPushButton *m_button = new QPushButton(parent);
    m_button->resize(fieldWidth, fieldHeight);
    m_button->move(spacing + col * (fieldWidth + spacing), spacing + row * (fieldHeight + spacing));
    QPalette pal = m_button->palette();
    pal.setColor(QPalette::Button, QColor(Qt::blue));
    m_button->setAutoFillBackground(true);
    m_button->setPalette(pal);
    m_button->update();
    QObject::connect(m_button, SIGNAL (clicked()), this, SLOT (changeVal()));

    m_currentChar = 'a';
}

Field::~Field(void)
{
}

void Field::changeVal(void)
{
    // m_button->setText("aaaa");
    m_currentChar++;

    // QString str = QChar(inBuffer[1]);
    QPushButton *caller = qobject_cast<QPushButton *>(sender());
    if (!caller)
        return;
    caller->setText(QChar(m_currentChar));
}
