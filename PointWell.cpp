#include "PointWell.h"

PointWell::PointWell() {
  currentPoint_ = 1;
  maxPoint_ = 1;
}

PointWell::PointWell(well_t currentPoint, well_t maxPoint) {
  currentPoint_ = currentPoint;
  maxPoint_ = maxPoint;
  if (currentPoint_ > maxPoint_) {
    currentPoint_ = maxPoint_;
  }
}

bool PointWell::setMax(well_t newMax) {
  if (newMax < 1) {
    return false;
  }

  maxPoint_ = newMax;

  if (currentPoint_ > maxPoint_) {
    currentPoint_ = maxPoint_;
  }

  return true;
}

void PointWell::reduce(well_t damage) {
  if (damage > currentPoint_) {
    currentPoint_ = 0;
    return;
  }

  currentPoint_ -= damage;
  return;
}

void PointWell::increaseCurrent(well_t amount) {
  if (amount + currentPoint_ > maxPoint_) {
    currentPoint_ = maxPoint_;
    return;
  }

  currentPoint_ += amount;
  return;
}


well_t PointWell::getMax() { return maxPoint_; }

well_t PointWell::getCurrent() { return currentPoint_; }