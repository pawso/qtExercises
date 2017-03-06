#include "gameArea.hpp"
#include "field.hpp"
#include <QApplication>

GameField::GameField(QWidget *parent) : QWidget(parent) {

    m_mainWidth = parent->width();
    m_mainHeight = parent->height();

    m_spacer = 10;

    m_fieldWidth = (m_mainWidth - 4 * m_spacer) / 3;
    m_fieldHeight = (m_mainHeight - 4 * m_spacer) / 3;

    createAndAttachMainField(parent);
    createAndAttachFields(parent);
}

GameField::~GameField()
{
}

void GameField::createAndAttachMainField(QWidget *parent) {
    QLabel *background = new QLabel(parent);
    
    background->setStyleSheet("QLabel { background-color : white; }");
    background->resize(m_mainWidth, m_mainHeight);
}

void GameField::createAndAttachFields(QWidget *parent) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            new Field(parent, m_spacer, m_fieldWidth, m_fieldHeight, i, j);
            /* QPushButton *button = new QPushButton(parent);
            button->resize(m_fieldWidth, m_fieldHeight);
            button->move(m_spacer + i * (m_fieldWidth + m_spacer), m_spacer + j * (m_fieldHeight + m_spacer));
            QPalette pal = button->palette();
            pal.setColor(QPalette::Button, QColor(Qt::blue));
            button->setAutoFillBackground(true);
            button->setPalette(pal);
            button->update();
            QObject::connect(button, SIGNAL (clicked()), QApplication::instance(), SLOT (quit())); */
        }
    }
}
