#ifndef PLAYER_H
#define PLAYER_H

#include "environment.h"

class Player{
    public:
      Player(int jug);
      Environment::ActionType Think();
      void Perceive(const Environment &env);
      double MiniMax(Environment V,int max, int depth,int& act);
      double PodaAlfaBeta(Environment V, int max, const int depth, double alpha, double beta, int &act);
    private:
      int jugador_;
      Environment actual_;
};
#endif
