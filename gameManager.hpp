#ifndef _GAME_MANAGER_HPP_
#define _GAME_MANAGER_HPP_

#include <QWidget>
#include <QObject>
#include <vector>

class GameManager : public QObject
{
    Q_OBJECT
    public:
        explicit GameManager(QWidget *parent = 0);

    public slots:
        void roundFinished(int playerIdx, int fieldIdx);

    signals:
        void gameFinished(int winnerNum);

    private:
        std::vector<unsigned> m_fields;
        short m_roundNo;

        bool checkState(int fieldChangedIdx, int playerIdx);
};

#endif
