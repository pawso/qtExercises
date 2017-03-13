#include "gameManager.hpp"
#include <cassert>
#include <iostream>

GameManager::GameManager(QWidget *parent) : QObject(parent)
{
    m_fields.resize(9);
    for (size_t i = 0; i < m_fields.size(); i++) {
        m_fields[i] = 0;
    }
}

void
GameManager::roundFinished(int playerIdx, int fieldIdx)
{
    assert(playerIdx == 1 || playerIdx == 2);
    assert(fieldIdx < 9);
    m_fields[fieldIdx] = playerIdx;

    if (checkState()) {
        std::cout << "player " << playerIdx << "won!" << std::endl;
    } else {
        std::cout << "game continues" << std::endl;
    }
}

bool
GameManager::checkState(void)
{
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            std::cout << m_fields[i * 3 + j] << " ";
        }
        std::cout << std::endl;
    }

    return false;
}
