#include "gameArea.hpp"
#include "field.hpp"
#include "gameManager.hpp"
#include <QApplication>
#include <iostream>

GameField::GameField(QWidget *parent) : QWidget(parent) {

    m_mainWidth = parent->width();
    m_mainHeight = parent->height();

    m_spacer = 10;

    m_fieldWidth = (m_mainWidth - 4 * m_spacer) / 3;
    m_fieldHeight = (m_mainHeight - 4 * m_spacer) / 3;

    createAndAttachMainField(parent);
    createAndAttachFields(parent);

    GameManager *gm = new GameManager(parent);
    QObject::connect(this, SIGNAL (roundFinished(int, int)), gm, SLOT (roundFinished(int, int)));
}

GameField::~GameField()
{
}

void
GameField::createAndAttachMainField(QWidget *parent) {
    QLabel *background = new QLabel(parent);
    
    background->setStyleSheet("QLabel { background-color : white; }");
    background->resize(m_mainWidth, m_mainHeight);
}

void
GameField::createAndAttachFields(QWidget *parent) {
    int k = 0;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            Field *f = new Field(parent, m_spacer, m_fieldWidth, m_fieldHeight, i, j, k++);
            QObject::connect(f, SIGNAL (playerChanged(int)), this, SLOT (changedButtonIdx(int)));
        }
    }
}

void
GameField::changedButtonIdx(int idx)
{
    static int i = 0;
    std::cout << "Idx is" << i << std::endl;
    Field::changePlayer(i++);
    emit roundFinished(1, idx);
}


