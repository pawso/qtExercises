#include "gameManager.hpp"
#include <cassert>
#include <iostream>

GameManager::GameManager(QWidget *parent) : QObject(parent)
{
    m_fields.resize(9);
    for (size_t i = 0; i < m_fields.size(); i++) {
        m_fields[i] = 0;
    }

    m_roundNo = 0;
}

void
GameManager::roundFinished(int playerIdx, int fieldIdx)
{
    assert(playerIdx == 1 || playerIdx == 2);
    assert(fieldIdx < 9);
    m_fields[fieldIdx] = playerIdx;

    m_roundNo++;

    if (checkState(fieldIdx, playerIdx)) {
        std::cout << "player " << playerIdx << "won!" << std::endl;
        emit gameFinished(playerIdx);
    } else if (m_roundNo == 9){
        emit gameFinished(playerIdx);
    } else {
        std::cout << "game continues" << std::endl;
    }
}

bool
GameManager::checkState(int fieldChangedIdx, int playerIdx)
{
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            std::cout << m_fields[i * 3 + j] << " ";
        }
        std::cout << std::endl;
    }


    int row = fieldChangedIdx / 3;
    int col = fieldChangedIdx % 3;

    std::cout << "row = " << row << " col = " << col << std::endl;

    int res = 0;
    int currIdx = 0;
    for (int i = -row; i < -row + 3; i++) {
        currIdx = (row + i) * 3 + col;
        std::cout << "Testing " << currIdx << std::endl;
        if (currIdx >= 0 && currIdx < 9 && m_fields[currIdx] == (unsigned) playerIdx) {
            res++;
           //  std::cout << "res = " << res << std::endl;
        }
    }
    if (res == 3)
        return true;
    res = 0;
    std::cout << std::endl;

    for (int i = -col; i < -col + 3; i++) {
        currIdx = row * 3 + col + i;
        std::cout << "Testing " << currIdx << std::endl;
        if (currIdx >= 0 && currIdx < 9 && m_fields[currIdx] == (unsigned) playerIdx) {
            res++;
            // std::cout << "res = " << res << std::endl;
        }
    }
    if (res == 3)
        return true;
    res = 0;
    std::cout << std::endl;


    for (int i = -row; i < -row + 3; i++) {
        currIdx = (row + i) * 3 + col + i;
        std::cout << "Testing " << currIdx << std::endl;
        if (currIdx >= 0 &&currIdx < 9 && m_fields[currIdx] == (unsigned) playerIdx) {
            res++;
            // std::cout << "res = " << res << std::endl;
        }
    }
    if (res == 3)
        return true;
    res = 0;
    std::cout << std::endl;

    for (int i = -col; i < 3; i++) {
        currIdx = (row - i) * 3 + col + i;
        std::cout << "Testing " << currIdx << std::endl;
        if (currIdx >= 0 && currIdx < 9 && m_fields[currIdx] == (unsigned) playerIdx) {
            res++;
           //  std::cout << "res = " << res << std::endl;
        }
    }
    if (res == 3)
        return true;

    std::cout << std::endl;

    return false;
}
