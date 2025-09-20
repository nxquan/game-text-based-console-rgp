#pragma once
#include "types.h"
#include <math.h>

class PointWell {
private:
  well_t currentPoint_;
  well_t maxPoint_;

public:
  PointWell();
  PointWell(well_t currentPoint, well_t naxPoint);
  bool setMax(well_t newMaxHp);
  void increaseCurrent(well_t amount);
  void reduce(well_t damage);
  well_t getMax();
  well_t getCurrent();
};